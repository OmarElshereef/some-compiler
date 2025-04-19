
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
#line 2 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbolTable.h"

    void yyerror(char* s);
    int yylex();

    _Bool inFunction = 0;


/* Line 189 of yacc.c  */
#line 86 "parser.tab.c"

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
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     FOR = 261,
     DO = 262,
     SWITCH = 263,
     CASE = 264,
     DEFAULT = 265,
     BREAK = 266,
     CONTINUE = 267,
     RETURN = 268,
     CONST = 269,
     INT = 270,
     FLOAT = 271,
     DOUBLE = 272,
     CHAR = 273,
     STRING = 274,
     BOOL = 275,
     VOID = 276,
     TRUE = 277,
     FALSE = 278,
     PLUS = 279,
     MINUS = 280,
     MUL = 281,
     DIV = 282,
     MOD = 283,
     INC = 284,
     DEC = 285,
     ASSIGN = 286,
     ADD_ASSIGN = 287,
     SUB_ASSIGN = 288,
     MUL_ASSIGN = 289,
     DIV_ASSIGN = 290,
     MOD_ASSIGN = 291,
     EQ = 292,
     NEQ = 293,
     LT = 294,
     GT = 295,
     LTE = 296,
     GTE = 297,
     AND = 298,
     OR = 299,
     NOT = 300,
     BIT_AND = 301,
     BIT_OR = 302,
     BIT_XOR = 303,
     COMMENT = 304,
     FUNC = 305,
     ID = 306,
     INT_CONST = 307,
     FLOAT_CONST = 308,
     STRING_CONST = 309,
     CHAR_CONST = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "parser.y"

    char cval;
    char *sval;
    int ival;
    float fval;
    char *id;



/* Line 214 of yacc.c  */
#line 187 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "parser.tab.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    56,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    16,    19,    20,
      23,    24,    27,    28,    32,    33,    36,    37,    40,    42,
      45,    48,    51,    52,    57,    66,    78,    83,    87,    88,
      90,    91,    93,    95,    96,   104,   105,   111,   117,   123,
     125,   126,   130,   132,   135,   138,   141,   143,   148,   153,
     158,   160,   161,   165,   167,   169,   177,   189,   197,   199,
     202,   204,   207,   209,   216,   222,   228,   233,   237,   240,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   266,   270,   274,   278,   282,   286,   290,   294,   298,
     301,   304,   308,   310,   312,   314,   316,   318,   320,   322,
     324,   328,   332,   335,   339,   343,   347,   351,   355,   359,
     363,   366,   369,   371,   373,   375,   377,   379,   381,   383,
     385
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    64,    65,    -1,    -1,    96,    56,    -1,
      95,    56,    -1,    97,    56,    -1,   103,    56,    -1,    -1,
      66,    89,    -1,    -1,    67,    90,    -1,    -1,    68,    72,
      56,    -1,    -1,    69,    77,    -1,    -1,    70,    73,    -1,
      78,    -1,    85,    56,    -1,    84,    56,    -1,    51,    56,
      -1,    -1,    71,    57,    64,    58,    -1,     7,    57,    64,
      58,     5,    59,   104,    60,    -1,     6,    59,    74,    56,
      75,    56,    76,    60,    57,    64,    58,    -1,    15,    51,
      31,    52,    -1,    51,    31,    52,    -1,    -1,   104,    -1,
      -1,   104,    -1,    97,    -1,    -1,     5,    59,   104,    60,
      57,    64,    58,    -1,    -1,    80,    79,    57,    64,    58,
      -1,    21,    51,    59,    81,    60,    -1,    99,    51,    59,
      81,    60,    -1,    82,    -1,    -1,    82,    61,    83,    -1,
      83,    -1,    99,    51,    -1,    13,   104,    -1,    13,    97,
      -1,    13,    -1,    51,    59,    86,    60,    -1,    97,    59,
      86,    60,    -1,    95,    59,    86,    60,    -1,    87,    -1,
      -1,    87,    61,    88,    -1,    88,    -1,   105,    -1,     3,
      59,   104,    60,    57,    64,    58,    -1,     3,    59,   104,
      60,    57,    64,    58,     4,    57,    64,    58,    -1,     8,
      59,    51,    60,    57,    91,    58,    -1,    92,    -1,    92,
      94,    -1,    94,    -1,    92,    93,    -1,    93,    -1,     9,
     105,    62,    64,    11,    56,    -1,    10,    62,    64,    11,
      56,    -1,    14,    99,    51,    31,   104,    -1,    99,    51,
      31,   104,    -1,    14,    99,    51,    -1,    99,    51,    -1,
      51,    98,   104,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    15,    -1,    16,    -1,
      18,    -1,    19,    -1,    20,    -1,   100,    46,   100,    -1,
     100,    47,   100,    -1,   100,    48,   100,    -1,   100,    24,
     100,    -1,   100,    25,   100,    -1,   100,    26,   100,    -1,
     100,    27,   100,    -1,   100,    28,   100,    -1,   100,    29,
      -1,   100,    30,    -1,    59,   100,    60,    -1,    53,    -1,
      52,    -1,    55,    -1,    51,    -1,    22,    -1,    23,    -1,
     100,    -1,    54,    -1,   104,    44,   104,    -1,   104,    43,
     104,    -1,    45,   104,    -1,   101,    37,   101,    -1,   101,
      38,   101,    -1,   101,    39,   101,    -1,   101,    40,   101,
      -1,   101,    41,   101,    -1,   101,    42,   101,    -1,    59,
     102,    60,    -1,    51,    29,    -1,    51,    30,    -1,   101,
      -1,   102,    -1,    51,    -1,    52,    -1,    53,    -1,    55,
      -1,    54,    -1,    22,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    79,    83,    85,    87,    89,    91,    91,
      93,    93,    95,    95,    97,    97,    99,    99,   101,   103,
     105,   107,   109,   109,   113,   117,   121,   123,   125,   129,
     131,   135,   137,   139,   143,   147,   147,   151,   153,   157,
     159,   163,   165,   169,   173,   175,   177,   181,   183,   185,
     189,   191,   195,   197,   201,   205,   207,   211,   215,   217,
     219,   223,   225,   229,   233,   237,   239,   243,   245,   249,
     253,   255,   257,   259,   261,   263,   267,   269,   271,   273,
     275,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307,   309,   311,   315,   317,
     321,   323,   325,   327,   329,   331,   333,   335,   337,   339,
     343,   345,   349,   351,   356,   358,   360,   362,   364,   366,
     368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "DO",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "CONST",
  "INT", "FLOAT", "DOUBLE", "CHAR", "STRING", "BOOL", "VOID", "TRUE",
  "FALSE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "INC", "DEC", "ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "AND", "OR", "NOT", "BIT_AND",
  "BIT_OR", "BIT_XOR", "COMMENT", "FUNC", "ID", "INT_CONST", "FLOAT_CONST",
  "STRING_CONST", "CHAR_CONST", "';'", "'{'", "'}'", "'('", "')'", "','",
  "':'", "$accept", "program", "statement", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "do_loop", "for_loop", "for_loop_initialization",
  "for_loop_condition", "for_loop_increment", "while_loop",
  "function_definition", "$@7", "function_declaration_prototype",
  "function_parameters_optional", "function_parameters",
  "function_parameter", "return_statement", "function_call",
  "function_arguments_optional", "function_arguments", "function_argument",
  "if_statement", "switch_statement", "switch_program", "case_statements",
  "case_statement", "default_statement", "initialization", "declaration",
  "assignment", "assign", "type", "evaluate_expression", "math_or_value",
  "condition", "unary_expression", "expression", "literal", 0
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
     305,   306,   307,   308,   309,   310,    59,   123,   125,    40,
      41,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    65,    65,    66,    65,
      67,    65,    68,    65,    69,    65,    70,    65,    65,    65,
      65,    65,    71,    65,    72,    73,    74,    74,    74,    75,
      75,    76,    76,    76,    77,    79,    78,    80,    80,    81,
      81,    82,    82,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    89,    89,    90,    91,    91,
      91,    92,    92,    93,    94,    95,    95,    96,    96,    97,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     2,     0,     2,
       0,     2,     0,     3,     0,     2,     0,     2,     1,     2,
       2,     2,     0,     4,     8,    11,     4,     3,     0,     1,
       0,     1,     1,     0,     7,     0,     5,     5,     5,     1,
       0,     3,     1,     2,     2,     2,     1,     4,     4,     4,
       1,     0,     3,     1,     1,     7,    11,     7,     1,     2,
       1,     2,     1,     6,     5,     5,     4,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     8,     1,    46,     0,    76,    77,    78,    79,    80,
       0,     0,     2,     0,     0,     0,     0,     0,     0,    18,
      35,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    95,    93,    92,    99,    94,     0,    45,    98,   112,
     113,    44,     0,     0,   110,   111,    70,    71,    72,    73,
      74,    75,    21,    51,     0,     0,     9,     0,    11,     0,
       0,     0,    15,     0,    17,     3,     0,    20,    19,     5,
      51,     4,     6,    51,    68,     7,    95,   102,    98,   113,
       0,     0,     0,     0,     0,     0,    89,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      40,   119,   120,   114,   115,   116,   118,   117,     0,    50,
      53,    54,    69,     0,     0,     3,    13,     0,    28,     8,
       3,     0,     0,     0,    40,    91,   109,     0,    84,    85,
      86,    87,    88,    81,    82,    83,   103,   104,   105,   106,
     107,   108,   101,   100,     0,     0,    39,    42,     0,    47,
       0,     0,     0,     8,     0,     0,     0,     0,    23,     8,
      49,    48,    66,     0,     0,    65,    37,     0,    43,    52,
       0,     0,     0,     0,     0,     0,    30,    36,    38,    41,
       3,     0,     0,     3,     0,    27,     0,    29,     8,     0,
       0,     0,    58,    62,    60,     0,     8,    26,    33,    55,
       0,     3,    57,    61,    59,     0,    34,     0,    32,    31,
       0,     3,     8,    24,     0,     3,     8,     0,     3,     8,
       0,    64,     8,    56,    63,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    17,    18,    60,
      64,   157,   186,   207,    62,    19,    66,    20,   145,   146,
     147,    21,    22,   108,   109,   110,    56,    58,   191,   192,
     193,   194,    23,    24,    25,    54,    26,    38,    39,    40,
      27,    41,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
     -63,    22,   -63,    38,    62,   -63,   -63,   -63,   -63,   -63,
     -45,   384,   -63,    10,    11,    16,    26,    33,    -8,   -63,
     -63,    -5,     0,   -51,     1,   -39,     8,     6,   -63,   -63,
     109,   414,   -63,   -63,   -63,   -63,   109,   -63,   204,   415,
     -63,   -32,    25,    28,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   357,   109,    36,   -63,    37,   -63,    44,
      50,    49,   -63,    51,   -63,   -63,    55,   -63,   -63,   -63,
     357,   -63,   -63,   357,   -27,   -63,   -63,   -63,   347,    53,
     -32,    52,    52,    52,    52,    52,   -63,   -63,    52,    52,
      52,    -7,    -7,    -7,    -7,    -7,    -7,   109,   109,    83,
      62,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    57,    58,
     -63,   -63,   -32,   109,    69,   -63,   -63,   109,    -1,   122,
     -63,    63,    64,   109,    62,   -63,   -63,    52,   212,   212,
       4,     4,     4,   405,   398,   285,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,    82,   109,    66,    72,   -63,    93,   -63,
     357,   -34,    74,   169,    42,    94,   115,    92,   -63,   186,
     -63,   -63,   -32,    90,   347,   -32,   -63,    62,   -63,   -63,
      95,    98,   146,   100,   127,   107,   109,   -63,   -63,   -63,
     -63,    45,   108,   -63,   118,   -63,   116,   -32,   203,   357,
     119,   113,    45,   -63,   -63,   109,   250,   -63,    38,   174,
     124,   -63,   -63,   -63,   -63,    56,   -63,   136,   -63,   -32,
     140,   -63,   332,   -63,   141,   -63,   349,   147,   -63,   267,
     156,   -63,   284,   -63,   -63,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -62,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    89,   -63,
      47,   -63,   -63,   -49,   -63,    65,   -63,   -63,   -63,   -63,
      43,    54,   -63,   -63,    -3,   -63,    -2,   -18,   367,   189,
     -63,   -29,    59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -23
static const yytype_int16 yytable[] =
{
      37,    77,    42,   119,   123,    69,    43,    80,    70,    97,
      98,    97,    98,    55,   155,    28,    29,    72,    78,    57,
      73,   121,     2,    59,   122,   112,   170,   -14,   -16,   -12,
     -10,    61,   124,    86,    87,     3,     4,     5,     6,    63,
       7,     8,     9,    10,    76,    32,    33,    34,    35,    65,
     156,    67,   127,   153,   189,   190,    68,    71,   159,    74,
      28,    29,    75,   128,   129,   130,   131,   132,   142,   143,
     133,   134,   135,    11,    28,    29,    99,     5,     6,   -22,
       7,     8,     9,    30,   151,    97,    98,   100,   154,    31,
      32,    33,    34,    35,   162,   113,   114,    36,   148,    97,
      98,   115,   173,    76,    32,    33,   116,    35,   117,   164,
     118,   127,   120,   126,   144,   165,   213,   149,   188,   150,
     152,   196,   148,   160,   161,    97,   166,   -14,   -16,   -12,
     -10,    28,    29,   167,   171,     3,     4,     5,     6,   212,
       7,     8,     9,    10,   168,   174,   175,   187,   176,   216,
     178,   182,   180,   219,    30,   181,   222,   183,   184,   185,
      76,    32,    33,    34,    35,   148,   205,   195,    36,   209,
     197,   202,   198,    11,   -14,   -16,   -12,   -10,   210,   -22,
     158,   201,     3,     4,     5,     6,   211,     7,     8,     9,
      10,   -14,   -16,   -12,   -10,   208,   214,   215,   218,     3,
       4,     5,     6,   221,     7,     8,     9,    10,   -14,   -16,
     -12,   -10,   224,   163,   179,   169,     3,     4,     5,     6,
      11,     7,     8,     9,    10,    79,   -22,   172,    81,    82,
      83,    84,    85,    86,    87,   203,     0,    11,    83,    84,
      85,    86,    87,   -22,   177,     0,   204,     0,   200,     0,
      88,    89,    90,     0,    11,   -14,   -16,   -12,   -10,     0,
     -22,   199,     0,     3,     4,     5,     6,     0,     7,     8,
       9,    10,   -14,   -16,   -12,   -10,     0,     0,     0,     0,
       3,     4,     5,     6,     0,     7,     8,     9,    10,   -14,
     -16,   -12,   -10,     0,     0,     0,     0,     3,     4,     5,
       6,    11,     7,     8,     9,    10,     0,   -22,   206,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    11,     0,
       0,     0,     0,     0,   -22,   223,     0,     0,     0,     0,
       0,    88,    89,     0,     0,    11,     0,   -14,   -16,   -12,
     -10,   -22,   225,   217,     0,     3,     4,     5,     6,     0,
       7,     8,     9,    10,   -14,   -16,   -12,   -10,     0,     0,
     220,     0,     3,     4,     5,     6,     0,     7,     8,     9,
      10,    81,    82,    83,    84,    85,    86,    87,     0,   101,
     102,     0,     0,    11,     0,     0,     0,     0,     0,   -22,
       0,     0,     0,    88,    89,    90,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,   -22,   125,   103,   104,
     105,   106,   107,    44,    45,    46,    47,    48,    49,    50,
      51,     0,    81,    82,    83,    84,    85,    86,    87,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      52,     0,     0,    53,    88,    46,    47,    48,    49,    50,
      51,     0,    91,    92,    93,    94,    95,    96,   136,   137,
     138,   139,   140,   141
};

static const yytype_int16 yycheck[] =
{
       3,    30,     4,    65,    31,    56,    51,    36,    59,    43,
      44,    43,    44,     3,    15,    22,    23,    56,    36,     8,
      59,    70,     0,     7,    73,    54,    60,     5,     6,     7,
       8,     5,    59,    29,    30,    13,    14,    15,    16,     6,
      18,    19,    20,    21,    51,    52,    53,    54,    55,    57,
      51,    56,    59,   115,     9,    10,    56,    56,   120,    51,
      22,    23,    56,    81,    82,    83,    84,    85,    97,    98,
      88,    89,    90,    51,    22,    23,    51,    15,    16,    57,
      18,    19,    20,    45,   113,    43,    44,    59,   117,    51,
      52,    53,    54,    55,   123,    59,    59,    59,   100,    43,
      44,    57,    60,    51,    52,    53,    56,    55,    59,   127,
      59,    59,    57,    60,    31,   144,    60,    60,   180,    61,
      51,   183,   124,    60,    60,    43,    60,     5,     6,     7,
       8,    22,    23,    61,    60,    13,    14,    15,    16,   201,
      18,    19,    20,    21,    51,    51,    31,   176,    56,   211,
      60,     5,    57,   215,    45,    57,   218,    57,    31,    52,
      51,    52,    53,    54,    55,   167,   195,    59,    59,   198,
      52,    58,    56,    51,     5,     6,     7,     8,     4,    57,
      58,    62,    13,    14,    15,    16,    62,    18,    19,    20,
      21,     5,     6,     7,     8,   198,    60,    57,    57,    13,
      14,    15,    16,    56,    18,    19,    20,    21,     5,     6,
       7,     8,    56,   124,   167,   150,    13,    14,    15,    16,
      51,    18,    19,    20,    21,    36,    57,    58,    24,    25,
      26,    27,    28,    29,    30,   192,    -1,    51,    26,    27,
      28,    29,    30,    57,    58,    -1,   192,    -1,   189,    -1,
      46,    47,    48,    -1,    51,     5,     6,     7,     8,    -1,
      57,    58,    -1,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    51,    18,    19,    20,    21,    -1,    57,    58,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    51,    -1,     5,     6,     7,
       8,    57,    58,    11,    -1,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,     5,     6,     7,     8,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    24,    25,    26,    27,    28,    29,    30,    -1,    22,
      23,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    60,    51,    52,
      53,    54,    55,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    24,    25,    26,    27,    28,    29,    30,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    46,    31,    32,    33,    34,    35,
      36,    -1,    37,    38,    39,    40,    41,    42,    91,    92,
      93,    94,    95,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,     0,    13,    14,    15,    16,    18,    19,    20,
      21,    51,    65,    66,    67,    68,    69,    70,    71,    78,
      80,    84,    85,    95,    96,    97,    99,   103,    22,    23,
      45,    51,    52,    53,    54,    55,    59,    97,   100,   101,
     102,   104,    99,    51,    29,    30,    31,    32,    33,    34,
      35,    36,    56,    59,    98,     3,    89,     8,    90,     7,
      72,     5,    77,     6,    73,    57,    79,    56,    56,    56,
      59,    56,    56,    59,    51,    56,    51,   104,   100,   102,
     104,    24,    25,    26,    27,    28,    29,    30,    46,    47,
      48,    37,    38,    39,    40,    41,    42,    43,    44,    51,
      59,    22,    23,    51,    52,    53,    54,    55,    86,    87,
      88,   105,   104,    59,    59,    57,    56,    59,    59,    64,
      57,    86,    86,    31,    59,    60,    60,    59,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   104,   104,    31,    81,    82,    83,    99,    60,
      61,   104,    51,    64,   104,    15,    51,    74,    58,    64,
      60,    60,   104,    81,   100,   104,    60,    61,    51,    88,
      60,    60,    58,    60,    51,    31,    56,    58,    60,    83,
      57,    57,     5,    57,    31,    52,    75,   104,    64,     9,
      10,    91,    92,    93,    94,    59,    64,    52,    56,    58,
     105,    62,    58,    93,    94,   104,    58,    76,    97,   104,
       4,    62,    64,    60,    60,    57,    64,    11,    57,    64,
      11,    56,    64,    58,    56,    58
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
        case 2:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { printf("Declaration\n"); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { printf("Initialization\n"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    { printf("Assignment\n"); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { printf("Unary Expression\n"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { printf("If statement start\n"); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { printf("If statement end\n"); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { printf("Switch case start\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { printf("Switch case end\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { printf("Do while loop start\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { printf("Do while loop end\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { printf("While loop start\n"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { printf("While loop end\n"); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { printf("For loop start\n"); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { printf("For loop end\n"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { printf("Function_definition\n"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { printf("Function_call\n"); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { if (!(inFunction)) yyerror("Return statement outside function"); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { printf("ID\n"); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    { printf("Scope start\n"); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    { printf("Scope end\n"); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { inFunction = 1; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { inFunction = 0; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {;;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { printf("ASSIGN\n"); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { printf("ADD_ASSIGN\n"); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    { printf("SUB_ASSIGN\n"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { printf("MUL_ASSIGN\n"); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    { printf("DIV_ASSIGN\n"); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { printf("MOD_ASSIGN\n"); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    { ; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { ; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { ; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { ; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    { ; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    { printf("BIT_AND\n"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 281 "parser.y"
    { printf("BIT_OR\n"); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    { printf("BIT_XOR\n"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    { printf("PLUS\n"); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    { printf("MINUS\n"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    { printf("MUL\n"); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    { printf("DIV\n"); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { printf("MOD\n"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    { printf("INC\n"); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    { printf("DEC\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 301 "parser.y"
    {;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {;;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    {;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    {;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    {;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { printf("OR\n"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { printf("AND\n"); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { printf("NOT\n"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    { printf("EQ\n"); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { printf("NEQ\n"); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    { printf("LT\n"); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    { printf("GT\n"); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    { printf("LTE\n"); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    { printf("GTE\n"); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    {;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    {;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    {;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    {;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 362 "parser.y"
    {;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {;;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    {;;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    {;;}
    break;



/* Line 1455 of yacc.c  */
#line 2427 "parser.tab.c"
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
#line 370 "parser.y"



/* Error handling */
void yyerror(char *msg){
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

int main(int argc, char *argv[]){

    extern FILE* yyin;
    char* filename = argv[1];
    FILE* file = fopen(filename,"r");
    if(!file)
    {
        printf("File Error\n");
    }
    yyin = file;

    yyparse();

    return 0;
}
