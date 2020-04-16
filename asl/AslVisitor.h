
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AslParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AslParser.
 */
class  AslVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AslParser.
   */
    virtual antlrcpp::Any visitProgram(AslParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitFunction(AslParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFunction_params(AslParser::Function_paramsContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(AslParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(AslParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl(AslParser::Variable_declContext *context) = 0;

    virtual antlrcpp::Any visitArray_type(AslParser::Array_typeContext *context) = 0;

    virtual antlrcpp::Any visitSimple_type(AslParser::Simple_typeContext *context) = 0;

    virtual antlrcpp::Any visitType(AslParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitStatements(AslParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(AslParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(AslParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitProcCall(AslParser::ProcCallContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(AslParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitReadStmt(AslParser::ReadStmtContext *context) = 0;

    virtual antlrcpp::Any visitWriteExpr(AslParser::WriteExprContext *context) = 0;

    virtual antlrcpp::Any visitWriteString(AslParser::WriteStringContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(AslParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitLeft_expr(AslParser::Left_exprContext *context) = 0;

    virtual antlrcpp::Any visitNot(AslParser::NotContext *context) = 0;

    virtual antlrcpp::Any visitNegValue(AslParser::NegValueContext *context) = 0;

    virtual antlrcpp::Any visitArrayPos(AslParser::ArrayPosContext *context) = 0;

    virtual antlrcpp::Any visitFuncValue(AslParser::FuncValueContext *context) = 0;

    virtual antlrcpp::Any visitExprIdent(AslParser::ExprIdentContext *context) = 0;

    virtual antlrcpp::Any visitArithmetic(AslParser::ArithmeticContext *context) = 0;

    virtual antlrcpp::Any visitNegExprIdent(AslParser::NegExprIdentContext *context) = 0;

    virtual antlrcpp::Any visitRelational(AslParser::RelationalContext *context) = 0;

    virtual antlrcpp::Any visitParenthesis(AslParser::ParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitValue(AslParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitLogical(AslParser::LogicalContext *context) = 0;

    virtual antlrcpp::Any visitIdent(AslParser::IdentContext *context) = 0;


};

