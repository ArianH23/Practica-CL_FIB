
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ASSIGN = 4, AND = 5, OR = 6, EQUAL = 7, 
    NE = 8, NOT = 9, LT = 10, GT = 11, GTE = 12, LTE = 13, PLUS = 14, SUB = 15, 
    LP = 16, RP = 17, LC = 18, RC = 19, BOOL = 20, FLOAT = 21, CHAR = 22, 
    MUL = 23, MOD = 24, DIV = 25, VAR = 26, ARRAY = 27, INT = 28, IF = 29, 
    THEN = 30, ELSE = 31, WHILE = 32, ENDWHILE = 33, DO = 34, RETURN = 35, 
    ENDIF = 36, FUNC = 37, ENDFUNC = 38, READ = 39, WRITE = 40, INTVAL = 41, 
    FLOATVAL = 42, BOOLVAL = 43, CHARVAL = 44, ID = 45, COMMA = 46, STRING = 47, 
    COMMENT = 48, WS = 49
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

