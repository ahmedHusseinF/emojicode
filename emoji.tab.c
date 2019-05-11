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
#line 1 "parsing/emoji.y" /* yacc.c:339  */

    #include <string>
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <unordered_map>
    #include <utility>
    #include <typeinfo>
    #include <stack>
    #include <string.h>

    #include "../parsing/symTable.hpp"
    using namespace std;
    // ////////////quadrauples/////////////
    void push(string);
    void gen_assign();
    void code_generate();
    void cond_if();
    void body_if();
    void else_if();
    void start_while ();
    void body_while ();
    void end_while ();
    void cond_for ();
    void loop_for ();
    void body_for ();
    void end_for ();
    void array_assign ();
    int label_number=0;
    std::string stack_for_quadruples[500];
    int label[50];
    int label_top=0;
    int top = 0;
    int temp_reg_count = 0;
    char temp [2]="t";
    /////////////////////
    SymbolTable* st;
    int currScope = 0; // the unique
    int depth = 0;
    void handle_error(Status ret);

    extern int yylex();
    extern int yylineno;
    void yyerror(const char *err) { cerr<<"Syntax Error: "<< err << " at line " << yylineno << endl; }

#line 113 "emoji.tab.c" /* yacc.c:339  */

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
    TIDENTIFIER = 258,
    TSTRING = 259,
    TINTEGER = 260,
    TFLOAT = 261,
    TCONST = 262,
    TIF = 263,
    TELSE = 264,
    TINTYPE = 265,
    TSTRINGTYPE = 266,
    TFLOATYPE = 267,
    TFOR = 268,
    TWHILE = 269,
    TBOOLTYPE = 270,
    TPASS = 271,
    TVOID = 272,
    TCEQ = 273,
    TCNE = 274,
    TCLT = 275,
    TCLE = 276,
    TCGT = 277,
    TCGE = 278,
    TEQUAL = 279,
    TTRUE = 280,
    TFALSE = 281,
    TSWITCH = 282,
    TDEFAULT = 283,
    TCASE = 284,
    TBREAK = 285,
    TLPAREN = 286,
    TRPAREN = 287,
    TLBRACE = 288,
    TRBRACE = 289,
    TCOMMA = 290,
    TSEP = 291,
    TCOLON = 292,
    TPLUS = 293,
    TMINUS = 294,
    TMUL = 295,
    TDIV = 296,
    TINC = 297,
    TDEC = 298,
    TAND = 299,
    TOR = 300,
    TNOT = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "parsing/emoji.y" /* yacc.c:355  */

    char* str;
    int token;
    float floaty;
    bool boolean;

#line 204 "emoji.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);



/* Copy the second part of user declarations.  */

#line 235 "emoji.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   475

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    94,    94,    97,    98,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   115,   115,   116,
     116,   117,   117,   118,   118,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   132,   135,   136,   137,   146,   146,
     149,   150,   153,   154,   155,   156,   157,   161,   161,   164,
     164,   167,   167,   170,   170,   173,   174,   175,   178,   179,
     180,   189,   189,   189,   190,   190,   190,   191,   191,   191,
     192,   192,   192,   193,   193,   193,   194,   194,   194,   195,
     195,   195,   196,   196,   196,   197,   197,   197,   198,   198,
     198,   199,   199,   199,   200,   200,   200,   201,   201,   201,
     202,   202,   202,   203,   203,   203,   204,   204,   204,   205,
     205,   205,   206,   206,   206,   207,   207,   207,   208,   208,
     208,   209,   209,   209,   210,   210,   210,   211,   211,   211,
     212,   212,   212,   213,   215,   215,   218,   218,   218,   219,
     219,   219,   220,   220,   220,   221,   221,   221,   222,   222,
     222,   223,   223,   223,   224,   224,   224,   225,   225,   225,
     226,   227,   227,   227,   228,   228,   228,   229,   229,   229,
     230,   230,   230,   231,   231,   232,   232,   235,   235,   235,
     235,   236,   236,   237,   237,   240,   241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENTIFIER", "TSTRING", "TINTEGER",
  "TFLOAT", "TCONST", "TIF", "TELSE", "TINTYPE", "TSTRINGTYPE",
  "TFLOATYPE", "TFOR", "TWHILE", "TBOOLTYPE", "TPASS", "TVOID", "TCEQ",
  "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TTRUE", "TFALSE",
  "TSWITCH", "TDEFAULT", "TCASE", "TBREAK", "TLPAREN", "TRPAREN",
  "TLBRACE", "TRBRACE", "TCOMMA", "TSEP", "TCOLON", "TPLUS", "TMINUS",
  "TMUL", "TDIV", "TINC", "TDEC", "TAND", "TOR", "TNOT", "$accept",
  "program", "stmts", "stmt", "func_decl", "$@1", "$@2", "$@3", "$@4",
  "args", "func_call", "call_args", "switch_statemnet", "$@5",
  "case_blocks", "case_stmt", "for_loop", "$@6", "while_loop", "$@7",
  "if_cond", "$@8", "if_else_cond", "$@9", "const_decl", "var_decl",
  "expr", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35",
  "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44",
  "$@45", "$@46", "$@47", "$@48", "$@49", "$@50", "$@51", "$@52", "$@53",
  "$@54", "$@55", "$@56", "$@57", "$@58", "arithmetic", "$@59", "$@60",
  "$@61", "$@62", "$@63", "$@64", "$@65", "$@66", "$@67", "$@68", "$@69",
  "$@70", "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "$@77", "$@78",
  "$@79", "$@80", "$@81", "$@82", "$@83", "$@84", "assignment", "$@85",
  "$@86", "$@87", "$@88", "$@89", "optexpr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -171

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     448,   -25,     4,    68,    14,    34,    40,    28,    36,    72,
     -19,    79,    45,    88,   423,  -119,  -119,  -119,  -119,  -119,
    -119,    82,  -119,    57,    60,    63,  -119,     0,    76,    80,
      85,   108,   114,   120,     0,    94,    96,     0,     0,    98,
    -119,   127,   132,  -119,  -119,   118,  -119,  -119,  -119,    50,
    -119,  -119,   -11,   424,   155,     0,     1,   136,   146,   147,
      42,     3,     3,   424,   137,   221,     3,     3,   140,  -119,
     157,   165,   172,   164,   171,   175,   158,   159,   185,   188,
     190,   195,   196,   194,   176,   174,   191,   193,     0,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,   424,   104,
     -31,     1,   223,  -119,     1,   234,     0,   212,  -119,  -119,
    -119,  -119,    -7,    -1,     0,   213,     6,    18,   215,   448,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,     0,  -119,   424,   246,
     247,   249,   259,   260,   261,   264,   265,  -119,   186,   230,
     231,   233,   237,   232,  -119,   243,   258,   263,   245,  -119,
     266,   294,   298,  -119,  -119,   424,  -119,   272,    12,   275,
     281,  -119,   285,   286,  -119,   123,   315,   316,   318,   320,
     322,   325,   334,   335,     0,     0,     0,     0,     0,     0,
       0,     0,   238,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   448,  -119,  -119,  -119,  -119,
    -119,  -119,     0,   448,  -119,  -119,   126,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,     1,     1,     1,     1,  -119,  -119,     1,
       1,     1,     1,  -119,  -119,   198,   448,   448,   309,   220,
     448,   448,   305,   338,   311,    73,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,   277,   299,   312,  -119,
     321,   343,   387,   324,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,   313,    41,   405,   448,  -119,  -119,   326,   105,
     365,  -119,  -119,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,    13,    14,    12,    11,
      10,     8,     9,     0,     0,     0,    16,    35,     0,     0,
       0,     0,     0,     0,     0,    58,    59,   186,     0,    60,
      15,     0,     0,     1,     4,     0,     6,     5,     7,    61,
     134,   133,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    25,    25,   185,     0,     0,    25,    25,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     112,   115,   118,   121,   124,   127,   130,   178,   182,   175,
     173,     0,   161,   184,     0,     0,     0,     0,    26,    27,
      28,    29,     0,     0,   186,     0,     0,     0,     0,     0,
      62,    65,    68,    71,    74,    77,    80,    83,    86,    89,
      92,    95,    98,   101,   104,   107,     0,    34,    37,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,   174,
       0,     0,     0,    55,    56,    57,    51,     0,     0,     0,
       0,    49,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   113,   116,   119,   122,   125,   128,
     131,   180,   137,   140,   143,   146,   168,   171,   149,   152,
     155,   158,   160,   162,   165,     0,    17,    30,    31,    32,
      33,    19,   186,     0,    21,    23,     0,    54,    63,    66,
      69,    72,    75,    78,    81,    84,    87,    90,    93,    96,
      99,   102,   105,   108,   135,   111,   114,   117,   120,   123,
     126,   129,   132,     0,     0,     0,     0,   169,   172,     0,
       0,     0,     0,   163,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,   138,   141,   144,
     147,   150,   153,   156,   159,    52,     0,     0,     0,    50,
       0,     0,     0,     0,    46,    39,    41,    18,    20,    47,
      22,    24,     0,     0,     0,     0,    45,    44,     0,     0,
       0,    43,    42,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -118,   -14,  -119,  -119,  -119,  -119,  -119,    23,
     -22,  -119,  -119,  -119,  -119,    77,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,    -8,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,   -65,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,   266,   267,   270,   271,   112,
      17,    52,    18,   226,   275,   276,    19,   305,    20,   223,
      21,   215,    22,   119,    23,    24,    63,    70,   176,    71,
     177,    72,   178,    73,   179,    74,   180,    75,   181,    76,
     182,    77,   183,    78,   184,    79,   185,    80,   186,    81,
     187,    82,   188,    83,   189,    84,   190,    85,   191,   139,
     245,   140,   246,   141,   247,   142,   248,   143,   249,   144,
     250,   145,   251,   146,   252,    86,   103,   148,   253,   149,
     254,   150,   255,   151,   256,   155,   259,   156,   260,   157,
     261,   158,   262,   161,   263,   162,   264,   152,   257,   153,
     258,   159,   154,    25,    28,   147,   201,    29,    30,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   175,   170,    49,    99,    51,   100,  -148,  -151,  -154,
    -157,    26,    51,   108,   109,    51,    51,    40,   110,    53,
     111,    87,   217,   218,    88,   167,    60,   219,   168,   220,
      65,   169,   101,    51,   168,    27,   160,    35,   172,   163,
     102,   168,     1,    36,     2,    34,    50,    98,     3,     4,
     173,     5,     6,   168,     7,     8,     9,    10,    11,    37,
      89,    90,    91,    92,    93,    94,    51,    38,    12,   -64,
     -67,   -70,   -73,   -76,   107,    39,    42,   307,    31,    32,
     138,    27,    41,    33,    51,   113,    95,    96,    43,   116,
     117,    45,    51,    46,   -79,   -82,    47,   265,   165,    48,
      54,   272,   273,   274,    55,   269,     1,   295,     2,    56,
     268,    57,     3,     4,    51,     5,     6,    58,     7,     8,
       9,    10,    11,    59,     1,    61,     2,    62,   192,    66,
       3,     4,    12,     5,     6,    68,     7,     8,     9,    10,
      11,   312,  -136,  -139,  -142,  -145,  -167,  -170,   286,   287,
      12,    69,   290,   291,   272,   273,   274,   227,    67,    97,
     104,    44,    51,    51,    51,    51,    51,    51,    51,    51,
     105,   106,   118,   114,   303,   120,   236,   237,   238,   239,
     240,   241,   242,   243,   121,   123,   309,   310,   277,   278,
     279,   280,   122,   124,   281,   282,   283,   284,   125,     1,
      51,     2,   126,   128,   127,     3,     4,   129,     5,     6,
     130,     7,     8,     9,    10,    11,   131,   133,   132,   135,
     134,     1,   136,     2,   202,    12,  -164,     3,     4,   137,
       5,     6,   285,     7,     8,     9,    10,    11,   164,    89,
      90,    91,    92,    93,    94,   166,   171,    12,   174,   193,
     194,    44,   195,   115,   289,    44,    89,    90,    91,    92,
      93,    94,   196,   197,   198,    95,    96,   199,   200,   203,
     244,   204,    44,    44,   205,   207,    44,    44,     1,   206,
       2,   208,    95,    96,     3,     4,   211,     5,     6,    44,
       7,     8,     9,    10,    11,    44,    44,   209,   212,   213,
       1,   214,     2,   210,    12,   216,     3,     4,   221,     5,
       6,   297,     7,     8,     9,    10,    11,   222,   224,   225,
     228,   229,     1,   230,     2,   231,    12,   232,     3,     4,
     233,     5,     6,   298,     7,     8,     9,    10,    11,   234,
     235,   288,   292,   293,     1,   299,     2,   294,    12,   306,
       3,     4,   296,     5,     6,   300,     7,     8,     9,    10,
      11,   304,   311,     0,     0,     0,     1,     0,     2,     0,
      12,     0,     3,     4,     0,     5,     6,   301,     7,     8,
       9,    10,    11,     0,     0,     0,     0,     0,     1,     0,
       2,     0,    12,     0,     3,     4,     0,     5,     6,   313,
       7,     8,     9,    10,    11,     0,     1,     0,     2,     0,
       0,     0,     3,     4,    12,     5,     6,   302,     7,     8,
       9,    10,    11,    -2,     1,     0,     2,     0,     0,     0,
       3,     4,    12,     5,     6,   308,     7,     8,     9,    10,
      11,     0,    89,    90,    91,    92,    93,    94,     0,     1,
      12,     2,     0,     0,     0,     3,     4,     0,     5,     6,
       0,     7,     8,     9,    10,    11,     0,     0,    95,    96,
       0,     0,     0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      14,   119,   114,     3,     3,    27,     5,    38,    39,    40,
      41,    36,    34,    10,    11,    37,    38,    36,    15,    27,
      17,    32,    10,    11,    35,    32,    34,    15,    35,    17,
      38,    32,    31,    55,    35,    31,   101,     3,    32,   104,
      39,    35,     1,     3,     3,    31,    46,    55,     7,     8,
      32,    10,    11,    35,    13,    14,    15,    16,    17,    31,
      18,    19,    20,    21,    22,    23,    88,    31,    27,    19,
      20,    21,    22,    23,    32,     3,    31,    36,    10,    11,
      88,    31,     3,    15,   106,    62,    44,    45,     0,    66,
      67,     9,   114,    36,    44,    45,    36,   215,   106,    36,
      24,    28,    29,    30,    24,   223,     1,    34,     3,    24,
     222,     3,     7,     8,   136,    10,    11,     3,    13,    14,
      15,    16,    17,     3,     1,    31,     3,    31,   136,    31,
       7,     8,    27,    10,    11,     3,    13,    14,    15,    16,
      17,    36,    38,    39,    40,    41,    42,    43,   266,   267,
      27,    33,   270,   271,    28,    29,    30,    34,    31,     4,
      24,   175,   184,   185,   186,   187,   188,   189,   190,   191,
      24,    24,    32,    36,   292,    18,   184,   185,   186,   187,
     188,   189,   190,   191,    19,    21,   304,   305,   253,   254,
     255,   256,    20,    22,   259,   260,   261,   262,    23,     1,
     222,     3,    44,    18,    45,     7,     8,    19,    10,    11,
      20,    13,    14,    15,    16,    17,    21,    23,    22,    45,
      44,     1,    31,     3,    38,    27,     3,     7,     8,    36,
      10,    11,    34,    13,    14,    15,    16,    17,     4,    18,
      19,    20,    21,    22,    23,    33,    33,    27,    33,     3,
       3,   265,     3,    32,    34,   269,    18,    19,    20,    21,
      22,    23,     3,     3,     3,    44,    45,     3,     3,    39,
      32,    40,   286,   287,    41,    43,   290,   291,     1,    42,
       3,    38,    44,    45,     7,     8,    41,    10,    11,   303,
      13,    14,    15,    16,    17,   309,   310,    39,    32,     5,
       1,     3,     3,    40,    27,    33,     7,     8,    33,    10,
      11,    34,    13,    14,    15,    16,    17,    36,    33,    33,
       5,     5,     1,     5,     3,     5,    27,     5,     7,     8,
       5,    10,    11,    34,    13,    14,    15,    16,    17,     5,
       5,    32,    37,     5,     1,    33,     3,    36,    27,    36,
       7,     8,   275,    10,    11,    34,    13,    14,    15,    16,
      17,    37,    36,    -1,    -1,    -1,     1,    -1,     3,    -1,
      27,    -1,     7,     8,    -1,    10,    11,    34,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,    -1,    27,    -1,     7,     8,    -1,    10,    11,    34,
      13,    14,    15,    16,    17,    -1,     1,    -1,     3,    -1,
      -1,    -1,     7,     8,    27,    10,    11,    30,    13,    14,
      15,    16,    17,     0,     1,    -1,     3,    -1,    -1,    -1,
       7,     8,    27,    10,    11,    30,    13,    14,    15,    16,
      17,    -1,    18,    19,    20,    21,    22,    23,    -1,     1,
      27,     3,    -1,    -1,    -1,     7,     8,    -1,    10,    11,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,    10,    11,    13,    14,    15,
      16,    17,    27,    48,    49,    50,    51,    57,    59,    63,
      65,    67,    69,    71,    72,   150,    36,    31,   151,   154,
     155,    10,    11,    15,    31,     3,     3,    31,    31,     3,
      36,     3,    31,     0,    50,     9,    36,    36,    36,     3,
      46,    57,    58,    73,    24,    24,    24,     3,     3,     3,
      73,    31,    31,    73,   156,    73,    31,    31,     3,    33,
      74,    76,    78,    80,    82,    84,    86,    88,    90,    92,
      94,    96,    98,   100,   102,   104,   122,    32,    35,    18,
      19,    20,    21,    22,    23,    44,    45,     4,    73,     3,
       5,    31,    39,   123,    24,    24,    24,    32,    10,    11,
      15,    17,    56,    56,    36,    32,    56,    56,    32,    70,
      18,    19,    20,    21,    22,    23,    44,    45,    18,    19,
      20,    21,    22,    23,    44,    45,    31,    36,    73,   106,
     108,   110,   112,   114,   116,   118,   120,   152,   124,   126,
     128,   130,   144,   146,   149,   132,   134,   136,   138,   148,
     123,   140,   142,   123,     4,    73,    33,    32,    35,    32,
     156,    33,    32,    32,    33,    49,    75,    77,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,    73,     3,     3,     3,     3,     3,     3,     3,
       3,   153,    38,    39,    40,    41,    42,    43,    38,    39,
      40,    41,    32,     5,     3,    68,    33,    10,    11,    15,
      17,    33,    36,    66,    33,    33,    60,    34,     5,     5,
       5,     5,     5,     5,     5,     5,    73,    73,    73,    73,
      73,    73,    73,    73,    32,   107,   109,   111,   113,   115,
     117,   119,   121,   125,   127,   129,   131,   145,   147,   133,
     135,   137,   139,   141,   143,    49,    52,    53,   156,    49,
      54,    55,    28,    29,    30,    61,    62,   123,   123,   123,
     123,   123,   123,   123,   123,    34,    49,    49,    32,    34,
      49,    49,    37,     5,    36,    34,    62,    34,    34,    33,
      34,    34,    30,    49,    37,    64,    36,    36,    30,    49,
      49,    36,    36,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    52,    51,    53,
      51,    54,    51,    55,    51,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    58,    58,    58,    60,    59,
      61,    61,    62,    62,    62,    62,    62,    64,    63,    66,
      65,    68,    67,    70,    69,    71,    71,    71,    72,    72,
      72,    74,    75,    73,    76,    77,    73,    78,    79,    73,
      80,    81,    73,    82,    83,    73,    84,    85,    73,    86,
      87,    73,    88,    89,    73,    90,    91,    73,    92,    93,
      73,    94,    95,    73,    96,    97,    73,    98,    99,    73,
     100,   101,    73,   102,   103,    73,   104,   105,    73,   106,
     107,    73,   108,   109,    73,   110,   111,    73,   112,   113,
      73,   114,   115,    73,   116,   117,    73,   118,   119,    73,
     120,   121,    73,    73,   122,    73,   124,   125,   123,   126,
     127,   123,   128,   129,   123,   130,   131,   123,   132,   133,
     123,   134,   135,   123,   136,   137,   123,   138,   139,   123,
     123,   140,   141,   123,   142,   143,   123,   144,   145,   123,
     146,   147,   123,   148,   123,   149,   123,   151,   152,   153,
     150,   154,   150,   155,   150,   156,   156
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     9,     0,
       9,     0,     9,     0,     9,     0,     1,     1,     1,     1,
       3,     3,     3,     3,     5,     0,     1,     3,     0,     8,
       1,     2,     5,     5,     4,     4,     2,     0,    12,     0,
       8,     0,     8,     0,     6,     5,     5,     5,     2,     2,
       2,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     1,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       3,     0,     0,     4,     0,     0,     4,     0,     0,     4,
       0,     0,     4,     0,     2,     0,     2,     0,     0,     0,
       6,     0,     4,     0,     4,     1,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 17:
#line 115 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1684 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1690 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1696 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1702 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1708 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 117 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1714 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 118 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1720 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1726 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 146 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1732 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 146 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1738 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 161 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1744 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 161 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1750 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1756 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 164 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1762 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 167 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1768 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 167 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1774 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "parsing/emoji.y" /* yacc.c:1646  */
    {depth++;currScope++;}
#line 1780 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 170 "parsing/emoji.y" /* yacc.c:1646  */
    {depth--;currScope++;}
#line 1786 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 173 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.Number=(yyvsp[0].token);handle_error(st->insert((yyvsp[-2].str), currScope, depth, Types::INT, val, true));}
#line 1792 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 174 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.str=(yyvsp[0].str);handle_error(st->insert((yyvsp[-2].str), currScope, depth, Types::STRING, val, true));}
#line 1798 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 175 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.Number=(yyvsp[0].boolean);handle_error(st->insert((yyvsp[-2].str), currScope, depth, Types::BOOLEAN, val, true));}
#line 1804 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 178 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.Number=0;handle_error(st->insert((yyvsp[0].str), currScope, depth, Types::INT, val, false));}
#line 1810 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 179 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.str=strdup("");handle_error(st->insert((yyvsp[0].str), currScope, depth, Types::STRING, val, false));}
#line 1816 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 180 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.Number=0;handle_error(st->insert((yyvsp[0].str), currScope, depth, Types::BOOLEAN, val, false));}
#line 1822 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 189 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1828 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 189 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "==";}
#line 1834 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 189 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1840 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 190 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1846 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 190 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "!=";}
#line 1852 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 190 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1858 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 191 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1864 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 191 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<";}
#line 1870 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 191 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1876 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 192 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1882 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 192 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<=";}
#line 1888 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 192 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1894 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 193 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1900 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 193 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">";}
#line 1906 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 193 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1912 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 194 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1918 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 194 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">=";}
#line 1924 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1930 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1936 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 195 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "&&";}
#line 1942 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 195 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1948 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 196 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1954 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 196 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "||";}
#line 1960 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 196 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 1966 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 197 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1972 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 197 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "==";}
#line 1978 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 197 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 1984 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 198 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1990 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 198 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "!=";}
#line 1996 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 198 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2002 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 199 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2008 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 199 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<";}
#line 2014 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 199 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2020 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 200 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2026 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 200 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<=";}
#line 2032 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 200 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2038 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 201 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2044 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 201 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">";}
#line 2050 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 201 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2056 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 202 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2062 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 202 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">=";}
#line 2068 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 202 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2074 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 203 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2080 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 203 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "&&";}
#line 2086 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 203 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2092 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 204 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2098 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 204 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "||";}
#line 2104 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 204 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2110 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 205 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "==";}
#line 2116 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 205 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2122 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 205 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2128 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 206 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "!=";}
#line 2134 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 206 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2140 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 206 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2146 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 207 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<";}
#line 2152 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 207 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2158 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 207 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2164 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 208 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "<=";}
#line 2170 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 208 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2176 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 208 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2182 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 209 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">";}
#line 2188 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 209 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2194 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 209 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2200 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 210 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = ">=";}
#line 2206 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 210 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2212 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 210 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2218 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 211 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "&&";}
#line 2224 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 211 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2230 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 211 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2236 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 212 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "||";}
#line 2242 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 212 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2248 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 212 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2254 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 215 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "!";}
#line 2260 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 215 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2266 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 218 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2272 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 218 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "+";}
#line 2278 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 219 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2284 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 219 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "-";}
#line 2290 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 220 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2296 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 220 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "*";}
#line 2302 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 221 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2308 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 221 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "/";}
#line 2314 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 222 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2320 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 222 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "+";}
#line 2326 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 223 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2332 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 223 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "-";}
#line 2338 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 224 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2344 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 224 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "*";}
#line 2350 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 225 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2356 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 225 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "/";}
#line 2362 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 227 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "-";}
#line 2368 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 227 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2374 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 227 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2380 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 228 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "-";}
#line 2386 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 228 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2392 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 228 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2398 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 229 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2404 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 229 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "++";}
#line 2410 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 229 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2416 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 230 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2422 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 230 "parsing/emoji.y" /* yacc.c:1646  */
    {stack_for_quadruples[++top] = "--";}
#line 2428 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 230 "parsing/emoji.y" /* yacc.c:1646  */
    {code_generate();}
#line 2434 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 231 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].token));}
#line 2440 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 231 "parsing/emoji.y" /* yacc.c:1646  */
    {gen_assign();}
#line 2446 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 232 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2452 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 232 "parsing/emoji.y" /* yacc.c:1646  */
    {gen_assign();}
#line 2458 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 235 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2464 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 235 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2470 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 235 "parsing/emoji.y" /* yacc.c:1646  */
    {gen_assign();}
#line 2476 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 235 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.str = (yyvsp[-2].str); handle_error(st->modify((yyvsp[-5].str), Types::STRING, val, depth));}
#line 2482 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 236 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2488 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 236 "parsing/emoji.y" /* yacc.c:1646  */
    {Values val; val.Number = (yyvsp[0].boolean) ? 1 : 0; handle_error(st->modify((yyvsp[-3].str), Types::BOOLEAN, val, depth));}
#line 2494 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 237 "parsing/emoji.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2500 "emoji.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 237 "parsing/emoji.y" /* yacc.c:1646  */
    {cout<<"in int ass";Values val; val.Number = (yyvsp[0].token); handle_error(st->modify((yyvsp[-3].str), Types::INT, val, depth));}
#line 2506 "emoji.tab.c" /* yacc.c:1646  */
    break;


#line 2510 "emoji.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 244 "parsing/emoji.y" /* yacc.c:1906  */


void handle_error(Status ret) {
    switch(ret) {
        case SYMBOL_NOT_FOUND:
            cerr << "Symbol not found"<<endl;
        break;
        case SUCCESSFUL_INSERTION:
            cerr << "Inserted symbol successfully"<<endl;
        break;
        case DUPLICATE_INSERTION:
            cerr << "Duplicate Insertion"<<endl;
        break;
        case FAILED_TO_INSERTION:
            cerr << "Failed to insert"<<endl;
        break;
        case SUCCESSFUL_UPDATE:
            cerr << "Updated successfully"<<endl;
        break;
        case SEMANTIC_ERROR_TYPE_INCOMPATIBLE:
            cerr << "Type mismatch"<<endl;
        break;
        case SEMANTIC_ERROR_ATTEMPT_CHANGING_CONSTANT:
            cerr << "Can't change a constant"<<endl;
        break;
        default:
            cout<<"Weird: "<<ret<<endl;
        break;
    }
}
// for quadruples
void push(string a)
{
    std::cout<<"pushed"<<endl;
    stack_for_quadruples[++top] = a;
}
void gen_assign()
{
    string value = stack_for_quadruples[top];
    string variable = stack_for_quadruples[top-2];
    std::cout<<"MOV"<<variable << " , "<<value<<endl;
    top-=2;
}
void code_generate()
{
    string variable1 = stack_for_quadruples[top-2];
    string operand = stack_for_quadruples[top-1];
    string variable2 = stack_for_quadruples[top];
    temp[2] = (char)temp_reg_count;
    if (operand == "+")
    {
        std::cout<<"ADD"<< " "<<temp << " " <<variable1<<" , "<<variable2<<endl;
        top-=2;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "-")
    {
        std::cout<<"SUB"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "*")
    {
        std::cout<<"MUL"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "/")
    {
        std::cout<<"DIV"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "==" )
    {
        std::cout <<"SEQ"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "!=")
    {
        std::cout <<"SNQ"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "<")
    {
        std::cout <<"SLT"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "<=")
    {
        std::cout <<"SLQ"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == ">")
    {
        std::cout <<"GRT"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == ">=")
    {
        std::cout <<"GRQ"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "&&")
    {
        std::cout <<"AND"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "||")
    {
        std::cout <<"OR"<< " "<<temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "!")
    {
        std::cout <<"NOT" << " " << temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "++")
    {
        std::cout <<"INC" << " " << temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "--")
    {
        std::cout <<"DEC" << " " << temp<< " " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }

}
void cond_if ()
{
    label_number++;
    temp[1] = (char)temp_reg_count;
    std::cout<<"NOT"<<" "<<temp<<" "<<stack_for_quadruples[top]<<endl;
    std::cout<<"IF"<<" "<<temp<<" "<<"goto Label"<<" "<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number; 
}
void body_if ()
{
    label_number++;
    std::cout<<"goto "<<label_number<<endl;
    std::cout<<"Label: "<<label[label_top--]<<endl;
    label[++label_top] = label_number;
}
void else_if ()
{
    std::cout<<"Label: "<<label[label_top--];
}
void start_while ()
{
    label_number++;
    label[++label_top] = label_number;
    std::cout<<"Label: "<<label_number;
}
void body_while ()
{
    label_number++;
    temp[1] = (char)temp_reg_count;
    std::cout<<"NOT "<<temp<<" , "<<stack_for_quadruples[top--]<<endl;
    std::cout<<"IF "<<temp<<" goto Label"<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number;
}
void end_while ()
{
    int dumy = label[label_top--];
    std::cout<<"goto Label"<<label[label_top--]<<endl;;
    std::cout<<"Label: "<<dumy<<endl;
}
void cond_for ()
{
    label_number++;
    label[++label_top] = label_number;
    std::cout<<"Label: "<<label_number<<endl;
}
void loop_for ()
{
    label_number++;
    temp[1] = (char)temp_reg_count;
    std::cout<<"NOT "<<temp<<" , "<<stack_for_quadruples[top--]<<endl;
    std::cout<<"IF "<<temp<<" goto Label"<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number++;
    std::cout<<"goto Label"<<label_number<<endl;
    label[++label_top] = label_number++;
    std::cout<<"goto Label"<<label_number<<endl;
    label[++label_top] = label_number; 
}
void body_for ()
{
    std::cout<<"goto Label"<<label[label_top-3]<<endl;
    std::cout<<"Label: "<<label[label_top-1]<<endl;
}
void end_for ()
{
    std::cout<<"goto Label"<<label[label_top]<<endl;
    std::cout<<"Label: "<<label[label_top-2]<<endl;
    label_top-=4;
}
void array_assign ()
{
    temp[1] = (char)temp_reg_count;
    std::cout<<"MOV "<<temp<<" , "<<stack_for_quadruples[top]<<endl;
    stack_for_quadruples[top] = temp;
    temp_reg_count++;
    temp[1] = (char)temp_reg_count;
    std::cout<<"MOV "<<temp<<" , "<<stack_for_quadruples[top-1]<<"["<<stack_for_quadruples[top]<<"]"<<endl;
    top--;
    stack_for_quadruples[top] = temp;
    temp_reg_count++;
}

int main(void) {

    st = new SymbolTable();

    yyparse();

    st->print();

    delete st;

    return 0;
}
