
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
#line 12 "project.y"

#include <stdio.h>   

int yyerror(char *);
int yylex(void);

extern FILE *yyin;
extern int yylineno;


/* Line 189 of yacc.c  */
#line 84 "y.tab.c"

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
     INTEGERNUMBER = 303,
     FLOATNUMBER = 304,
     TEXT = 305,
     CHARACTER = 306,
     IDENTIFIER = 307,
     ASSIGN = 308,
     POWER = 309,
     FALSE = 310,
     TRUE = 311,
     BOOL = 312,
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
#define INTEGERNUMBER 303
#define FLOATNUMBER 304
#define TEXT 305
#define CHARACTER 306
#define IDENTIFIER 307
#define ASSIGN 308
#define POWER 309
#define FALSE 310
#define TRUE 311
#define BOOL 312
#define IFX 313
#define UMINUS 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 244 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   613

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  177

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
       0,     0,     3,     5,     8,     9,    13,    18,    24,    31,
      34,    40,    48,    61,    67,    75,    81,    85,    88,    92,
      95,    97,    99,   108,   113,   117,   118,   123,   124,   128,
     131,   135,   137,   140,   142,   144,   146,   148,   150,   152,
     154,   158,   162,   166,   170,   174,   178,   181,   184,   187,
     190,   193,   197,   201,   205,   209,   211,   215,   219,   223,
     226,   230,   234,   238,   242,   246,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   272,   276,   282
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    62,    63,    -1,    -1,    71,
      52,    14,    -1,    52,    53,    77,    14,    -1,    71,    52,
      53,    77,    14,    -1,    47,    71,    52,    53,    77,    14,
      -1,    73,    14,    -1,    36,    12,    77,    13,    63,    -1,
       8,    68,    36,    12,    77,    13,    14,    -1,    37,    12,
      41,    52,    53,    48,    14,    75,    14,    74,    13,    68,
      -1,    38,    12,    77,    13,    68,    -1,    38,    12,    77,
      13,    68,    39,    68,    -1,     7,    12,    52,    13,    69,
      -1,    40,    77,    14,    -1,    65,    14,    -1,     4,    77,
      14,    -1,     4,    14,    -1,    64,    -1,    68,    -1,    71,
      52,    12,    66,    13,    10,    70,    11,    -1,    52,    12,
      66,    13,    -1,    71,    52,    67,    -1,    -1,     3,    71,
      52,    67,    -1,    -1,    10,    70,    11,    -1,    10,    11,
      -1,    10,    78,    11,    -1,    63,    -1,    70,    63,    -1,
      41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,
      46,    -1,    57,    -1,    77,    28,    77,    -1,    77,    29,
      77,    -1,    77,    30,    77,    -1,    77,    31,    77,    -1,
      77,    32,    77,    -1,    77,    54,    77,    -1,    29,    77,
      -1,    52,    16,    -1,    52,    17,    -1,    52,    16,    -1,
      52,    17,    -1,    52,    18,    77,    -1,    52,    19,    77,
      -1,    52,    20,    77,    -1,    52,    21,    77,    -1,    73,
      -1,    52,    53,    72,    -1,    77,    33,    77,    -1,    77,
      34,    77,    -1,    35,    77,    -1,    77,    22,    77,    -1,
      77,    23,    77,    -1,    77,    24,    77,    -1,    77,    25,
      77,    -1,    77,    27,    77,    -1,    77,    26,    77,    -1,
      49,    -1,    48,    -1,    51,    -1,    55,    -1,    56,    -1,
      50,    -1,    52,    -1,    76,    -1,    72,    -1,    75,    -1,
      65,    -1,    12,    77,    13,    -1,     6,    15,    70,     5,
      14,    -1,     9,    48,    15,    70,     5,    14,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    29,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    57,    61,    65,    66,    70,    71,    76,    77,
      81,    85,    86,    89,    90,    91,    92,    93,    94,    95,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   110,
     111,   112,   113,   114,   115,   120,   121,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   136,   137,   138,   139,
     140,   141,   142,   145,   146,   147,   148,   149,   152,   153
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
  "STRING", "CONST", "INTEGERNUMBER", "FLOATNUMBER", "TEXT", "CHARACTER",
  "IDENTIFIER", "ASSIGN", "POWER", "FALSE", "TRUE", "BOOL", "IFX",
  "UMINUS", "$accept", "program", "function_declaration", "statement",
  "function", "function_call", "argument_list", "continuation",
  "brace_scope", "switch_scope", "statement_list", "datatype",
  "arithmetic_expression", "increment_statement", "for_expression",
  "boolean_expression", "value", "expression", "case_expression", 0
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
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     4,     5,     6,     2,
       5,     7,    12,     5,     7,     5,     3,     2,     3,     2,
       1,     1,     8,     4,     3,     0,     4,     0,     3,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     1,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
      39,     3,    20,     0,    21,     0,     0,     0,    19,     0,
       0,    67,    66,    71,    68,    72,    69,    70,    76,    74,
      75,    73,     0,     0,     0,    29,    31,     0,     0,     0,
       0,     0,     0,    25,    49,    50,     0,     0,     0,     0,
       0,    17,     0,     9,     0,    46,    59,    47,    48,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    32,     0,     0,
       0,    16,     0,     0,     0,    51,    52,    53,    54,     0,
      25,     5,     0,    77,    60,    61,    62,    63,    65,    64,
      40,    41,    42,    43,    44,    57,    58,    45,     0,     0,
       0,     0,     0,     0,    23,    27,     6,     0,     0,     0,
      15,     0,    10,     0,    13,     0,     0,    24,     0,     7,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,    30,    11,     0,    14,    27,     0,     0,     0,    75,
       0,    26,    22,     0,     0,     0,    78,     0,     0,    55,
       0,     0,     0,     0,    79,    74,    12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    46,    22,    38,    93,   137,    24,   130,
      47,    25,    39,    26,   170,    40,    41,   160,   142
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
    -102,    10,   312,  -102,    59,   -10,     3,   133,    20,    29,
      31,   152,  -102,  -102,  -102,  -102,  -102,  -102,   108,    79,
    -102,  -102,  -102,    37,  -102,    -7,    39,   152,  -102,   152,
     152,  -102,  -102,  -102,  -102,     0,  -102,  -102,  -102,  -102,
    -102,  -102,   414,     6,    23,  -102,  -102,   184,   152,    14,
     152,   447,    13,   108,  -102,  -102,   152,   152,   152,   152,
     152,  -102,    -9,  -102,    -4,  -102,    38,  -102,  -102,  -102,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,    43,    78,  -102,  -102,   308,    41,
     348,  -102,    48,    92,    60,   559,   559,   559,   559,   480,
     108,  -102,   152,  -102,    38,    38,    38,    38,    38,    38,
      72,    72,    63,    63,    63,    38,    38,  -102,   103,   152,
     312,    65,     3,   152,  -102,   117,  -102,   111,   513,     5,
    -102,   381,  -102,    73,    89,   546,   108,  -102,   119,  -102,
     115,    83,   122,   120,   121,     3,  -102,    84,   312,   312,
     123,  -102,  -102,   152,  -102,   117,   202,   248,   312,   128,
     559,  -102,  -102,   131,   266,    94,  -102,   146,    19,  -102,
     148,     5,   152,     3,  -102,   149,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,  -102,     2,  -102,    -1,    68,    17,    -6,  -102,
    -101,   -11,    11,    21,  -102,    36,  -102,     4,    22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
      44,    23,    43,   100,    21,   101,    23,    52,    42,   103,
       3,   140,    53,     7,   141,    51,    67,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    64,    48,    65,    66,    54,    55,    56,    57,    58,
      59,    49,    94,    50,   102,    62,    23,   156,   157,    87,
      83,    61,    88,    63,    90,    89,   118,   164,    84,    85,
      95,    96,    97,    98,    99,    92,    76,    77,    78,    79,
      80,    27,   172,    28,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    29,    94,
     119,    53,    83,   121,    30,    54,    55,    56,    57,    58,
      59,   123,    78,    79,    80,   124,   128,    31,    32,    33,
      34,    35,   125,   129,    36,    37,   134,    83,   133,    23,
     136,   144,   132,   131,   138,   147,    83,   135,   145,   148,
     149,   150,    60,   151,   152,   153,   155,     4,   158,   154,
       5,     6,   165,     7,    45,   166,   168,    23,    23,    12,
      13,    14,    15,    16,    17,    23,    23,    23,    87,    87,
     171,   173,   -56,    23,    27,    20,    87,   176,   127,     8,
       9,    10,   161,    11,    12,    13,    14,    15,    16,    17,
      18,    29,     0,   175,     0,    19,   169,    30,     4,   159,
      20,     5,     6,   174,     7,    86,     0,     0,     0,     0,
      31,    32,    33,    34,    35,     0,     4,    36,    37,     5,
       6,     0,     7,   162,     0,     0,     0,     0,     0,     0,
       8,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,     0,     0,    19,     0,     8,     9,
      10,    20,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     4,   163,    19,     5,     6,     0,     7,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,   167,     0,     5,     6,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,     0,     8,     9,    10,    20,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     4,     0,    19,     5,
       6,   120,     7,    20,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     8,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
       0,   122,    83,     0,    19,     0,     0,     0,     0,    20,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,    83,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,    83,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,    83,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,    83,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,    83,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,     0,     0,     0,     0,     0,    83,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
       6,     2,    12,    12,     2,    14,     7,    18,     4,    13,
       0,     6,    12,    10,     9,    11,    16,    17,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    27,    12,    29,    30,    16,    17,    18,    19,    20,
      21,    12,    53,    12,    53,    52,    47,   148,   149,    47,
      54,    14,    48,    14,    50,    41,    13,   158,    52,    36,
      56,    57,    58,    59,    60,    52,    28,    29,    30,    31,
      32,    12,    53,    14,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    29,   100,
      12,    12,    54,    52,    35,    16,    17,    18,    19,    20,
      21,    53,    30,    31,    32,    13,   102,    48,    49,    50,
      51,    52,    52,    10,    55,    56,   122,    54,    53,   120,
       3,    48,   120,   119,    13,   136,    54,   123,    39,    10,
      15,    48,    53,    11,    14,    14,    52,     4,    15,   145,
       7,     8,    14,    10,    11,    14,    52,   148,   149,    41,
      42,    43,    44,    45,    46,   156,   157,   158,   156,   157,
      14,    13,    13,   164,    12,    57,   164,   173,   100,    36,
      37,    38,   155,    40,    41,    42,    43,    44,    45,    46,
      47,    29,    -1,   172,    -1,    52,   165,    35,     4,   153,
      57,     7,     8,   171,    10,    11,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,     4,    55,    56,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    36,    37,
      38,    57,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,     4,     5,    52,     7,     8,    -1,    10,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    36,    37,    38,    57,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,     4,    -1,    52,     7,
       8,    13,    10,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    13,    54,    -1,    52,    -1,    -1,    -1,    -1,    57,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    54,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    54,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     4,     7,     8,    10,    36,    37,
      38,    40,    41,    42,    43,    44,    45,    46,    47,    52,
      57,    63,    64,    65,    68,    71,    73,    12,    14,    29,
      35,    48,    49,    50,    51,    52,    55,    56,    65,    72,
      75,    76,    77,    12,    68,    11,    63,    70,    12,    12,
      12,    77,    71,    12,    16,    17,    18,    19,    20,    21,
      53,    14,    52,    14,    77,    77,    77,    16,    17,    14,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    54,    52,    36,    11,    63,    77,    41,
      77,    14,    52,    66,    71,    77,    77,    77,    77,    77,
      12,    14,    53,    13,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    13,    12,
      13,    52,    13,    53,    13,    52,    14,    66,    77,    10,
      69,    77,    63,    53,    68,    77,     3,    67,    13,    14,
       6,     9,    78,    13,    48,    39,    14,    71,    10,    15,
      48,    11,    14,    14,    68,    52,    70,    70,    15,    75,
      77,    67,    11,     5,    70,    14,    14,     5,    52,    73,
      74,    14,    53,    13,    78,    72,    68
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
        case 5:

/* Line 1455 of yacc.c  */
#line 34 "project.y"
    {printf("Declare variable\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 35 "project.y"
    {printf("Assign value\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 36 "project.y"
    {printf("Declare and initialize variable\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 37 "project.y"
    {printf("Assign constant value\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 38 "project.y"
    {printf("Increment\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 39 "project.y"
    {printf("While loop\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 40 "project.y"
    {printf("Do-while loop\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 44 "project.y"
    {printf("For loop\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 45 "project.y"
    {printf("If statement\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 46 "project.y"
    {printf("If-else statement\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 47 "project.y"
    {printf("Switch case\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 48 "project.y"
    {printf("Print\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 50 "project.y"
    {printf("Return value\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 51 "project.y"
    {printf("Return\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 53 "project.y"
    {printf("New scope\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 57 "project.y"
    {printf("Define function\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 61 "project.y"
    {printf("function call\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 76 "project.y"
    {printf("Block of statements\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 81 "project.y"
    {printf("Switch case block\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 99 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(3) - (3)]);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 100 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) - (yyvsp[(3) - (3)]); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 101 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) * (yyvsp[(3) - (3)]); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 102 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) / (yyvsp[(3) - (3)]); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 103 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) % (yyvsp[(3) - (3)]); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 104 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) % (yyvsp[(3) - (3)]); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 105 "project.y"
    { (yyval) = -(yyvsp[(1) - (2)]); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 106 "project.y"
    { (yyval) = (yyvsp[(1) - (2)])+1; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 107 "project.y"
    { (yyval) = (yyvsp[(1) - (2)])+1; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 110 "project.y"
    { (yyval) = (yyvsp[(1) - (2)])+1; }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 111 "project.y"
    { (yyval) = (yyvsp[(1) - (2)])+1; }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 112 "project.y"
    { (yyvsp[(1) - (3)]) = (yyvsp[(1) - (3)])+(yyvsp[(3) - (3)]); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 113 "project.y"
    { (yyvsp[(1) - (3)]) = (yyvsp[(1) - (3)])-(yyvsp[(3) - (3)]); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 114 "project.y"
    { (yyvsp[(1) - (3)]) = (yyvsp[(1) - (3)])*(yyvsp[(3) - (3)]); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 115 "project.y"
    { (yyvsp[(1) - (3)]) = (yyvsp[(1) - (3)])/(yyvsp[(3) - (3)]); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 120 "project.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 124 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 125 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 126 "project.y"
    { (yyval) = ! (yyvsp[(2) - (2)]); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 127 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) > (yyvsp[(3) - (3)]); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 128 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) < (yyvsp[(3) - (3)]); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 129 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) >= (yyvsp[(3) - (3)]); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 130 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) <= (yyvsp[(3) - (3)]); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 131 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) != (yyvsp[(3) - (3)]); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 132 "project.y"
    { (yyval) = (yyvsp[(1) - (3)]) == (yyvsp[(3) - (3)]); }
    break;



/* Line 1455 of yacc.c  */
#line 1982 "y.tab.c"
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
#line 156 "project.y"
 

int yyerror(char *s) {  
    int lineno = ++yylineno;   
    fprintf(stderr, "Line number : %d %s\n", lineno, s);     
    return 0; 
}

int main(void) {    
    yyin = fopen("input.txt", "r");
    
    if (!yyparse()) {
        printf("\nParsing complete\n");
    } else {
        printf("\nParsing failed\n");
        return 0;
    }
    
    fclose(yyin);
    
    return 0;
}

