
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ASSIGN = 4, AND = 5, OR = 6, EQUAL = 7, 
    NE = 8, NOT = 9, LT = 10, GT = 11, GTE = 12, LTE = 13, PLUS = 14, SUB = 15, 
    LP = 16, RP = 17, LC = 18, RC = 19, BOOL = 20, FLOAT = 21, CHAR = 22, 
    MUL = 23, DIV = 24, VAR = 25, ARRAY = 26, INT = 27, IF = 28, THEN = 29, 
    ELSE = 30, WHILE = 31, ENDWHILE = 32, DO = 33, RETURN = 34, ENDIF = 35, 
    FUNC = 36, ENDFUNC = 37, READ = 38, WRITE = 39, INTVAL = 40, FLOATVAL = 41, 
    BOOLVAL = 42, CHARVAL = 43, ID = 44, COMMA = 45, STRING = 46, COMMENT = 47, 
    WS = 48
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

