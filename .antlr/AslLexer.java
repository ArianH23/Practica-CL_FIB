// Generated from /home/arian/Uni/CL/practica/asl/Asl.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, ASSIGN=3, AND=4, OR=5, EQUAL=6, NE=7, NOT=8, LT=9, GT=10, 
		GTE=11, LTE=12, PLUS=13, SUB=14, LP=15, RP=16, BOOL=17, FLOAT=18, CHAR=19, 
		MUL=20, DIV=21, VAR=22, INT=23, BOOLVAL=24, IF=25, THEN=26, ELSE=27, WHILE=28, 
		ENDWHILE=29, DO=30, RETURN=31, ENDIF=32, FUNC=33, ENDFUNC=34, READ=35, 
		WRITE=36, ID=37, INTVAL=38, FLOATVAL=39, CHARVAL=40, COMMA=41, STRING=42, 
		COMMENT=43, WS=44;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", "GT", 
		"GTE", "LTE", "PLUS", "SUB", "LP", "RP", "BOOL", "FLOAT", "CHAR", "MUL", 
		"DIV", "VAR", "INT", "BOOLVAL", "IF", "THEN", "ELSE", "WHILE", "ENDWHILE", 
		"DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "ID", "INTVAL", 
		"FLOATVAL", "CHARVAL", "COMMA", "STRING", "ESC_SEQ", "COMMENT", "WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "':'", "';'", "'='", "'and'", "'or'", "'=='", "'!='", "'not'", "'<'", 
		"'>'", "'>='", "'<='", "'+'", "'-'", "'('", "')'", "'bool'", "'float'", 
		"'char'", "'*'", "'/'", "'var'", "'int'", null, "'if'", "'then'", "'else'", 
		"'while'", "'endwhile'", "'do'", "'return'", "'endif'", "'func'", "'endfunc'", 
		"'read'", "'write'", null, null, null, null, "','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", "GT", 
		"GTE", "LTE", "PLUS", "SUB", "LP", "RP", "BOOL", "FLOAT", "CHAR", "MUL", 
		"DIV", "VAR", "INT", "BOOLVAL", "IF", "THEN", "ELSE", "WHILE", "ENDWHILE", 
		"DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "ID", "INTVAL", 
		"FLOATVAL", "CHARVAL", "COMMA", "STRING", "COMMENT", "WS"
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


	public AslLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2.\u0135\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3"+
		"\7\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3"+
		"\r\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\22"+
		"\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\25\3\25"+
		"\3\26\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31"+
		"\3\31\3\31\3\31\3\31\3\31\5\31\u00ac\n\31\3\32\3\32\3\32\3\33\3\33\3\33"+
		"\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\35\3\35\3\36"+
		"\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3 \3 \3 \3 \3"+
		" \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3#\3#\3#\3#\3#\3#\3#\3#"+
		"\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3&\3&\7&\u00f4\n&\f&\16&\u00f7\13&\3"+
		"\'\6\'\u00fa\n\'\r\'\16\'\u00fb\3(\6(\u00ff\n(\r(\16(\u0100\3(\3(\6(\u0105"+
		"\n(\r(\16(\u0106\3)\3)\3)\5)\u010c\n)\3)\3)\3*\3*\3+\3+\3+\7+\u0115\n"+
		"+\f+\16+\u0118\13+\3+\3+\3,\3,\3,\3-\3-\3-\3-\7-\u0123\n-\f-\16-\u0126"+
		"\13-\3-\5-\u0129\n-\3-\3-\3-\3-\3.\6.\u0130\n.\r.\16.\u0131\3.\3.\2\2"+
		"/\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20"+
		"\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37"+
		"= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W\2Y-[.\3\2\t\5\2C\\aac|\6\2\62;C\\aac|\4"+
		"\2))^^\4\2$$^^\n\2$$))^^ddhhppttvv\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2"+
		"\u013e\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2"+
		"\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3"+
		"\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2"+
		"\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2"+
		"/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2"+
		"\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2"+
		"G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3"+
		"\2\2\2\2U\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\3]\3\2\2\2\5_\3\2\2\2\7a\3\2\2"+
		"\2\tc\3\2\2\2\13g\3\2\2\2\rj\3\2\2\2\17m\3\2\2\2\21p\3\2\2\2\23t\3\2\2"+
		"\2\25v\3\2\2\2\27x\3\2\2\2\31{\3\2\2\2\33~\3\2\2\2\35\u0080\3\2\2\2\37"+
		"\u0082\3\2\2\2!\u0084\3\2\2\2#\u0086\3\2\2\2%\u008b\3\2\2\2\'\u0091\3"+
		"\2\2\2)\u0096\3\2\2\2+\u0098\3\2\2\2-\u009a\3\2\2\2/\u009e\3\2\2\2\61"+
		"\u00ab\3\2\2\2\63\u00ad\3\2\2\2\65\u00b0\3\2\2\2\67\u00b5\3\2\2\29\u00ba"+
		"\3\2\2\2;\u00c0\3\2\2\2=\u00c9\3\2\2\2?\u00cc\3\2\2\2A\u00d3\3\2\2\2C"+
		"\u00d9\3\2\2\2E\u00de\3\2\2\2G\u00e6\3\2\2\2I\u00eb\3\2\2\2K\u00f1\3\2"+
		"\2\2M\u00f9\3\2\2\2O\u00fe\3\2\2\2Q\u0108\3\2\2\2S\u010f\3\2\2\2U\u0111"+
		"\3\2\2\2W\u011b\3\2\2\2Y\u011e\3\2\2\2[\u012f\3\2\2\2]^\7<\2\2^\4\3\2"+
		"\2\2_`\7=\2\2`\6\3\2\2\2ab\7?\2\2b\b\3\2\2\2cd\7c\2\2de\7p\2\2ef\7f\2"+
		"\2f\n\3\2\2\2gh\7q\2\2hi\7t\2\2i\f\3\2\2\2jk\7?\2\2kl\7?\2\2l\16\3\2\2"+
		"\2mn\7#\2\2no\7?\2\2o\20\3\2\2\2pq\7p\2\2qr\7q\2\2rs\7v\2\2s\22\3\2\2"+
		"\2tu\7>\2\2u\24\3\2\2\2vw\7@\2\2w\26\3\2\2\2xy\7@\2\2yz\7?\2\2z\30\3\2"+
		"\2\2{|\7>\2\2|}\7?\2\2}\32\3\2\2\2~\177\7-\2\2\177\34\3\2\2\2\u0080\u0081"+
		"\7/\2\2\u0081\36\3\2\2\2\u0082\u0083\7*\2\2\u0083 \3\2\2\2\u0084\u0085"+
		"\7+\2\2\u0085\"\3\2\2\2\u0086\u0087\7d\2\2\u0087\u0088\7q\2\2\u0088\u0089"+
		"\7q\2\2\u0089\u008a\7n\2\2\u008a$\3\2\2\2\u008b\u008c\7h\2\2\u008c\u008d"+
		"\7n\2\2\u008d\u008e\7q\2\2\u008e\u008f\7c\2\2\u008f\u0090\7v\2\2\u0090"+
		"&\3\2\2\2\u0091\u0092\7e\2\2\u0092\u0093\7j\2\2\u0093\u0094\7c\2\2\u0094"+
		"\u0095\7t\2\2\u0095(\3\2\2\2\u0096\u0097\7,\2\2\u0097*\3\2\2\2\u0098\u0099"+
		"\7\61\2\2\u0099,\3\2\2\2\u009a\u009b\7x\2\2\u009b\u009c\7c\2\2\u009c\u009d"+
		"\7t\2\2\u009d.\3\2\2\2\u009e\u009f\7k\2\2\u009f\u00a0\7p\2\2\u00a0\u00a1"+
		"\7v\2\2\u00a1\60\3\2\2\2\u00a2\u00a3\7v\2\2\u00a3\u00a4\7t\2\2\u00a4\u00a5"+
		"\7w\2\2\u00a5\u00ac\7g\2\2\u00a6\u00a7\7h\2\2\u00a7\u00a8\7c\2\2\u00a8"+
		"\u00a9\7n\2\2\u00a9\u00aa\7u\2\2\u00aa\u00ac\7g\2\2\u00ab\u00a2\3\2\2"+
		"\2\u00ab\u00a6\3\2\2\2\u00ac\62\3\2\2\2\u00ad\u00ae\7k\2\2\u00ae\u00af"+
		"\7h\2\2\u00af\64\3\2\2\2\u00b0\u00b1\7v\2\2\u00b1\u00b2\7j\2\2\u00b2\u00b3"+
		"\7g\2\2\u00b3\u00b4\7p\2\2\u00b4\66\3\2\2\2\u00b5\u00b6\7g\2\2\u00b6\u00b7"+
		"\7n\2\2\u00b7\u00b8\7u\2\2\u00b8\u00b9\7g\2\2\u00b98\3\2\2\2\u00ba\u00bb"+
		"\7y\2\2\u00bb\u00bc\7j\2\2\u00bc\u00bd\7k\2\2\u00bd\u00be\7n\2\2\u00be"+
		"\u00bf\7g\2\2\u00bf:\3\2\2\2\u00c0\u00c1\7g\2\2\u00c1\u00c2\7p\2\2\u00c2"+
		"\u00c3\7f\2\2\u00c3\u00c4\7y\2\2\u00c4\u00c5\7j\2\2\u00c5\u00c6\7k\2\2"+
		"\u00c6\u00c7\7n\2\2\u00c7\u00c8\7g\2\2\u00c8<\3\2\2\2\u00c9\u00ca\7f\2"+
		"\2\u00ca\u00cb\7q\2\2\u00cb>\3\2\2\2\u00cc\u00cd\7t\2\2\u00cd\u00ce\7"+
		"g\2\2\u00ce\u00cf\7v\2\2\u00cf\u00d0\7w\2\2\u00d0\u00d1\7t\2\2\u00d1\u00d2"+
		"\7p\2\2\u00d2@\3\2\2\2\u00d3\u00d4\7g\2\2\u00d4\u00d5\7p\2\2\u00d5\u00d6"+
		"\7f\2\2\u00d6\u00d7\7k\2\2\u00d7\u00d8\7h\2\2\u00d8B\3\2\2\2\u00d9\u00da"+
		"\7h\2\2\u00da\u00db\7w\2\2\u00db\u00dc\7p\2\2\u00dc\u00dd\7e\2\2\u00dd"+
		"D\3\2\2\2\u00de\u00df\7g\2\2\u00df\u00e0\7p\2\2\u00e0\u00e1\7f\2\2\u00e1"+
		"\u00e2\7h\2\2\u00e2\u00e3\7w\2\2\u00e3\u00e4\7p\2\2\u00e4\u00e5\7e\2\2"+
		"\u00e5F\3\2\2\2\u00e6\u00e7\7t\2\2\u00e7\u00e8\7g\2\2\u00e8\u00e9\7c\2"+
		"\2\u00e9\u00ea\7f\2\2\u00eaH\3\2\2\2\u00eb\u00ec\7y\2\2\u00ec\u00ed\7"+
		"t\2\2\u00ed\u00ee\7k\2\2\u00ee\u00ef\7v\2\2\u00ef\u00f0\7g\2\2\u00f0J"+
		"\3\2\2\2\u00f1\u00f5\t\2\2\2\u00f2\u00f4\t\3\2\2\u00f3\u00f2\3\2\2\2\u00f4"+
		"\u00f7\3\2\2\2\u00f5\u00f3\3\2\2\2\u00f5\u00f6\3\2\2\2\u00f6L\3\2\2\2"+
		"\u00f7\u00f5\3\2\2\2\u00f8\u00fa\4\62;\2\u00f9\u00f8\3\2\2\2\u00fa\u00fb"+
		"\3\2\2\2\u00fb\u00f9\3\2\2\2\u00fb\u00fc\3\2\2\2\u00fcN\3\2\2\2\u00fd"+
		"\u00ff\4\62;\2\u00fe\u00fd\3\2\2\2\u00ff\u0100\3\2\2\2\u0100\u00fe\3\2"+
		"\2\2\u0100\u0101\3\2\2\2\u0101\u0102\3\2\2\2\u0102\u0104\7\60\2\2\u0103"+
		"\u0105\4\62;\2\u0104\u0103\3\2\2\2\u0105\u0106\3\2\2\2\u0106\u0104\3\2"+
		"\2\2\u0106\u0107\3\2\2\2\u0107P\3\2\2\2\u0108\u010b\7)\2\2\u0109\u010c"+
		"\5W,\2\u010a\u010c\n\4\2\2\u010b\u0109\3\2\2\2\u010b\u010a\3\2\2\2\u010c"+
		"\u010d\3\2\2\2\u010d\u010e\7)\2\2\u010eR\3\2\2\2\u010f\u0110\7.\2\2\u0110"+
		"T\3\2\2\2\u0111\u0116\7$\2\2\u0112\u0115\5W,\2\u0113\u0115\n\5\2\2\u0114"+
		"\u0112\3\2\2\2\u0114\u0113\3\2\2\2\u0115\u0118\3\2\2\2\u0116\u0114\3\2"+
		"\2\2\u0116\u0117\3\2\2\2\u0117\u0119\3\2\2\2\u0118\u0116\3\2\2\2\u0119"+
		"\u011a\7$\2\2\u011aV\3\2\2\2\u011b\u011c\7^\2\2\u011c\u011d\t\6\2\2\u011d"+
		"X\3\2\2\2\u011e\u011f\7\61\2\2\u011f\u0120\7\61\2\2\u0120\u0124\3\2\2"+
		"\2\u0121\u0123\n\7\2\2\u0122\u0121\3\2\2\2\u0123\u0126\3\2\2\2\u0124\u0122"+
		"\3\2\2\2\u0124\u0125\3\2\2\2\u0125\u0128\3\2\2\2\u0126\u0124\3\2\2\2\u0127"+
		"\u0129\7\17\2\2\u0128\u0127\3\2\2\2\u0128\u0129\3\2\2\2\u0129\u012a\3"+
		"\2\2\2\u012a\u012b\7\f\2\2\u012b\u012c\3\2\2\2\u012c\u012d\b-\2\2\u012d"+
		"Z\3\2\2\2\u012e\u0130\t\b\2\2\u012f\u012e\3\2\2\2\u0130\u0131\3\2\2\2"+
		"\u0131\u012f\3\2\2\2\u0131\u0132\3\2\2\2\u0132\u0133\3\2\2\2\u0133\u0134"+
		"\b.\2\2\u0134\\\3\2\2\2\16\2\u00ab\u00f5\u00fb\u0100\u0106\u010b\u0114"+
		"\u0116\u0124\u0128\u0131\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}