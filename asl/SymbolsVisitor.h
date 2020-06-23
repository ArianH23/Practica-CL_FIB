#pragma once

#include "antlr4-runtime.h"
#include "AslBaseVisitor.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

// using namespace std;


//////////////////////////////////////////////////////////////////////
// Class SymbolVisitor:  derived from AslBaseVisitor.
// The tree visitor go through the parse tree and call the methods of
// this class to register the symbols of the program in the symbol
// table. In this visit, if some node/method does not have an
// associated task, it does not have to be visited/called so
// no redefinition is needed.

class SymbolsVisitor final : public AslBaseVisitor {

public:

  // Constructor
  SymbolsVisitor(TypesMgr       & Types,
                 SymTable       & Symbols,
                 TreeDecoration & Decorations,
                 SemErrors      & Errors);

  // Methods to visit each kind of node:
  antlrcpp::Any visitProgram(AslParser::ProgramContext *ctx);
  antlrcpp::Any visitFunction(AslParser::FunctionContext *ctx);
  antlrcpp::Any visitDeclarations(AslParser::DeclarationsContext *ctx);
  antlrcpp::Any visitVariable_decl(AslParser::Variable_declContext *ctx);
  antlrcpp::Any visitFunction_params(AslParser::Function_paramsContext *ctx);
  antlrcpp::Any visitType(AslParser::TypeContext *ctx);
  antlrcpp::Any visitSimple_type(AslParser::Simple_typeContext *ctx);
  antlrcpp::Any visitArray_type(AslParser::Array_typeContext *ctx);

private:

  // Attributes:
  TypesMgr       & Types;
  SymTable       & Symbols;
  TreeDecoration & Decorations;
  SemErrors      & Errors;

  // Getters for the necessary tree node atributes:
  //   Scope and Type
  SymTable::ScopeId getScopeDecor (antlr4::ParserRuleContext *ctx);
  TypesMgr::TypeId  getTypeDecor  (antlr4::ParserRuleContext *ctx);

  // Setters for the necessary tree node attributes:
  //   Scope and Type
  void putScopeDecor (antlr4::ParserRuleContext *ctx, SymTable::ScopeId s);
  void putTypeDecor  (antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t);

};  // class SymbolsVisitor
