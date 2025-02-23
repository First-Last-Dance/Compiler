
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "project.y"

#include <stdio.h>   
#include "SymbolTable.h"
#include "types.h"


nodeType * opr(int oper, int nops, ...);
nodeType * id(int type, char * name);
nodeType * getId(char * name, SymbolTable * table);
nodeType * con(char* value, int type);
void freeNode(nodeType *p);
void ftoa(float n,char res[], int afterpoint);
int ex(nodeType *p) ;//phase 2 semantic analyser;
extern int yyerror(char *);
extern int yyerrorvar(char *s, char *var);
extern int yylex(void);


extern FILE *yyin;
FILE *f1;
FILE *f2;
extern int yylineno;

int lineIndex = 0;
int blockLevel = 0;



SymbolTable* symbolTable;



/* Line 189 of yacc.c  */
#line 106 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMMA = 258,
     RET = 259,
     BREAK = 260,
     DEFAULT = 261,
     SWITCH = 262,
     DO = 263,
     CASE = 264,
     OBRACE = 265,
     EBRACE = 266,
     ORBRACKET = 267,
     ERBRACKET = 268,
     SEMICOLON = 269,
     COLON = 270,
     INCREMENT = 271,
     DECREMENT = 272,
     PEQUAL = 273,
     MEQUAL = 274,
     MULEQUAL = 275,
     DIVEQUAL = 276,
     GREATER = 277,
     LESS = 278,
     GE = 279,
     LE = 280,
     EQ = 281,
     NE = 282,
     PLUS = 283,
     MINUS = 284,
     MUL = 285,
     DIV = 286,
     REM = 287,
     AND = 288,
     OR = 289,
     NOT = 290,
     WHILE = 291,
     FOR = 292,
     IF = 293,
     ELSE = 294,
     PRINT = 295,
     INT = 296,
     FLOAT = 297,
     DOUBLE = 298,
     LONG = 299,
     CHAR = 300,
     STRING = 301,
     CONST = 302,
     ASSIGN = 303,
     POWER = 304,
     FALSE = 305,
     TRUE = 306,
     BOOL = 307,
     INTEGERNUMBER = 308,
     FLOATNUMBER = 309,
     TEXT = 310,
     CHARACTER = 311,
     IDENTIFIER = 312,
     IFX = 313,
     UMINUS = 314
   };
#endif
/* Tokens.  */
#define COMMA 258
#define RET 259
#define BREAK 260
#define DEFAULT 261
#define SWITCH 262
#define DO 263
#define CASE 264
#define OBRACE 265
#define EBRACE 266
#define ORBRACKET 267
#define ERBRACKET 268
#define SEMICOLON 269
#define COLON 270
#define INCREMENT 271
#define DECREMENT 272
#define PEQUAL 273
#define MEQUAL 274
#define MULEQUAL 275
#define DIVEQUAL 276
#define GREATER 277
#define LESS 278
#define GE 279
#define LE 280
#define EQ 281
#define NE 282
#define PLUS 283
#define MINUS 284
#define MUL 285
#define DIV 286
#define REM 287
#define AND 288
#define OR 289
#define NOT 290
#define WHILE 291
#define FOR 292
#define IF 293
#define ELSE 294
#define PRINT 295
#define INT 296
#define FLOAT 297
#define DOUBLE 298
#define LONG 299
#define CHAR 300
#define STRING 301
#define CONST 302
#define ASSIGN 303
#define POWER 304
#define FALSE 305
#define TRUE 306
#define BOOL 307
#define INTEGERNUMBER 308
#define FLOATNUMBER 309
#define TEXT 310
#define CHARACTER 311
#define IDENTIFIER 312
#define IFX 313
#define UMINUS 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 "project.y"

    int iValue;                 /* integer value */
	float fValue;               /* float Value */
    char * sValue;              /* string value */
	char * cValue;               /* character value */
	char * id ;                 /* id value */
    nodeType *nPtr;             /* node pointer */



/* Line 214 of yacc.c  */
#line 271 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 283 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    23,    26,    29,    32,    35,    39,    44,    50,    56,
      59,    65,    73,    85,    91,    99,   105,   107,   109,   121,
     132,   136,   139,   144,   148,   152,   155,   157,   159,   163,
     165,   168,   172,   176,   180,   184,   188,   192,   195,   198,
     201,   204,   207,   211,   215,   219,   223,   225,   229,   233,
     237,   240,   244,   248,   252,   256,   260,   264,   266,   268,
     270,   272,   274,   276,   278,   280,   282,   284,   288,   294,
     302
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    62,    65,    -1,    65,    -1,
      41,    -1,    42,    -1,    45,    -1,    46,    -1,    52,    -1,
      47,    41,    -1,    47,    42,    -1,    47,    45,    -1,    47,
      46,    -1,    47,    52,    -1,    63,    57,    14,    -1,    57,
      48,    79,    14,    -1,    63,    57,    48,    79,    14,    -1,
      64,    57,    48,    79,    14,    -1,    75,    14,    -1,    36,
      12,    79,    13,    69,    -1,     8,    69,    36,    12,    79,
      13,    14,    -1,    37,    12,    57,    48,    53,    14,    77,
      14,    76,    13,    69,    -1,    38,    12,    79,    13,    69,
      -1,    38,    12,    79,    13,    69,    39,    69,    -1,     7,
      12,    57,    13,    72,    -1,    66,    -1,    69,    -1,    63,
      57,    12,    67,    13,    70,    73,     4,    79,    14,    71,
      -1,    63,    57,    12,    13,    70,    73,     4,    79,    14,
      71,    -1,    63,    57,    68,    -1,    63,    57,    -1,     3,
      63,    57,    68,    -1,     3,    63,    57,    -1,    70,    73,
      71,    -1,    70,    71,    -1,    10,    -1,    11,    -1,    70,
      80,    71,    -1,    65,    -1,    73,    65,    -1,    79,    28,
      79,    -1,    79,    29,    79,    -1,    79,    30,    79,    -1,
      79,    31,    79,    -1,    79,    32,    79,    -1,    79,    49,
      79,    -1,    29,    79,    -1,    57,    16,    -1,    57,    17,
      -1,    57,    16,    -1,    57,    17,    -1,    57,    18,    79,
      -1,    57,    19,    79,    -1,    57,    20,    79,    -1,    57,
      21,    79,    -1,    75,    -1,    57,    48,    74,    -1,    79,
      33,    79,    -1,    79,    34,    79,    -1,    35,    79,    -1,
      79,    22,    79,    -1,    79,    23,    79,    -1,    79,    24,
      79,    -1,    79,    25,    79,    -1,    79,    27,    79,    -1,
      79,    26,    79,    -1,    54,    -1,    53,    -1,    56,    -1,
      50,    -1,    51,    -1,    55,    -1,    57,    -1,    78,    -1,
      74,    -1,    77,    -1,    12,    79,    13,    -1,     6,    15,
      73,     5,    14,    -1,     9,    53,    15,    73,     5,    14,
      80,    -1,     9,    53,    15,    73,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    73,    74,    78,    79,    80,    81,    82,
      85,    86,    87,    88,    89,    93,    94,    95,    96,    97,
      98,    99,   100,   103,   104,   105,   106,   107,   111,   112,
     120,   121,   125,   126,   131,   132,   135,   136,   139,   143,
     144,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     160,   161,   162,   163,   164,   165,   170,   171,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   186,   187,   188,
     189,   190,   191,   192,   195,   196,   197,   199,   202,   203,
     204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "RET", "BREAK", "DEFAULT",
  "SWITCH", "DO", "CASE", "OBRACE", "EBRACE", "ORBRACKET", "ERBRACKET",
  "SEMICOLON", "COLON", "INCREMENT", "DECREMENT", "PEQUAL", "MEQUAL",
  "MULEQUAL", "DIVEQUAL", "GREATER", "LESS", "GE", "LE", "EQ", "NE",
  "PLUS", "MINUS", "MUL", "DIV", "REM", "AND", "OR", "NOT", "WHILE", "FOR",
  "IF", "ELSE", "PRINT", "INT", "FLOAT", "DOUBLE", "LONG", "CHAR",
  "STRING", "CONST", "ASSIGN", "POWER", "FALSE", "TRUE", "BOOL",
  "INTEGERNUMBER", "FLOATNUMBER", "TEXT", "CHARACTER", "IDENTIFIER", "IFX",
  "UMINUS", "$accept", "program", "function_declaration", "datatype",
  "Constant", "statement", "function", "argument_list", "continuation",
  "brace_scope", "OpeningBRACE", "ClosingBRACE", "switch_scope",
  "statement_list", "arithmetic_expression", "increment_statement",
  "for_expression", "boolean_expression", "value", "expression",
  "case_expression", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    71,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     3,     4,     5,     5,     2,
       5,     7,    11,     5,     7,     5,     1,     1,    11,    10,
       3,     2,     4,     3,     3,     2,     1,     1,     3,     1,
       2,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     1,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     7,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    36,     0,     0,     0,     5,     6,     7,
       8,     0,     9,     0,     0,     2,     0,     0,     4,    26,
      27,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    50,    51,     0,     0,     0,     0,     0,
       1,     3,     0,     0,    37,    39,    35,     0,    19,     0,
       0,     0,     0,     0,    70,    71,    68,    67,    72,    69,
      73,    75,    76,    74,     0,     0,     0,    52,    53,    54,
      55,     0,     0,    15,     0,     0,    40,    34,     0,     0,
       0,    47,    60,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    25,
       0,    77,    20,    61,    62,    63,    64,    66,    65,    41,
      42,    43,    44,    45,    58,    59,    46,     0,    23,     0,
      31,     0,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,    38,    21,    76,     0,
      24,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,    56,     0,     0,    32,     0,    78,     0,
      80,     0,     0,    29,     0,     0,    75,    22,    28,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    45,    19,   105,   142,    20,
      21,    46,   109,    47,    61,    22,   164,    62,    63,   149,
     136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -149
static const yytype_int16 yypact[] =
{
     235,    12,    21,  -149,    20,    26,    27,  -149,  -149,  -149,
    -149,    64,  -149,    69,    33,   235,   -15,   -11,  -149,  -149,
    -149,   222,    35,   -10,    14,   249,    -4,   249,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,   249,   249,   249,   249,   249,
    -149,  -149,    -5,     4,  -149,  -149,  -149,   222,  -149,    41,
      43,   249,   249,   249,  -149,  -149,  -149,  -149,  -149,  -149,
      13,  -149,  -149,  -149,   285,    11,   313,   522,   522,   522,
     522,   397,    -1,  -149,   249,   249,  -149,  -149,    21,   249,
     341,  -149,    94,  -149,  -149,    21,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
      15,    21,  -149,    21,    10,    48,   425,   453,     8,  -149,
     369,  -149,  -149,    94,    94,    94,    94,    94,    94,   -26,
     -26,    16,    16,    16,    94,    94,  -149,    81,    57,   235,
      97,    21,  -149,  -149,    89,    54,   100,    98,   249,    21,
      56,    86,  -149,   235,   235,    99,  -149,  -149,   116,   522,
    -149,   249,    76,   111,   179,   235,    78,   481,    97,   249,
     122,   166,   161,  -149,   126,   100,  -149,   509,  -149,   130,
    -149,   249,    21,  -149,   100,     8,   127,  -149,  -149,  -149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,   -57,  -149,     1,  -149,  -149,   -13,    -2,
     -75,   -45,  -149,  -118,   -25,    -6,  -149,    22,  -149,   -17,
    -148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      24,    18,    77,   108,    94,    95,    96,    72,    64,    73,
      66,   140,   103,   170,   134,   104,    41,   135,    67,    68,
      69,    70,    71,    99,    23,   153,   154,   179,   129,    83,
      84,     3,    25,    40,    80,    81,    82,   161,    26,    27,
       7,     8,    42,    74,     9,    10,    43,    49,    76,    48,
      50,    12,    75,    65,    78,    79,   143,   106,   107,   100,
     151,   131,   110,     1,     2,    99,     3,   130,   127,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   112,   152,    33,    34,    35,    36,    37,
      38,   146,     4,     5,     6,   138,   139,     7,     8,   128,
     141,     9,    10,    11,   144,    28,    29,   145,    12,    30,
      31,    44,   147,    13,   155,   159,    32,    39,     1,     2,
     173,     3,    92,    93,    94,    95,    96,     7,     8,   178,
     156,     9,    10,   158,   157,   162,   168,   150,    12,   172,
     -57,    76,   167,    99,   175,   166,   176,     4,     5,     6,
     163,     0,     7,     8,    76,    76,     9,    10,    11,     0,
     148,     0,    76,    12,     0,     0,     0,     0,    13,     0,
     177,   169,   134,     1,     2,   135,     3,    33,    34,    35,
      36,    37,    38,     0,   160,     0,     1,     2,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     0,     0,     7,     8,   171,
       0,     9,    10,    11,     0,     4,     5,     6,    12,     0,
       7,     8,     0,    13,     9,    10,    11,     0,     0,     1,
       2,    12,     3,    44,     0,     0,    13,     0,     0,     0,
       0,     0,     1,     2,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,    51,     0,     7,     8,     0,     0,     9,    10,    11,
       0,     4,     5,     6,    12,     0,     7,     8,    52,    13,
       9,    10,    11,     0,    53,     0,     0,    12,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,    85,    54,
      55,     0,    56,    57,    58,    59,    60,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,    99,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,    99,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
      99,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,   102,     0,     0,     0,     0,     0,     0,    99,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,    99,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,    99,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,    99,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
      99,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99
};

static const yytype_int16 yycheck[] =
{
       2,     0,    47,    78,    30,    31,    32,    12,    25,    14,
      27,   129,    13,   161,     6,    72,    15,     9,    35,    36,
      37,    38,    39,    49,    12,   143,   144,   175,   103,    16,
      17,    10,    12,     0,    51,    52,    53,   155,    12,    12,
      41,    42,    57,    48,    45,    46,    57,    57,    47,    14,
      36,    52,    48,    57,    13,    12,   131,    74,    75,    48,
       4,    13,    79,     7,     8,    49,    10,    57,    53,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    85,   141,    16,    17,    18,    19,    20,
      21,   136,    36,    37,    38,    14,    39,    41,    42,   101,
       3,    45,    46,    47,    15,    41,    42,    53,    52,    45,
      46,    11,    14,    57,    15,     4,    52,    48,     7,     8,
     165,    10,    28,    29,    30,    31,    32,    41,    42,   174,
      14,    45,    46,    57,   151,    57,    14,   139,    52,    13,
      13,   140,   159,    49,    14,   158,   171,    36,    37,    38,
     156,    -1,    41,    42,   153,   154,    45,    46,    47,    -1,
     138,    -1,   161,    52,    -1,    -1,    -1,    -1,    57,    -1,
     172,     5,     6,     7,     8,     9,    10,    16,    17,    18,
      19,    20,    21,    -1,     5,    -1,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,    48,
      -1,    45,    46,    47,    -1,    36,    37,    38,    52,    -1,
      41,    42,    -1,    57,    45,    46,    47,    -1,    -1,     7,
       8,    52,    10,    11,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    12,    -1,    41,    42,    -1,    -1,    45,    46,    47,
      -1,    36,    37,    38,    52,    -1,    41,    42,    29,    57,
      45,    46,    47,    -1,    35,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    13,    50,
      51,    -1,    53,    54,    55,    56,    57,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    49,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    36,    37,    38,    41,    42,    45,
      46,    47,    52,    57,    61,    62,    63,    64,    65,    66,
      69,    70,    75,    12,    69,    12,    12,    12,    41,    42,
      45,    46,    52,    16,    17,    18,    19,    20,    21,    48,
       0,    65,    57,    57,    11,    65,    71,    73,    14,    57,
      36,    12,    29,    35,    50,    51,    53,    54,    55,    56,
      57,    74,    77,    78,    79,    57,    79,    79,    79,    79,
      79,    79,    12,    14,    48,    48,    65,    71,    13,    12,
      79,    79,    79,    16,    17,    13,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    49,
      48,    13,    14,    13,    63,    67,    79,    79,    70,    72,
      79,    13,    69,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    53,    69,    70,
      57,    13,    14,    14,     6,     9,    80,    13,    14,    39,
      73,     3,    68,    70,    15,    53,    71,    14,    77,    79,
      69,     4,    63,    73,    73,    15,    14,    79,    57,     4,
       5,    73,    57,    75,    76,    14,    68,    79,    14,     5,
      80,    48,    13,    71,    14,    14,    74,    69,    71,    80
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 73 "project.y"
    {ex((yyvsp[(2) - (2)].nPtr)); freeNode((yyvsp[(2) - (2)].nPtr));}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 74 "project.y"
    {ex((yyvsp[(1) - (1)].nPtr)); freeNode((yyvsp[(1) - (1)].nPtr));}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 78 "project.y"
    {(yyval.iValue)=0;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 79 "project.y"
    {(yyval.iValue)=1;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 80 "project.y"
    {(yyval.iValue)=2;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 81 "project.y"
    {(yyval.iValue)=3;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 82 "project.y"
    {(yyval.iValue)=4;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 85 "project.y"
    {(yyval.iValue)=5;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 86 "project.y"
    {(yyval.iValue)=6;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 87 "project.y"
    {(yyval.iValue)=7;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 88 "project.y"
    {(yyval.iValue)=8;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "project.y"
    {(yyval.iValue)=9;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 93 "project.y"
    {(yyval.nPtr)=id((yyvsp[(1) - (3)].iValue),(yyvsp[(2) - (3)].id));printf("Declare variable\n"); lineIndex++;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 94 "project.y"
    {(yyval.nPtr) = opr(ASSIGN,2, getId((yyvsp[(1) - (4)].id), symbolTable), (yyvsp[(3) - (4)].nPtr));printf("Assign value\n"); lineIndex++;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 95 "project.y"
    {(yyval.nPtr) = opr(ASSIGN,2, id((yyvsp[(1) - (5)].iValue),(yyvsp[(2) - (5)].id)), (yyvsp[(4) - (5)].nPtr));lineIndex++;printf("Declare and initialize variable\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 96 "project.y"
    {(yyval.nPtr) = opr(ASSIGN,2, id((yyvsp[(1) - (5)].iValue),(yyvsp[(2) - (5)].id)), (yyvsp[(4) - (5)].nPtr));printf("Assign constant value\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 97 "project.y"
    {(yyval.nPtr)=(yyvsp[(1) - (2)].nPtr); printf("Increment\n"); lineIndex++;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 98 "project.y"
    {(yyval.nPtr) = opr(WHILE,2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));printf("While loop\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 99 "project.y"
    {(yyval.nPtr) = opr(DO,2, (yyvsp[(2) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr));printf("Do-while loop\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 102 "project.y"
    {char c[] = {}; sprintf(c,"%d",(yyvsp[(5) - (11)].iValue));(yyval.nPtr) = opr(FOR, 4, opr(ASSIGN, 2, getId((yyvsp[(3) - (11)].id),symbolTable), con(c, 0)), (yyvsp[(7) - (11)].nPtr), (yyvsp[(9) - (11)].nPtr), (yyvsp[(11) - (11)].nPtr));printf("For loop\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 103 "project.y"
    {(yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr));printf("If statement\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 104 "project.y"
    {(yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr));printf("If-else statement\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 105 "project.y"
    {(yyval.nPtr) = opr(SWITCH, 2, getId((yyvsp[(3) - (5)].id),symbolTable), (yyvsp[(5) - (5)].nPtr));printf("Switch case\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 107 "project.y"
    {printf("New scope\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 111 "project.y"
    { char c[] = {}; sprintf(c,"%d",(yyvsp[(1) - (11)].iValue));  (yyval.nPtr)=opr( RET,3,con(c ,0),(yyvsp[(7) - (11)].nPtr),(yyvsp[(9) - (11)].nPtr) ); printf("function\n");printf("Define function\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 112 "project.y"
    { char c[] = {}; sprintf(c,"%d",(yyvsp[(1) - (10)].iValue));  (yyval.nPtr)=opr( RET,3,con(c ,0),(yyvsp[(6) - (10)].nPtr),(yyvsp[(8) - (10)].nPtr) );printf("Define function\n");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 131 "project.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); printf("Block of statements\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 135 "project.y"
    {blockLevel++ ;symbolTable = createChild(symbolTable); printf("Block %d\n", blockLevel);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 136 "project.y"
    {printf("End of block %d\n", blockLevel); symbolTable = deleteChild(symbolTable);  blockLevel--;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 139 "project.y"
    {(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);printf("Switch case block\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 144 "project.y"
    { (yyval.nPtr) = opr(SEMICOLON, 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 148 "project.y"
    {(yyval.nPtr) = opr(PLUS, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 149 "project.y"
    {(yyval.nPtr)= opr(MINUS,2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 150 "project.y"
    {(yyval.nPtr)= opr(MUL, 2 ,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 151 "project.y"
    {(yyval.nPtr)= opr(DIV, 2 ,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 152 "project.y"
    {(yyval.nPtr)= opr(REM, 2 ,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 153 "project.y"
    {(yyval.nPtr)= opr(POWER, 2 ,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 154 "project.y"
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 155 "project.y"
    {(yyval.nPtr)=opr(INCREMENT,1,getId((yyvsp[(1) - (2)].id), symbolTable));}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 156 "project.y"
    {(yyval.nPtr)=opr(DECREMENT,1,getId((yyvsp[(1) - (2)].id), symbolTable));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 160 "project.y"
    {(yyval.nPtr)=opr(INCREMENT,1,getId((yyvsp[(1) - (2)].id), symbolTable));}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 161 "project.y"
    {(yyval.nPtr)=opr(DECREMENT,1,getId((yyvsp[(1) - (2)].id), symbolTable));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 162 "project.y"
    { (yyval.nPtr) = opr(ASSIGN, 2,getId((yyvsp[(1) - (3)].id), symbolTable), opr(PLUS, 2, getId((yyvsp[(1) - (3)].id), symbolTable), (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 163 "project.y"
    { (yyval.nPtr) = opr(ASSIGN, 2,getId((yyvsp[(1) - (3)].id), symbolTable), opr(MINUS, 2, getId((yyvsp[(1) - (3)].id), symbolTable), (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 164 "project.y"
    { (yyval.nPtr) = opr(ASSIGN, 2,getId((yyvsp[(1) - (3)].id), symbolTable), opr(MUL, 2, getId((yyvsp[(1) - (3)].id), symbolTable), (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 165 "project.y"
    { (yyval.nPtr) = opr(ASSIGN, 2,getId((yyvsp[(1) - (3)].id), symbolTable), opr(DIV, 2, getId((yyvsp[(1) - (3)].id), symbolTable), (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 170 "project.y"
    {(yyval.nPtr)=(yyvsp[(1) - (1)].nPtr);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 171 "project.y"
    {(yyval.nPtr) = opr(ASSIGN, 2, getId((yyvsp[(1) - (3)].id),symbolTable), (yyvsp[(3) - (3)].nPtr));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 174 "project.y"
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 175 "project.y"
    { (yyval.nPtr) = opr(OR , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 176 "project.y"
    { (yyval.nPtr) = opr(NOT, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 177 "project.y"
    { (yyval.nPtr) = opr(GREATER, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 178 "project.y"
    { (yyval.nPtr) = opr(LESS, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 179 "project.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 180 "project.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 181 "project.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 182 "project.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 186 "project.y"
    { char c[] = {}; ftoa((yyvsp[(1) - (1)].fValue), c, 6); (yyval.nPtr) = con(c, 1); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 187 "project.y"
    { char c[] = {};sprintf(c,"%d",(yyvsp[(1) - (1)].iValue)); (yyval.nPtr) = con(c, 0); printf("Integer\n");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 188 "project.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].cValue), 2); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 189 "project.y"
    { (yyval.nPtr) = con("false", 4); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 190 "project.y"
    { (yyval.nPtr) = con("true", 4); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 191 "project.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].sValue), 3); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 192 "project.y"
    { (yyval.nPtr) = getId((yyvsp[(1) - (1)].id), symbolTable); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 195 "project.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 196 "project.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 197 "project.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 199 "project.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 202 "project.y"
    { (yyval.nPtr) = opr(DEFAULT, 2, (yyvsp[(3) - (5)].nPtr), opr(BREAK, 0)); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 203 "project.y"
    { char c[] = {}; sprintf(c,"%d",(yyvsp[(2) - (7)].iValue)); (yyval.nPtr) = opr(CASE, 4, con(c, 0), (yyvsp[(4) - (7)].nPtr), opr(BREAK, 0), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 204 "project.y"
    { char c[] = {}; sprintf(c,"%d",(yyvsp[(2) - (5)].iValue)); (yyval.nPtr) = opr(CASE, 3, con(c, 0), (yyvsp[(4) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;



/* Line 1455 of yacc.c  */
#line 2211 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 207 "project.y"
 

nodeType *con(char* value, int type) 
{
    nodeType *p;

    // allocate node
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    // copy information
    p->type = typeCon;
    p->con.value = strdup(value);
    p->con.type=type;
    return p;
}

nodeType * id(int type, char * name)
{

	nodeType *p;
   
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");

    SymbolTableData *data = malloc(sizeof(SymbolTableData));
    if (data != NULL) {
        data->symbolType = type;
        data->symbolInitialized = false;
        data->symbolValue = NULL;
        data->symbolName = strdup(name);
        data->table = symbolTable;
    }

    SymbolTableNode *node = malloc(sizeof(SymbolTableNode));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
	
    insertFirst(symbolTable, node);

    p->type = typeId;
    p->id.table = symbolTable;
    p->id.node = node;
    p->id.name 	= strdup(name);
    p->id.type 	= type;



    return p;
}

nodeType * getId(char * name, SymbolTable * table)
{

    nodeType *p;
    struct SymbolTableNode * node = getSymbolTableNode(symbolTable, name);
    
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)         
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    
    p->id.type 	= node->data->symbolType;
    p->id.name 	= strdup(node->data->symbolName);
    p->id.table = table;
    p->id.node = node;


    return p;
	
}

nodeType *opr(int oper, int nops, ...) 
{
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p)
{
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void reverse(char *str, int len) 
{
	int i=0, j=len-1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int toStr(int x, char str[], int d) 
{
	int i = 0;
	while (x)
	{
		str[i++] = (x%10) + '0';
		x = x/10;
	}
 
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';
 
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char res[], int afterpoint) 
{
	
	// Extract integer part
	int ipart = (int)n;
 
	// Extract floating part
	float fpart = n - (float)ipart;
	
 
	// convert integer part to string
	int i = toStr(ipart, res, 0);
 
	// check for display option after point
	if (afterpoint != 0)
	{
		res[i] = '.';  // add dot
 
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		toStr((int)fpart, res + i + 1, afterpoint);
	}
}

int yyerror(char *s) 
{ 
	fclose(f1);
	remove("output.txt"); 
	f1=fopen("output.txt","w");
	fprintf(f1, "Syntax Error Could not parse quadruples\n"); 
	fprintf(f1, "line number : %d %s\n", yylineno,s);    
 
 	fclose(f2);
	remove("symbol.txt");
	f2 = fopen("symbol.txt","w");
	fprintf(f2, "Syntax Error was Found\n");
 	fprintf(stderr, "line number : %d %s\n", yylineno,s);    
 
	exit(0);
}
 
int yyerrorvar(char *s, char *var) 
{
	fclose(f1);
	remove("output.txt");
	f1 = fopen("output.txt","w");
	fprintf(f1, "Syntax Error Could not parse quadruples\n");
 	fprintf(f1, "line number: %d %s : %s\n", yylineno,s,var);
	
	fclose(f2);
	remove("symbol.txt");
	f2 = fopen("symbol.txt","w");
	fprintf(f2, "Syntax Error was Found\n");
 	fprintf(f2, "line number: %d %s : %s\n", yylineno,s,var);
	
 	exit(0);
}

int main(int argc, char *argv[]) 
{   
    if(argc < 4) {
        printf("Please provide an input file, output file, and symbol file.\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    f1 = fopen(argv[2],"w");
    f2 = fopen(argv[3],"w");
    symbolTable = createSymbolTable();
    if(!yyparse())
    {
        printf("\nParsing complete\n");
        
        printListToFile(symbolTable, f2);
        
    }
    else
    {
        printf("\nParsing failed\n");
        return 0;
    }
    fclose(f1);
    fclose(f2);
    fclose(yyin);
    return 0;
}
