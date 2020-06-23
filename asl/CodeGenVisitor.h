#pragma once

#include "antlr4-runtime.h"
#include "AslBaseVisitor.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>

// using namespace std;


//////////////////////////////////////////////////////////////////////
// Class CodeGenVisitor: derived from AslBaseVisitor.
// The tree visitor go through the parser tree and call the methods of
// this class to generate the code of the program. This is done
// once the SymbolsVisitor and TypeCheckVisitor have finish with no
// semantic error. So all the symbols of the program has been added to
// their respective scope and the type of each expresion has also be
// computed and decorate the parse tree. In this visit, if some node/method
// does not have an associated task, it does not have to be visited/called
// so no redefinition is needed.

class CodeGenVisitor final : public AslBaseVisitor {

public:

  // Constructor
  CodeGenVisitor(TypesMgr       & Types,
		 SymTable       & Symbols,
		 TreeDecoration & Decorations);

  // Methods to visit each kind of node:
  antlrcpp::Any visitProgram(AslParser::ProgramContext *ctx);
  antlrcpp::Any visitFunction(AslParser::FunctionContext *ctx);
  antlrcpp::Any visitDeclarations(AslParser::DeclarationsContext *ctx);
  antlrcpp::Any visitVariable_decl(AslParser::Variable_declContext *ctx);
  antlrcpp::Any visitFunction_params(AslParser::Function_paramsContext *ctx);
  antlrcpp::Any visitStatements(AslParser::StatementsContext *ctx);
  antlrcpp::Any visitAssignStmt(AslParser::AssignStmtContext *ctx);
  antlrcpp::Any visitIfStmt(AslParser::IfStmtContext *ctx);
  antlrcpp::Any visitWhileStmt(AslParser::WhileStmtContext *ctx);
  antlrcpp::Any visitProcCall(AslParser::ProcCallContext *ctx);
  antlrcpp::Any visitReadStmt(AslParser::ReadStmtContext *ctx);
  antlrcpp::Any visitWriteExpr(AslParser::WriteExprContext *ctx);
  antlrcpp::Any visitWriteString(AslParser::WriteStringContext *ctx);
  antlrcpp::Any visitLeft_expr(AslParser::Left_exprContext *ctx);
  antlrcpp::Any visitExprIdent(AslParser::ExprIdentContext *ctx);
  antlrcpp::Any visitArithmetic(AslParser::ArithmeticContext *ctx);
  antlrcpp::Any visitRelational(AslParser::RelationalContext *ctx);
  antlrcpp::Any visitValue(AslParser::ValueContext *ctx);
  antlrcpp::Any visitIdent(AslParser::IdentContext *ctx);
  antlrcpp::Any visitParenthesis(AslParser::ParenthesisContext *ctx);
  antlrcpp::Any visitNot(AslParser::NotContext *ctx);
  antlrcpp::Any visitLogical(AslParser::LogicalContext *ctx);
  antlrcpp::Any visitNegValue(AslParser::NegValueContext *ctx);
  antlrcpp::Any visitReturnStmt(AslParser::ReturnStmtContext *ctx);
  antlrcpp::Any visitFuncValue(AslParser::FuncValueContext *ctx);
  antlrcpp::Any visitArrayPos(AslParser::ArrayPosContext *ctx);
  antlrcpp::Any visitNegExprIdent(AslParser::NegExprIdentContext *ctx);


private:

  // Attributes
  TypesMgr        & Types;
  SymTable        & Symbols;
  TreeDecoration  & Decorations;
  counters          codeCounters;

  // Getters for the necessary tree node atributes:
  //   Scope and Type
  SymTable::ScopeId getScopeDecor (antlr4::ParserRuleContext *ctx) const;
  TypesMgr::TypeId  getTypeDecor  (antlr4::ParserRuleContext *ctx) const;


  //////////////////////////////////////////////////////////////////
  // Class CodeAttribs: is declared inside CodeGenVisitor as an
  // auxiliary class to group the three attributes necessaries for
  // code generation (address, offset, instructions list).
  // Some language constructions, for example expressions, can
  // generate the three attributes. Others, like statements, only
  // generate the instruction list.
  class CodeAttribs {
    
  public:
    // Constructors
    CodeAttribs(const std::string & addr,
	        const std::string & offs,
		instructionList & code);
    CodeAttribs(const std::string & addr,
	        const std::string & offs,
		instructionList && code);

    // Attributes (publics):
    //   - the address that will hold the value of an expression
    std::string addr;
    //   - the offset applied to the address (for array access)
    std::string offs;
    //   - the three-address code associated to an statement/expression
    instructionList code;

  };  // class CodeAttribs
  
};  // class CodeGenVisitor
