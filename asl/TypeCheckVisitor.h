#pragma once

#include "antlr4-runtime.h"
#include "AslBaseVisitor.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

// using namespace std;


//////////////////////////////////////////////////////////////////////
// Class TypeCheckVisitor: derived from AslBaseVisitor.
// The tree visitor go through the parser tree and call the methods of
// this class to do the semantic typecheck of the program. This is
// done once the SymbolsVisitor has finish and all the symbols of the
// program has been added to their respective scope. In this visit,
// if some node/method does not have an associated task, it does not
// have to be visited/called so no redefinition is needed.

class TypeCheckVisitor final : public AslBaseVisitor {

public:

  // Constructor
  TypeCheckVisitor(TypesMgr       & Types,
		   SymTable       & Symbols,
		   TreeDecoration & Decorations,
		   SemErrors      & Errors);

  // Methods to visit each kind of node:
  antlrcpp::Any visitProgram(AslParser::ProgramContext *ctx);
  antlrcpp::Any visitFunction(AslParser::FunctionContext *ctx);
  antlrcpp::Any visitStatements(AslParser::StatementsContext *ctx);
  antlrcpp::Any visitAssignStmt(AslParser::AssignStmtContext *ctx);
  antlrcpp::Any visitIfStmt(AslParser::IfStmtContext *ctx);
  antlrcpp::Any visitWhileStmt(AslParser::WhileStmtContext *ctx);
  antlrcpp::Any visitProcCall(AslParser::ProcCallContext *ctx);
  antlrcpp::Any visitReadStmt(AslParser::ReadStmtContext *ctx);
  antlrcpp::Any visitWriteExpr(AslParser::WriteExprContext *ctx);
  antlrcpp::Any visitLeft_expr(AslParser::Left_exprContext *ctx);
  antlrcpp::Any visitExprIdent(AslParser::ExprIdentContext *ctx);
  antlrcpp::Any visitArithmetic(AslParser::ArithmeticContext *ctx);
  antlrcpp::Any visitRelational(AslParser::RelationalContext *ctx);
  antlrcpp::Any visitValue(AslParser::ValueContext *ctx);
  antlrcpp::Any visitIdent(AslParser::IdentContext *ctx);
  antlrcpp::Any visitLogical(AslParser::LogicalContext *ctx);
  antlrcpp::Any visitNot(AslParser::NotContext *ctx);
  antlrcpp::Any visitNegValue(AslParser::NegValueContext *ctx);
  antlrcpp::Any visitNegExprIdent(AslParser::NegExprIdentContext *ctx);
  antlrcpp::Any visitArrayPos(AslParser::ArrayPosContext *ctx);
  antlrcpp::Any visitFuncValue(AslParser::FuncValueContext *ctx);
  antlrcpp::Any visitReturnStmt(AslParser::ReturnStmtContext *ctx);
  antlrcpp::Any visitParenthesis(AslParser::ParenthesisContext *ctx);

  
private:

  // Attributes
  TypesMgr       & Types;
  SymTable       & Symbols;
  TreeDecoration & Decorations;
  SemErrors      & Errors;

  // Getters for the necessary tree node atributes:
  //   Scope, Type ans IsLValue
  SymTable::ScopeId getScopeDecor    (antlr4::ParserRuleContext *ctx);
  TypesMgr::TypeId  getTypeDecor     (antlr4::ParserRuleContext *ctx);
  bool              getIsLValueDecor (antlr4::ParserRuleContext *ctx);

  // Setters for the necessary tree node attributes:
  //   Scope, Type ans IsLValue
  void putScopeDecor    (antlr4::ParserRuleContext *ctx, SymTable::ScopeId s);
  void putTypeDecor     (antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t);
  void putIsLValueDecor (antlr4::ParserRuleContext *ctx, bool b);

};  // class TypeCheckVisitor
