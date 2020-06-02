//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2019  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);

  subroutine subr(ctx->ID()->getText());

  // std::cout<<ctx->function_params()->getText()<<std::endl;
  // ////////////////////

  // std::vector<var> && fvars = visit(ctx->function_params());
  //Si devuelve algo, entonces reservamos en la pila el resultado.
  if(ctx->type()){
    subr.add_param("_result");
  }
  std::vector<std::string> && fvars = visit(ctx->function_params());
  for (auto & onevar : fvars) {
    subr.add_param(onevar);

  }
  ///////////////////////////////////////////////////
  

  codeCounters.reset();
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }
  // std::cout<<subr.dump()<<std::endl;
  
  instructionList && code = visit(ctx->statements());
  code = code || instruction(instruction::RETURN());
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;

  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> varset = visit(varDeclCtx);
    for (auto i : varset)
    lvars.push_back(i);
  }
  DEBUG_EXIT();
  return lvars;
}


antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> vars;
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  for (auto i : ctx->ID()){
    vars.push_back(var{i->getText(),size});
  }
  DEBUG_EXIT();
  return vars;
}

antlrcpp::Any CodeGenVisitor::visitFunction_params(AslParser::Function_paramsContext *ctx) {
  DEBUG_ENTER();
  std::vector<std::string> lvars;
  // subroutine subRef(code::get_last_subroutine());

    for(uint i = 0; i < ctx->ID().size();++i){
      std::string texto = ctx->ID()[i]->getText();
      // std::size_t   size = Types.getSizeOfType(ctx->type()[i]);
      lvars.push_back(texto);
    }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();

  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());


  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  // std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

  //Assignar arrays entre ellos
  
  if(Types.isArrayTy(tid1) and Types.isArrayTy(tid2)){
    code = code1 || code2;
      std::string     dire1;
      std::string     dire2;

    //Comprobar cual de los dos arrays es pasado por referencia o local
    if(Symbols.isLocalVarClass(addr1)){
      dire1 = addr1;
    }
    else{
      dire1    = "%"+codeCounters.newTEMP();
      code = code || instruction::LOAD(dire1, addr1);
    }

    if(Symbols.isLocalVarClass(addr2)){
      dire2 = addr2;
    }
    else{
      dire2    = "%"+codeCounters.newTEMP();
      code = code || instruction::LOAD(dire2, addr2);
    }
    
    //Inicializar bucle 
    std::string inicio = "while"+codeCounters.newLabelWHILE();
    std::string final = "end"+inicio;

    std::string     contador    = "%"+codeCounters.newTEMP();
    std::string     longitud    = "%"+codeCounters.newTEMP();
    std::string     resultado    = "%"+codeCounters.newTEMP();
    std::string     incrementador    = "%"+codeCounters.newTEMP();
    std::string     igualdad    = "%"+codeCounters.newTEMP();


    uint arrSize = Types.getArraySize(tid1);
    code = code || instruction::ILOAD(contador, "0");
    code = code || instruction::ILOAD(longitud, std::to_string(arrSize));
    code = code || instruction::ILOAD(incrementador, "1");

    instructionList     codigoBucle;

    codigoBucle = instruction::LOADX(resultado, dire2, contador);

    //Concatenacion del codigo del bucle
    codigoBucle = codigoBucle || instruction::XLOAD(dire1, contador, resultado);

    codigoBucle = codigoBucle || instruction::ADD(contador, contador, incrementador);

    codigoBucle = codigoBucle || instruction::UJUMP(inicio);

    //Codigo resultante
    code = code || instruction::LABEL(inicio) 
                || instruction::LE(igualdad, contador, longitud) || instruction::FJUMP(igualdad, final)
                || codigoBucle 
                || instruction::LABEL(final);
  }
  //Assignacion de una posicion de un array a un valor
  else if(ctx->left_expr()->expr()){
    if(Symbols.isLocalVarClass(addr1)){
      code = code1 || code2;

      std::string     newtemp    = "%"+codeCounters.newTEMP();      
      code = code || instruction::LOAD(newtemp,addr2);

      if(Types.isFloatTy(tid1) and Types.isIntegerTy(tid2)){
        
        code = code || instruction::FLOAT(newtemp, newtemp);
      }

      code = code || instruction::XLOAD(addr1,offs1,newtemp);

    }
    else{
      std::string     dire    = "%"+codeCounters.newTEMP();      
      code = code1 || code2|| instruction::LOAD(dire, addr1);
      
      std::string     newtemp    = "%"+codeCounters.newTEMP();      
      code = code || instruction::LOAD(newtemp,addr2);

      if(Types.isFloatTy(tid1) and Types.isIntegerTy(tid2)){
        
        code = code || instruction::FLOAT(newtemp, newtemp);
      }

      code = code || instruction::XLOAD(dire,offs1,newtemp);

      
    }
  }
  //Variable basica
  else{
    if (Types.isFloatTy(tid1) and Types.isIntegerTy(tid2)){
      std::string tempF = "%"+codeCounters.newTEMP();

      code = code1 || code2||instruction::FLOAT(tempF, addr2) || instruction::LOAD(addr1, tempF);
    }
    else{
      code = code1 || code2||instruction::LOAD(addr1, addr2);

    }
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements(0));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;

  //Si el condicional tiene un else
  if (ctx->ELSE()){
    std::string labelElse = "else"+label;
    instructionList &&   code3 = visit(ctx->statements(1));


    code = code1 || instruction::FJUMP(addr1, labelElse) ||
          code2 || instruction::LABEL(labelElse) || code3 || instruction::LABEL(labelEndIf);

  }
  else{
  code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements());
  std::string labelWhile = "while"+codeCounters.newLabelWHILE();
  std::string labelEndWhile = "end"+labelWhile;
  code =   instruction::LABEL(labelWhile) || code1 || instruction::FJUMP(addr1, labelEndWhile) ||
          code2 || instruction::UJUMP(labelWhile) || instruction::LABEL(labelEndWhile);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  // std::string name = ctx->ident()->ID()->getSymbol()->getText();
  std::string name = ctx->ident()->getText();
  bool popalfinal = false;
  if(not Types.isVoidTy(getTypeDecor(ctx->ident()))){
    popalfinal = true;
    code = instruction::PUSH();
  }

  auto param_types = Types.getFuncParamsTypes(getTypeDecor(ctx->ident()));
  // std::cout<<(ctx->expr()).size()<<std::endl;

  for (uint i = 0; i< (ctx->expr()).size(); ++i){
    CodeAttribs     && codAt1 = visit(ctx->expr(i));
    std::string         addr1 = codAt1.addr;
    instructionList &   code1 = codAt1.code;

    // std::cout<<"xd"<<std::endl;
    code = code || code1;

    if (Types.isFloatTy(param_types[i]) and Types.isIntegerTy(getTypeDecor(ctx->expr(i)))) {
      std::string tempF = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(tempF, addr1) || instruction::PUSH(tempF);
    }
    else if(Types.isArrayTy(param_types[i])){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp, addr1) || instruction::PUSH(temp);
    }
    else{
      code = code ||instruction::PUSH(addr1);
    }
  }

  code = code || instruction::CALL(name);
  
  for (uint i = 0; i< (ctx->expr()).size(); ++i){
    code = code || instruction::POP();
  }
  if (popalfinal) code = code || instruction::POP();

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = visit(ctx->left_expr());
  TypesMgr::TypeId t1   = getTypeDecor(ctx->left_expr());

  std::string          addr1 = codAtsE.addr;
  std::string          offs1 = codAtsE.offs;

  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;

  std::string          readTemporal = "%"+codeCounters.newTEMP();

  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

  if(ctx->left_expr()->expr()){
    if(Types.isIntegerTy(t1) or Types.isBooleanTy(t1))
    code = code || code1 || instruction::READI(readTemporal) || instruction::XLOAD(addr1, offs1, readTemporal);

    else if(Types.isFloatTy(t1))
    code = code || code1 || instruction::READF(readTemporal) || instruction::XLOAD(addr1, offs1, readTemporal);

    else if (Types.isCharacterTy(t1)) 
    code = code || code1 || instruction::READC(readTemporal) || instruction::XLOAD(addr1, offs1, readTemporal);

  }
  else{
     if(Types.isIntegerTy(t1) or Types.isBooleanTy(t1))
    code = code || code1 || instruction::READI(addr1);

    else if(Types.isFloatTy(t1))
    code = code || code1 || instruction::READF(addr1);

    else if (Types.isCharacterTy(t1)) 
    code = code || code1 || instruction::READC(addr1);
  }

  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  // instructionList &    code = code1;
  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());

  // std::cout<<ctx->expr()->getText()<<std::endl;
  TypesMgr::TypeId t  = getTypeDecor(ctx->expr());

  // std::cout<<t<<std::endl;
  instructionList   code;
  if(Types.isIntegerTy(t) || Types.isBooleanTy(t))
    code = code1 || instruction::WRITEI(addr1);
  else if (Types.isFloatTy(t)){
    code = code1 || instruction::WRITEF(addr1);
  }
  else if (Types.isCharacterTy(t)){
    code = code1 || instruction::WRITEC(addr1);
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts1 = visit(ctx->ident());
  std::string         addr1 = codAts1.addr;
  instructionList code = codAts1.code;

  std::string offset = "%"+codeCounters.newTEMP();
  // std::string temp = "%"+codeCounters.newTEMP();

  // code = code || instruction::ALOAD(temp, addr1);
  //Si es un array
  if(ctx->expr()){
      CodeAttribs && codAts2 = visit(ctx->expr());
      std::string         addr2 = codAts2.addr;
      instructionList code2 = codAts2.code;
    // Si el array es local/////////////// a lo mejor se puede unificar
    if(Symbols.isLocalVarClass(addr1)){
      
      code = code || code2;

    }
    else{
      code = code || code2;
      // std::cout<< code.dump()<<std::endl;

    }
      offset = addr2;
  }


  CodeAttribs codAts(addr1, offset, code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  
  TypesMgr::TypeId t  = getTypeDecor(ctx);
  //The result is an integer
  if(Types.isIntegerTy(t)){
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if(ctx->DIV()){
      code = code || instruction::DIV(temp, addr1, addr2);
    }
    else if(ctx->SUB()){
      code = code || instruction::SUB(temp, addr1, addr2);
    }
    else if(ctx->PLUS()){
      code = code || instruction::ADD(temp, addr1, addr2);
    }
    else{
      code = code || instruction::DIV(temp, addr1, addr2) || instruction::MUL(temp, temp, addr2) || instruction::SUB(temp, addr1, temp);
    }
  }
  else{// is a FLOAT
    std::string float1 = "%"+codeCounters.newTEMP();
    std::string float2 = "%"+codeCounters.newTEMP();

    TypesMgr::TypeId t1  = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2  = getTypeDecor(ctx->expr(1));

    instruction cast1 = instruction::NOOP();
    instruction cast2 = instruction::NOOP();
    
    if(Types.isIntegerTy(t1)){
      cast1 = instruction::FLOAT(float1,addr1);
    }
    else{
      cast1 = instruction::LOAD(float1,addr1);
    }

    if(Types.isIntegerTy(t2)){
      cast2 = instruction::FLOAT(float2,addr2);
    }
    else{
      cast2 = instruction::LOAD(float2,addr2);
    }

    if (ctx->MUL()){
      code = code || cast1 || cast2 || instruction::FMUL(temp, float1, float2);
    }
    else if (ctx->DIV()){
      code = code || cast1 || cast2 || instruction::FDIV(temp, float1, float2);
    }
    else if (ctx->SUB()){
      code = code || cast1 || cast2 || instruction::FSUB(temp, float1, float2);
    }
    else {
      code = code || cast1 || cast2 || instruction::FADD(temp, float1, float2);
    }
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->EQUAL()){
    code = code || instruction::EQ(temp, addr1, addr2);
  }
  else if (ctx->GTE()){
    code = code || instruction::LE(temp, addr2, addr1);
  }
  else if (ctx->LTE()){
    code = code || instruction::LE(temp, addr1, addr2);
  }
  else if (ctx->LT()){
    code = code || instruction::LT(temp, addr1, addr2);
  }
  else if (ctx->GT()){
    code = code || instruction::LT(temp, addr2, addr1);
  }
  else if(ctx->NE()){
    std::string temp2 = "%"+codeCounters.newTEMP();

    code = code || instruction::EQ(temp, addr1, addr2);
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  if(ctx->INTVAL()){
    code = instruction::ILOAD(temp, ctx->getText());
  }
  else if(ctx->FLOATVAL()){
    code = instruction::FLOAD(temp, ctx->getText());
  }
  else if(ctx->BOOLVAL()){
    if(ctx->getText()=="true")
    code = instruction::ILOAD(temp, "1");
    else code = instruction::ILOAD(temp, "0");
  }
  else if(ctx->CHARVAL()){
    std::string s =ctx->getText();

    code = instruction::CHLOAD(temp, s.substr(1,s.size()-2));

  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}
antlrcpp::Any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx){
  DEBUG_ENTER();
  CodeAttribs codAts = visit(ctx->expr());
  DEBUG_EXIT();
  return codAts;
}
antlrcpp::Any CodeGenVisitor::visitNot(AslParser::NotContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  
  std::string temp = "%"+codeCounters.newTEMP();
  
  instructionList && code = code1 || instruction::NOT(temp, addr1);

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}
antlrcpp::Any CodeGenVisitor::visitLogical(AslParser::LogicalContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->AND()){
    code = code || instruction::AND(temp, addr1, addr2);
  }
  else if (ctx->OR()){
    code = code || instruction::OR(temp, addr2, addr1);
  }

  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitNegValue(AslParser::NegValueContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  
  std::string temp = "%"+codeCounters.newTEMP();
  
  TypesMgr::TypeId t  = getTypeDecor(ctx);
  
  if(Types.isIntegerTy(t)){
    instructionList && code = code1 || instruction::NEG(temp, addr1); 
    CodeAttribs codAts(temp, "", code);
 
    DEBUG_EXIT();
    return codAts;
  }
  else {
    instructionList && code = code1 || instruction::FNEG(temp, addr1); 
    CodeAttribs codAts(temp, "", code);

    DEBUG_EXIT();
    return codAts;
  }
  CodeAttribs codAts(addr1, "", code1);
 
  DEBUG_EXIT();
  return codAts;
}
antlrcpp::Any CodeGenVisitor::visitNegExprIdent(AslParser::NegExprIdentContext *ctx){
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->ident());
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  
  std::string temp = "%"+codeCounters.newTEMP();
  
  TypesMgr::TypeId t  = getTypeDecor(ctx);
  
  if(Types.isIntegerTy(t)){
    instructionList && code = code1 || instruction::NEG(temp, addr1); 
    CodeAttribs codAts(temp, "", code);
 
    DEBUG_EXIT();
    return codAts;
  }
  else {
    instructionList && code = code1 || instruction::FNEG(temp, addr1); 
    CodeAttribs codAts(temp, "", code);

    DEBUG_EXIT();
    return codAts;
  }
  CodeAttribs codAts(addr1, "", code1);
 
  DEBUG_EXIT();
  return codAts;
}
antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx){
  DEBUG_ENTER();
  instructionList && code = instruction::RETURN();
  if(ctx->expr()){
    CodeAttribs     && codAt1 = visit(ctx->expr());
    std::string         addr1 = codAt1.addr;
    instructionList &   code1 = codAt1.code;

    std::string temp = "_result";

    
    code = code1 || instruction::LOAD(temp, addr1) || instruction::RETURN(); ;
  }
  DEBUG_EXIT();
  return code;
}
antlrcpp::Any CodeGenVisitor::visitFuncValue(AslParser::FuncValueContext *ctx){
  DEBUG_ENTER();
  instructionList code;
  code = instruction::PUSH();

  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  auto param_types = Types.getFuncParamsTypes(getTypeDecor(ctx->ident()));

  std::vector<std::string> params;
  
  std::string funcionLlamada = ctx->ident()->getText();


  for (uint i = 0;i < ctx->expr().size() ; ++i){
    CodeAttribs     && codAt1 = visit(ctx->expr(i));
    std::string         addr1 = codAt1.addr;
    instructionList &   code1 = codAt1.code;

    TypesMgr::TypeId p1type = Types.getParameterType(t1, i);
    // std::cout<<i<<" " <<p1type<<" "<< ctx->expr().size()<<std::endl;
    if (Types.isFloatTy(p1type) and Types.isIntegerTy(getTypeDecor(ctx->expr(i)))) {
      // std::cout<<"he casteado el param " <<i << std::endl;
      std::string temp = "%"+codeCounters.newTEMP();
      // code = code || instruction::FLOAT(temp,getAddrDecor(i));

      code = code || code1 || instruction::FLOAT(temp, addr1) || instruction::PUSH(temp);

    }
    else if(Types.isArrayTy(p1type)){
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::ALOAD(temp, addr1) || instruction::PUSH(temp);
    }
    else {
      code = code || code1 || instruction::PUSH(addr1);
    }
  }
  // std::cout<<code.dump()<<std::endl;
  code = code || instruction::CALL(funcionLlamada);

  for (uint i = 0; i< (ctx->expr()).size(); ++i){
    code = code || instruction::POP();
  }
  
  std::string temp = "%"+codeCounters.newTEMP();

  code = code || instruction::POP(temp);

  CodeAttribs ret(temp, "", code);

  DEBUG_EXIT();
  return ret;

}
antlrcpp::Any CodeGenVisitor::visitArrayPos(AslParser::ArrayPosContext *ctx){
  DEBUG_ENTER();

  instructionList code;
  CodeAttribs     && codAtI = visit(ctx->ident());
  CodeAttribs     && codAtE = visit(ctx->expr());

  instructionList &   codeE = codAtE.code;

  code = codeE;

  std::string         array = ctx->ident()->getText();

  std::string         addrI = codAtI.addr;
  std::string         addrO = codAtE.addr;

  std::string     temp    = "%"+codeCounters.newTEMP();


  if (Symbols.isLocalVarClass(addrI)){
    code = code || instruction::LOADX(temp, addrI, addrO);
  }
  else{
    std::string     dire    = "%"+codeCounters.newTEMP();

    code = code || instruction::LOAD(dire, addrI)||instruction::LOADX(temp, dire, addrO);
  }
  // std::cout<<code.dump()<<std::endl;

  CodeAttribs codAts(temp,"",code);
  DEBUG_EXIT();
  return codAts;
}


// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
					 const std::string & offs,
					 instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
					 const std::string & offs,
					 instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
