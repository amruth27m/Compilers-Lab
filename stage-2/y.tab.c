/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "static.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE tnode*
#include "exprtree.h"
#include "exprtree.c"
extern int ylineno;

#line 75 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEG = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    ID = 262,
    CONSTANT = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    ENDWHILE = 269,
    DO = 270,
    CONTINUE = 271,
    BREAK = 272,
    DECL = 273,
    ENDDECL = 274,
    INT = 275,
    STR = 276,
    PLUS = 277,
    MIN = 278,
    MUL = 279,
    DIV = 280,
    LT = 281,
    LTE = 282,
    GT = 283,
    GTE = 284,
    EQ = 285,
    NEQ = 286
  };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define READ 260
#define WRITE 261
#define ID 262
#define CONSTANT 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define ENDWHILE 269
#define DO 270
#define CONTINUE 271
#define BREAK 272
#define DECL 273
#define ENDDECL 274
#define INT 275
#define STR 276
#define PLUS 277
#define MIN 278
#define MUL 279
#define DIV 280
#define LT 281
#define LTE 282
#define GT 283
#define GTE 284
#define EQ 285
#define NEQ 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    34,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    15,    15,    22,    30,    40,    41,    44,    45,    48,
      50,    51,    53,    54,    55,    56,    57,    58,    59,    60,
      63,    64,    67,    69,    70,    72,    73,    76,    79,    80,
      83,    84,    86,    88,    89,    92,    95,    99,   100,   104,
     105,   106,   107,   108,   109,   110,   112,   113,   114,   115,
     116,   117,   118,   120,   122,   123,   124,   125,   126,   127,
     128,   131,   132,   134,   135,   137,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   165,   166
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "READ", "WRITE", "ID",
  "CONSTANT", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "DO",
  "CONTINUE", "BREAK", "DECL", "ENDDECL", "INT", "STR", "PLUS", "MIN",
  "MUL", "DIV", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "'\\n'", "';'",
  "' '", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "'='", "$accept",
  "program", "GDeclBlock", "Declist", "Decl", "Type", "Varlist",
  "FdefBlock", "Fdef", "LMainBlock", "ParamList", "Param", "LdeclBlock",
  "LdeclList", "Ldecl", "IDList", "MainBlock", "slist", "stmt",
  "inputstmt", "outputstmt", "assignstmt", "breakstmt", "continuestmt",
  "ifstmt", "whilestmt", "E", "f", "Arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    10,    59,    32,    44,    91,    93,    40,    41,
     123,   125,    61
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    24,    39,   116,     4,   -82,    48,    73,   -82,   -82,
     -82,    42,   118,    69,   -82,    87,    84,    85,   -26,    86,
      89,   -82,   -82,   121,    96,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,    98,   109,    99,   104,   124,   -82,   -82,   -82,
     132,    13,    19,    13,    13,    13,   108,   110,   -82,   111,
     112,   134,   113,    36,   -25,   -82,    13,   114,     6,   115,
     117,   -82,   119,   120,   -82,    53,   -82,    69,    49,   -82,
      69,    91,   -82,    93,    11,   122,   -82,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    31,    32,   135,
     131,   -82,   -82,   134,   139,    69,   123,   125,   127,   126,
     128,   129,   130,   -82,   133,   136,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,    95,    13,    97,
      13,   137,   138,   -82,   140,   141,   142,   143,    69,    47,
      52,   145,   146,    13,   -82,   147,   148,   -82,   149,   150,
     -82,    53,    53,    71,   144,   -82,   156,   -82,   101,   -82,
     103,   -82,   105,   107,   -82,   151,   152,   154,   155,   106,
     157,   134,   164,   134,   158,   153,   161,   162,   163,   165,
     166,   167,   168,    13,    13,    13,    13,   159,   -82,   -82,
     -82,   169,   -82,   160,    53,   170,   171,   172,   173,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,    53,   178,    76,
     174,   -82,   -82,   -82,   -82,   -82,   177,   134,   176,   194,
     195,    69,   184,   -82,   -82,   -82,   182,   -82,   186,   -82,
     -82,   194,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,     1,    10,
      11,     0,     0,    21,     3,     0,     0,     0,     0,     0,
       0,    62,    61,     0,     0,    39,    40,    41,    44,    45,
      42,    43,     0,     0,     0,     0,     0,     2,    20,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,    78,    85,     0,     0,    76,     0,
       0,    54,     0,     0,    35,    38,     5,     8,    17,     9,
       0,     0,    46,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     7,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,    86,    89,     0,    77,    66,    67,    69,
      68,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,    80,    79,     0,    87,     0,     0,    56,     0,     0,
      55,     0,     0,    15,    18,    27,     0,    25,     0,    48,
       0,    47,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    65,
      13,     0,    19,     0,    24,     0,     0,     0,     0,    84,
      82,    83,    81,    58,    59,    60,    57,     0,    16,     0,
       0,    23,    50,    52,    51,    49,     0,     0,     0,     0,
       0,    31,     0,    64,    14,    29,    34,    32,     0,    30,
      22,     0,    28,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,    81,   -82,    -4,   -81,   206,   -82,   -82,
     -80,   -82,   -82,   -61,   -82,   -66,    10,   -64,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -39,   -82,    23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    33,    34,    96,    69,    12,    13,   200,
      97,    98,   184,   210,   211,   217,     5,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   104,    58,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    91,    57,    35,    61,    62,    63,     1,     1,    11,
      42,    73,   123,    74,    14,   125,    43,    75,    54,    55,
      54,    55,    37,     2,     9,    10,    59,    60,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   147,    56,
     103,    56,    15,    16,    17,    18,     6,    19,    16,    17,
      18,    20,    19,    35,    21,    22,    20,   117,   119,    21,
      22,     7,    71,   118,   120,    72,    36,   159,   160,   137,
     180,   140,   182,   148,    93,    94,   149,    95,   150,     9,
      10,   151,    32,     9,    10,   208,     9,    10,    99,   100,
     101,   102,   135,   136,   138,   139,   161,   162,   165,   166,
     167,   168,   169,   170,   171,   172,     8,   177,   178,    39,
     201,     1,    40,    41,    44,    46,   214,    45,    49,    47,
      48,    52,    50,   206,   193,   194,   195,   196,    51,    53,
      64,    68,    65,    66,    67,   121,   122,   124,    92,   145,
     219,    70,    87,    76,    88,   223,   154,   126,    89,    90,
       0,   106,   128,   129,   127,   130,   131,   132,   133,   141,
     142,   179,   181,     0,     0,   134,   183,   143,     0,   163,
     144,   152,   153,   146,   155,   156,   157,   158,   164,   213,
     185,   197,   199,   173,   174,   209,   175,   176,   186,   187,
     188,   216,   189,   190,   191,   192,   198,   209,   215,   202,
     203,   204,   205,   207,   218,   212,   220,   221,   222,    38
};

static const yytype_int16 yycheck[] =
{
       4,    65,    41,     7,    43,    44,    45,     3,     3,    13,
      36,    36,    93,    38,     4,    95,    42,    56,     7,     8,
       7,     8,    12,    18,    20,    21,     7,     8,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   128,    38,
      39,    38,     4,     5,     6,     7,    32,     9,     5,     6,
       7,    13,     9,    67,    16,    17,    13,    36,    36,    16,
      17,    32,    36,    42,    42,    39,    34,   141,   142,   118,
     161,   120,   163,    36,    35,    36,    39,    38,    36,    20,
      21,    39,    19,    20,    21,    19,    20,    21,     7,     8,
       7,     8,     7,     8,     7,     8,    35,    36,     7,     8,
       7,     8,     7,     8,     7,     8,     0,    11,    12,    32,
     184,     3,    38,    38,    38,     4,   207,    38,    19,    33,
      32,     7,    33,   197,   173,   174,   175,   176,    34,     7,
      32,     7,    32,    32,    32,    10,    15,     8,    67,     7,
     211,    38,    37,    39,    37,   221,   133,    34,    39,    39,
      -1,    39,    35,    37,    39,    37,    37,    37,    35,    32,
      32,    14,     8,    -1,    -1,    39,    18,    37,    -1,    35,
      39,    36,    36,    40,    37,    37,    37,    37,    32,    12,
      37,    32,    32,    42,    42,   199,    42,    42,    37,    37,
      37,     7,    37,    37,    37,    37,    37,   211,    32,    39,
      39,    39,    39,    35,    19,    41,    32,    35,    32,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    18,    44,    45,    59,    32,    32,     0,    20,
      21,    48,    50,    51,    59,     4,     5,     6,     7,     9,
      13,    16,    17,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    19,    46,    47,    48,    34,    59,    50,    32,
      38,    38,    36,    42,    38,    38,     4,    33,    32,    19,
      33,    34,     7,     7,     7,     8,    38,    69,    70,     7,
       8,    69,    69,    69,    32,    32,    32,    32,     7,    49,
      38,    36,    39,    36,    38,    69,    39,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    37,    37,    39,
      39,    60,    46,    35,    36,    38,    48,    53,    54,     7,
       8,     7,     8,    39,    69,    71,    39,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    36,    42,    36,
      42,    10,    15,    49,     8,    53,    34,    39,    35,    37,
      37,    37,    37,    35,    39,     7,     8,    69,     7,     8,
      69,    32,    32,    37,    39,     7,    40,    53,    36,    39,
      36,    39,    36,    36,    71,    37,    37,    37,    37,    60,
      60,    35,    36,    35,    32,     7,     8,     7,     8,     7,
       8,     7,     8,    42,    42,    42,    42,    11,    12,    14,
      49,     8,    49,    18,    55,    37,    37,    37,    37,    37,
      37,    37,    37,    69,    69,    69,    69,    32,    37,    32,
      52,    60,    39,    39,    39,    39,    60,    35,    19,    48,
      56,    57,    41,    12,    49,    32,     7,    58,    19,    56,
      32,    35,    32,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      50,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    64,    64,    64,    64,
      64,    65,    66,    67,    67,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     5,     4,     4,     3,     3,
       1,     1,     3,     6,     9,     4,     7,     1,     4,     6,
       2,     1,    12,     1,     0,     3,     1,     3,     5,     4,
       2,     1,     2,     3,     1,     5,     4,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     7,    10,
      10,    10,    10,     4,     3,     6,     6,     9,     9,     9,
       9,     1,     1,     8,    11,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     4,
       4,     7,     7,     7,     7,     1,     3,     4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 15 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);
		printf("successfully evaluated the source code\n");
		FILE *fp = fopen("out","w");
		codeGen((yyval),fp);
		printSymbolTable();
		exit(1);
	}
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 22 "static.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[0]);
		printf("successfully evaluated the source code\n");
		FILE *fp = fopen("out","w");
		codeGen((yyval),fp);
		printSymbolTable();
		exit(1);
	}
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 30 "static.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[0]);
		printf("successfully evaluated the source code\n");
		FILE *fp = fopen("out","w");
		codeGen((yyval),fp);
		printSymbolTable();
		exit(1);
	}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 40 "static.y" /* yacc.c:1646  */
    { printf("successfully constructed symbol table\n");}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 41 "static.y" /* yacc.c:1646  */
    { printf("successfully constructed symbol table\n"); }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-3]);}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]);printf("Single decl");}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "static.y" /* yacc.c:1646  */
    {createDeclarations((yyvsp[-2]),(yyvsp[0]));printf("type varlist");}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 51 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "static.y" /* yacc.c:1646  */
    {(yyval) = linkVarNode((yyvsp[-2]),(yyvsp[0]));}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "static.y" /* yacc.c:1646  */
    {(yyval) = linkArrayNode((yyvsp[-5]),(yyvsp[-3])->val,(yyvsp[0]));}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 55 "static.y" /* yacc.c:1646  */
    {(yyval) = linkMatrixNode((yyvsp[-8]),(yyvsp[-6])->val,(yyvsp[-3])->val,(yyvsp[0]));}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 56 "static.y" /* yacc.c:1646  */
    {(yyval) = createArrayNode((yyvsp[-3]),(yyvsp[-1])->val);}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 57 "static.y" /* yacc.c:1646  */
    {(yyval) = createMatrixNode((yyvsp[-6]),(yyvsp[-4])->val,(yyvsp[-1])->val);}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 58 "static.y" /* yacc.c:1646  */
    {/*$$ = createVarNode($1);*/}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 59 "static.y" /* yacc.c:1646  */
    {(yyval)= createFunctionNode((yyvsp[-3]),(yyvsp[-1])->param);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 60 "static.y" /* yacc.c:1646  */
    {(yyval) = linkFunctionNode((yyvsp[-5]),(yyvsp[-3])->param,(yyvsp[0]));}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 63 "static.y" /* yacc.c:1646  */
    {}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 64 "static.y" /* yacc.c:1646  */
    {}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 67 "static.y" /* yacc.c:1646  */
    {}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 69 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 70 "static.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 72 "static.y" /* yacc.c:1646  */
    {(yyval) = appendParameterList((yyvsp[-2]),(yyvsp[0]));}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 73 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 76 "static.y" /* yacc.c:1646  */
    { (yyval) = createParameterList(1,(yyvsp[0])->varname); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 79 "static.y" /* yacc.c:1646  */
    {}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 80 "static.y" /* yacc.c:1646  */
    {}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 83 "static.y" /* yacc.c:1646  */
    {}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 84 "static.y" /* yacc.c:1646  */
    {}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 86 "static.y" /* yacc.c:1646  */
    {}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 88 "static.y" /* yacc.c:1646  */
    {}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 89 "static.y" /* yacc.c:1646  */
    {}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 92 "static.y" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-2]);
	}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "static.y" /* yacc.c:1646  */
    {
	(yyval) = NULL;	
	}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 99 "static.y" /* yacc.c:1646  */
    { (yyval) = createTreeNode(0,3,NULL,NULL,(yyvsp[-3]),(yyvsp[0]));}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 100 "static.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 104 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 105 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 106 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 107 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 108 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 109 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 110 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 112 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-1]),NULL);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 113 "static.y" /* yacc.c:1646  */
    {(yyvsp[-4]) = appendConstantVal((yyvsp[-4]),(yyvsp[-2])->val); (yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-4]),NULL);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 114 "static.y" /* yacc.c:1646  */
    {(yyvsp[-4]) = appendVariableVal((yyvsp[-4]),(yyvsp[-2])->varname); (yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-4]),NULL);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 115 "static.y" /* yacc.c:1646  */
    {(yyvsp[-7]) = appendDoubleConst((yyvsp[-7]),(yyvsp[-5])->val,(yyvsp[-2])->val); (yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-7]),NULL);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 116 "static.y" /* yacc.c:1646  */
    {(yyvsp[-7]) = appendDoubleVar((yyvsp[-7]), (yyvsp[-5])->varname,(yyvsp[-2])->varname); (yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-7]),NULL);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 117 "static.y" /* yacc.c:1646  */
    {(yyvsp[-7]) = appendConstVar((yyvsp[-7]), (yyvsp[-5])->val,(yyvsp[-2])->varname);(yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-7]),NULL);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 118 "static.y" /* yacc.c:1646  */
    {(yyvsp[-7]) = appendVarConst((yyvsp[-7]),(yyvsp[-5])->varname,(yyvsp[-2])->val);(yyval) = createTreeNode(0,5,NULL,'r',(yyvsp[-7]),NULL);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 120 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,5,NULL,'w',(yyvsp[-1]),NULL);}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 122 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-2]),(yyvsp[0]));}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 123 "static.y" /* yacc.c:1646  */
    {(yyvsp[-5]) = appendConstantVal((yyvsp[-5]),(yyvsp[-3])->val); (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-5]),(yyvsp[0]));}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 124 "static.y" /* yacc.c:1646  */
    {(yyvsp[-5]) = appendVariableVal((yyvsp[-5]),(yyvsp[-3])->varname); (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-5]),(yyvsp[0]));}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 125 "static.y" /* yacc.c:1646  */
    {(yyvsp[-8]) = appendDoubleConst((yyvsp[-8]),(yyvsp[-6])->val,(yyvsp[-3])->val);  (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-8]),(yyvsp[0]));}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 126 "static.y" /* yacc.c:1646  */
    {(yyvsp[-8]) = appendDoubleVar((yyvsp[-8]),(yyvsp[-6])->varname,(yyvsp[-3])->varname); (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-8]),(yyvsp[0]));}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 127 "static.y" /* yacc.c:1646  */
    {(yyvsp[-8]) = appendVarConst((yyvsp[-8]),(yyvsp[-6])->varname,(yyvsp[-3])->val);  (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-8]),(yyvsp[0]));}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 128 "static.y" /* yacc.c:1646  */
    {(yyvsp[-8]) = appendConstVar((yyvsp[-8]),(yyvsp[-6])->val,(yyvsp[-3])->varname); (yyval) = createTreeNode(0,2,NULL,'=',(yyvsp[-8]),(yyvsp[0]));}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 131 "static.y" /* yacc.c:1646  */
    {(yyval) = createBreakNode(BREAK_STATEMENT);}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 132 "static.y" /* yacc.c:1646  */
    {(yyval) = createBreakNode(CONTINUE_STATEMENT);}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 134 "static.y" /* yacc.c:1646  */
    {(yyval) = createConditionalNode(CIF_ELSE,(yyvsp[-5]),(yyvsp[-1]),NULL);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "static.y" /* yacc.c:1646  */
    {(yyval) = createConditionalNode(CIF,(yyvsp[-8]),(yyvsp[-4]),(yyvsp[-1]));}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 137 "static.y" /* yacc.c:1646  */
    {(yyval) = createConditionalNode(CWHILE,(yyvsp[-5]),NULL,(yyvsp[-1])); }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 139 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,2,NULL,'+',(yyvsp[-2]),(yyvsp[0]));}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 140 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,2,NULL,'-',(yyvsp[-2]),(yyvsp[0]));}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 141 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,2,NULL,'/',(yyvsp[-2]),(yyvsp[0]));}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 142 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,2,NULL,'*',(yyvsp[-2]),(yyvsp[0]));}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 143 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CLT,(yyvsp[-2]),(yyvsp[0]));}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 144 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CLTE,(yyvsp[-2]),(yyvsp[0])); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 145 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CGT,(yyvsp[-2]),(yyvsp[0]));}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 146 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CGTE,(yyvsp[-2]),(yyvsp[0]));}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 147 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CEQ,(yyvsp[-2]),(yyvsp[0]));}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 148 "static.y" /* yacc.c:1646  */
    {(yyval) = createTreeNode(0,4,NULL,CNEQ,(yyvsp[-2]),(yyvsp[0]));}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 149 "static.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 150 "static.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 153 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 154 "static.y" /* yacc.c:1646  */
    {(yyvsp[-3]) = appendConstantVal((yyvsp[-3]),(yyvsp[-1])->val); (yyval) = (yyvsp[-3]);}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 155 "static.y" /* yacc.c:1646  */
    { (yyvsp[-3]) = appendVariableVal((yyvsp[-3]),(yyvsp[-1])->varname); (yyval) = (yyvsp[-3]); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 156 "static.y" /* yacc.c:1646  */
    {(yyvsp[-6]) = appendDoubleConst((yyvsp[-6]),(yyvsp[-4])->val,(yyvsp[-1])->val); (yyval) = (yyvsp[-6]);}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 157 "static.y" /* yacc.c:1646  */
    {(yyvsp[-6]) = appendVarConst((yyvsp[-6]),(yyvsp[-4])->varname,(yyvsp[-1])->val); (yyval) = (yyvsp[-6]);}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 158 "static.y" /* yacc.c:1646  */
    {(yyvsp[-6]) = appendConstVar((yyvsp[-6]),(yyvsp[-4])->val,(yyvsp[-1])->varname); (yyval) = (yyvsp[-6]);}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 159 "static.y" /* yacc.c:1646  */
    {(yyvsp[-6]) = appendDoubleVar((yyvsp[-6]),(yyvsp[-4])->varname,(yyvsp[-1])->varname); (yyval)=(yyvsp[-6]);}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 160 "static.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 161 "static.y" /* yacc.c:1646  */
    {}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 165 "static.y" /* yacc.c:1646  */
    {}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 166 "static.y" /* yacc.c:1646  */
    {}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1948 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 169 "static.y" /* yacc.c:1906  */


void yyerror(char *s){
	printf("%s %d", s,ylineno);
}
int main(void){
	extern FILE* yyin;
	yyin = fopen("ip","r");
	yyparse();
	return 0;
}
