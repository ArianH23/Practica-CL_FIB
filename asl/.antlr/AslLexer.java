// Generated from /home/arian/Uni/CL/Practica-CL-real/asl/Asl.g4 by ANTLR 4.7.1
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
		T__0=1, T__1=2, T__2=3, ASSIGN=4, AND=5, OR=6, EQUAL=7, NE=8, NOT=9, LT=10, 
		GT=11, GTE=12, LTE=13, PLUS=14, SUB=15, LP=16, RP=17, LC=18, RC=19, BOOL=20, 
		FLOAT=21, CHAR=22, MUL=23, MOD=24, DIV=25, VAR=26, ARRAY=27, INT=28, IF=29, 
		THEN=30, ELSE=31, WHILE=32, ENDWHILE=33, DO=34, RETURN=35, ENDIF=36, FUNC=37, 
		ENDFUNC=38, READ=39, WRITE=40, INTVAL=41, FLOATVAL=42, BOOLVAL=43, CHARVAL=44, 
		ID=45, COMMA=46, STRING=47, COMMENT=48, WS=49;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", 
		"GT", "GTE", "LTE", "PLUS", "SUB", "LP", "RP", "LC", "RC", "BOOL", "FLOAT", 
		"CHAR", "MUL", "MOD", "DIV", "VAR", "ARRAY", "INT", "IF", "THEN", "ELSE", 
		"WHILE", "ENDWHILE", "DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", "READ", 
		"WRITE", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", "ID", "COMMA", "STRING", 
		"ESC_SEQ", "COMMENT", "WS"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "':'", "'of'", "';'", "'='", "'and'", "'or'", "'=='", "'!='", "'not'", 
		"'<'", "'>'", "'>='", "'<='", "'+'", "'-'", "'('", "')'", "'['", "']'", 
		"'bool'", "'float'", "'char'", "'*'", "'%'", "'/'", "'var'", "'array'", 
		"'int'", "'if'", "'then'", "'else'", "'while'", "'endwhile'", "'do'", 
		"'return'", "'endif'", "'func'", "'endfunc'", "'read'", "'write'", null, 
		null, null, null, null, "','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, "ASSIGN", "AND", "OR", "EQUAL", "NE", "NOT", "LT", 
		"GT", "GTE", "LTE", "PLUS", "SUB", "LP", "RP", "LC", "RC", "BOOL", "FLOAT", 
		"CHAR", "MUL", "MOD", "DIV", "VAR", "ARRAY", "INT", "IF", "THEN", "ELSE", 
		"WHILE", "ENDWHILE", "DO", "RETURN", "ENDIF", "FUNC", "ENDFUNC", "READ", 
		"WRITE", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", "ID", "COMMA", "STRING", 
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\63\u014e\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\3\2"+
		"\3\2\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\b\3\b\3"+
		"\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\r\3\16\3\16"+
		"\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25"+
		"\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27"+
		"\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\33\3\33\3\34\3\34\3\34"+
		"\3\34\3\34\3\34\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\37\3\37\3\37\3\37"+
		"\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\""+
		"\3\"\3#\3#\3#\3$\3$\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3&\3&\3&\3&\3&\3"+
		"\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3(\3(\3(\3(\3(\3)\3)\3)\3)\3)\3)\3*\6*"+
		"\u0101\n*\r*\16*\u0102\3+\6+\u0106\n+\r+\16+\u0107\3+\3+\6+\u010c\n+\r"+
		"+\16+\u010d\3,\3,\3,\3,\3,\3,\3,\3,\3,\5,\u0119\n,\3-\3-\3-\5-\u011e\n"+
		"-\3-\3-\3.\3.\7.\u0124\n.\f.\16.\u0127\13.\3/\3/\3\60\3\60\3\60\7\60\u012e"+
		"\n\60\f\60\16\60\u0131\13\60\3\60\3\60\3\61\3\61\3\61\3\62\3\62\3\62\3"+
		"\62\7\62\u013c\n\62\f\62\16\62\u013f\13\62\3\62\5\62\u0142\n\62\3\62\3"+
		"\62\3\62\3\62\3\63\6\63\u0149\n\63\r\63\16\63\u014a\3\63\3\63\2\2\64\3"+
		"\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37"+
		"\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37="+
		" ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\2c\62e\63\3\2\t\4\2))^^\5\2"+
		"C\\aac|\6\2\62;C\\aac|\4\2$$^^\n\2$$))^^ddhhppttvv\4\2\f\f\17\17\5\2\13"+
		"\f\17\17\"\"\2\u0157\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2"+
		"\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3"+
		"\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2"+
		"\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2"+
		"\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2"+
		"\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2"+
		"\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q"+
		"\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2"+
		"\2\2\2_\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\3g\3\2\2\2\5i\3\2\2\2\7l\3\2\2\2"+
		"\tn\3\2\2\2\13p\3\2\2\2\rt\3\2\2\2\17w\3\2\2\2\21z\3\2\2\2\23}\3\2\2\2"+
		"\25\u0081\3\2\2\2\27\u0083\3\2\2\2\31\u0085\3\2\2\2\33\u0088\3\2\2\2\35"+
		"\u008b\3\2\2\2\37\u008d\3\2\2\2!\u008f\3\2\2\2#\u0091\3\2\2\2%\u0093\3"+
		"\2\2\2\'\u0095\3\2\2\2)\u0097\3\2\2\2+\u009c\3\2\2\2-\u00a2\3\2\2\2/\u00a7"+
		"\3\2\2\2\61\u00a9\3\2\2\2\63\u00ab\3\2\2\2\65\u00ad\3\2\2\2\67\u00b1\3"+
		"\2\2\29\u00b7\3\2\2\2;\u00bb\3\2\2\2=\u00be\3\2\2\2?\u00c3\3\2\2\2A\u00c8"+
		"\3\2\2\2C\u00ce\3\2\2\2E\u00d7\3\2\2\2G\u00da\3\2\2\2I\u00e1\3\2\2\2K"+
		"\u00e7\3\2\2\2M\u00ec\3\2\2\2O\u00f4\3\2\2\2Q\u00f9\3\2\2\2S\u0100\3\2"+
		"\2\2U\u0105\3\2\2\2W\u0118\3\2\2\2Y\u011a\3\2\2\2[\u0121\3\2\2\2]\u0128"+
		"\3\2\2\2_\u012a\3\2\2\2a\u0134\3\2\2\2c\u0137\3\2\2\2e\u0148\3\2\2\2g"+
		"h\7<\2\2h\4\3\2\2\2ij\7q\2\2jk\7h\2\2k\6\3\2\2\2lm\7=\2\2m\b\3\2\2\2n"+
		"o\7?\2\2o\n\3\2\2\2pq\7c\2\2qr\7p\2\2rs\7f\2\2s\f\3\2\2\2tu\7q\2\2uv\7"+
		"t\2\2v\16\3\2\2\2wx\7?\2\2xy\7?\2\2y\20\3\2\2\2z{\7#\2\2{|\7?\2\2|\22"+
		"\3\2\2\2}~\7p\2\2~\177\7q\2\2\177\u0080\7v\2\2\u0080\24\3\2\2\2\u0081"+
		"\u0082\7>\2\2\u0082\26\3\2\2\2\u0083\u0084\7@\2\2\u0084\30\3\2\2\2\u0085"+
		"\u0086\7@\2\2\u0086\u0087\7?\2\2\u0087\32\3\2\2\2\u0088\u0089\7>\2\2\u0089"+
		"\u008a\7?\2\2\u008a\34\3\2\2\2\u008b\u008c\7-\2\2\u008c\36\3\2\2\2\u008d"+
		"\u008e\7/\2\2\u008e \3\2\2\2\u008f\u0090\7*\2\2\u0090\"\3\2\2\2\u0091"+
		"\u0092\7+\2\2\u0092$\3\2\2\2\u0093\u0094\7]\2\2\u0094&\3\2\2\2\u0095\u0096"+
		"\7_\2\2\u0096(\3\2\2\2\u0097\u0098\7d\2\2\u0098\u0099\7q\2\2\u0099\u009a"+
		"\7q\2\2\u009a\u009b\7n\2\2\u009b*\3\2\2\2\u009c\u009d\7h\2\2\u009d\u009e"+
		"\7n\2\2\u009e\u009f\7q\2\2\u009f\u00a0\7c\2\2\u00a0\u00a1\7v\2\2\u00a1"+
		",\3\2\2\2\u00a2\u00a3\7e\2\2\u00a3\u00a4\7j\2\2\u00a4\u00a5\7c\2\2\u00a5"+
		"\u00a6\7t\2\2\u00a6.\3\2\2\2\u00a7\u00a8\7,\2\2\u00a8\60\3\2\2\2\u00a9"+
		"\u00aa\7\'\2\2\u00aa\62\3\2\2\2\u00ab\u00ac\7\61\2\2\u00ac\64\3\2\2\2"+
		"\u00ad\u00ae\7x\2\2\u00ae\u00af\7c\2\2\u00af\u00b0\7t\2\2\u00b0\66\3\2"+
		"\2\2\u00b1\u00b2\7c\2\2\u00b2\u00b3\7t\2\2\u00b3\u00b4\7t\2\2\u00b4\u00b5"+
		"\7c\2\2\u00b5\u00b6\7{\2\2\u00b68\3\2\2\2\u00b7\u00b8\7k\2\2\u00b8\u00b9"+
		"\7p\2\2\u00b9\u00ba\7v\2\2\u00ba:\3\2\2\2\u00bb\u00bc\7k\2\2\u00bc\u00bd"+
		"\7h\2\2\u00bd<\3\2\2\2\u00be\u00bf\7v\2\2\u00bf\u00c0\7j\2\2\u00c0\u00c1"+
		"\7g\2\2\u00c1\u00c2\7p\2\2\u00c2>\3\2\2\2\u00c3\u00c4\7g\2\2\u00c4\u00c5"+
		"\7n\2\2\u00c5\u00c6\7u\2\2\u00c6\u00c7\7g\2\2\u00c7@\3\2\2\2\u00c8\u00c9"+
		"\7y\2\2\u00c9\u00ca\7j\2\2\u00ca\u00cb\7k\2\2\u00cb\u00cc\7n\2\2\u00cc"+
		"\u00cd\7g\2\2\u00cdB\3\2\2\2\u00ce\u00cf\7g\2\2\u00cf\u00d0\7p\2\2\u00d0"+
		"\u00d1\7f\2\2\u00d1\u00d2\7y\2\2\u00d2\u00d3\7j\2\2\u00d3\u00d4\7k\2\2"+
		"\u00d4\u00d5\7n\2\2\u00d5\u00d6\7g\2\2\u00d6D\3\2\2\2\u00d7\u00d8\7f\2"+
		"\2\u00d8\u00d9\7q\2\2\u00d9F\3\2\2\2\u00da\u00db\7t\2\2\u00db\u00dc\7"+
		"g\2\2\u00dc\u00dd\7v\2\2\u00dd\u00de\7w\2\2\u00de\u00df\7t\2\2\u00df\u00e0"+
		"\7p\2\2\u00e0H\3\2\2\2\u00e1\u00e2\7g\2\2\u00e2\u00e3\7p\2\2\u00e3\u00e4"+
		"\7f\2\2\u00e4\u00e5\7k\2\2\u00e5\u00e6\7h\2\2\u00e6J\3\2\2\2\u00e7\u00e8"+
		"\7h\2\2\u00e8\u00e9\7w\2\2\u00e9\u00ea\7p\2\2\u00ea\u00eb\7e\2\2\u00eb"+
		"L\3\2\2\2\u00ec\u00ed\7g\2\2\u00ed\u00ee\7p\2\2\u00ee\u00ef\7f\2\2\u00ef"+
		"\u00f0\7h\2\2\u00f0\u00f1\7w\2\2\u00f1\u00f2\7p\2\2\u00f2\u00f3\7e\2\2"+
		"\u00f3N\3\2\2\2\u00f4\u00f5\7t\2\2\u00f5\u00f6\7g\2\2\u00f6\u00f7\7c\2"+
		"\2\u00f7\u00f8\7f\2\2\u00f8P\3\2\2\2\u00f9\u00fa\7y\2\2\u00fa\u00fb\7"+
		"t\2\2\u00fb\u00fc\7k\2\2\u00fc\u00fd\7v\2\2\u00fd\u00fe\7g\2\2\u00feR"+
		"\3\2\2\2\u00ff\u0101\4\62;\2\u0100\u00ff\3\2\2\2\u0101\u0102\3\2\2\2\u0102"+
		"\u0100\3\2\2\2\u0102\u0103\3\2\2\2\u0103T\3\2\2\2\u0104\u0106\4\62;\2"+
		"\u0105\u0104\3\2\2\2\u0106\u0107\3\2\2\2\u0107\u0105\3\2\2\2\u0107\u0108"+
		"\3\2\2\2\u0108\u0109\3\2\2\2\u0109\u010b\7\60\2\2\u010a\u010c\4\62;\2"+
		"\u010b\u010a\3\2\2\2\u010c\u010d\3\2\2\2\u010d\u010b\3\2\2\2\u010d\u010e"+
		"\3\2\2\2\u010eV\3\2\2\2\u010f\u0110\7v\2\2\u0110\u0111\7t\2\2\u0111\u0112"+
		"\7w\2\2\u0112\u0119\7g\2\2\u0113\u0114\7h\2\2\u0114\u0115\7c\2\2\u0115"+
		"\u0116\7n\2\2\u0116\u0117\7u\2\2\u0117\u0119\7g\2\2\u0118\u010f\3\2\2"+
		"\2\u0118\u0113\3\2\2\2\u0119X\3\2\2\2\u011a\u011d\7)\2\2\u011b\u011e\5"+
		"a\61\2\u011c\u011e\n\2\2\2\u011d\u011b\3\2\2\2\u011d\u011c\3\2\2\2\u011e"+
		"\u011f\3\2\2\2\u011f\u0120\7)\2\2\u0120Z\3\2\2\2\u0121\u0125\t\3\2\2\u0122"+
		"\u0124\t\4\2\2\u0123\u0122\3\2\2\2\u0124\u0127\3\2\2\2\u0125\u0123\3\2"+
		"\2\2\u0125\u0126\3\2\2\2\u0126\\\3\2\2\2\u0127\u0125\3\2\2\2\u0128\u0129"+
		"\7.\2\2\u0129^\3\2\2\2\u012a\u012f\7$\2\2\u012b\u012e\5a\61\2\u012c\u012e"+
		"\n\5\2\2\u012d\u012b\3\2\2\2\u012d\u012c\3\2\2\2\u012e\u0131\3\2\2\2\u012f"+
		"\u012d\3\2\2\2\u012f\u0130\3\2\2\2\u0130\u0132\3\2\2\2\u0131\u012f\3\2"+
		"\2\2\u0132\u0133\7$\2\2\u0133`\3\2\2\2\u0134\u0135\7^\2\2\u0135\u0136"+
		"\t\6\2\2\u0136b\3\2\2\2\u0137\u0138\7\61\2\2\u0138\u0139\7\61\2\2\u0139"+
		"\u013d\3\2\2\2\u013a\u013c\n\7\2\2\u013b\u013a\3\2\2\2\u013c\u013f\3\2"+
		"\2\2\u013d\u013b\3\2\2\2\u013d\u013e\3\2\2\2\u013e\u0141\3\2\2\2\u013f"+
		"\u013d\3\2\2\2\u0140\u0142\7\17\2\2\u0141\u0140\3\2\2\2\u0141\u0142\3"+
		"\2\2\2\u0142\u0143\3\2\2\2\u0143\u0144\7\f\2\2\u0144\u0145\3\2\2\2\u0145"+
		"\u0146\b\62\2\2\u0146d\3\2\2\2\u0147\u0149\t\b\2\2\u0148\u0147\3\2\2\2"+
		"\u0149\u014a\3\2\2\2\u014a\u0148\3\2\2\2\u014a\u014b\3\2\2\2\u014b\u014c"+
		"\3\2\2\2\u014c\u014d\b\63\2\2\u014df\3\2\2\2\16\2\u0102\u0107\u010d\u0118"+
		"\u011d\u0125\u012d\u012f\u013d\u0141\u014a\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}