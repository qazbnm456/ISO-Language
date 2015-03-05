/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IFX = 258,
     ELSE = 259,
     OP_EQ = 260,
     OP_NE = 261,
     IDENTIFIER = 262,
     STRING_LITERAL = 263,
     SIZEOF = 264,
     HEX = 265,
     STRING = 266,
     UNS32 = 267,
     UNS64 = 268,
     FLOAT32 = 269,
     FLOAT64 = 270,
     PTR_OP = 271,
     INC_OP = 272,
     DEC_OP = 273,
     LEFT_OP = 274,
     RIGHT_OP = 275,
     MUL_ASSIGN = 276,
     DIV_ASSIGN = 277,
     MOD_ASSIGN = 278,
     ADD_ASSIGN = 279,
     SUB_ASSIGN = 280,
     LEFT_ASSIGN = 281,
     RIGHT_ASSIGN = 282,
     AND_ASSIGN = 283,
     XOR_ASSIGN = 284,
     OR_ASSIGN = 285,
     CAT_ASSIGN = 286,
     TYPE_NAME = 287,
     OP_OR = 288,
     OP_AND = 289,
     OP_LT = 290,
     OP_ST = 291,
     OP_LE = 292,
     OP_SE = 293,
     SEMICOLON = 294,
     LCURLY = 295,
     RCURLY = 296,
     COMMA = 297,
     COLON = 298,
     ASSIGN = 299,
     LPAREN = 300,
     RPAREN = 301,
     LBRACKET = 302,
     RBRACKET = 303,
     DOT = 304,
     AND = 305,
     NOT = 306,
     CAT = 307,
     MINUS = 308,
     PLUS = 309,
     MUL = 310,
     DIV = 311,
     MOD = 312,
     XOR = 313,
     OR = 314,
     QUESTION = 315,
     TYPEDEF = 316,
     EXTERN = 317,
     STATIC = 318,
     AUTO = 319,
     CHAR = 320,
     SHORT = 321,
     INT = 322,
     LONG = 323,
     SIGNED = 324,
     UNSIGNED = 325,
     FLOAT = 326,
     DOUBLE = 327,
     CONST = 328,
     VOLATILE = 329,
     VOID = 330,
     CASE = 331,
     DEFAULT = 332,
     IF = 333,
     SWITCH = 334,
     WHILE = 335,
     DO = 336,
     FOR = 337,
     GOTO = 338,
     CONTINUE = 339,
     BREAK = 340,
     RETURN = 341,
     END = 342,
     NEW = 343,
     PROC = 344,
     CLASS = 345,
     STRUCT = 346,
     UNION = 347,
     ENUM = 348,
     ELLIPSIS = 349
   };
#endif
/* Tokens.  */
#define IFX 258
#define ELSE 259
#define OP_EQ 260
#define OP_NE 261
#define IDENTIFIER 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define HEX 265
#define STRING 266
#define UNS32 267
#define UNS64 268
#define FLOAT32 269
#define FLOAT64 270
#define PTR_OP 271
#define INC_OP 272
#define DEC_OP 273
#define LEFT_OP 274
#define RIGHT_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define CAT_ASSIGN 286
#define TYPE_NAME 287
#define OP_OR 288
#define OP_AND 289
#define OP_LT 290
#define OP_ST 291
#define OP_LE 292
#define OP_SE 293
#define SEMICOLON 294
#define LCURLY 295
#define RCURLY 296
#define COMMA 297
#define COLON 298
#define ASSIGN 299
#define LPAREN 300
#define RPAREN 301
#define LBRACKET 302
#define RBRACKET 303
#define DOT 304
#define AND 305
#define NOT 306
#define CAT 307
#define MINUS 308
#define PLUS 309
#define MUL 310
#define DIV 311
#define MOD 312
#define XOR 313
#define OR 314
#define QUESTION 315
#define TYPEDEF 316
#define EXTERN 317
#define STATIC 318
#define AUTO 319
#define CHAR 320
#define SHORT 321
#define INT 322
#define LONG 323
#define SIGNED 324
#define UNSIGNED 325
#define FLOAT 326
#define DOUBLE 327
#define CONST 328
#define VOLATILE 329
#define VOID 330
#define CASE 331
#define DEFAULT 332
#define IF 333
#define SWITCH 334
#define WHILE 335
#define DO 336
#define FOR 337
#define GOTO 338
#define CONTINUE 339
#define BREAK 340
#define RETURN 341
#define END 342
#define NEW 343
#define PROC 344
#define CLASS 345
#define STRUCT 346
#define UNION 347
#define ENUM 348
#define ELLIPSIS 349




/* Copy the first part of user declarations.  */
#line 1 "ISO.y"

	#include "iso_ast.h"
	#include "iso_token.h"
	int yylex(void);
	void yyerror(const char *);
	extern char yytext[];
	SegmentAST* ProgramHead;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "ISO.y"
{
    isoToken token;
    class NodeAST* node;
    class BlockAST* block;
    class InitDeclListAST* initDecl;
    class InitListAST* init;
    class FunctionAST* func;
    class StringList* arglist;
    class SegmentAST* segment;
    class DeclarationAST* decl;
}
/* Line 193 of yacc.c.  */
#line 305 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 318 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   957

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNRULES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    46,    49,    51,    53,    57,    62,    66,    71,
      76,    80,    82,    84,    88,    90,    94,    97,    99,   101,
     105,   107,   110,   113,   116,   120,   122,   125,   127,   130,
     132,   135,   137,   141,   143,   147,   149,   153,   158,   160,
     164,   166,   168,   170,   172,   174,   177,   179,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   202,   205,
     209,   211,   213,   216,   224,   230,   236,   244,   252,   259,
     267,   269,   273,   276,   279,   282,   286,   288,   290,   294,
     296,   301,   303,   305,   307,   309,   311,   313,   315,   317,
     319,   321,   323,   325,   331,   333,   337,   339,   343,   345,
     349,   351,   355,   357,   361,   363,   367,   371,   373,   377,
     381,   385,   389,   391,   395,   399,   401,   405,   409,   411,
     415,   419,   423,   425,   430,   432,   435,   437,   440,   442,
     444,   447,   450,   453,   456,   461,   463,   465,   467,   469,
     471,   473,   475,   480,   484,   489,   493,   497,   500,   503,
     505,   509,   511,   514,   516,   518,   520,   524,   530,   534
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,     7,    -1,    97,    -1,    45,   127,    46,
      -1,    98,    -1,    99,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,     8,    -1,    11,    -1,    10,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   126,
      -1,   100,    -1,   101,   100,    -1,   109,   103,    -1,   103,
      -1,     7,    -1,    45,   102,    46,    -1,   103,    47,   104,
      48,    -1,   103,    47,    48,    -1,   103,    45,   105,    46,
      -1,   103,    45,   108,    46,    -1,   103,    45,    46,    -1,
     131,    -1,   106,    -1,   106,    42,    94,    -1,   107,    -1,
     106,    42,   107,    -1,   111,   102,    -1,   111,    -1,     7,
      -1,   108,    42,     7,    -1,    55,    -1,    55,   119,    -1,
      55,   109,    -1,   111,    39,    -1,   111,   112,    39,    -1,
     116,    -1,   116,   111,    -1,   117,    -1,   117,   111,    -1,
     118,    -1,   118,   111,    -1,   113,    -1,   112,    42,   113,
      -1,   102,    -1,   102,    44,   114,    -1,   128,    -1,    40,
     115,    41,    -1,    40,   115,    42,    41,    -1,   114,    -1,
     115,    42,   114,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    75,    -1,    90,     7,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    71,    -1,    72,    -1,    69,
      -1,    70,    -1,    73,    -1,    74,    -1,   118,    -1,   119,
     118,    -1,    40,    41,    -1,    40,   101,    41,    -1,   110,
      -1,    39,    -1,   127,    39,    -1,    78,    45,   127,    46,
     100,     4,   100,    -1,    78,    45,   127,    46,   100,    -1,
      80,    45,   127,    46,   100,    -1,    81,   100,    80,    45,
     127,    46,    39,    -1,   147,    81,    59,   108,    59,   125,
      87,    -1,    82,    45,   122,   122,    46,   100,    -1,    82,
      45,   122,   122,   127,    46,   100,    -1,   101,    -1,    83,
       7,    39,    -1,    84,    39,    -1,    85,    39,    -1,    86,
      39,    -1,    86,   127,    39,    -1,   128,    -1,   131,    -1,
     145,   130,   128,    -1,   129,    -1,    89,    49,    88,   120,
      -1,    44,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,   132,    -1,   132,    60,   127,    43,   131,
      -1,   133,    -1,   132,    33,   133,    -1,   134,    -1,   133,
      34,   134,    -1,   135,    -1,   134,    59,   135,    -1,   136,
      -1,   135,    58,   136,    -1,   137,    -1,   136,    50,   137,
      -1,   138,    -1,   137,     5,   138,    -1,   137,     6,   138,
      -1,   139,    -1,   138,    36,   139,    -1,   138,    35,   139,
      -1,   138,    38,   139,    -1,   138,    37,   139,    -1,   140,
      -1,   139,    19,   140,    -1,   139,    20,   140,    -1,   141,
      -1,   140,    54,   141,    -1,   140,    53,   141,    -1,   142,
      -1,   141,    55,   142,    -1,   141,    56,   142,    -1,   141,
      57,   142,    -1,   145,    -1,    45,   143,    46,   142,    -1,
     144,    -1,   117,   144,    -1,   117,    -1,   118,   144,    -1,
     118,    -1,   147,    -1,    17,   145,    -1,    18,   145,    -1,
     146,   142,    -1,     9,   145,    -1,     9,    45,   143,    46,
      -1,    50,    -1,    55,    -1,    54,    -1,    53,    -1,    52,
      -1,    51,    -1,    96,    -1,   147,    47,   127,    48,    -1,
     147,    45,    46,    -1,   147,    45,   148,    46,    -1,   147,
      49,     7,    -1,   147,    16,     7,    -1,   147,    17,    -1,
     147,    18,    -1,   128,    -1,   148,    42,   128,    -1,   150,
      -1,   149,   150,    -1,   151,    -1,   152,    -1,   110,    -1,
      90,     7,   120,    -1,    90,     7,    36,     7,   120,    -1,
     111,   102,   120,    -1,   102,   120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   123,   124,   128,   129,   133,   134,   135,
     136,   140,   141,   142,   146,   147,   148,   149,   150,   151,
     155,   156,   160,   161,   165,   166,   167,   168,   169,   170,
     171,   175,   179,   180,   184,   185,   189,   191,   195,   196,
     200,   201,   202,   207,   208,   212,   213,   214,   215,   216,
     217,   221,   222,   226,   227,   231,   232,   233,   237,   238,
     242,   243,   244,   245,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   265,   266,   270,   271,   275,   276,
     282,   291,   292,   296,   297,   302,   303,   304,   305,   306,
     310,   314,   315,   316,   317,   318,   322,   327,   328,   329,
     333,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   351,   352,   356,   357,   361,   362,   366,   367,
     371,   372,   376,   377,   381,   382,   383,   387,   388,   389,
     390,   391,   395,   396,   397,   401,   402,   403,   407,   408,
     409,   410,   414,   415,   419,   423,   424,   425,   426,   430,
     431,   432,   433,   434,   435,   439,   440,   441,   442,   443,
     444,   448,   449,   450,   451,   452,   453,   454,   455,   459,
     460,   464,   465,   469,   470,   471,   475,   476,   481,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IFX", "ELSE", "OP_EQ", "OP_NE",
  "IDENTIFIER", "STRING_LITERAL", "SIZEOF", "HEX", "STRING", "UNS32",
  "UNS64", "FLOAT32", "FLOAT64", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "CAT_ASSIGN", "TYPE_NAME", "OP_OR", "OP_AND", "OP_LT",
  "OP_ST", "OP_LE", "OP_SE", "SEMICOLON", "LCURLY", "RCURLY", "COMMA",
  "COLON", "ASSIGN", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "DOT",
  "AND", "NOT", "CAT", "MINUS", "PLUS", "MUL", "DIV", "MOD", "XOR", "OR",
  "QUESTION", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "CASE", "DEFAULT", "IF", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "END", "NEW", "PROC",
  "CLASS", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "$accept",
  "primary_expression", "constant", "numeric", "string", "statement",
  "statement_list", "declarator", "direct_declarator",
  "constant_expression", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "pointer", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "initializer", "initializer_list", "storage_class_specifier",
  "type_specifier", "type_qualifier", "type_qualifier_list",
  "compound_statement", "declaration_statement", "expression_statement",
  "selection_statement", "iteration_statement", "block", "jump_statement",
  "expression", "assignment_expression", "procedure_expression",
  "assignment_operator", "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "type_name",
  "specifier_qualifier_list", "unary_expression", "unary_operator",
  "postfix_expression", "argument_expression_list", "translation_unit",
  "external_declaration", "class_definition", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    96,    97,    97,    98,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   123,   124,   124,   124,   124,   124,
     125,   126,   126,   126,   126,   126,   127,   128,   128,   128,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   138,   138,   138,
     138,   138,   139,   139,   139,   140,   140,   140,   141,   141,
     141,   141,   142,   142,   143,   144,   144,   144,   144,   145,
     145,   145,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   151,   151,   152,   152
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     1,     3,     1,     3,     2,     1,     1,     3,
       1,     2,     2,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     1,     2,     7,     5,     5,     7,     7,     6,     7,
       1,     3,     2,     2,     2,     3,     1,     1,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     2,     1,     2,     1,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     1,     1,     1,     3,     5,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,     0,    40,    60,    61,    62,    63,    66,    67,
      68,    69,    72,    73,    70,    71,    74,    75,    64,     0,
       0,    23,     0,   175,     0,    45,    47,    49,     0,   171,
     173,   174,     0,    42,    76,    41,    65,     0,   179,     0,
       0,    22,    43,    53,     0,    51,     0,    46,    48,    50,
       1,   172,    25,    77,     0,   176,     2,    11,     0,    13,
      12,     7,     8,     9,    10,     0,     0,    81,    78,     0,
     155,   160,   159,   158,   157,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     3,     5,     6,    20,
       0,    80,     0,    14,    15,    16,    17,    18,    19,     0,
      96,    99,    97,   112,   114,   116,   118,   120,   122,   124,
     127,   132,   135,   138,   142,     0,   149,    38,    30,     0,
      32,    34,     0,    37,    27,     0,    31,   142,   149,     0,
     178,    44,     0,    65,     0,     0,   153,     0,   150,   151,
     146,   148,     0,     0,   144,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,    79,    21,    53,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   101,     0,
     152,     0,   167,   168,     0,     0,     0,     0,    28,     0,
       0,    29,    36,    26,     0,    54,    55,    52,   177,     0,
     145,   147,     4,     0,     0,     0,     0,     0,    91,    95,
       0,   115,     0,   117,   119,   121,   123,   125,   126,   129,
     128,   131,   130,   133,   134,   137,   136,   139,   140,   141,
      98,   166,   163,   169,     0,     0,   165,     0,    33,    35,
      39,    58,     0,   154,   143,     0,     0,     0,     0,   100,
       0,     0,   164,   162,     0,    56,     0,    84,    85,     0,
       0,     0,   113,   170,     0,    57,    59,     0,     0,    88,
       0,    90,     0,    83,    86,    89,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,    87,    88,    89,    90,    20,    21,   125,
     119,   120,   121,   122,    22,    91,    92,    44,    45,   205,
     252,    25,    26,    27,    35,    93,    94,    95,    96,    97,
     282,    98,    99,   100,   101,   189,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   143,   144,
     114,   115,   128,   244,    28,    29,    30,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -200
static const yytype_int16 yypact[] =
{
     500,  -200,     6,    -5,  -200,  -200,  -200,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,    14,
       3,    26,    13,  -200,     7,   343,   343,   343,    96,  -200,
    -200,  -200,     8,  -200,  -200,    24,    -8,   217,  -200,   259,
     785,    26,  -200,   -11,    21,  -200,    75,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,    82,  -200,  -200,  -200,   834,  -200,
    -200,  -200,  -200,  -200,  -200,   851,   851,  -200,  -200,   469,
    -200,  -200,  -200,  -200,  -200,  -200,    54,    94,   385,    99,
     170,   139,   140,   586,   133,  -200,  -200,  -200,  -200,  -200,
     301,  -200,     7,  -200,  -200,  -200,  -200,  -200,  -200,   144,
    -200,  -200,  -200,   -21,   150,   126,   129,   138,   108,    69,
      97,    65,    38,  -200,   913,   863,     0,  -200,  -200,   143,
     148,  -200,    37,     6,  -200,   145,  -200,  -200,    39,   636,
    -200,  -200,     6,  -200,     3,   469,  -200,   768,  -200,  -200,
     423,   423,   146,   151,  -200,   768,   768,   111,   653,   155,
    -200,  -200,  -200,   157,   110,  -200,  -200,   156,  -200,   863,
     768,   863,   863,   863,   863,   863,   863,   863,   863,   863,
     863,   863,   863,   863,   863,   863,   863,   863,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,  -200,   768,
    -200,   192,  -200,  -200,   702,   768,   194,   152,  -200,   858,
     196,  -200,  -200,  -200,   636,  -200,  -200,  -200,  -200,   158,
    -200,  -200,  -200,   863,   163,   164,   169,   653,  -200,  -200,
       3,   150,   172,   126,   129,   138,   108,    69,    69,    97,
      97,    97,    97,    65,    65,    38,    38,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,    45,   168,  -200,   210,  -200,  -200,
    -200,  -200,   107,  -200,  -200,   385,   385,   768,   719,  -200,
     863,   768,  -200,  -200,   -17,  -200,   569,   216,  -200,   177,
     385,   190,  -200,  -200,   385,  -200,  -200,   385,   199,  -200,
     385,   385,   154,  -200,  -200,  -200,  -200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -200,  -200,  -200,  -200,  -200,   -75,   -35,    20,   220,  -200,
    -200,  -200,    46,     1,   243,    31,     9,  -200,   115,  -199,
    -200,  -200,   -63,     5,  -200,   -13,  -200,  -137,  -200,  -200,
    -200,  -200,   -45,  -119,  -200,  -200,   -38,  -200,    90,    89,
      91,    88,    95,   -12,   -59,   -16,    -1,  -111,   117,    35,
     -39,  -200,   -37,  -200,  -200,   226,  -200,  -200
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     116,   127,   126,   147,   190,   251,   140,    38,    34,    24,
     206,   217,   159,     1,     1,   156,   191,   192,   193,   136,
       1,    36,    32,    55,   142,   200,   138,   139,    54,    37,
     130,    23,    37,   129,    47,    48,    49,    24,   153,   160,
      53,   116,   274,    37,    43,   194,    42,   195,   123,   196,
       3,     2,     2,   116,    52,   191,   192,   193,     2,    23,
     131,     3,     3,   132,   237,   238,   239,   276,    16,    17,
     240,    39,   140,    40,   141,   243,   127,   140,   140,   200,
     258,   197,   133,   201,   194,   206,   195,   261,   196,   134,
     142,   262,   142,   175,   176,   177,    50,    16,    17,   145,
     214,   215,   254,     1,   167,   168,   169,   170,   229,   230,
     231,   232,   157,   165,   166,   222,   171,   172,   173,   174,
     127,   208,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   146,
     141,     2,   273,   202,   148,   141,   141,   206,   265,   266,
     245,     3,   157,   227,   228,   233,   234,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   235,   236,   127,   210,   211,   149,   150,   151,
     267,   268,   154,   158,   161,   162,    19,   163,   164,   198,
     199,   216,   212,   203,   218,   279,   219,   213,   220,   241,
     129,   246,   283,   250,   253,   285,   156,   259,   123,   255,
     256,   247,   269,   271,   257,   260,   263,   117,   116,   116,
     277,   127,   272,   278,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   116,    65,    66,   280,   116,   284,   281,
     116,   286,    41,   116,   116,   249,    33,   207,   264,   221,
     223,   225,   209,   224,    51,     0,    67,    37,    68,   226,
       0,     0,    69,     0,     0,     0,   117,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,    76,     0,    77,    78,    79,
      80,    81,    82,    83,     0,   118,    84,    46,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      67,    37,   155,     0,     0,     0,    69,     0,     0,    46,
       0,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    76,
       0,    77,    78,    79,    80,    81,    82,    83,     0,     0,
      84,    46,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,    67,    37,     0,     0,     0,     0,
      69,     0,     0,    46,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,    76,     0,    77,    78,    79,    80,    81,
      82,    83,     0,     0,    84,    46,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,    46,    69,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,    84,    46,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,     0,     0,
      19,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,     0,     0,     0,     0,   204,
     275,     0,     0,     0,    69,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,   152,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,     0,     0,     0,    84,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,     0,     0,     0,    84,   204,     0,     0,     0,
       0,    69,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    67,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,     0,     0,     0,     0,    84,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,     0,     0,
       0,     0,    84,     0,     0,     0,     0,    69,   242,     0,
       0,     0,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,     0,     0,    69,   270,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,     0,     0,     0,
       0,    84,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,     0,     0,     0,     0,    84,     0,
       0,     0,     0,    69,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      69,     0,     0,   124,     0,    70,    71,    72,    73,    74,
      75,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,     0,     0,     0,     0,    84,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   135,
      65,    66,     0,     0,    70,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,     0,    69,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,     0,     0,     0,    46,     0,
       0,     0,   248,     0,     0,     0,     0,   188
};

static const yytype_int16 yycheck[] =
{
      37,    40,    40,    78,   115,   204,    69,    20,     3,     0,
     129,   148,    33,     7,     7,    90,    16,    17,    18,    58,
       7,     7,     2,    36,    69,    42,    65,    66,    36,    40,
      43,     0,    40,    44,    25,    26,    27,    28,    83,    60,
      35,    78,    59,    40,    24,    45,    39,    47,    39,    49,
      55,    45,    45,    90,    46,    16,    17,    18,    45,    28,
      39,    55,    55,    42,   175,   176,   177,   266,    73,    74,
     189,    45,   135,    47,    69,   194,   115,   140,   141,    42,
     217,    81,     7,    46,    45,   204,    47,    42,    49,     7,
     135,    46,   137,    55,    56,    57,     0,    73,    74,    45,
     145,   146,   213,     7,    35,    36,    37,    38,   167,   168,
     169,   170,    92,     5,     6,   160,    19,    20,    53,    54,
     159,   134,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    45,
     135,    45,   261,   123,    45,   140,   141,   266,    41,    42,
     195,    55,   132,   165,   166,   171,   172,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,   173,   174,   213,   140,   141,     7,    39,    39,
     255,   256,    49,    39,    34,    59,    90,    58,    50,    46,
      42,    80,    46,    48,    39,   270,    39,    46,    88,     7,
      44,     7,   277,     7,    46,   280,   281,   220,   199,    46,
      46,    59,   257,   258,    45,    43,    48,     7,   255,   256,
       4,   260,   260,    46,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   270,    17,    18,    46,   274,    39,   274,
     277,    87,    22,   280,   281,   199,     3,   132,   247,   159,
     161,   163,   135,   162,    28,    -1,    39,    40,    41,   164,
      -1,    -1,    45,    -1,    -1,    -1,     7,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    -1,    46,    89,    90,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    90,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    90,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    -1,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      -1,    -1,    -1,    90,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    89,    90,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    -1,
      90,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    -1,    -1,    -1,    89,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    -1,    -1,    89,    40,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    -1,    -1,    -1,    -1,    89,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    89,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    -1,    -1,    -1,    -1,    89,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    45,
      17,    18,    -1,    -1,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    45,    55,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    90,
     102,   103,   109,   110,   111,   116,   117,   118,   149,   150,
     151,   152,   102,   109,   118,   119,     7,    40,   120,    45,
      47,   103,    39,   102,   112,   113,    90,   111,   111,   111,
       0,   150,    46,   118,    36,   120,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    18,    39,    41,    45,
      50,    51,    52,    53,    54,    55,    78,    80,    81,    82,
      83,    84,    85,    86,    89,    96,    97,    98,    99,   100,
     101,   110,   111,   120,   121,   122,   123,   124,   126,   127,
     128,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   145,   146,   147,     7,    46,   105,
     106,   107,   108,   111,    48,   104,   131,   145,   147,    44,
     120,    39,    42,     7,     7,    45,   145,    45,   145,   145,
     117,   118,   127,   143,   144,    45,    45,   100,    45,     7,
      39,    39,    39,   127,    49,    41,   100,   102,    39,    33,
      60,    34,    59,    58,    50,     5,     6,    35,    36,    37,
      38,    19,    20,    53,    54,    55,    56,    57,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    44,   130,
     142,    16,    17,    18,    45,    47,    49,    81,    46,    42,
      42,    46,   102,    48,    40,   114,   128,   113,   120,   143,
     144,   144,    46,    46,   127,   127,    80,   122,    39,    39,
      88,   133,   127,   134,   135,   136,   137,   138,   138,   139,
     139,   139,   139,   140,   140,   141,   141,   142,   142,   142,
     128,     7,    46,   128,   148,   127,     7,    59,    94,   107,
       7,   114,   115,    46,   142,    46,    46,    45,   122,   120,
      43,    42,    46,    48,   108,    41,    42,   100,   100,   127,
      46,   127,   131,   128,    59,    41,   114,     4,    46,   100,
      46,   101,   125,   100,    39,   100,    87
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 122 "ISO.y"
    { (yyval.node) = new GetVarAST(NULL, (yyvsp[(1) - (1)].token).m_name, GetVarAST::NONE); }
    break;

  case 3:
#line 123 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:
#line 124 "ISO.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 5:
#line 128 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 133 "ISO.y"
    { (yyval.node) = new Int32AST((yyvsp[(1) - (1)].token).m_integerValue); }
    break;

  case 8:
#line 134 "ISO.y"
    { (yyval.node) = new Int64AST((yyvsp[(1) - (1)].token).m_integerValue); }
    break;

  case 9:
#line 135 "ISO.y"
    { (yyval.node) = new FloatAST((yyvsp[(1) - (1)].token).m_doubleValue); }
    break;

  case 10:
#line 136 "ISO.y"
    { (yyval.node) = new DoubleAST((yyvsp[(1) - (1)].token).m_doubleValue); }
    break;

  case 11:
#line 140 "ISO.y"
    {}
    break;

  case 12:
#line 141 "ISO.y"
    {}
    break;

  case 13:
#line 142 "ISO.y"
    {}
    break;

  case 14:
#line 146 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 147 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:
#line 148 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 17:
#line 149 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 18:
#line 150 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 151 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 155 "ISO.y"
    { (yyval.block) = new BlockAST(); (yyval.block)->m_statements.push_back((yyvsp[(1) - (1)].node)); }
    break;

  case 21:
#line 156 "ISO.y"
    { if((yyvsp[(2) - (2)].node) != NULL) (yyvsp[(1) - (2)].block)->m_statements.push_back((yyvsp[(2) - (2)].node)); }
    break;

  case 22:
#line 160 "ISO.y"
    { (yyval.func) = (yyvsp[(1) - (2)].func); }
    break;

  case 23:
#line 161 "ISO.y"
    { (yyval.func) = (yyvsp[(1) - (1)].func); }
    break;

  case 24:
#line 165 "ISO.y"
    { (yyval.func) = new FunctionAST(*((yyvsp[(1) - (1)].token).m_name), NULL, FunctionAST::e_Identifier); }
    break;

  case 25:
#line 166 "ISO.y"
    { (yyval.func) = (yyvsp[(2) - (3)].func); }
    break;

  case 26:
#line 167 "ISO.y"
    { (yyvsp[(1) - (4)].func)->expr = (yyvsp[(3) - (4)].node); (yyvsp[(1) - (4)].func)->e_Type = FunctionAST::e_Array; }
    break;

  case 27:
#line 168 "ISO.y"
    { (yyvsp[(1) - (3)].func)->expr = NULL; (yyvsp[(1) - (3)].func)->e_Type = FunctionAST::e_Array; }
    break;

  case 28:
#line 169 "ISO.y"
    { (yyvsp[(1) - (4)].func)->e_Type = FunctionAST::e_Func;}
    break;

  case 29:
#line 170 "ISO.y"
    { (yyvsp[(1) - (4)].func)->e_Type = FunctionAST::e_Func; (yyvsp[(1) - (4)].func)->Args = &((yyvsp[(3) - (4)].arglist)->m_stringVec); }
    break;

  case 30:
#line 171 "ISO.y"
    { (yyvsp[(1) - (3)].func)->e_Type = FunctionAST::e_Func; (yyvsp[(1) - (3)].func)->Args = NULL; }
    break;

  case 31:
#line 175 "ISO.y"
    {}
    break;

  case 32:
#line 179 "ISO.y"
    {}
    break;

  case 33:
#line 180 "ISO.y"
    {}
    break;

  case 34:
#line 184 "ISO.y"
    {}
    break;

  case 35:
#line 185 "ISO.y"
    {}
    break;

  case 36:
#line 189 "ISO.y"
    {}
    break;

  case 37:
#line 191 "ISO.y"
    {}
    break;

  case 38:
#line 195 "ISO.y"
    { (yyval.arglist) = new StringList(); (yyval.arglist)->m_stringVec.push_back(*((yyvsp[(1) - (1)].token).m_name)); }
    break;

  case 39:
#line 196 "ISO.y"
    { (yyvsp[(1) - (3)].arglist)->m_stringVec.push_back(*((yyvsp[(3) - (3)].token).m_name)); }
    break;

  case 40:
#line 200 "ISO.y"
    {}
    break;

  case 41:
#line 201 "ISO.y"
    {}
    break;

  case 42:
#line 202 "ISO.y"
    {}
    break;

  case 43:
#line 207 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (2)].decl); }
    break;

  case 44:
#line 208 "ISO.y"
    { (yyvsp[(1) - (3)].decl)->InitDeclList = (yyvsp[(2) - (3)].initDecl); (yyval.node) = (yyvsp[(1) - (3)].decl); }
    break;

  case 45:
#line 212 "ISO.y"
    { (yyval.decl) = new DeclarationAST(); (yyval.decl)->specifiers.push_front((yyvsp[(1) - (1)].token).m_name); }
    break;

  case 46:
#line 213 "ISO.y"
    { (yyvsp[(2) - (2)].decl)->specifiers.push_front((yyvsp[(1) - (2)].token).m_name); (yyval.decl) = (yyvsp[(2) - (2)].decl); }
    break;

  case 47:
#line 214 "ISO.y"
    { (yyval.decl) = new DeclarationAST(); (yyval.decl)->specifiers.push_front((yyvsp[(1) - (1)].token).m_name); }
    break;

  case 48:
#line 215 "ISO.y"
    { (yyvsp[(2) - (2)].decl)->specifiers.push_front((yyvsp[(1) - (2)].token).m_name); (yyval.decl) = (yyvsp[(2) - (2)].decl); }
    break;

  case 49:
#line 216 "ISO.y"
    { (yyval.decl) = new DeclarationAST(); (yyval.decl)->specifiers.push_front((yyvsp[(1) - (1)].token).m_name); }
    break;

  case 50:
#line 217 "ISO.y"
    { (yyvsp[(2) - (2)].decl)->specifiers.push_front((yyvsp[(1) - (2)].token).m_name); (yyval.decl) = (yyvsp[(2) - (2)].decl); }
    break;

  case 51:
#line 221 "ISO.y"
    { (yyval.initDecl) = new InitDeclListAST(); (yyval.initDecl)->decl_inits.push_back((yyvsp[(1) - (1)].node)); }
    break;

  case 52:
#line 222 "ISO.y"
    { (yyvsp[(1) - (3)].initDecl)->decl_inits.push_back((yyvsp[(3) - (3)].node)); }
    break;

  case 53:
#line 226 "ISO.y"
    { (yyval.node) = new InitDeclAST((yyvsp[(1) - (1)].func)); }
    break;

  case 54:
#line 227 "ISO.y"
    { (yyval.node) = new InitDeclAST((yyvsp[(1) - (3)].func)); (yyvsp[(1) - (3)].func)->initializer = (yyvsp[(3) - (3)].node); }
    break;

  case 55:
#line 231 "ISO.y"
    { (yyval.node) = new InitAST((yyvsp[(1) - (1)].node), NULL, InitAST::e_Expr); }
    break;

  case 56:
#line 232 "ISO.y"
    { (yyval.node) = new InitAST(NULL, (yyvsp[(2) - (3)].init), InitAST::e_List); }
    break;

  case 57:
#line 233 "ISO.y"
    { (yyval.node) = new InitAST(NULL, (yyvsp[(2) - (4)].init), InitAST::e_List_With_Comma); }
    break;

  case 58:
#line 237 "ISO.y"
    { (yyval.init) = new InitListAST(); (yyval.init)->inits.push_back((yyvsp[(1) - (1)].node)); }
    break;

  case 59:
#line 238 "ISO.y"
    { (yyvsp[(1) - (3)].init)->inits.push_back((yyvsp[(3) - (3)].node)); }
    break;

  case 60:
#line 242 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 61:
#line 243 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 62:
#line 244 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 63:
#line 245 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 65:
#line 250 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (2)].token); }
    break;

  case 66:
#line 251 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 67:
#line 252 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 68:
#line 253 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 69:
#line 254 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 70:
#line 255 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 71:
#line 256 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 72:
#line 257 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 73:
#line 258 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 74:
#line 265 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 75:
#line 266 "ISO.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 76:
#line 270 "ISO.y"
    {}
    break;

  case 77:
#line 271 "ISO.y"
    {}
    break;

  case 78:
#line 275 "ISO.y"
    { (yyval.node) = new BlockAST(); }
    break;

  case 79:
#line 276 "ISO.y"
    { (yyval.node) = (yyvsp[(2) - (3)].block); }
    break;

  case 80:
#line 282 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 81:
#line 291 "ISO.y"
    { (yyval.node) = NULL; }
    break;

  case 82:
#line 292 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 83:
#line 296 "ISO.y"
    { (yyval.node) = new IfElseAST((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 84:
#line 297 "ISO.y"
    { (yyval.node) = new IfElseAST((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL); }
    break;

  case 85:
#line 302 "ISO.y"
    { (yyval.node) = new WhileAST((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 86:
#line 303 "ISO.y"
    { (yyval.node) = new DoWhileAST((yyvsp[(5) - (7)].node), (yyvsp[(2) - (7)].node)); }
    break;

  case 87:
#line 304 "ISO.y"
    {}
    break;

  case 88:
#line 305 "ISO.y"
    { (yyval.node) = new ForAST((yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node), NULL, (yyvsp[(6) - (6)].node)); }
    break;

  case 89:
#line 306 "ISO.y"
    { (yyval.node) = new ForAST((yyvsp[(3) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 90:
#line 310 "ISO.y"
    {}
    break;

  case 91:
#line 314 "ISO.y"
    {}
    break;

  case 92:
#line 315 "ISO.y"
    { (yyval.node) = new ContinueAST(); }
    break;

  case 93:
#line 316 "ISO.y"
    { (yyval.node) = new BreakAST(); }
    break;

  case 94:
#line 317 "ISO.y"
    { (yyval.node) = new ReturnAST(NULL); }
    break;

  case 95:
#line 318 "ISO.y"
    { (yyval.node) = new ReturnAST((yyvsp[(2) - (3)].node)); }
    break;

  case 96:
#line 322 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 327 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 98:
#line 328 "ISO.y"
    { (yyval.node) = new AssignmentAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 99:
#line 329 "ISO.y"
    {}
    break;

  case 100:
#line 333 "ISO.y"
    {}
    break;

  case 112:
#line 351 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 113:
#line 352 "ISO.y"
    { (yyval.node) = new ConditionalAST((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 114:
#line 356 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 115:
#line 357 "ISO.y"
    { (yyval.node) = new LogicalOrAST((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 116:
#line 361 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 117:
#line 362 "ISO.y"
    { (yyval.node) = new LogicalAndAST((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 118:
#line 366 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 119:
#line 367 "ISO.y"
    { (yyval.node) = new InclusiveOrAST((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 120:
#line 371 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 121:
#line 372 "ISO.y"
    { (yyval.node) = new ExclusiveOrAST((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 122:
#line 376 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 123:
#line 377 "ISO.y"
    { (yyval.node) = new AndAST((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 124:
#line 381 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 125:
#line 382 "ISO.y"
    { (yyval.node) = new EqualityAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 126:
#line 383 "ISO.y"
    { (yyval.node) = new EqualityAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 127:
#line 387 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 128:
#line 388 "ISO.y"
    { (yyval.node) = new RelationalAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 129:
#line 389 "ISO.y"
    { (yyval.node) = new RelationalAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 130:
#line 390 "ISO.y"
    { (yyval.node) = new RelationalAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 131:
#line 391 "ISO.y"
    { (yyval.node) = new RelationalAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 132:
#line 395 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 133:
#line 396 "ISO.y"
    { (yyval.node) = new ShiftAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 134:
#line 397 "ISO.y"
    { (yyval.node) = new ShiftAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 135:
#line 401 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 136:
#line 402 "ISO.y"
    { (yyval.node) = new AdditiveAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 137:
#line 403 "ISO.y"
    { (yyval.node) = new AdditiveAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 138:
#line 407 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 139:
#line 408 "ISO.y"
    { (yyval.node) = new MultiplicativeAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 140:
#line 409 "ISO.y"
    { (yyval.node) = new MultiplicativeAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 141:
#line 410 "ISO.y"
    { (yyval.node) = new MultiplicativeAST((yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].token).m_name, (yyvsp[(3) - (3)].node)); }
    break;

  case 142:
#line 414 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 143:
#line 415 "ISO.y"
    {}
    break;

  case 144:
#line 419 "ISO.y"
    {}
    break;

  case 145:
#line 423 "ISO.y"
    {}
    break;

  case 146:
#line 424 "ISO.y"
    {}
    break;

  case 147:
#line 425 "ISO.y"
    {}
    break;

  case 148:
#line 426 "ISO.y"
    {}
    break;

  case 149:
#line 430 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 150:
#line 431 "ISO.y"
    { (yyval.node) = new UnaryAST((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].token).m_name); }
    break;

  case 151:
#line 432 "ISO.y"
    { (yyval.node) = new UnaryAST((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].token).m_name); }
    break;

  case 152:
#line 433 "ISO.y"
    {}
    break;

  case 153:
#line 434 "ISO.y"
    {}
    break;

  case 154:
#line 435 "ISO.y"
    {}
    break;

  case 161:
#line 448 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 162:
#line 449 "ISO.y"
    {}
    break;

  case 163:
#line 450 "ISO.y"
    {}
    break;

  case 164:
#line 451 "ISO.y"
    {}
    break;

  case 165:
#line 452 "ISO.y"
    {}
    break;

  case 166:
#line 453 "ISO.y"
    {}
    break;

  case 167:
#line 454 "ISO.y"
    {}
    break;

  case 168:
#line 455 "ISO.y"
    {}
    break;

  case 169:
#line 459 "ISO.y"
    {}
    break;

  case 170:
#line 460 "ISO.y"
    {}
    break;

  case 171:
#line 464 "ISO.y"
    { ProgramHead = new SegmentAST(); (yyval.segment) = ProgramHead; if((yyvsp[(1) - (1)].node) != NULL) (yyval.segment)->m_segments.push_back((yyvsp[(1) - (1)].node)); }
    break;

  case 172:
#line 465 "ISO.y"
    { if((yyvsp[(2) - (2)].node) != NULL) (yyvsp[(1) - (2)].segment)->m_segments.push_back((yyvsp[(2) - (2)].node)); }
    break;

  case 173:
#line 469 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 174:
#line 470 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 175:
#line 471 "ISO.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 176:
#line 475 "ISO.y"
    {}
    break;

  case 177:
#line 476 "ISO.y"
    {}
    break;

  case 178:
#line 481 "ISO.y"
    { (yyval.node) = new DefinitionAST((yyvsp[(1) - (3)].decl), (yyvsp[(2) - (3)].func), (yyvsp[(3) - (3)].node), DefinitionAST::e_Func); }
    break;

  case 179:
#line 483 "ISO.y"
    {}
    break;


/* Line 1267 of yacc.c.  */
#line 2745 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 486 "ISO.y"

