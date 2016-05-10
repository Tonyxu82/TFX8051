/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 21 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>

#define NOPE
#include "as31.h"
#undef NOPE

#define YYSTYPE union ystack

static unsigned char bytebuf[1024];		/* used by dumplist() */
static int bytecount;


void yyerror(const char *s);
int makeop(struct opcode * op, struct mode *m, int add);
void inclc(int i);
char *padline(char *line);
void dumplist(char *txt, int show);
void genbyte(int b);
void genstr(const char *s);
void genword(unsigned long w);

/* ------------------------ G R A M M E R ----------------------------- */


#line 94 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    STRING = 258,
    D_ORG = 259,
    D_BYTE = 260,
    D_WORD = 261,
    D_SKIP = 262,
    D_EQU = 263,
    D_FLAG = 264,
    D_END = 265,
    ACALL = 266,
    ADD = 267,
    ADDC = 268,
    AJMP = 269,
    ANL = 270,
    CJNE = 271,
    CLR = 272,
    CPL = 273,
    DA = 274,
    DEC = 275,
    DIV = 276,
    DJNZ = 277,
    INC = 278,
    JB = 279,
    JBC = 280,
    JC = 281,
    JMP = 282,
    JNB = 283,
    JNC = 284,
    JNZ = 285,
    JZ = 286,
    LCALL = 287,
    LJMP = 288,
    MOV = 289,
    MOVC = 290,
    MOVX = 291,
    NOP = 292,
    MUL = 293,
    ORL = 294,
    POP = 295,
    PUSH = 296,
    RET = 297,
    RETI = 298,
    RL = 299,
    RLC = 300,
    RR = 301,
    RRC = 302,
    SETB = 303,
    SJMP = 304,
    SUBB = 305,
    SWAP = 306,
    XCH = 307,
    XCHD = 308,
    XRL = 309,
    AB = 310,
    A = 311,
    C = 312,
    PC = 313,
    DPTR = 314,
    BITPOS = 315,
    R0 = 316,
    R1 = 317,
    R2 = 318,
    R3 = 319,
    R4 = 320,
    R5 = 321,
    R6 = 322,
    R7 = 323,
    VALUE = 324,
    SYMBOL = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  155
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   599

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  316

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      81,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,    87,     2,    75,    77,     2,
      84,    85,    73,    71,    83,    72,    82,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,     2,
      79,     2,    78,     2,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    76,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   131,   132,   135,   145,   148,   153,   159,
     164,   164,   183,   190,   191,   192,   195,   204,   210,   213,
     223,   236,   242,   246,   254,   259,   270,   275,   287,   292,
     306,   309,   312,   315,   318,   321,   324,   327,   330,   333,
     336,   339,   341,   354,   366,   368,   370,   372,   374,   376,
     378,   380,   382,   384,   386,   388,   390,   392,   394,   399,
     401,   403,   405,   407,   409,   411,   413,   415,   417,   419,
     421,   423,   425,   427,   429,   433,   435,   437,   441,   450,
     459,   461,   463,   465,   467,   469,   471,   473,   475,   477,
     479,   481,   483,   485,   487,   491,   493,   495,   497,   500,
     502,   504,   506,   518,   524,   531,   537,   546,   553,   563,
     570,   577,   586,   596,   603,   613,   619,   626,   633,   640,
     648,   655,   661,   668,   675,   683,   699,   706,   725,   732,
     738,   745,   753,   759,   765,   774,   782,   790,   798,   808,
     825,   838,   851,   861,   867,   870,   871,   872,   873,   874,
     875,   876,   877,   880,   881,   882,   885,   888,   891,   894,
     897,   902,   912,   922,   937,   951
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "D_ORG", "D_BYTE", "D_WORD",
  "D_SKIP", "D_EQU", "D_FLAG", "D_END", "ACALL", "ADD", "ADDC", "AJMP",
  "ANL", "CJNE", "CLR", "CPL", "DA", "DEC", "DIV", "DJNZ", "INC", "JB",
  "JBC", "JC", "JMP", "JNB", "JNC", "JNZ", "JZ", "LCALL", "LJMP", "MOV",
  "MOVC", "MOVX", "NOP", "MUL", "ORL", "POP", "PUSH", "RET", "RETI", "RL",
  "RLC", "RR", "RRC", "SETB", "SJMP", "SUBB", "SWAP", "XCH", "XCHD", "XRL",
  "AB", "A", "C", "PC", "DPTR", "BITPOS", "R0", "R1", "R2", "R3", "R4",
  "R5", "R6", "R7", "VALUE", "SYMBOL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'|'", "'&'", "'>'", "'<'", "':'", "'\\n'", "'.'", "','", "'('", "')'",
  "'@'", "'#'", "'!'", "$accept", "program", "linelist", "line",
  "linerest", "$@1", "directive", "defexpr", "flag", "flagv", "undefsym",
  "blist", "wlist", "expr", "instr", "two_op1", "two_op2", "two_op3",
  "two_op4", "two_op5", "two_op6", "single_op1", "single_op2", "three_op1",
  "rel", "rel2", "bit", "bitv", "reg", "regi", "data8", "data16", "addr11",
  "addr16", "relative", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    43,    45,    42,    47,    37,   124,    38,    62,    60,
      58,    10,    46,    44,    40,    41,    64,    35,    33
};
# endif

#define YYPACT_NINF -239

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-239)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     370,  -239,   139,   -24,   -24,   139,   120,    70,    15,    15,
     -19,   470,   -12,   292,   441,    23,    23,   139,   -45,    23,
     139,   139,   139,   139,   139,   222,    -9,   -26,  -239,    14,
     120,   139,   139,  -239,  -239,    19,    25,    31,    49,    15,
     139,   -24,    54,   -24,   -24,    85,  -239,  -239,   440,    89,
     298,  -239,  -239,   -27,    37,    38,    41,  -239,  -239,   139,
    -239,   139,   513,  -239,    64,  -239,  -239,  -239,    67,   513,
    -239,  -239,  -239,    68,    77,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,   454,  -239,    87,  -239,  -239,  -239,  -239,
    -239,  -239,    83,  -239,  -239,  -239,   454,  -239,  -239,  -239,
    -239,  -239,    90,    91,  -239,  -239,  -239,   101,  -239,   513,
    -239,   -30,  -239,  -239,  -239,  -239,   513,  -239,  -239,   102,
     108,   454,  -239,  -239,  -239,   111,   -50,   115,   124,   485,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,   139,     4,
     139,   139,   140,   143,  -239,  -239,  -239,  -239,   442,  -239,
    -239,   104,   354,   139,   139,   139,   139,   139,   139,   139,
      75,   145,   496,   126,   -47,   133,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,   135,   132,  -239,  -239,   139,   139,
     139,   154,   155,    23,   141,   144,   -17,   147,    34,   146,
     148,   150,   152,  -239,   513,  -239,   156,  -239,   158,   513,
    -239,  -239,   159,   160,  -239,  -239,   520,   520,   104,   104,
     104,    30,    30,   139,   139,   454,   139,  -239,  -239,    23,
      23,  -239,  -239,   139,   139,   162,   151,   139,   513,  -239,
     513,  -239,  -239,   172,   190,  -239,   139,    55,  -239,   139,
    -239,   191,  -239,   454,  -239,  -239,    56,   511,   193,   195,
      10,   139,   139,    60,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,   164,   139,   139,   170,  -239,  -239,  -239,  -239,   139,
    -239,  -239,  -239,  -239,   183,   184,   185,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,   513,  -239,  -239,  -239,   197,   139,
    -239,   175,   139,  -239,    86,   205,   206,  -239,  -239,   139,
    -239,  -239,  -239,  -239,  -239,  -239
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     9,     0,     0,
       0,     4,     6,     0,     0,     0,     0,    43,    42,     0,
      30,     0,   163,    45,     0,    47,    48,    46,     0,   161,
      52,    53,    54,     0,     0,   145,   146,   147,   148,   149,
     150,   151,   152,     0,    87,     0,   132,   133,   144,   143,
      75,   134,   142,    76,    62,   128,     0,    61,   129,   130,
      63,    91,     0,     0,    60,    59,    88,     0,    90,   165,
      82,     0,    89,    83,    84,    85,   164,    81,    80,     0,
       0,     0,    92,    93,    94,     0,     0,     0,     0,     0,
      66,    55,    56,    57,    79,    78,    69,    70,    71,    72,
      77,    86,    49,    73,    58,    74,    50,    51,     0,     0,
       0,     0,     0,     0,    18,     1,     3,     7,     0,     8,
      11,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,   141,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    19,    27,    13,    26,    14,   162,
      29,    15,     0,     0,     5,    31,    39,    38,    35,    36,
      37,    33,    34,     0,     0,     0,     0,   103,   104,     0,
       0,   109,   107,     0,     0,     0,     0,     0,   140,   113,
     139,   114,   112,     0,     0,   125,     0,     0,   115,     0,
     116,     0,   126,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,   105,   106,   110,   111,
     108,     0,     0,     0,     0,    64,    65,   124,   121,     0,
     122,   117,   127,   120,     0,     0,     0,   100,    99,   102,
     101,    25,    24,    28,    16,    22,    21,    17,     0,     0,
     135,     0,     0,   123,     0,     0,     0,    20,   136,     0,
     137,    97,    95,    98,    96,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,  -239,   214,   107,  -239,  -239,   116,  -239,  -239,
     114,  -239,  -239,    -2,  -239,    21,    33,   238,    26,  -239,
    -239,   255,    22,  -239,  -186,  -239,   -14,  -239,    -1,   -85,
       3,  -238,   266,   248,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    49,    50,    51,    52,    56,    53,   203,   297,   298,
      54,   206,   208,    69,    55,    65,    71,    72,   106,   101,
     124,    97,    90,    84,   241,   239,    91,    92,    98,   184,
      73,   210,    63,   117,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   107,   107,    62,   242,   107,    85,   205,   277,   232,
     197,   187,   102,   291,    99,   109,   103,    99,   109,   109,
     109,   116,   116,   293,   125,    66,   191,    70,   126,   192,
     128,    93,    64,   198,   134,   135,   195,    94,   109,   248,
     233,   111,   108,   100,   202,   112,   122,   127,   113,   114,
     115,   131,    57,    58,   157,    59,    60,   161,   123,   162,
     129,   140,   142,   132,   144,   145,   146,    61,   141,   130,
     249,    86,    87,    57,    58,   136,    59,    60,   147,    57,
      58,   137,    59,    60,    88,    89,   300,   138,    61,   155,
     232,   252,    88,    89,    61,    75,    76,    77,    78,    79,
      80,    81,    82,    57,    58,   139,    59,    60,   170,   171,
     143,   278,   284,   308,   285,   286,   310,   158,    61,   159,
     253,   233,   160,   315,    57,    58,    74,    59,    60,   295,
     296,    75,    76,    77,    78,    79,    80,    81,    82,    61,
     266,    64,   279,   186,   311,   312,   204,   172,   209,   204,
     173,   174,   207,   223,    57,    58,    83,    59,    60,   231,
     175,   216,   217,   218,   219,   220,   221,   222,   283,    61,
     185,   227,   288,   188,   189,   228,    64,    68,   235,   245,
     168,   169,   170,   171,   190,   193,   238,   240,   240,    57,
      58,   194,    59,    60,   196,    88,    89,   254,   199,   250,
     229,   255,    57,    58,    61,    59,    60,   200,    57,    58,
      46,    59,    60,   213,   230,   268,   269,    61,   236,   237,
     234,   264,   265,    61,   224,   243,   244,   247,   246,   267,
     251,   275,   256,   258,   257,   259,   270,   271,   273,   260,
     274,   261,   262,   263,   209,   272,   276,   299,   282,   289,
     280,   290,   281,   302,   304,   305,   306,   307,   309,   209,
     294,   313,   314,   292,   156,   214,   212,   211,   133,   105,
     240,    67,   118,     0,     0,     0,   301,     0,    64,   119,
       0,   120,   303,    75,    76,    77,    78,    79,    80,    81,
      82,    57,    58,     0,    59,    60,     0,   240,    -2,     1,
     240,     0,     0,     0,     0,     0,    61,   240,   121,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    75,    76,    77,    78,    79,    80,    81,
      82,    57,    58,     0,    59,    60,     0,     0,    46,     0,
       0,     1,     0,     0,     0,     0,    61,     0,     0,    47,
      48,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,     0,     0,     0,   215,
      46,     0,     0,     1,   148,   149,   150,   151,   152,   153,
     154,    47,    48,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    95,     0,     0,
     104,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      57,    58,     0,    59,    60,   176,   177,   178,   179,   180,
     181,   182,   183,    47,    48,    61,    95,    96,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    57,
      58,     0,    59,    60,   201,     0,   176,   177,   178,   179,
     180,   181,   182,   183,    61,     0,    96,    75,    76,    77,
      78,    79,    80,    81,    82,    57,    58,     0,    59,    60,
     287,     0,   176,   177,   178,   179,   180,   181,   182,   183,
      61,     0,   225,   226,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   165,   166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
       2,    15,    16,     5,   190,    19,     7,     3,   246,    56,
      60,    96,    13,     3,    11,    17,    13,    14,    20,    21,
      22,    23,    24,   261,    25,     4,    56,     6,    25,    59,
      56,     9,    56,    83,    31,    32,   121,    56,    40,    56,
      87,    86,    16,    55,   129,    19,    25,    56,    20,    21,
      22,    30,    69,    70,    81,    72,    73,    59,    25,    61,
      86,    39,    41,    30,    43,    44,    45,    84,    40,    55,
      87,    56,    57,    69,    70,    56,    72,    73,    45,    69,
      70,    56,    72,    73,    69,    70,   272,    56,    84,     0,
      56,    57,    69,    70,    84,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    56,    72,    73,    78,    79,
      56,    56,    56,   299,    58,    59,   302,    80,    84,    81,
      86,    87,    81,   309,    69,    70,    56,    72,    73,    69,
      70,    61,    62,    63,    64,    65,    66,    67,    68,    84,
     225,    56,    87,    60,    58,    59,   148,    83,   150,   151,
      83,    83,   149,    78,    69,    70,    86,    72,    73,   173,
      83,   163,   164,   165,   166,   167,   168,   169,   253,    84,
      83,   172,   257,    83,    83,   172,    56,    57,   175,   193,
      76,    77,    78,    79,    83,    83,   188,   189,   190,    69,
      70,    83,    72,    73,    83,    69,    70,   198,    83,   196,
      74,   198,    69,    70,    84,    72,    73,    83,    69,    70,
      70,    72,    73,    70,    88,   229,   230,    84,    83,    87,
      87,   223,   224,    84,    79,    71,    71,    83,    87,   226,
      83,    59,    86,    83,    86,    83,   233,   234,    87,    83,
     237,    83,    83,    83,   246,    83,    56,    83,    57,    56,
     247,    56,   249,    83,    71,    71,    71,    60,    83,   261,
     262,    56,    56,   260,    50,   158,   152,   151,    30,    14,
     272,     5,    24,    -1,    -1,    -1,   273,    -1,    56,    57,
      -1,    59,   279,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    -1,   299,     0,     1,
     302,    -1,    -1,    -1,    -1,    -1,    84,   309,    86,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    -1,    -1,    70,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    81,
      82,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      70,    -1,    -1,     1,     4,     5,     6,     7,     8,     9,
      10,    81,    82,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    56,    -1,    -1,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    72,    73,    61,    62,    63,    64,    65,
      66,    67,    68,    81,    82,    84,    56,    86,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    72,    73,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    84,    -1,    86,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    72,    73,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      84,    -1,    86,    87,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    73,    74,    75,    76,    77,    78,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    70,    81,    82,    90,
      91,    92,    93,    95,    99,   103,    94,    69,    70,    72,
      73,    84,   102,   121,    56,   104,   104,   121,    57,   102,
     104,   105,   106,   119,    56,    61,    62,    63,    64,    65,
      66,    67,    68,    86,   112,   117,    56,    57,    69,    70,
     111,   115,   116,   111,    56,    56,    86,   110,   117,   119,
      55,   108,   117,   119,    59,   110,   107,   115,   107,   102,
     123,    86,   107,   123,   123,   123,   102,   122,   122,    57,
      59,    86,   104,   105,   109,   117,   119,    56,    56,    86,
      55,   104,   105,   106,   119,   119,    56,    56,    56,    56,
     111,   123,   104,    56,   104,   104,   104,   105,     4,     5,
       6,     7,     8,     9,    10,     0,    92,    81,    80,    81,
      81,   102,   102,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    83,    83,    83,    83,    61,    62,    63,    64,
      65,    66,    67,    68,   118,    83,    60,   118,    83,    83,
      83,    56,    59,    83,    83,   118,    83,    60,    83,    83,
      83,    59,   118,    96,   102,     3,   100,   119,   101,   102,
     120,    96,    99,    70,    93,    85,   102,   102,   102,   102,
     102,   102,   102,    78,    79,    86,    87,   117,   119,    74,
      88,   115,    56,    87,    87,   119,    83,    87,   102,   114,
     102,   113,   113,    71,    71,   115,    87,    83,    56,    87,
     119,    83,    57,    86,   117,   119,    86,    86,    83,    83,
      83,    83,    83,    83,   102,   102,   118,   119,   115,   115,
     119,   119,    83,    87,   119,    59,    56,   120,    56,    87,
     119,   119,    57,   118,    56,    58,    59,    59,   118,    56,
      56,     3,   119,   120,   102,    69,    70,    97,    98,    83,
     113,   119,    83,   119,    71,    71,    71,    60,   113,    83,
     113,    58,    59,    56,    56,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    93,    95,    95,    95,    95,    95,    95,    95,    96,
      97,    98,    98,    99,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   106,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   113,
     114,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   120,   121,   122,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     2,     2,     1,
       0,     3,     3,     3,     3,     3,     5,     5,     2,     1,
       2,     1,     1,     1,     3,     3,     1,     1,     3,     1,
       1,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     5,     5,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     7,     7,     7,     7,     5,
       5,     5,     5,     3,     3,     4,     4,     3,     4,     3,
       4,     4,     3,     3,     3,     3,     3,     4,     3,     3,
       4,     4,     4,     5,     4,     3,     3,     4,     1,     1,
       1,     2,     1,     1,     1,     5,     6,     6,     7,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 127 "parser.y" /* yacc.c:1646  */
    {
}
#line 1575 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 136 "parser.y" /* yacc.c:1646  */
    {
	if (abort_asap) {YYABORT;}
	if( pass1 ) {
		(yyvsp[-2]).sym->type = LABEL;
		(yyvsp[-2]).sym->value = lc;
	}
	inclc((yyvsp[0]).value);
	bytecount = 0;
}
#line 1589 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 145 "parser.y" /* yacc.c:1646  */
    { inclc((yyvsp[0]).value); bytecount = 0; }
#line 1595 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "parser.y" /* yacc.c:1646  */
    {
						(yyval).value = (yyvsp[-1]).value;
						if( dashl && pass2 )
							dumplist((yyvsp[0]).str,1);
					}
#line 1605 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 153 "parser.y" /* yacc.c:1646  */
    {
						(yyval).value = (yyvsp[-1]).value;
						if( dashl && pass2 )
							dumplist((yyvsp[0]).str,1);

					}
#line 1616 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parser.y" /* yacc.c:1646  */
    {
						(yyval).value = 0;
						if( dashl && pass2 )
							dumplist((yyvsp[0]).str,0);
					}
#line 1626 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 164 "parser.y" /* yacc.c:1646  */
    {
						seek_eol();
					}
#line 1634 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "parser.y" /* yacc.c:1646  */
    {
						(yyval).value = 0;
						if( dashl && pass2 )
							dumplist((yyvsp[-2]).str,0);
					}
#line 1644 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "parser.y" /* yacc.c:1646  */
    {
	lc = (yyvsp[0]).val.v;
	if( pass2 ) emitaddr(lc);
	bytecount = 0;
	(yyval).value = 0;
}
#line 1655 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval).value = (yyvsp[0]).value; }
#line 1661 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval).value = (yyvsp[0]).value; }
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval).value = (yyvsp[0]).val.v;
					  if( pass2 )
						emitaddr(lc+(yyval).value); }
#line 1675 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 196 "parser.y" /* yacc.c:1646  */
    {
	if( (yyvsp[0]).val.d == 0 )
		warn("Expression is undefined in pass 1");
	(yyvsp[-2]).sym->type = LABEL;
	(yyvsp[-2]).sym->value = (yyvsp[0]).val.v;
	(yyval).value = 0;
}
#line 1687 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 205 "parser.y" /* yacc.c:1646  */
    {
	(yyvsp[-2]).sym->type = LABEL;
	(yyvsp[-2]).sym->value = (yyvsp[0]).value;
	(yyval).value = 0;
}
#line 1697 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0; }
#line 1703 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "parser.y" /* yacc.c:1646  */
    {
		if( (yyvsp[0]).val.d == 0 )
			warn("Expression is undefined in pass 1");
		if( !(isbit16((yyvsp[0]).val.v)) )
			warn("Value greater than 16-bits");
		(yyval).value = (yyvsp[0]).val.v;
}
#line 1715 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "parser.y" /* yacc.c:1646  */
    {
	if( !isbit8((yyvsp[-1]).value) )
		warn("Bit address exceeds 8-bits");
	if( isbmram((yyvsp[-1]).value) )
		(yyval).value = ((yyvsp[-1]).value-0x20)*8+ (yyvsp[0]).value;
	else if( isbmsfr((yyvsp[-1]).value) )
		(yyval).value = (yyvsp[-1]).value + (yyvsp[0]).value;
	else
		warn("Invalid bit addressable RAM location");
}
#line 1730 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 237 "parser.y" /* yacc.c:1646  */
    {
	if( (yyvsp[0]).sym->type == UNDEF )
		warn("Symbol %s must be defined in pass 1",(yyvsp[0]).sym->name);
	(yyval).value = (yyvsp[0]).sym->value;
}
#line 1740 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval).value = (yyvsp[0]).value; }
#line 1746 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "parser.y" /* yacc.c:1646  */
    {
	if( (yyvsp[0]).sym->type != UNDEF && pass1)
		warn("Attempt to redefine symbol: %s",(yyvsp[0]).sym->name);
	(yyval).sym = (yyvsp[0]).sym;
}
#line 1756 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 255 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) genbyte((yyvsp[0]).value);
	(yyval).value = (yyvsp[-2]).value + 1;
}
#line 1765 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 260 "parser.y" /* yacc.c:1646  */
    {
	if( pass1 )
		(yyval).value = (yyvsp[-2]).value + (yyvsp[0]).value;
	else {
		(yyval).value = (yyvsp[-2]).value + strlen((yyvsp[0]).str);
		genstr((yyvsp[0]).str);
		
		free((yyvsp[0]).str);
	}
}
#line 1780 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 271 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) genbyte((yyvsp[0]).value);
	(yyval).value = 1;
}
#line 1789 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 276 "parser.y" /* yacc.c:1646  */
    {
	if( pass1 )
		(yyval).value = (yyvsp[0]).value;
	else {
		(yyval).value = strlen((yyvsp[0]).str);
		genstr((yyvsp[0]).str);
		free((yyvsp[0]).str);
	}
}
#line 1803 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) genword((yyvsp[0]).value);
	(yyval).value = (yyvsp[-2]).value + 2;
}
#line 1812 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 293 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) genword((yyvsp[0]).value);
	(yyval).value = 2;
}
#line 1821 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = lc;
					  (yyval).val.d = 1; }
#line 1828 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-1]).val.v;
					  (yyval).val.d = (yyvsp[-1]).val.d; }
#line 1835 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = -(yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[0]).val.d;  }
#line 1842 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v | (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1849 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v & (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1856 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v * (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1863 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v / (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1870 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v % (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1877 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 330 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v - (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1884 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-2]).val.v + (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-2]).val.d && (yyvsp[0]).val.d; }
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-3]).val.v >> (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-3]).val.d && (yyvsp[0]).val.d; }
#line 1898 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[-3]).val.v << (yyvsp[0]).val.v;
					  (yyval).val.d = (yyvsp[-3]).val.d && (yyvsp[0]).val.d; }
#line 1905 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 342 "parser.y" /* yacc.c:1646  */
    {
	if( pass1 ) {
		(yyval).val.v = (yyvsp[0]).sym->value;
		(yyval).val.d = ((yyvsp[0]).sym->type != UNDEF);
	}
	else {
		if( (yyvsp[0]).sym->type == UNDEF )
			warn("Undefined symbol %s",(yyvsp[0]).sym->name);
		(yyval).val.v = (yyvsp[0]).sym->value;
		(yyval).val.d = 1;
	}
}
#line 1922 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval).val.v = (yyvsp[0]).val.v; (yyval).val.d=1; }
#line 1928 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[0]).op,NULL,0); }
#line 1934 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1940 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1946 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 373 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1952 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 375 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1958 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1964 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 379 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1970 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,4); }
#line 1976 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 1982 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 385 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,4); }
#line 1988 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,6); }
#line 1994 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2000 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,4); }
#line 2006 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 393 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,6); }
#line 2012 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "parser.y" /* yacc.c:1646  */
    { if( get_md((yyvsp[0]).mode) == 3 )
					warn("Immediate mode is illegal");
				  (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0);
				}
#line 2021 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 400 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2027 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,4); }
#line 2033 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 404 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2039 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2045 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2051 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 410 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,0); }
#line 2057 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 412 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,0); }
#line 2063 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 414 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2069 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 416 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[0]).op,NULL,0); }
#line 2075 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 418 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[0]).op,NULL,0); }
#line 2081 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 420 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2087 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 422 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2093 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 424 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2099 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 426 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2105 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 428 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,NULL,0); }
#line 2111 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 430 "parser.y" /* yacc.c:1646  */
    { if( get_md((yyvsp[0]).mode) != 2 )
					warn("Invalid addressing mode");
				  (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,-2); }
#line 2119 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 434 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2125 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 436 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2131 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 438 "parser.y" /* yacc.c:1646  */
    { if( get_md((yyvsp[0]).mode) == 0 )
					warn("Invalid addressing mode");
				  (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,-1); }
#line 2139 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 442 "parser.y" /* yacc.c:1646  */
    {
				   struct mode tmp;
					set_md(tmp,0);
					set_ov(tmp,0);
					set_sz(tmp,1);
					set_b1(tmp,(yyvsp[0]).value);
					(yyval).value = makeop((yyvsp[-1]).op,&tmp,0);
				}
#line 2152 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 451 "parser.y" /* yacc.c:1646  */
    {
				   struct mode tmp;
					set_md(tmp,0);
					set_ov(tmp,0);
					set_sz(tmp,1);
					set_b1(tmp,(yyvsp[0]).value);
					(yyval).value = makeop((yyvsp[-1]).op,&tmp,0);
				}
#line 2165 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 460 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2171 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 462 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2177 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 464 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2183 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2189 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2195 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 470 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2201 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 472 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2207 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 474 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2213 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2219 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2225 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 480 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2231 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 482 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2237 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,0); }
#line 2243 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 486 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,4); }
#line 2249 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-1]).op,&(yyvsp[0]).mode,6); }
#line 2255 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 492 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-6]).op,NULL,0); }
#line 2261 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-6]).op,NULL,0); }
#line 2267 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 496 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-6]).op,NULL,1); }
#line 2273 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-6]).op,NULL,1); }
#line 2279 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 501 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,(yyvsp[0]).value); }
#line 2285 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 503 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,2); }
#line 2291 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 505 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,(yyvsp[-2]).value+3); }
#line 2297 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 507 "parser.y" /* yacc.c:1646  */
    { (yyval).value = makeop((yyvsp[-4]).op,NULL,5); }
#line 2303 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 519 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode, (yyvsp[0]).value);
					set_sz((yyval).mode, 0);
				}
#line 2313 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 525 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2324 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 532 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,2);
					set_ov((yyval).mode,(yyvsp[0]).value);
					set_sz((yyval).mode,0);
				}
#line 2334 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 538 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,3);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2345 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 547 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[-2]).value);
				}
#line 2356 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 554 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-3]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2368 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 564 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2379 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 571 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2390 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 578 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2401 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 587 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2413 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 597 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,(yyvsp[-2]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2424 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 604 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2436 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 614 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,(yyvsp[-2]).value);
					set_sz((yyval).mode,0);
				}
#line 2446 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 620 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,(yyvsp[-2]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2457 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 627 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,2);
					set_ov((yyval).mode,(yyvsp[-3]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2468 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 634 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,3);
					set_ov((yyval).mode,(yyvsp[0]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[-2]).value);
				}
#line 2479 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 641 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,4);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[0]).value);
					set_b2((yyval).mode,(yyvsp[-2]).value);
				}
#line 2491 "parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 649 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,5);
					set_ov((yyval).mode,(yyvsp[0]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[-3]).value);
				}
#line 2502 "parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 656 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,6);
					set_ov((yyval).mode,(yyvsp[-2]).value);
					set_sz((yyval).mode,0);
				}
#line 2512 "parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 662 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,7);
					set_ov((yyval).mode,(yyvsp[-2]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2523 "parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 669 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,8);
					set_ov((yyval).mode,(yyvsp[-3]).value);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2534 "parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 676 "parser.y" /* yacc.c:1646  */
    {
				set_md((yyval).mode,9);
				set_ov((yyval).mode,0);
				set_sz((yyval).mode,2);
				set_b1((yyval).mode, ((yyvsp[0]).value & 0xff00) >> 8 );
				set_b2((yyval).mode, ((yyvsp[0]).value & 0x00ff) );
			}
#line 2546 "parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 684 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,10);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2557 "parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 700 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,11);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[-2]).value);
				}
#line 2568 "parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 707 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) {
		if( !isbit8((yyvsp[-3]).value) )
			warn("Bit address exceeds 8-bits");
		if( isbmram((yyvsp[-3]).value) )
			set_b1((yyval).mode, ((yyvsp[-3]).value-0x20)*8+ (yyvsp[-2]).value );
		else if( isbmsfr((yyvsp[-3]).value) )
			set_b1((yyval).mode, (yyvsp[-3]).value + (yyvsp[-2]).value );
		else
			warn("Invalid bit addressable RAM location");
	}
	set_md((yyval).mode,11);
	set_ov((yyval).mode,0);
	set_sz((yyval).mode,1);
}
#line 2588 "parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 726 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,0);
				}
#line 2598 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 733 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,(yyvsp[0]).value);
					set_sz((yyval).mode,0);
				}
#line 2608 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 739 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,2);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2619 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 746 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,3);
					set_ov((yyval).mode,(yyvsp[0]).value);
					set_sz((yyval).mode,0);
				}
#line 2629 "parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 754 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,0);
				}
#line 2639 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 760 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,0);
				}
#line 2649 "parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 766 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,2);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,1);
					set_b1((yyval).mode,(yyvsp[0]).value);
				}
#line 2660 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 775 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,0);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2672 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 783 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,1);
					set_ov((yyval).mode,0);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2684 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 791 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,2);
					set_ov((yyval).mode,(yyvsp[-5]).value);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2696 "parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 799 "parser.y" /* yacc.c:1646  */
    {
					set_md((yyval).mode,3);
					set_ov((yyval).mode,(yyvsp[-5]).value);
					set_sz((yyval).mode,2);
					set_b1((yyval).mode,(yyvsp[-2]).value);
					set_b2((yyval).mode,(yyvsp[0]).value);
				}
#line 2708 "parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 809 "parser.y" /* yacc.c:1646  */
    {
		long offset;
		if( pass2 ) {
			offset = (yyvsp[0]).val.v - (lc+3);
			if( offset > 127 || offset < -128 )
			   warn("Relative offset exceeds -128 / +127");
			(yyval).value = offset;
		}
}
#line 2722 "parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 826 "parser.y" /* yacc.c:1646  */
    {
		long offset;
		if( pass2 ) {
			offset = (yyvsp[0]).val.v - (lc+2); /* different! */
			if( offset > 127 || offset < -128 )
			   warn("Relative offset exceeds -128 / +127");
			(yyval).value = offset;
		}
}
#line 2736 "parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 839 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) {
		if( !isbit8((yyvsp[-1]).value) )
			warn("Bit address exceeds 8-bits");
		if( isbmram((yyvsp[-1]).value) )
			(yyval).value = ((yyvsp[-1]).value-0x20)*8+(yyvsp[0]).value;
		else if( isbmsfr((yyvsp[-1]).value) )
			(yyval).value = (yyvsp[-1]).value + (yyvsp[0]).value;
		else
			warn("Invalid bit addressable RAM location");
	}
}
#line 2753 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 852 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) {
		if( !isbit8((yyvsp[0]).value) )
			warn("Bit address exceeds 8-bits");
		(yyval).value = (yyvsp[0]).value;
	}
}
#line 2765 "parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 862 "parser.y" /* yacc.c:1646  */
    {
	if( (yyvsp[0]).sym->type == UNDEF && pass2 )
		warn("Symbol %s undefined",(yyvsp[0]).sym->name);
	(yyval).value = (yyvsp[0]).sym->value;
}
#line 2775 "parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 867 "parser.y" /* yacc.c:1646  */
    { (yyval).value = (yyvsp[0]).value; }
#line 2781 "parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 870 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0; }
#line 2787 "parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 871 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 1; }
#line 2793 "parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 872 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 2; }
#line 2799 "parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 873 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 3; }
#line 2805 "parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 874 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 4; }
#line 2811 "parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 875 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 5; }
#line 2817 "parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 876 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 6; }
#line 2823 "parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 877 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 7; }
#line 2829 "parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 880 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0; }
#line 2835 "parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 881 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 1; }
#line 2841 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 883 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r2"); }
#line 2848 "parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 886 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r3"); }
#line 2855 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 889 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r4"); }
#line 2862 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 892 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r5"); }
#line 2869 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 895 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r6"); }
#line 2876 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 898 "parser.y" /* yacc.c:1646  */
    { (yyval).value = 0;
				  warn("Illegal indirect register: @r7"); }
#line 2883 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 903 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) {
		if( !isbit8((yyvsp[0]).val.v) )
			warn("Expression greater than 8-bits");
	}
	(yyval).value = (yyvsp[0]).val.v;
}
#line 2895 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 913 "parser.y" /* yacc.c:1646  */
    {
	if( pass2 ) {
		if( !isbit16((yyvsp[0]).val.v) )
			warn("Expression greater than 16-bits");
	}
	(yyval).value = (yyvsp[0]).val.v;
}
#line 2907 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 923 "parser.y" /* yacc.c:1646  */
    {
		if( pass2 ) {
			if( !isbit16((yyvsp[0]).val.v)  )
				warn("Address greater than 16-bits");
			if( ((yyvsp[0]).val.v & size11) != ((lc+2) & size11) )
				warn("Address outside current 2K page");
		}
		set_md((yyval).mode,0);
		set_ov((yyval).mode, ((yyvsp[0]).val.v&0x0700)>>3 );
		set_sz((yyval).mode,1);
		set_b1((yyval).mode,(yyvsp[0]).val.v&0x00ff);
}
#line 2924 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 938 "parser.y" /* yacc.c:1646  */
    {
		if( pass2 ) {
			if( !isbit16((yyvsp[0]).val.v)  )
				warn("Address greater than 16-bits");
		}
		set_md((yyval).mode,0);
		set_ov((yyval).mode, 0 );
		set_sz((yyval).mode,2);
		set_b1((yyval).mode, ((yyvsp[0]).val.v & 0xff00 ) >> 8 );
		set_b2((yyval).mode, ((yyvsp[0]).val.v & 0x00ff ) );
}
#line 2940 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 952 "parser.y" /* yacc.c:1646  */
    {
		long offset=0;
		if( pass2 ) {
			offset = (yyvsp[0]).val.v - (lc+2);
			if( offset>127 || offset<-128 )
			   warn("Relative offset exceeds -128 / +127");
		}
		set_md((yyval).mode,0);
		set_ov((yyval).mode,0);
		set_sz((yyval).mode,1);
		set_b1((yyval).mode,offset);

}
#line 2958 "parser.c" /* yacc.c:1646  */
    break;


#line 2962 "parser.c" /* yacc.c:1646  */
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
#line 967 "parser.y" /* yacc.c:1906  */


/* ---------------------------------------------------------------------- */

void yyerror(const char *s)
{
	warn("%s near \"%s\"", s, get_last_token());
}


/* ----------------------------------------------------------------------
 * makeop:
 *	This function makes an opcode based on the instruction symbol table
 *	entry, and an addressing mode structure.
 *	This function is called from both passes, but
 *	only generates code in pass 2.
 *
 *	Resultant opcode bytes are passed to genbyte().
 *
 *	Returns the nuumber of bytes that the instruction
 *	occupies.
 *
 */

int makeop(struct opcode * op, struct mode *m, int add)
{
	register unsigned int newop;

	if( m == NULL ) {
		if(pass2) genbyte(op->bytes[0+add]);
		return(1);
	}

	if( pass2 ) {
		newop = op->bytes[ get_md(*m)+add ] | get_ov(*m);
		genbyte(newop);
		if( get_sz(*m) > 0 ) genbyte( get_b1(*m) );
		if( get_sz(*m) > 1 ) genbyte( get_b2(*m) );
	}
	return( get_sz(*m)+1 );
}


/* ----------------------------------------------------------------------
 * inclc:
 *	Increments the Location Counter by 'i' amount.
 *	Check to see if 'i' overflows 64K.
 *	Checks to see if assembler is overlapping previous sections
 *	of code. (using a large bit field).
 *
 */

#define indx(a) ( (a)/(sizeof(long)*8) )
#define bit(a)	( 1 << ((a)%(sizeof(long)*8)) )

#define getloc(a) (regions[indx(a)] & bit(a))
#define setloc(a) (regions[indx(a)] |= bit(a))

static unsigned long regions[ 0x10000/(sizeof(long)*8) ];

void inclc(int i)
{

	while (i-- > 0) {
		if( pass2 && getloc(lc) )
			error("Location counter overlaps");
		if( pass2 ) setloc(lc);
		lc += 1;
	}
		
	if( lc > 0xffff )
		error("Location counter has exceeded 16-bits");
}

void clear_location_counter(void)
{
	memset(regions, 0, sizeof(regions));
}


/* ----------------------------------------------------------------------
 * padline:
 *	This routine returns a new string, which is equivilant to
 *	'line' except that all tabs have been expanded to spaces, and
 *	the total length has been truncated to 60 chars.
 */

char *padline(char *line)
{
	static char newline[61];
	char *p1;
	int pos=0,nxtpos;

	for(p1=line; pos<sizeof(newline)-1 && *p1; p1++ ) {
		if( *p1 == '\t' ) {
			nxtpos = pos+8-pos%8;
			while(pos<sizeof(newline)-1 && pos <= nxtpos)
				newline[pos++] = ' ';
		} else if( *p1 != '\n' )
			newline[pos++]= *p1;
	}
	newline[pos] = '\0';
	return(newline);
}


/* ----------------------------------------------------------------------
 * dumplist:
 *	Outputs the current location counter, bytebuf[] array, and
 *	the string 'txt' to the listing file.
 *	This routine is called for every source line encountered in the
 *	source file. (Only in pass 2, and if listing is turned on).
 *
 */

void dumplist(char *txt, int show)
{
	int i,j;

	fprintf(listing,show?"%04X: ":"      ",lc);

	j=0;
	for(i=0; i<bytecount; i++ ) {
		fprintf(listing,"%02X ",bytebuf[i]);
		if( ++j >= 4 ) {
			j = 0;
			fprintf(listing,"\n      ");
		}
	}
	while(++j <= 4)
		fprintf(listing,"   ");

	fprintf(listing," %s\n",padline(txt));
}

/* ----------------------------------------------------------------------
 * gen* routines:
 *	Place information into the bytebuf[] array, and also
 *	call emitbyte with the byte.
 *
 */

void genbyte(int b)
{
	if( bytecount < sizeof(bytebuf) )
		bytebuf[bytecount++] = b;
	emitbyte(b);
}

void genstr(const char *s)
{
	while( *s )
		genbyte(*s++);
}

void genword(unsigned long w)
{
	genbyte( (w & 0xff00) >> 8 );
	genbyte( (w & 0x00ff) );
}

