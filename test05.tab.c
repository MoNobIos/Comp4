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
#line 1 "test05.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP 26

extern int yylex();
extern int check_else; // 1 when else , 0 when }
extern int line;
extern int check_while; // 1 when while , 0 when }
extern int check_if; // 1 when if , 0 when }


/* variable */
struct var{
	char *name;
	int val;
};

char data[512];
char temp_state[2048];
char temp_state_else[255]="";
char temp_exp[1024];
char temp_condition_if[255];


void yyerror();
int getVar(char *name);
void asm_print_alloc(char *msg);
void asm_print_alloc_newline(char *msg);
void asm_print_init();
void asm_print_string(char *msg);
void asm_print_exp(char* num);
void asm_print_exp_newline(char* num);
void asm_print_hex(char* num);
void asm_print_hex_newline(char* num);
void asm_if(char* a,char* b);
void asm_add(char* a,char* b);
void asm_sub(char* a,char* b);
void asm_div(char* a,char* b);
void asm_mod(char* a,char* b);
void asm_loop(char* a,char* b);
void reset_flag_condition();
void asm_statement();

void asm_mul(char* a,char* b);
void asm_assign(char* var,char* val);
char* minus(char* a);

int STATE;

struct var myVar[26];
int top=-1;
int count_string=0;
int count_if=0;
int count_loop = 0;
int count_mod=0;

FILE *file;


#line 129 "test05.tab.c" /* yacc.c:339  */

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
   by #include "test05.tab.h".  */
#ifndef YY_YY_TEST05_TAB_H_INCLUDED
# define YY_YY_TEST05_TAB_H_INCLUDED
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
    NUMBER = 258,
    SEMICOLON = 259,
    VARIABLE = 260,
    ASSIGN = 261,
    WHILE = 262,
    IF = 263,
    ELSE = 264,
    PRINT = 265,
    MSG = 266,
    ERR = 267,
    NEWLINE = 268,
    PRINT_HEX = 269,
    GREAT = 270,
    LESS = 271,
    EQ = 272,
    NEQ = 273,
    UMINUS = 274,
    IFX = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "test05.y" /* yacc.c:355  */

	int val;
	char *str;

#line 195 "test05.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TEST05_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "test05.tab.c" /* yacc.c:358  */

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    27,    21,    19,     2,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    24,    25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    97,   100,   101,   102,   103,   104,   105,
     108,   109,   112,   113,   114,   115,   116,   117,   118,   120,
     121,   122,   123,   124,   125,   126,   127,   128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "SEMICOLON", "VARIABLE",
  "ASSIGN", "WHILE", "IF", "ELSE", "PRINT", "MSG", "ERR", "NEWLINE",
  "PRINT_HEX", "GREAT", "LESS", "EQ", "NEQ", "'+'", "'-'", "'*'", "'/'",
  "'\\\\'", "UMINUS", "IFX", "'('", "')'", "'{'", "'}'", "$accept", "prog",
  "statement", "group_command", "command", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    43,
      45,    42,    47,    92,   274,   275,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      57,   -44,   -44,     2,   -20,    -6,    58,    16,    16,    16,
      30,     4,   -44,   -44,    72,    16,    16,    16,   -44,     3,
      66,    77,   -44,    83,   -44,     4,     2,   -44,   -44,    16,
      16,    16,    16,    16,    97,    92,   120,   -44,    18,   -44,
      19,   -44,    28,   -44,    52,    52,   -44,   -44,   -44,   -44,
      16,    16,   -44,   -44,   -44,   102,   111,     6,    11,    57,
      57,    43,     4,    12,   -44,    34,    17,    57,    20,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     2,     8,    10,     0,     0,     0,     0,    27,     0,
       0,     0,    24,     0,     1,     3,     0,    11,     4,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,    14,
       0,    16,     0,    25,    19,    20,    21,    22,    23,    18,
       0,     0,    13,    15,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     7,     5,     0,     0,     8,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,     0,   -43,   -10,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    62,    12,    13,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    27,    20,    21,    22,    23,    16,    37,    15,    26,
      25,    34,    35,    36,     6,    27,    38,    63,     7,     2,
      17,    18,    52,    53,    68,    44,    45,    46,    47,    48,
      24,     1,    54,     2,    59,     3,     8,     4,     5,    60,
       6,    65,     9,    66,     7,    67,    55,    56,    26,    69,
       8,    27,    27,     6,     0,     0,     9,     7,     1,    61,
       2,     2,     3,    18,     4,     5,     0,     6,     0,    19,
      39,     7,    64,    31,    32,    33,    28,     8,     8,    40,
       0,    41,     0,     9,     9,    29,    30,    31,    32,    33,
      42,    29,    30,    31,    32,    33,    29,    30,    31,    32,
      33,    49,    29,    30,    31,    32,    33,     0,    50,     0,
      43,    29,    30,    31,    32,    33,    29,    30,    31,    32,
      33,    29,    30,    31,    32,    33,     0,     0,     0,    57,
      29,    30,    31,    32,    33,     0,     0,    51,    58,    29,
      30,    31,    32,    33
};

static const yytype_int8 yycheck[] =
{
       0,    11,     6,     7,     8,     9,    26,     4,     6,     5,
      10,    15,    16,    17,    10,    25,    13,    60,    14,     3,
      26,     5,     4,     4,    67,    29,    30,    31,    32,    33,
       0,     1,     4,     3,    28,     5,    20,     7,     8,    28,
      10,    29,    26,     9,    14,    28,    50,    51,     5,    29,
      20,    61,    62,    10,    -1,    -1,    26,    14,     1,    59,
       3,     3,     5,     5,     7,     8,    -1,    10,    -1,    11,
       4,    14,    29,    21,    22,    23,     4,    20,    20,    13,
      -1,     4,    -1,    26,    26,    19,    20,    21,    22,    23,
      13,    19,    20,    21,    22,    23,    19,    20,    21,    22,
      23,     4,    19,    20,    21,    22,    23,    -1,    16,    -1,
      27,    19,    20,    21,    22,    23,    19,    20,    21,    22,
      23,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      19,    20,    21,    22,    23,    -1,    -1,    17,    27,    19,
      20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     7,     8,    10,    14,    20,    26,
      31,    32,    33,    34,    35,     6,    26,    26,     5,    11,
      35,    35,    35,    35,     0,    32,     5,    34,     4,    19,
      20,    21,    22,    23,    35,    35,    35,     4,    13,     4,
      13,     4,    13,    27,    35,    35,    35,    35,    35,     4,
      16,    17,     4,     4,     4,    35,    35,    27,    27,    28,
      28,    32,    32,    33,    29,    29,     9,    28,    33,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      33,    33,    34,    34,    34,    34,    34,    34,    34,    35,
      35,    35,    35,    35,    35,    35,    35,    35
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     9,    13,     9,     1,     1,
       1,     2,     3,     4,     3,     4,     3,     4,     4,     3,
       3,     3,     3,     3,     2,     3,     1,     1
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
#line 96 "test05.y" /* yacc.c:1646  */
    { asm_statement();}
#line 1336 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "test05.y" /* yacc.c:1646  */
    { asm_statement();}
#line 1342 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "test05.y" /* yacc.c:1646  */
    {  }
#line 1348 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "test05.y" /* yacc.c:1646  */
    {asm_if((char*)(yyvsp[-6].str),(char*)(yyvsp[-4].str));}
#line 1354 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "test05.y" /* yacc.c:1646  */
    { asm_if((char*)(yyvsp[-10].str),(char*)(yyvsp[-8].str));  }
#line 1360 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "test05.y" /* yacc.c:1646  */
    { asm_loop((char*)(yyvsp[-6].str),(char*)(yyvsp[-4].str)); }
#line 1366 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "test05.y" /* yacc.c:1646  */
    {}
#line 1372 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "test05.y" /* yacc.c:1646  */
    { yyerror(); }
#line 1378 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 108 "test05.y" /* yacc.c:1646  */
    {}
#line 1384 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "test05.y" /* yacc.c:1646  */
    {}
#line 1390 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 112 "test05.y" /* yacc.c:1646  */
    { asm_print_alloc((char*)(yyvsp[-1].str)); asm_print_string((char*)(yyvsp[-1].str)); }
#line 1396 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "test05.y" /* yacc.c:1646  */
    { asm_print_alloc_newline((char*)(yyvsp[-2].str)); asm_print_string((char*)(yyvsp[-2].str)); }
#line 1402 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "test05.y" /* yacc.c:1646  */
    { asm_print_exp((yyvsp[-1].str));  }
#line 1408 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "test05.y" /* yacc.c:1646  */
    { asm_print_exp_newline((yyvsp[-2].str));  }
#line 1414 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "test05.y" /* yacc.c:1646  */
    { asm_print_hex((yyvsp[-1].str));  }
#line 1420 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "test05.y" /* yacc.c:1646  */
    { asm_print_hex_newline((yyvsp[-2].str));  }
#line 1426 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "test05.y" /* yacc.c:1646  */
    { asm_assign((char*)(yyvsp[-3].str),(char*)(yyvsp[-1].str)); }
#line 1432 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 120 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; asm_add((yyvsp[-2].str),(yyvsp[0].str)); }
#line 1438 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; asm_sub((yyvsp[-2].str),(yyvsp[0].str)); }
#line 1444 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; asm_mul((char*)(yyvsp[-2].str),(char*)(yyvsp[0].str)); }
#line 1450 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 123 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; asm_div((char*)(yyvsp[-2].str),(char*)(yyvsp[0].str)); ; }
#line 1456 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 124 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; asm_mod((char*)(yyvsp[-2].str),(char*)(yyvsp[0].str)); }
#line 1462 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 125 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = minus((yyvsp[0].str)); 	printf("t %s\n",(yyval.str));}
#line 1468 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 126 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = "pop"; }
#line 1474 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 127 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = (char*)(yyvsp[0].str); }
#line 1480 "test05.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "test05.y" /* yacc.c:1646  */
    { (yyval.str) = (char*)(yyvsp[0].str); }
#line 1486 "test05.tab.c" /* yacc.c:1646  */
    break;


#line 1490 "test05.tab.c" /* yacc.c:1646  */
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
#line 130 "test05.y" /* yacc.c:1906  */


/*  syntax error */
void yyerror(){
	printf("error has occured line : %d\n",line);
}


void reset_flag_condition(){
	check_while = check_if = 0;
}

char* minus(char* a){
	char* temp = (char*)malloc(sizeof(char)*strlen(a)+1);
	sprintf(temp,"-%s",a);
	printf("%s\n",temp);
	return temp;
}

void asm_assign(char* var,char* val){
	int i;
	int flag=0;
	char temp_string[255];
	char temp[255];
	for(i=0 ; i<=top ; i++){
		if(strcmp(var,myVar[i].name)==0){
			if(strcmp(val,"pop")==0){
				strcpy(temp_string,"\tmov r9,[array+8*r8]\n");
				strcat(temp_string,"\tsub r8,1\n");
				strcat(temp_string,"\tmov [");
				strcat(temp_string,var);
				strcat(temp_string,"],r9\n");
			}
			else {
				strcpy(temp_string,"\tmov r9,");
				strcat(temp_string,val);
				strcat(temp_string,"\n");
				strcat(temp_string,"\tmov [");
				strcat(temp_string,var);
				strcat(temp_string,"],r9\n");
			}
			printf("%s\n\n",temp_string);
			if(check_else==0){
				strcat(temp_state,temp_string);
			}
			else{
				strcat(temp_state_else,temp_string);
			}

			flag = 1;
			break;
		}
	}
	if(!flag){
		++top;
		myVar[top].name = var;

		strcpy(temp_string,"\t");
		strcat(temp_string,var);
		strcpy(temp,":\tdq\t");
		strcat(temp_string,temp);
		strcat(temp_string,val);
		strcat(temp_string,"\n");
		strcat(data,temp_string);
	}
}

void asm_statement(){

	/* write all statement to file */
	fprintf(file,"%s",temp_state);

	int i;
	for(i=0 ; i<2048 ; i++) temp_state[i] = 0;
}

void asm_add(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;add\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tadd rax,r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}

}

void asm_sub(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;sub\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tsub rax,r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_mul(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;mul\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\timul dword r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_div(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;div\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tmov rdx,0\n");
	strcat(temp_exp,"\tidiv dword r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_mod(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;nod\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	char num_mod[2];
	sprintf(num_mod,"%d",count_mod++);
	strcat(temp_exp,"MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,":\n");
	strcat(temp_exp,"\tcmp rax,r10\n");
	strcat(temp_exp,"\tjl END_MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,"\n");
	strcat(temp_exp,"\tsub rax,r10\n");
	strcat(temp_exp,"\tjmp MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,"\n");
	strcat(temp_exp,"END_MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,":\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");
}

void asm_loop(char* a,char* b){
	char temp_string[1024] = "\nLOOP_";
	char num_loop[2];
	int i;

	sprintf(num_loop,"%d",count_loop++);
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");
	/* LOOP_0: */

	if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_string,"\tmov r10,");
		strcat(temp_string,a);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r10,[");
		strcat(temp_string,a);
		strcat(temp_string,"]\n");
	}

	if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_string,"\tmov r11,");
		strcat(temp_string,b);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r11,[");
		strcat(temp_string,b);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tcmp r10,r11\n");
	strcat(temp_string,"\tjge END_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");

	strcat(temp_string,"\nSTATE_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");

	strcat(temp_string,temp_state);
	strcat(temp_string,"\tmov r8,0\n");
	/* statement */
	for(i=0 ; i<255 ; i++) temp_state[i] = 0;

	strcat(temp_string,"\tjmp LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");
	strcat(temp_string,"\nEND_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n\n");

	fprintf(file,"%s",temp_string);

}

void asm_if(char* a,char* b){
	char temp_string[1024] = "\nSTATE_IF_";
	char num_if[2];
	int i;
	printf("if%s\nelse%s\n",temp_state,temp_state_else);
	sprintf(num_if,"%d",count_if++);
	strcat(temp_string,num_if);
	strcat(temp_string,":\n");

	strcat(temp_string,temp_condition_if);
	if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_string,"\tmov r10,");
		strcat(temp_string,a);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r10,[");
		strcat(temp_string,a);
		strcat(temp_string,"]\n");
	}

	if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_string,"\tmov r11,");
		strcat(temp_string,b);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r11,[");
		strcat(temp_string,b);
		strcat(temp_string,"]\n");
	}
	strcat(temp_string,"\tcmp r10,r11\n");
	strcat(temp_string,"\tje STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_TRUE\n");
	strcat(temp_string,"\tjmp STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_FALSE");
	strcat(temp_string,"\n");

	strcat(temp_string,"\nSTATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_TRUE:\n");
	strcat(temp_string,temp_state);
	strcat(temp_string,"\tjmp NEXT_STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"\n");

	/* add ELSE */
	strcat(temp_string,"\nSTATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_FALSE:\n");
	strcat(temp_string,temp_state_else);
	strcat(temp_string,"\n");

	/* END */
	strcat(temp_string,"\nNEXT_STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,":\n");


	strcat(temp_state,temp_string);

	strcpy(temp_state,temp_string);


	/* reset value */
	check_else = 0;

	for(i=0 ; i<255 ; i++){
		temp_condition_if[i]=0;
	}
}

void asm_print_string(char *msg){
	char temp_str[255];
	char num[2];
	sprintf(num,"%d",count_string-1);

	strcpy(temp_str,"\tmov\trdi,string_");
	strcat(temp_str,num);
	strcat(temp_str,"\n");
	strcat(temp_str,"\tmov\trsi,string_");
	strcat(temp_str,num);
	strcat(temp_str,"\n");
	strcat(temp_str,"\tmov\trax,0\n");
	strcat(temp_str,"\tcall printf\n");
	strcat(temp_str,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_str);
	}
	else strcat(temp_state_else,temp_str);
}

void asm_print_exp(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_num");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_exp_newline(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_num_newline");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_hex(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_hex");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_hex_newline(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_hex_newline");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_alloc(char *msg){
	char temp[255];
	char temp2[255];
	char num[2];
	strcpy(temp,"\t");
	strcpy(temp2,"string_");
	strcat(temp,temp2);

	sprintf(num,"%d",count_string++);
	strcat(temp,num);

	strcpy(temp2,": db ");
	strcat(temp,temp2);

	strcpy(temp2,msg);
	strcat(temp,temp2);

	strcpy(temp2,",0,0\n");
	strcat(temp,temp2);

	strcat(data,temp);
}

void asm_print_alloc_newline(char *msg){
	char temp[255];
	char temp2[255];
	char num[2];
	strcpy(temp,"\t");
	strcpy(temp2,"string_");
	strcat(temp,temp2);

	sprintf(num,"%d",count_string++);
	strcat(temp,num);

	strcpy(temp2,": db ");
	strcat(temp,temp2);

	strcpy(temp2,msg);
	strcat(temp,temp2);

	strcpy(temp2,",10,0\n");
	strcat(temp,temp2);

	strcat(data,temp);
}

void asm_print_init(){
	char temp[255];
	strcpy(data,"\n\nEXIT:\n\tpop rbp\n\tret\n\n");
	strcpy(temp,"section .data\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_num: db \"%d\",0,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_num_newline: db \"%d\",10,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_hex: db \"0x%x\",0,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_hex_newline: db \"0x%x\",10,0\n");
	strcat(data,temp);
	strcpy(temp,"\tarray :	dq	1,2,3,4,5\n");
	strcat(data,temp);
}


int main(void) {
printf(" < b start\n");
	file = fopen("test.asm", "w+");
	fprintf(file,"%s", "section .text\n");
	fprintf(file,"%s", "\textern printf\n");
	fprintf(file,"%s", "\tglobal main\n\n");
	fprintf(file,"%s", "main:\n");
	fprintf(file,"%s", "\tpush    rbp\n");
	fprintf(file,"%s", "\tmov rax,0 ; init\n");
	fprintf(file,"%s", "\tmov r8,-1 ;\n");

	asm_print_init();

    yyparse();

    fprintf(file,"%s", data);
    fclose(file);
    return 0;
}
