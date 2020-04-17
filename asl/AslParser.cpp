
// Generated from Asl.g4 by ANTLR 4.7.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}


antlrcpp::Any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      function();
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(33);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

tree::TerminalNode* AslParser::FunctionContext::LP() {
  return getToken(AslParser::LP, 0);
}

AslParser::Function_paramsContext* AslParser::FunctionContext::function_params() {
  return getRuleContext<AslParser::Function_paramsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::RP() {
  return getToken(AslParser::RP, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}


antlrcpp::Any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(AslParser::FUNC);
    setState(36);
    match(AslParser::ID);
    setState(37);
    match(AslParser::LP);
    setState(38);
    function_params();
    setState(39);
    match(AslParser::RP);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__0) {
      setState(40);
      match(AslParser::T__0);
      setState(41);
      type();
    }
    setState(44);
    declarations();
    setState(45);
    statements();
    setState(46);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_paramsContext ------------------------------------------------------------------

AslParser::Function_paramsContext::Function_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::Function_paramsContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Function_paramsContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeContext *> AslParser::Function_paramsContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::Function_paramsContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::Function_paramsContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::Function_paramsContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}


size_t AslParser::Function_paramsContext::getRuleIndex() const {
  return AslParser::RuleFunction_params;
}


antlrcpp::Any AslParser::Function_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction_params(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Function_paramsContext* AslParser::function_params() {
  Function_paramsContext *_localctx = _tracker.createInstance<Function_paramsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleFunction_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::RP: {
        break;
      }

      case AslParser::ID: {
        setState(49);
        match(AslParser::ID);
        setState(50);
        match(AslParser::T__0);
        setState(51);
        type();
        setState(58);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::COMMA) {
          setState(52);
          match(AslParser::COMMA);
          setState(53);
          match(AslParser::ID);
          setState(54);
          match(AslParser::T__0);
          setState(55);
          type();
          setState(60);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

AslParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Function_callContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Function_callContext::LP() {
  return getToken(AslParser::LP, 0);
}

tree::TerminalNode* AslParser::Function_callContext::RP() {
  return getToken(AslParser::RP, 0);
}

std::vector<AslParser::ExprContext *> AslParser::Function_callContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::Function_callContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::Function_callContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::Function_callContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}


size_t AslParser::Function_callContext::getRuleIndex() const {
  return AslParser::RuleFunction_call;
}


antlrcpp::Any AslParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Function_callContext* AslParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    ident();
    setState(64);
    match(AslParser::LP);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::NOT)
      | (1ULL << AslParser::SUB)
      | (1ULL << AslParser::LP)
      | (1ULL << AslParser::INTVAL)
      | (1ULL << AslParser::FLOATVAL)
      | (1ULL << AslParser::BOOLVAL)
      | (1ULL << AslParser::CHARVAL)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(65);
      expr(0);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::COMMA) {
        setState(66);
        match(AslParser::COMMA);
        setState(67);
        expr(0);
        setState(72);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(75);
    match(AslParser::RP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}


antlrcpp::Any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(77);
      variable_decl();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::Variable_declContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}


antlrcpp::Any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(AslParser::VAR);
    setState(84);
    match(AslParser::ID);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::COMMA) {
      setState(85);
      match(AslParser::COMMA);
      setState(86);
      match(AslParser::ID);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(AslParser::T__0);
    setState(93);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

AslParser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Array_typeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::LC() {
  return getToken(AslParser::LC, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::RC() {
  return getToken(AslParser::RC, 0);
}

AslParser::Simple_typeContext* AslParser::Array_typeContext::simple_type() {
  return getRuleContext<AslParser::Simple_typeContext>(0);
}


size_t AslParser::Array_typeContext::getRuleIndex() const {
  return AslParser::RuleArray_type;
}


antlrcpp::Any AslParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Array_typeContext* AslParser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleArray_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(AslParser::ARRAY);
    setState(96);
    match(AslParser::LC);
    setState(97);
    match(AslParser::INTVAL);
    setState(98);
    match(AslParser::RC);
    setState(99);
    match(AslParser::T__1);
    setState(100);
    simple_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_typeContext ------------------------------------------------------------------

AslParser::Simple_typeContext::Simple_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Simple_typeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Simple_typeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Simple_typeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}

tree::TerminalNode* AslParser::Simple_typeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}


size_t AslParser::Simple_typeContext::getRuleIndex() const {
  return AslParser::RuleSimple_type;
}


antlrcpp::Any AslParser::Simple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitSimple_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Simple_typeContext* AslParser::simple_type() {
  Simple_typeContext *_localctx = _tracker.createInstance<Simple_typeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleSimple_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR)
      | (1ULL << AslParser::INT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Array_typeContext* AslParser::TypeContext::array_type() {
  return getRuleContext<AslParser::Array_typeContext>(0);
}

AslParser::Simple_typeContext* AslParser::TypeContext::simple_type() {
  return getRuleContext<AslParser::Simple_typeContext>(0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}


antlrcpp::Any AslParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::ARRAY: {
        setState(104);
        array_type();
        break;
      }

      case AslParser::BOOL:
      case AslParser::FLOAT:
      case AslParser::CHAR:
      case AslParser::INT: {
        setState(105);
        simple_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}


antlrcpp::Any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(108);
      statement();
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ProcCallContext::LP() {
  return getToken(AslParser::LP, 0);
}

tree::TerminalNode* AslParser::ProcCallContext::RP() {
  return getToken(AslParser::RP, 0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::ProcCallContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::ProcCallContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(114);
      left_expr();
      setState(115);
      match(AslParser::ASSIGN);
      setState(116);
      expr(0);
      setState(117);
      match(AslParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(119);
      match(AslParser::IF);
      setState(120);
      expr(0);
      setState(121);
      match(AslParser::THEN);
      setState(122);
      statements();
      setState(125);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(123);
        match(AslParser::ELSE);
        setState(124);
        statements();
      }
      setState(127);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(129);
      ident();
      setState(130);
      match(AslParser::LP);
      setState(139);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::LP)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(131);
        expr(0);
        setState(136);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::COMMA) {
          setState(132);
          match(AslParser::COMMA);
          setState(133);
          expr(0);
          setState(138);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(141);
      match(AslParser::RP);
      setState(142);
      match(AslParser::T__2);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(144);
      match(AslParser::WHILE);
      setState(145);
      expr(0);
      setState(146);
      match(AslParser::DO);
      setState(147);
      statements();
      setState(148);
      match(AslParser::ENDWHILE);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(150);
      match(AslParser::READ);
      setState(151);
      left_expr();
      setState(152);
      match(AslParser::T__2);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(154);
      match(AslParser::WRITE);
      setState(155);
      expr(0);
      setState(156);
      match(AslParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(158);
      match(AslParser::WRITE);
      setState(159);
      match(AslParser::STRING);
      setState(160);
      match(AslParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(161);
      match(AslParser::RETURN);
      setState(163);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::LP)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(162);
        expr(0);
      }
      setState(165);
      match(AslParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Left_exprContext::LC() {
  return getToken(AslParser::LC, 0);
}

AslParser::ExprContext* AslParser::Left_exprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::Left_exprContext::RC() {
  return getToken(AslParser::RC, 0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}


antlrcpp::Any AslParser::Left_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeft_expr(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 22, AslParser::RuleLeft_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    ident();
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::LC) {
      setState(169);
      match(AslParser::LC);
      setState(170);
      expr(0);
      setState(171);
      match(AslParser::RC);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NotContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::NotContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::NotContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

AslParser::NotContext::NotContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::NegValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::NegValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::NegValueContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::NegValueContext::NegValueContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::NegValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitNegValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayPosContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ArrayPosContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ArrayPosContext::LC() {
  return getToken(AslParser::LC, 0);
}

AslParser::ExprContext* AslParser::ArrayPosContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::ArrayPosContext::RC() {
  return getToken(AslParser::RC, 0);
}

AslParser::ArrayPosContext::ArrayPosContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ArrayPosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArrayPos(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncValueContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::FuncValueContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::FuncValueContext::LP() {
  return getToken(AslParser::LP, 0);
}

tree::TerminalNode* AslParser::FuncValueContext::RP() {
  return getToken(AslParser::RP, 0);
}

std::vector<AslParser::ExprContext *> AslParser::FuncValueContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::FuncValueContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::FuncValueContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::FuncValueContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}

AslParser::FuncValueContext::FuncValueContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::FuncValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFuncValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::NegExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::NegExprIdentContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::NegExprIdentContext::NegExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::NegExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitNegExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LTE() {
  return getToken(AslParser::LTE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GTE() {
  return getToken(AslParser::GTE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NE() {
  return getToken(AslParser::NE, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ParenthesisContext::LP() {
  return getToken(AslParser::LP, 0);
}

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::ParenthesisContext::RP() {
  return getToken(AslParser::RP, 0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::LogicalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::LogicalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::LogicalContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::LogicalContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::LogicalContext::LogicalContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(176);
      match(AslParser::LP);
      setState(177);
      expr(0);
      setState(178);
      match(AslParser::RP);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayPosContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      ident();
      setState(181);
      match(AslParser::LC);
      setState(182);
      expr(0);
      setState(183);
      match(AslParser::RC);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FuncValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      ident();
      setState(186);
      match(AslParser::LP);
      setState(195);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::LP)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(187);
        expr(0);
        setState(192);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::COMMA) {
          setState(188);
          match(AslParser::COMMA);
          setState(189);
          expr(0);
          setState(194);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(197);
      match(AslParser::RP);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      dynamic_cast<NotContext *>(_localctx)->op = match(AslParser::NOT);
      setState(200);
      expr(9);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NegValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(201);
      match(AslParser::SUB);
      setState(202);
      _la = _input->LA(1);
      if (!(_la == AslParser::INTVAL

      || _la == AslParser::FLOATVAL)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::CHARVAL))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(204);
      ident();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<NegExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(205);
      match(AslParser::SUB);
      setState(206);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(223);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(221);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(209);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(210);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::MUL)
            | (1ULL << AslParser::MOD)
            | (1ULL << AslParser::DIV))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(211);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(212);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(213);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::SUB)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(214);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(215);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(216);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::NE)
            | (1ULL << AslParser::LT)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::GTE)
            | (1ULL << AslParser::LTE))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(217);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(218);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(219);
          dynamic_cast<LogicalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::AND

          || _la == AslParser::OR)) {
            dynamic_cast<LogicalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(220);
          expr(5);
          break;
        }

        } 
      }
      setState(225);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}


antlrcpp::Any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 26, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "function_params", "function_call", "declarations", 
  "variable_decl", "array_type", "simple_type", "type", "statements", "statement", 
  "left_expr", "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "':'", "'of'", "';'", "'='", "'and'", "'or'", "'=='", "'!='", "'not'", 
  "'<'", "'>'", "'>='", "'<='", "'+'", "'-'", "'('", "')'", "'['", "']'", 
  "'bool'", "'float'", "'char'", "'*'", "'%'", "'/'", "'var'", "'array'", 
  "'int'", "'if'", "'then'", "'else'", "'while'", "'endwhile'", "'do'", 
  "'return'", "'endif'", "'func'", "'endfunc'", "'read'", "'write'", "", 
  "", "", "", "", "','"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", "GT", 
  "GTE", "LTE", "PLUS", "SUB", "LP", "RP", "LC", "RC", "BOOL", "FLOAT", 
  "CHAR", "MUL", "MOD", "DIV", "VAR", "ARRAY", "INT", "IF", "THEN", "ELSE", 
  "WHILE", "ENDWHILE", "DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", "READ", 
  "WRITE", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", "ID", "COMMA", "STRING", 
  "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x33, 0xe7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x6, 0x2, 0x20, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 
    0x21, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3b, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x3e, 0xb, 0x4, 0x5, 0x4, 0x40, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x47, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x4a, 0xb, 0x5, 0x5, 0x5, 0x4c, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x7, 0x6, 0x51, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x54, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5a, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x5d, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x6d, 0xa, 0xa, 0x3, 0xb, 0x7, 0xb, 0x70, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x73, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0x80, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x89, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0x8c, 0xb, 0xc, 0x5, 0xc, 0x8e, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0xa6, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa9, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb0, 0xa, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0xc1, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xc4, 0xb, 0xe, 0x5, 0xe, 
    0xc6, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd2, 0xa, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xe0, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0xe3, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x2, 0x3, 0x1a, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x9, 0x4, 0x2, 0x16, 0x18, 0x1e, 
    0x1e, 0x3, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x19, 0x1b, 
    0x3, 0x2, 0x10, 0x11, 0x4, 0x2, 0x9, 0xa, 0xc, 0xf, 0x3, 0x2, 0x7, 0x8, 
    0x2, 0xfb, 0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x41, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x52, 0x3, 0x2, 0x2, 0x2, 0xc, 0x55, 0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x68, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x71, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 0x3, 0x2, 
    0x1f, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x2, 0x2, 0x3, 0x24, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x27, 0x2, 0x2, 0x26, 0x27, 0x7, 0x2f, 
    0x2, 0x2, 0x27, 0x28, 0x7, 0x12, 0x2, 0x2, 0x28, 0x29, 0x5, 0x6, 0x4, 
    0x2, 0x29, 0x2c, 0x7, 0x13, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x3, 0x2, 0x2, 
    0x2b, 0x2d, 0x5, 0x12, 0xa, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x5, 0xa, 0x6, 0x2, 0x2f, 0x30, 0x5, 0x14, 0xb, 0x2, 0x30, 0x31, 0x7, 
    0x28, 0x2, 0x2, 0x31, 0x5, 0x3, 0x2, 0x2, 0x2, 0x32, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x7, 0x2f, 0x2, 0x2, 0x34, 0x35, 0x7, 0x3, 0x2, 
    0x2, 0x35, 0x3c, 0x5, 0x12, 0xa, 0x2, 0x36, 0x37, 0x7, 0x30, 0x2, 0x2, 
    0x37, 0x38, 0x7, 0x2f, 0x2, 0x2, 0x38, 0x39, 0x7, 0x3, 0x2, 0x2, 0x39, 
    0x3b, 0x5, 0x12, 0xa, 0x2, 0x3a, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x7, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0x1c, 0xf, 0x2, 
    0x42, 0x4b, 0x7, 0x12, 0x2, 0x2, 0x43, 0x48, 0x5, 0x1a, 0xe, 0x2, 0x44, 
    0x45, 0x7, 0x30, 0x2, 0x2, 0x45, 0x47, 0x5, 0x1a, 0xe, 0x2, 0x46, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x7, 0x13, 0x2, 0x2, 0x4e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x51, 0x5, 0xc, 0x7, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0xb, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x1c, 0x2, 0x2, 0x56, 0x5b, 0x7, 0x2f, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x30, 0x2, 0x2, 0x58, 0x5a, 0x7, 0x2f, 0x2, 0x2, 
    0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
    0x3, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x12, 0xa, 0x2, 0x60, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x7, 0x1d, 0x2, 0x2, 0x62, 0x63, 0x7, 0x14, 0x2, 
    0x2, 0x63, 0x64, 0x7, 0x2b, 0x2, 0x2, 0x64, 0x65, 0x7, 0x15, 0x2, 0x2, 
    0x65, 0x66, 0x7, 0x4, 0x2, 0x2, 0x66, 0x67, 0x5, 0x10, 0x9, 0x2, 0x67, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x9, 0x2, 0x2, 0x2, 0x69, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x5, 0xe, 0x8, 0x2, 0x6b, 0x6d, 0x5, 
    0x10, 0x9, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x5, 0x16, 0xc, 
    0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 
    0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 0x7, 0x6, 0x2, 0x2, 0x76, 0x77, 0x5, 
    0x1a, 0xe, 0x2, 0x77, 0x78, 0x7, 0x5, 0x2, 0x2, 0x78, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x7, 0x1f, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x1a, 0xe, 
    0x2, 0x7b, 0x7c, 0x7, 0x20, 0x2, 0x2, 0x7c, 0x7f, 0x5, 0x14, 0xb, 0x2, 
    0x7d, 0x7e, 0x7, 0x21, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x14, 0xb, 0x2, 0x7f, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x26, 0x2, 0x2, 0x82, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x1c, 0xf, 0x2, 0x84, 0x8d, 0x7, 0x12, 
    0x2, 0x2, 0x85, 0x8a, 0x5, 0x1a, 0xe, 0x2, 0x86, 0x87, 0x7, 0x30, 0x2, 
    0x2, 0x87, 0x89, 0x5, 0x1a, 0xe, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x13, 
    0x2, 0x2, 0x90, 0x91, 0x7, 0x5, 0x2, 0x2, 0x91, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x93, 0x7, 0x22, 0x2, 0x2, 0x93, 0x94, 0x5, 0x1a, 0xe, 0x2, 
    0x94, 0x95, 0x7, 0x24, 0x2, 0x2, 0x95, 0x96, 0x5, 0x14, 0xb, 0x2, 0x96, 
    0x97, 0x7, 0x23, 0x2, 0x2, 0x97, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 
    0x7, 0x29, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x18, 0xd, 0x2, 0x9a, 0x9b, 0x7, 
    0x5, 0x2, 0x2, 0x9b, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x2a, 
    0x2, 0x2, 0x9d, 0x9e, 0x5, 0x1a, 0xe, 0x2, 0x9e, 0x9f, 0x7, 0x5, 0x2, 
    0x2, 0x9f, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x2a, 0x2, 0x2, 
    0xa1, 0xa2, 0x7, 0x31, 0x2, 0x2, 0xa2, 0xa9, 0x7, 0x5, 0x2, 0x2, 0xa3, 
    0xa5, 0x7, 0x25, 0x2, 0x2, 0xa4, 0xa6, 0x5, 0x1a, 0xe, 0x2, 0xa5, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa9, 0x7, 0x5, 0x2, 0x2, 0xa8, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0x79, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0x92, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x17, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xaf, 
    0x5, 0x1c, 0xf, 0x2, 0xab, 0xac, 0x7, 0x14, 0x2, 0x2, 0xac, 0xad, 0x5, 
    0x1a, 0xe, 0x2, 0xad, 0xae, 0x7, 0x15, 0x2, 0x2, 0xae, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x8, 0xe, 0x1, 0x2, 
    0xb2, 0xb3, 0x7, 0x12, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x1a, 0xe, 0x2, 0xb4, 
    0xb5, 0x7, 0x13, 0x2, 0x2, 0xb5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 
    0x5, 0x1c, 0xf, 0x2, 0xb7, 0xb8, 0x7, 0x14, 0x2, 0x2, 0xb8, 0xb9, 0x5, 
    0x1a, 0xe, 0x2, 0xb9, 0xba, 0x7, 0x15, 0x2, 0x2, 0xba, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xbc, 0x5, 0x1c, 0xf, 0x2, 0xbc, 0xc5, 0x7, 0x12, 0x2, 
    0x2, 0xbd, 0xc2, 0x5, 0x1a, 0xe, 0x2, 0xbe, 0xbf, 0x7, 0x30, 0x2, 0x2, 
    0xbf, 0xc1, 0x5, 0x1a, 0xe, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x13, 0x2, 
    0x2, 0xc8, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0xb, 0x2, 0x2, 
    0xca, 0xd2, 0x5, 0x1a, 0xe, 0xb, 0xcb, 0xcc, 0x7, 0x11, 0x2, 0x2, 0xcc, 
    0xd2, 0x9, 0x3, 0x2, 0x2, 0xcd, 0xd2, 0x9, 0x4, 0x2, 0x2, 0xce, 0xd2, 
    0x5, 0x1c, 0xf, 0x2, 0xcf, 0xd0, 0x7, 0x11, 0x2, 0x2, 0xd0, 0xd2, 0x5, 
    0x1c, 0xf, 0x2, 0xd1, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0xc, 0x9, 0x2, 0x2, 0xd4, 0xd5, 
    0x9, 0x5, 0x2, 0x2, 0xd5, 0xe0, 0x5, 0x1a, 0xe, 0xa, 0xd6, 0xd7, 0xc, 
    0x8, 0x2, 0x2, 0xd7, 0xd8, 0x9, 0x6, 0x2, 0x2, 0xd8, 0xe0, 0x5, 0x1a, 
    0xe, 0x9, 0xd9, 0xda, 0xc, 0x7, 0x2, 0x2, 0xda, 0xdb, 0x9, 0x7, 0x2, 
    0x2, 0xdb, 0xe0, 0x5, 0x1a, 0xe, 0x8, 0xdc, 0xdd, 0xc, 0x6, 0x2, 0x2, 
    0xdd, 0xde, 0x9, 0x8, 0x2, 0x2, 0xde, 0xe0, 0x5, 0x1a, 0xe, 0x7, 0xdf, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xe4, 0xe5, 0x7, 0x2f, 0x2, 0x2, 0xe5, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x21, 0x2c, 0x3c, 0x3f, 0x48, 0x4b, 0x52, 0x5b, 0x6c, 0x71, 0x7f, 
    0x8a, 0x8d, 0xa5, 0xa8, 0xaf, 0xc2, 0xc5, 0xd1, 0xdf, 0xe1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
