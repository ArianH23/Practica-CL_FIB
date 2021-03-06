#include "TypeCheckVisitor.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
				   SymTable       & Symbols,
				   TreeDecoration & Decorations,
				   SemErrors      & Errors) :
  Types{Types},
  Symbols {Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);  
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();

  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  
  TypesMgr::TypeId t = Types.createVoidTy();
  
  if(ctx->type()){
    visit(ctx->type());
    t = getTypeDecor(ctx->type());
  }

  Symbols.setCurrentFunctionTy(t);
  
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();

  TypesMgr::TypeId t1 = Symbols.getCurrentFunctionTy();

  if(ctx->expr()){
    visit(ctx->expr());

    TypesMgr::TypeId exp = getTypeDecor(ctx->expr());
    if(not Types.equalTypes(exp, t1) and not Types.isErrorTy(exp)){
      if(not (Types.isFloatTy(t1) and Types.isIntegerTy(exp))){
        Errors.incompatibleReturn(ctx->RETURN());
      }
    }
  }
  else{
   if(not Types.equalTypes(Types.createVoidTy(), t1)){
      Errors.incompatibleReturn(ctx->RETURN());
    }
  }

  DEBUG_EXIT();
  return 0;

}

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();

  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());

  visit(ctx->expr());  
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());

  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArrayPos(AslParser::ArrayPosContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  visit(ctx->expr());
  
  TypesMgr::TypeId id = getTypeDecor(ctx->ident());
  TypesMgr::TypeId expr = getTypeDecor(ctx->expr());

  TypesMgr::TypeId type = Types.createErrorTy();

  if(not Types.isErrorTy(id)){
    if(not Types.isArrayTy(id)) {
      Errors.nonArrayInArrayAccess(ctx); 
    }
    else{
      type = Types.getArrayElemType(id);
    }
  }
  
  if (not Types.isIntegerTy(expr) and not Types.isErrorTy(expr)){
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  }

  putTypeDecor(ctx, type);
  
  putIsLValueDecor(ctx, true);

  DEBUG_EXIT();

  return 0;
}
antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements(0));
  if(ctx->ELSE()) visit(ctx->statements(1));
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();

  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {

    Errors.isNotCallable(ctx->ident());
  }

  
  else if(not Types.isErrorTy(t1)){

    for(uint i = 0; i < ctx->expr().size(); ++i){
      visit(ctx->expr(i));
    }
    if(Types.getNumOfParameters(t1) != ctx->expr().size()){
      Errors.numberOfParameters(ctx->ident());
    }
    else{
      for(uint i = 0; i < ctx->expr().size(); ++i){
        visit(ctx->expr(i));
        TypesMgr::TypeId p1type = Types.getParameterType(t1, i);
        
        TypesMgr::TypeId p2type = getTypeDecor(ctx->expr(i));

        if(not Types.equalTypes(p1type,p2type)){
          if(not(Types.isFloatTy(p1type)and Types.isIntegerTy(p2type))){
            Errors.incompatibleParameter(ctx->expr(i),i+1,ctx);
          }
        }
      }
    }
  }
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());

  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());    
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  bool left = getIsLValueDecor(ctx->ident());

  if(ctx->expr()){
    visit(ctx->expr());

    TypesMgr::TypeId ex = getTypeDecor(ctx->expr());

    bool correct = not Types.isErrorTy(t1);

    if((not Types.isErrorTy(t1)) and (not Types.isArrayTy(t1))) {

      Errors.nonArrayInArrayAccess(ctx->ident());
      left = false;
      t1 = Types.createErrorTy();
      correct=false;

    }

    if(not Types.isIntegerTy(ex) and not Types.isErrorTy(ex)) {
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
      correct=false;
    }
    if(correct){
       t1 = Types.getArrayElemType(t1);
    }
  }

  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, left);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId t = Types.createIntegerTy();

  //Operacion MOD
  if (ctx->MOD()) {
    if ((not Types.isErrorTy(t1) and not Types.isIntegerTy(t1)) or 
        (not Types.isErrorTy(t2) and not Types.isIntegerTy(t2)))

      Errors.incompatibleOperator(ctx->op);
  }

  // MUL, DIV, ADD, SUB
  else {
    if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
        ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
      Errors.incompatibleOperator(ctx->op);

    if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) 
    t = Types.createFloatTy();
  }
  
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLogical(AslParser::LogicalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitNot(AslParser::NotContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) 
    Errors.incompatibleOperator(ctx->op);
  
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();

  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  
  if(ctx->INTVAL()){
    t = Types.createIntegerTy();
  }
  else if(ctx->FLOATVAL()){
    t = Types.createFloatTy();
  }
  else if(ctx->BOOLVAL()){
    t = Types.createBooleanTy();
  }
  else if(ctx->CHARVAL()){
    t = Types.createCharacterTy();
  }
  else t = Types.createErrorTy();

  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitNegValue(AslParser::NegValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  t = Types.createErrorTy();
  visit(ctx->expr());
  TypesMgr::TypeId check = getTypeDecor(ctx->expr());

  if(Types.isIntegerTy(check)){
    t = Types.createIntegerTy();
  }
  else if(Types.isFloatTy(check)){
    t = Types.createFloatTy();
  }
  
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  bool left = getIsLValueDecor(ctx->ident());

  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, left);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFuncValue(AslParser::FuncValueContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  TypesMgr::TypeId t= Types.createErrorTy();
  
  if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
    Errors.isNotCallable(ctx->ident());
  }

  else{
    t = Types.getFuncReturnType(t1);

    if (Types.isVoidFunction(t1)){
      Errors.isNotFunction(ctx->ident());
      t = Types.createErrorTy();     
    }
    
    if(Types.getNumOfParameters(t1) != ctx->expr().size()){
      Errors.numberOfParameters(ctx->ident());
    }

    else{

      for(uint i = 0; i < ctx->expr().size(); ++i){
        
        visit(ctx->expr(i));
        TypesMgr::TypeId p1type = Types.getParameterType(t1, i);
        
        TypesMgr::TypeId p2type = getTypeDecor(ctx->expr(i));
        
        if(not(Types.isFloatTy(p1type)and Types.isIntegerTy(p2type))){
          if(not Types.equalTypes(p1type,p2type)) Errors.incompatibleParameter(ctx->expr(i),i+1,ctx);
        }
      }
    }
    putTypeDecor(ctx, t);
  
    putIsLValueDecor(ctx, false);

  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitNegExprIdent(AslParser::NegExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());

  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  bool left = getIsLValueDecor(ctx->ident());

  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, left);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {

    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}
antlrcpp::Any TypeCheckVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx) {
  DEBUG_ENTER();

  visit(ctx->expr());

  putTypeDecor(ctx, getTypeDecor(ctx->expr()));
  putIsLValueDecor(ctx, getIsLValueDecor(ctx->expr()));

  DEBUG_EXIT();
  return 0;

}


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
