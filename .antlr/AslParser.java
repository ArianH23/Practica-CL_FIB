// Generated from /home/arian/Uni/CL/practica/asl/Asl.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, ASSIGN=4, AND=5, OR=6, EQUAL=7, NE=8, NOT=9, LT=10, 
		GT=11, GTE=12, LTE=13, PLUS=14, SUB=15, LP=16, RP=17, LC=18, RC=19, BOOL=20, 
		FLOAT=21, CHAR=22, MUL=23, DIV=24, VAR=25, ARRAY=26, INT=27, BOOLVAL=28, 
		IF=29, THEN=30, ELSE=31, WHILE=32, ENDWHILE=33, DO=34, RETURN=35, ENDIF=36, 
		FUNC=37, ENDFUNC=38, READ=39, WRITE=40, ID=41, INTVAL=42, FLOATVAL=43, 
		CHARVAL=44, COMMA=45, STRING=46, COMMENT=47, WS=48;
	public static final int
		RULE_program = 0, RULE_function = 1, RULE_function_params = 2, RULE_declarations = 3, 
		RULE_variable_decl = 4, RULE_array_type = 5, RULE_simple_type = 6, RULE_type = 7, 
		RULE_statements = 8, RULE_statement = 9, RULE_left_expr = 10, RULE_expr = 11, 
		RULE_ident = 12;
	public static final String[] ruleNames = {
		"program", "function", "function_params", "declarations", "variable_decl", 
		"array_type", "simple_type", "type", "statements", "statement", "left_expr", 
		"expr", "ident"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "':'", "'of'", "';'", "'='", "'and'", "'or'", "'=='", "'!='", "'not'", 
		"'<'", "'>'", "'>='", "'<='", "'+'", "'-'", "'('", "')'", "'['", "']'", 
		"'bool'", "'float'", "'char'", "'*'", "'/'", "'var'", "'array'", "'int'", 
		null, "'if'", "'then'", "'else'", "'while'", "'endwhile'", "'do'", "'return'", 
		"'endif'", "'func'", "'endfunc'", "'read'", "'write'", null, null, null, 
		null, "','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", 
		"GT", "GTE", "LTE", "PLUS", "SUB", "LP", "RP", "LC", "RC", "BOOL", "FLOAT", 
		"CHAR", "MUL", "DIV", "VAR", "ARRAY", "INT", "BOOLVAL", "IF", "THEN", 
		"ELSE", "WHILE", "ENDWHILE", "DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", 
		"READ", "WRITE", "ID", "INTVAL", "FLOATVAL", "CHARVAL", "COMMA", "STRING", 
		"COMMENT", "WS"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AslParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AslParser.EOF, 0); }
		public List<FunctionContext> function() {
			return getRuleContexts(FunctionContext.class);
		}
		public FunctionContext function(int i) {
			return getRuleContext(FunctionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(27); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(26);
				function();
				}
				}
				setState(29); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==FUNC );
			setState(31);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionContext extends ParserRuleContext {
		public TerminalNode FUNC() { return getToken(AslParser.FUNC, 0); }
		public TerminalNode ID() { return getToken(AslParser.ID, 0); }
		public Function_paramsContext function_params() {
			return getRuleContext(Function_paramsContext.class,0);
		}
		public DeclarationsContext declarations() {
			return getRuleContext(DeclarationsContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode ENDFUNC() { return getToken(AslParser.ENDFUNC, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(33);
			match(FUNC);
			setState(34);
			match(ID);
			setState(35);
			match(LP);
			setState(36);
			function_params();
			setState(37);
			match(RP);
			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__0) {
				{
				setState(38);
				match(T__0);
				setState(39);
				type();
				}
			}

			setState(42);
			declarations();
			setState(43);
			statements();
			setState(44);
			match(ENDFUNC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Function_paramsContext extends ParserRuleContext {
		public List<TerminalNode> ID() { return getTokens(AslParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(AslParser.ID, i);
		}
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AslParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AslParser.COMMA, i);
		}
		public Function_paramsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_params; }
	}

	public final Function_paramsContext function_params() throws RecognitionException {
		Function_paramsContext _localctx = new Function_paramsContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_function_params);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RP:
				{
				}
				break;
			case ID:
				{
				setState(47);
				match(ID);
				setState(48);
				match(T__0);
				setState(49);
				type();
				setState(56);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(50);
					match(COMMA);
					setState(51);
					match(ID);
					setState(52);
					match(T__0);
					setState(53);
					type();
					}
					}
					setState(58);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationsContext extends ParserRuleContext {
		public List<Variable_declContext> variable_decl() {
			return getRuleContexts(Variable_declContext.class);
		}
		public Variable_declContext variable_decl(int i) {
			return getRuleContext(Variable_declContext.class,i);
		}
		public DeclarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarations; }
	}

	public final DeclarationsContext declarations() throws RecognitionException {
		DeclarationsContext _localctx = new DeclarationsContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_declarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==VAR) {
				{
				{
				setState(61);
				variable_decl();
				}
				}
				setState(66);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Variable_declContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(AslParser.VAR, 0); }
		public List<TerminalNode> ID() { return getTokens(AslParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(AslParser.ID, i);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(AslParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AslParser.COMMA, i);
		}
		public Variable_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_decl; }
	}

	public final Variable_declContext variable_decl() throws RecognitionException {
		Variable_declContext _localctx = new Variable_declContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_variable_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(67);
			match(VAR);
			setState(68);
			match(ID);
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(69);
				match(COMMA);
				setState(70);
				match(ID);
				}
				}
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(76);
			match(T__0);
			setState(77);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Array_typeContext extends ParserRuleContext {
		public TerminalNode ARRAY() { return getToken(AslParser.ARRAY, 0); }
		public TerminalNode LC() { return getToken(AslParser.LC, 0); }
		public TerminalNode INT() { return getToken(AslParser.INT, 0); }
		public TerminalNode RC() { return getToken(AslParser.RC, 0); }
		public Simple_typeContext simple_type() {
			return getRuleContext(Simple_typeContext.class,0);
		}
		public Array_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_array_type; }
	}

	public final Array_typeContext array_type() throws RecognitionException {
		Array_typeContext _localctx = new Array_typeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_array_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			match(ARRAY);
			setState(80);
			match(LC);
			setState(81);
			match(INT);
			setState(82);
			match(RC);
			setState(83);
			match(T__1);
			setState(84);
			simple_type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Simple_typeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(AslParser.INT, 0); }
		public TerminalNode BOOL() { return getToken(AslParser.BOOL, 0); }
		public TerminalNode CHAR() { return getToken(AslParser.CHAR, 0); }
		public TerminalNode FLOAT() { return getToken(AslParser.FLOAT, 0); }
		public Simple_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_type; }
	}

	public final Simple_typeContext simple_type() throws RecognitionException {
		Simple_typeContext _localctx = new Simple_typeContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_simple_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(86);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOL) | (1L << FLOAT) | (1L << CHAR) | (1L << INT))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public Array_typeContext array_type() {
			return getRuleContext(Array_typeContext.class,0);
		}
		public Simple_typeContext simple_type() {
			return getRuleContext(Simple_typeContext.class,0);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_type);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(90);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ARRAY:
				{
				setState(88);
				array_type();
				}
				break;
			case BOOL:
			case FLOAT:
			case CHAR:
			case INT:
				{
				setState(89);
				simple_type();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementsContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(95);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << WHILE) | (1L << RETURN) | (1L << READ) | (1L << WRITE) | (1L << ID))) != 0)) {
				{
				{
				setState(92);
				statement();
				}
				}
				setState(97);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ProcCallContext extends StatementContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ProcCallContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class WriteExprContext extends StatementContext {
		public TerminalNode WRITE() { return getToken(AslParser.WRITE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public WriteExprContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class WhileStmtContext extends StatementContext {
		public TerminalNode WHILE() { return getToken(AslParser.WHILE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode DO() { return getToken(AslParser.DO, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode ENDWHILE() { return getToken(AslParser.ENDWHILE, 0); }
		public WhileStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class IfStmtContext extends StatementContext {
		public TerminalNode IF() { return getToken(AslParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode THEN() { return getToken(AslParser.THEN, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode ENDIF() { return getToken(AslParser.ENDIF, 0); }
		public IfStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ReadStmtContext extends StatementContext {
		public TerminalNode READ() { return getToken(AslParser.READ, 0); }
		public Left_exprContext left_expr() {
			return getRuleContext(Left_exprContext.class,0);
		}
		public ReadStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class AssignStmtContext extends StatementContext {
		public Left_exprContext left_expr() {
			return getRuleContext(Left_exprContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AslParser.ASSIGN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class ReturnStmtContext extends StatementContext {
		public TerminalNode RETURN() { return getToken(AslParser.RETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ReturnStmtContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class WriteStringContext extends StatementContext {
		public TerminalNode WRITE() { return getToken(AslParser.WRITE, 0); }
		public TerminalNode STRING() { return getToken(AslParser.STRING, 0); }
		public WriteStringContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_statement);
		int _la;
		try {
			setState(136);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				_localctx = new AssignStmtContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(98);
				left_expr();
				setState(99);
				match(ASSIGN);
				setState(100);
				expr(0);
				setState(101);
				match(T__2);
				}
				break;
			case 2:
				_localctx = new IfStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				match(IF);
				setState(104);
				expr(0);
				setState(105);
				match(THEN);
				setState(106);
				statements();
				setState(107);
				match(ENDIF);
				}
				break;
			case 3:
				_localctx = new ProcCallContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(109);
				ident();
				setState(110);
				match(LP);
				setState(111);
				match(RP);
				setState(112);
				match(T__2);
				}
				break;
			case 4:
				_localctx = new WhileStmtContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(114);
				match(WHILE);
				setState(115);
				expr(0);
				setState(116);
				match(DO);
				setState(117);
				statements();
				setState(118);
				match(ENDWHILE);
				}
				break;
			case 5:
				_localctx = new ReadStmtContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(120);
				match(READ);
				setState(121);
				left_expr();
				setState(122);
				match(T__2);
				}
				break;
			case 6:
				_localctx = new WriteExprContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(124);
				match(WRITE);
				setState(125);
				expr(0);
				setState(126);
				match(T__2);
				}
				break;
			case 7:
				_localctx = new WriteStringContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(128);
				match(WRITE);
				setState(129);
				match(STRING);
				setState(130);
				match(T__2);
				}
				break;
			case 8:
				_localctx = new ReturnStmtContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(131);
				match(RETURN);
				setState(133);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << NOT) | (1L << SUB) | (1L << LP) | (1L << BOOLVAL) | (1L << ID) | (1L << INTVAL) | (1L << FLOATVAL) | (1L << CHARVAL))) != 0)) {
					{
					setState(132);
					expr(0);
					}
				}

				setState(135);
				match(T__2);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Left_exprContext extends ParserRuleContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public Left_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_left_expr; }
	}

	public final Left_exprContext left_expr() throws RecognitionException {
		Left_exprContext _localctx = new Left_exprContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_left_expr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(138);
			ident();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NotContext extends ExprContext {
		public Token op;
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NOT() { return getToken(AslParser.NOT, 0); }
		public NotContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NegvalueContext extends ExprContext {
		public TerminalNode INTVAL() { return getToken(AslParser.INTVAL, 0); }
		public TerminalNode FLOATVAL() { return getToken(AslParser.FLOATVAL, 0); }
		public TerminalNode CHARVAL() { return getToken(AslParser.CHARVAL, 0); }
		public TerminalNode BOOLVAL() { return getToken(AslParser.BOOLVAL, 0); }
		public TerminalNode SUB() { return getToken(AslParser.SUB, 0); }
		public NegvalueContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprIdentContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public ExprIdentContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ArithmeticContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(AslParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(AslParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(AslParser.PLUS, 0); }
		public TerminalNode SUB() { return getToken(AslParser.SUB, 0); }
		public ArithmeticContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NegExprIdentContext extends ExprContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public TerminalNode SUB() { return getToken(AslParser.SUB, 0); }
		public NegExprIdentContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class RelationalContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode EQUAL() { return getToken(AslParser.EQUAL, 0); }
		public TerminalNode LT() { return getToken(AslParser.LT, 0); }
		public TerminalNode LTE() { return getToken(AslParser.LTE, 0); }
		public TerminalNode GT() { return getToken(AslParser.GT, 0); }
		public TerminalNode GTE() { return getToken(AslParser.GTE, 0); }
		public TerminalNode NE() { return getToken(AslParser.NE, 0); }
		public RelationalContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ParenthesisContext extends ExprContext {
		public TerminalNode LP() { return getToken(AslParser.LP, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RP() { return getToken(AslParser.RP, 0); }
		public ParenthesisContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ValueContext extends ExprContext {
		public TerminalNode INTVAL() { return getToken(AslParser.INTVAL, 0); }
		public TerminalNode FLOATVAL() { return getToken(AslParser.FLOATVAL, 0); }
		public TerminalNode CHARVAL() { return getToken(AslParser.CHARVAL, 0); }
		public TerminalNode BOOLVAL() { return getToken(AslParser.BOOLVAL, 0); }
		public ValueContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class LogicalContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode AND() { return getToken(AslParser.AND, 0); }
		public TerminalNode OR() { return getToken(AslParser.OR, 0); }
		public LogicalContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				_localctx = new ParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(141);
				match(LP);
				setState(142);
				expr(0);
				setState(143);
				match(RP);
				}
				break;
			case 2:
				{
				_localctx = new ValueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(145);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLVAL) | (1L << INTVAL) | (1L << FLOATVAL) | (1L << CHARVAL))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case 3:
				{
				_localctx = new NegvalueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				{
				setState(146);
				match(SUB);
				}
				setState(147);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOLVAL) | (1L << INTVAL) | (1L << FLOATVAL) | (1L << CHARVAL))) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			case 4:
				{
				_localctx = new ExprIdentContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(148);
				ident();
				}
				break;
			case 5:
				{
				_localctx = new NegExprIdentContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				{
				setState(149);
				match(SUB);
				}
				setState(150);
				ident();
				}
				break;
			case 6:
				{
				_localctx = new NotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(151);
				((NotContext)_localctx).op = match(NOT);
				setState(152);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(169);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(167);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new ArithmeticContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(155);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(156);
						((ArithmeticContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==MUL || _la==DIV) ) {
							((ArithmeticContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(157);
						expr(6);
						}
						break;
					case 2:
						{
						_localctx = new ArithmeticContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(158);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(159);
						((ArithmeticContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==SUB) ) {
							((ArithmeticContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(160);
						expr(5);
						}
						break;
					case 3:
						{
						_localctx = new RelationalContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(161);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(162);
						((RelationalContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EQUAL) | (1L << NE) | (1L << LT) | (1L << GT) | (1L << GTE) | (1L << LTE))) != 0)) ) {
							((RelationalContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(163);
						expr(4);
						}
						break;
					case 4:
						{
						_localctx = new LogicalContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(164);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(165);
						((LogicalContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==AND || _la==OR) ) {
							((LogicalContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(166);
						expr(3);
						}
						break;
					}
					} 
				}
				setState(171);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class IdentContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(AslParser.ID, 0); }
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_ident);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(172);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 11:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 5);
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\62\u00b1\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\6\2\36\n\2\r\2\16\2\37\3\2\3\2\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\5\3+\n\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\7\49\n\4\f\4\16\4<\13\4\5\4>\n\4\3\5\7\5A\n\5\f\5\16\5D\13"+
		"\5\3\6\3\6\3\6\3\6\7\6J\n\6\f\6\16\6M\13\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\b\3\b\3\t\3\t\5\t]\n\t\3\n\7\n`\n\n\f\n\16\nc\13\n\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\13\3\13\3\13\5\13\u0088\n\13\3\13\5\13\u008b\n\13\3"+
		"\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5\r\u009c\n"+
		"\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\u00aa\n\r\f\r\16"+
		"\r\u00ad\13\r\3\16\3\16\3\16\2\3\30\17\2\4\6\b\n\f\16\20\22\24\26\30\32"+
		"\2\b\4\2\26\30\35\35\4\2\36\36,.\3\2\31\32\3\2\20\21\4\2\t\n\f\17\3\2"+
		"\7\b\2\u00bc\2\35\3\2\2\2\4#\3\2\2\2\6=\3\2\2\2\bB\3\2\2\2\nE\3\2\2\2"+
		"\fQ\3\2\2\2\16X\3\2\2\2\20\\\3\2\2\2\22a\3\2\2\2\24\u008a\3\2\2\2\26\u008c"+
		"\3\2\2\2\30\u009b\3\2\2\2\32\u00ae\3\2\2\2\34\36\5\4\3\2\35\34\3\2\2\2"+
		"\36\37\3\2\2\2\37\35\3\2\2\2\37 \3\2\2\2 !\3\2\2\2!\"\7\2\2\3\"\3\3\2"+
		"\2\2#$\7\'\2\2$%\7+\2\2%&\7\22\2\2&\'\5\6\4\2\'*\7\23\2\2()\7\3\2\2)+"+
		"\5\20\t\2*(\3\2\2\2*+\3\2\2\2+,\3\2\2\2,-\5\b\5\2-.\5\22\n\2./\7(\2\2"+
		"/\5\3\2\2\2\60>\3\2\2\2\61\62\7+\2\2\62\63\7\3\2\2\63:\5\20\t\2\64\65"+
		"\7/\2\2\65\66\7+\2\2\66\67\7\3\2\2\679\5\20\t\28\64\3\2\2\29<\3\2\2\2"+
		":8\3\2\2\2:;\3\2\2\2;>\3\2\2\2<:\3\2\2\2=\60\3\2\2\2=\61\3\2\2\2>\7\3"+
		"\2\2\2?A\5\n\6\2@?\3\2\2\2AD\3\2\2\2B@\3\2\2\2BC\3\2\2\2C\t\3\2\2\2DB"+
		"\3\2\2\2EF\7\33\2\2FK\7+\2\2GH\7/\2\2HJ\7+\2\2IG\3\2\2\2JM\3\2\2\2KI\3"+
		"\2\2\2KL\3\2\2\2LN\3\2\2\2MK\3\2\2\2NO\7\3\2\2OP\5\20\t\2P\13\3\2\2\2"+
		"QR\7\34\2\2RS\7\24\2\2ST\7\35\2\2TU\7\25\2\2UV\7\4\2\2VW\5\16\b\2W\r\3"+
		"\2\2\2XY\t\2\2\2Y\17\3\2\2\2Z]\5\f\7\2[]\5\16\b\2\\Z\3\2\2\2\\[\3\2\2"+
		"\2]\21\3\2\2\2^`\5\24\13\2_^\3\2\2\2`c\3\2\2\2a_\3\2\2\2ab\3\2\2\2b\23"+
		"\3\2\2\2ca\3\2\2\2de\5\26\f\2ef\7\6\2\2fg\5\30\r\2gh\7\5\2\2h\u008b\3"+
		"\2\2\2ij\7\37\2\2jk\5\30\r\2kl\7 \2\2lm\5\22\n\2mn\7&\2\2n\u008b\3\2\2"+
		"\2op\5\32\16\2pq\7\22\2\2qr\7\23\2\2rs\7\5\2\2s\u008b\3\2\2\2tu\7\"\2"+
		"\2uv\5\30\r\2vw\7$\2\2wx\5\22\n\2xy\7#\2\2y\u008b\3\2\2\2z{\7)\2\2{|\5"+
		"\26\f\2|}\7\5\2\2}\u008b\3\2\2\2~\177\7*\2\2\177\u0080\5\30\r\2\u0080"+
		"\u0081\7\5\2\2\u0081\u008b\3\2\2\2\u0082\u0083\7*\2\2\u0083\u0084\7\60"+
		"\2\2\u0084\u008b\7\5\2\2\u0085\u0087\7%\2\2\u0086\u0088\5\30\r\2\u0087"+
		"\u0086\3\2\2\2\u0087\u0088\3\2\2\2\u0088\u0089\3\2\2\2\u0089\u008b\7\5"+
		"\2\2\u008ad\3\2\2\2\u008ai\3\2\2\2\u008ao\3\2\2\2\u008at\3\2\2\2\u008a"+
		"z\3\2\2\2\u008a~\3\2\2\2\u008a\u0082\3\2\2\2\u008a\u0085\3\2\2\2\u008b"+
		"\25\3\2\2\2\u008c\u008d\5\32\16\2\u008d\27\3\2\2\2\u008e\u008f\b\r\1\2"+
		"\u008f\u0090\7\22\2\2\u0090\u0091\5\30\r\2\u0091\u0092\7\23\2\2\u0092"+
		"\u009c\3\2\2\2\u0093\u009c\t\3\2\2\u0094\u0095\7\21\2\2\u0095\u009c\t"+
		"\3\2\2\u0096\u009c\5\32\16\2\u0097\u0098\7\21\2\2\u0098\u009c\5\32\16"+
		"\2\u0099\u009a\7\13\2\2\u009a\u009c\5\30\r\3\u009b\u008e\3\2\2\2\u009b"+
		"\u0093\3\2\2\2\u009b\u0094\3\2\2\2\u009b\u0096\3\2\2\2\u009b\u0097\3\2"+
		"\2\2\u009b\u0099\3\2\2\2\u009c\u00ab\3\2\2\2\u009d\u009e\f\7\2\2\u009e"+
		"\u009f\t\4\2\2\u009f\u00aa\5\30\r\b\u00a0\u00a1\f\6\2\2\u00a1\u00a2\t"+
		"\5\2\2\u00a2\u00aa\5\30\r\7\u00a3\u00a4\f\5\2\2\u00a4\u00a5\t\6\2\2\u00a5"+
		"\u00aa\5\30\r\6\u00a6\u00a7\f\4\2\2\u00a7\u00a8\t\7\2\2\u00a8\u00aa\5"+
		"\30\r\5\u00a9\u009d\3\2\2\2\u00a9\u00a0\3\2\2\2\u00a9\u00a3\3\2\2\2\u00a9"+
		"\u00a6\3\2\2\2\u00aa\u00ad\3\2\2\2\u00ab\u00a9\3\2\2\2\u00ab\u00ac\3\2"+
		"\2\2\u00ac\31\3\2\2\2\u00ad\u00ab\3\2\2\2\u00ae\u00af\7+\2\2\u00af\33"+
		"\3\2\2\2\17\37*:=BK\\a\u0087\u008a\u009b\u00a9\u00ab";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}