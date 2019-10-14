/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         yara_yyparse
#define yylex           yara_yylex
#define yyerror         yara_yyerror
#define yydebug         yara_yydebug
#define yynerrs         yara_yynerrs


/* Copy the first part of user declarations.  */
#line 30 "grammar.y" /* yacc.c:339  */



#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#include <yara/integers.h>
#include <yara/utils.h>
#include <yara/strutils.h>
#include <yara/compiler.h>
#include <yara/object.h>
#include <yara/sizedstr.h>
#include <yara/exec.h>
#include <yara/error.h>
#include <yara/mem.h>
#include <yara/lexer.h>
#include <yara/parser.h>

#if defined(_MSC_VER)
#define llabs _abs64
#endif

#define YYERROR_VERBOSE

#define YYMALLOC yr_malloc
#define YYFREE yr_free

#define INTEGER_SET_ENUMERATION   1
#define INTEGER_SET_RANGE         2

#define FOR_EXPRESSION_ALL 1
#define FOR_EXPRESSION_ANY 2

#define fail_if_error(e) \
    if (e != ERROR_SUCCESS) \
    { \
      compiler->last_error = e; \
      yyerror(yyscanner, compiler, NULL); \
      YYERROR; \
    } \


#define set_flag_or_error(flags, new_flag) \
    if (flags & new_flag) \
    { \
      compiler->last_error = ERROR_DUPLICATED_MODIFIER; \
      yyerror(yyscanner, compiler, NULL); \
      YYERROR; \
    } \
    else \
    { \
      flags |= new_flag; \
    }


#define check_type_with_cleanup(expression, expected_type, op, cleanup) \
    if (((expression.type) & (expected_type)) == 0) \
    { \
      switch(expression.type) \
      { \
        case EXPRESSION_TYPE_INTEGER: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"integer\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_FLOAT: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"float\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_STRING: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"string\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_BOOLEAN: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"boolean\" for " op " operator"); \
          break; \
      } \
      cleanup; \
      compiler->last_error = ERROR_WRONG_TYPE; \
      yyerror(yyscanner, compiler, NULL); \
      YYERROR; \
    }

// check_type(expression, EXPRESSION_TYPE_INTEGER | EXPRESSION_TYPE_FLOAT) is
// used to ensure that the type of "expression" is either integer or float.
#define check_type(expression, expected_type, op) \
    check_type_with_cleanup(expression, expected_type, op, )


#line 166 "grammar.c" /* yacc.c:339  */

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
#ifndef YY_YARA_YY_GRAMMAR_H_INCLUDED
# define YY_YARA_YY_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yara_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _END_OF_FILE_ = 0,
    _END_OF_INCLUDED_FILE_ = 258,
    _DOT_DOT_ = 259,
    _RULE_ = 260,
    _PRIVATE_ = 261,
    _GLOBAL_ = 262,
    _META_ = 263,
    _STRINGS_ = 264,
    _CONDITION_ = 265,
    _IDENTIFIER_ = 266,
    _STRING_IDENTIFIER_ = 267,
    _STRING_COUNT_ = 268,
    _STRING_OFFSET_ = 269,
    _STRING_LENGTH_ = 270,
    _STRING_IDENTIFIER_WITH_WILDCARD_ = 271,
    _NUMBER_ = 272,
    _DOUBLE_ = 273,
    _INTEGER_FUNCTION_ = 274,
    _TEXT_STRING_ = 275,
    _HEX_STRING_ = 276,
    _REGEXP_ = 277,
    _ASCII_ = 278,
    _WIDE_ = 279,
    _XOR_ = 280,
    _NOCASE_ = 281,
    _FULLWORD_ = 282,
    _AT_ = 283,
    _FILESIZE_ = 284,
    _ENTRYPOINT_ = 285,
    _ALL_ = 286,
    _ANY_ = 287,
    _IN_ = 288,
    _OF_ = 289,
    _FOR_ = 290,
    _THEM_ = 291,
    _MATCHES_ = 292,
    _CONTAINS_ = 293,
    _IMPORT_ = 294,
    _TRUE_ = 295,
    _FALSE_ = 296,
    _OR_ = 297,
    _AND_ = 298,
    _NOT_ = 299,
    _EQ_ = 300,
    _NEQ_ = 301,
    _LT_ = 302,
    _LE_ = 303,
    _GT_ = 304,
    _GE_ = 305,
    _SHIFT_LEFT_ = 306,
    _SHIFT_RIGHT_ = 307,
    UNARY_MINUS = 308
  };
#endif
/* Tokens.  */
#define _END_OF_FILE_ 0
#define _END_OF_INCLUDED_FILE_ 258
#define _DOT_DOT_ 259
#define _RULE_ 260
#define _PRIVATE_ 261
#define _GLOBAL_ 262
#define _META_ 263
#define _STRINGS_ 264
#define _CONDITION_ 265
#define _IDENTIFIER_ 266
#define _STRING_IDENTIFIER_ 267
#define _STRING_COUNT_ 268
#define _STRING_OFFSET_ 269
#define _STRING_LENGTH_ 270
#define _STRING_IDENTIFIER_WITH_WILDCARD_ 271
#define _NUMBER_ 272
#define _DOUBLE_ 273
#define _INTEGER_FUNCTION_ 274
#define _TEXT_STRING_ 275
#define _HEX_STRING_ 276
#define _REGEXP_ 277
#define _ASCII_ 278
#define _WIDE_ 279
#define _XOR_ 280
#define _NOCASE_ 281
#define _FULLWORD_ 282
#define _AT_ 283
#define _FILESIZE_ 284
#define _ENTRYPOINT_ 285
#define _ALL_ 286
#define _ANY_ 287
#define _IN_ 288
#define _OF_ 289
#define _FOR_ 290
#define _THEM_ 291
#define _MATCHES_ 292
#define _CONTAINS_ 293
#define _IMPORT_ 294
#define _TRUE_ 295
#define _FALSE_ 296
#define _OR_ 297
#define _AND_ 298
#define _NOT_ 299
#define _EQ_ 300
#define _NEQ_ 301
#define _LT_ 302
#define _LE_ 303
#define _GT_ 304
#define _GE_ 305
#define _SHIFT_LEFT_ 306
#define _SHIFT_RIGHT_ 307
#define UNARY_MINUS 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 264 "grammar.y" /* yacc.c:355  */

  YR_EXPRESSION   expression;
  SIZED_STRING*   sized_string;
  char*           c_string;
  int64_t         integer;
  double          double_;
  YR_STRING*      string;
  YR_META*        meta;
  YR_RULE*        rule;
  YR_MODIFIER     modifier;

#line 326 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yara_yyparse (void *yyscanner, YR_COMPILER* compiler);

#endif /* !YY_YARA_YY_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 342 "grammar.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   385

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    60,    55,     2,
      68,    69,    58,    56,    73,    57,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
       2,    67,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,    59,    72,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,    53,    65,    61,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   279,   279,   281,   282,   283,   284,   285,   286,   294,
     307,   312,   306,   333,   336,   366,   369,   394,   399,   400,
     405,   406,   412,   415,   433,   442,   481,   482,   487,   504,
     518,   532,   546,   564,   565,   571,   570,   586,   585,   603,
     602,   624,   629,   649,   650,   651,   652,   653,   654,   660,
     681,   715,   716,   720,   721,   722,   723,   724,   728,   729,
     733,   737,   826,   873,   932,   978,   979,   983,  1011,  1051,
    1094,  1114,  1121,  1128,  1140,  1150,  1164,  1179,  1190,  1251,
    1285,  1199,  1403,  1402,  1487,  1493,  1500,  1499,  1545,  1544,
    1588,  1595,  1602,  1609,  1616,  1623,  1630,  1634,  1642,  1670,
    1679,  1688,  1697,  1721,  1736,  1756,  1755,  1761,  1773,  1774,
    1779,  1786,  1797,  1801,  1806,  1815,  1819,  1827,  1839,  1853,
    1861,  1868,  1893,  1905,  1917,  1933,  1945,  1961,  2013,  2034,
    2069,  2104,  2138,  2163,  2180,  2190,  2200,  2210,  2220,  2240,
    2260
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"end of included file\"",
  "\"..\"", "\"<rule>\"", "\"<private>\"", "\"<global>\"", "\"<meta>\"",
  "\"<strings>\"", "\"<condition>\"", "\"identifier\"",
  "\"string identifier\"", "\"string count\"", "\"string offset\"",
  "\"string length\"", "\"string identifier with wildcard\"",
  "\"integer number\"", "\"floating point number\"",
  "\"integer function\"", "\"text string\"", "\"hex string\"",
  "\"regular expression\"", "\"<ascii>\"", "\"<wide>\"", "\"<xor>\"",
  "\"<nocase>\"", "\"<fullword>\"", "\"<at>\"", "\"<filesize>\"",
  "\"<entrypoint>\"", "\"<all>\"", "\"<any>\"", "\"<in>\"", "\"<of>\"",
  "\"<for>\"", "\"<them>\"", "\"<matches>\"", "\"<contains>\"",
  "\"<import>\"", "\"<true>\"", "\"<false\"", "\"<or>\"", "\"<and>\"",
  "\"<not>\"", "\"==\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"",
  "\"<<\"", "\">>\"", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'\\\\'",
  "'%'", "'~'", "UNARY_MINUS", "\"include\"", "'{'", "'}'", "':'", "'='",
  "'('", "')'", "'.'", "'['", "']'", "','", "$accept", "rules", "import",
  "rule", "@1", "$@2", "meta", "strings", "condition", "rule_modifiers",
  "rule_modifier", "tags", "tag_list", "meta_declarations",
  "meta_declaration", "string_declarations", "string_declaration", "$@3",
  "$@4", "$@5", "string_modifiers", "string_modifier", "regexp_modifiers",
  "regexp_modifier", "hex_modifiers", "hex_modifier", "identifier",
  "arguments", "arguments_list", "regexp", "boolean_expression",
  "expression", "$@6", "$@7", "$@8", "$@9", "$@10", "iterator",
  "integer_set", "range", "integer_enumeration", "string_set", "$@11",
  "string_enumeration", "string_enumeration_item", "for_expression",
  "primary_expression", YY_NULLPTR
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
     305,   306,   307,   124,    94,    38,    43,    45,    42,    92,
      37,   126,   308,   309,   123,   125,    58,    61,    40,    41,
      46,    91,    93,    44
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -74,   102,   -74,   -35,   -74,    -2,   -74,   -74,    70,   -74,
     -74,   -74,   -74,    47,   -74,   -74,   -74,   -74,   -37,    59,
      19,   -74,    80,    84,   -74,    33,   107,    93,    57,   -74,
      58,    93,   -74,   112,   118,    15,   -74,    62,   112,   -74,
      64,    67,   -74,   -74,   -74,   -74,   129,    -6,   -74,    49,
     -74,   -74,   123,   136,   145,   -74,   -19,   -74,    92,    96,
     -74,   -74,   100,   -74,   -74,   -74,   -74,   -74,   -74,   120,
     -74,   -74,    49,   142,   142,    49,    17,   -74,    69,   -74,
     139,   215,   -74,   -74,   -74,   142,   106,   142,   142,   142,
     142,     2,   305,   -74,   -74,   -74,    69,   101,   188,    49,
     164,   142,   -74,   -74,   -11,   154,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,    95,   121,   173,   305,   142,   -74,   225,
     235,   138,   267,   -74,   147,   -11,   -74,   -74,   131,   114,
      71,   -74,   257,    49,    49,   -74,   -74,   -74,   -74,   305,
     305,   305,   305,   305,   305,   305,   126,   126,   315,   172,
     325,    38,    38,   -74,   -74,   -74,   -74,   -74,   -74,   133,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   161,   -74,   -74,   -74,   -74,   140,   -74,    49,   -74,
     159,   -74,    18,   187,   142,    -3,   -74,    71,   -74,   -74,
     -42,   -74,   -45,   286,   142,    17,   143,   -74,   -74,   137,
     -74,    18,   191,   -74,   -74,    13,   161,   -74,    49,   -74,
     181,   -74,   142,   183,   -32,   -74,   305,    49,   -74,    31,
     -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    18,     8,     0,     4,     3,     0,     7,
       6,     5,     9,     0,    20,    21,    19,    10,    22,     0,
       0,    24,    23,    13,    25,     0,    15,     0,     0,    11,
       0,    14,    26,     0,     0,     0,    27,     0,    16,    33,
       0,     0,    29,    28,    31,    32,     0,    35,    34,     0,
      12,    30,     0,     0,     0,    61,    75,   122,   124,   126,
     119,   120,     0,   121,    69,   116,   117,   113,   114,     0,
      71,    72,     0,     0,     0,     0,   127,   140,    17,    70,
       0,    96,    41,    51,    58,     0,     0,     0,     0,     0,
       0,     0,   112,    85,   128,   137,     0,    70,    96,    65,
       0,     0,    88,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    38,    40,    76,     0,    77,     0,
       0,     0,     0,    78,     0,     0,    97,   115,     0,    66,
      67,    62,     0,     0,     0,   107,   105,    84,    73,    74,
      94,    95,    90,    92,    91,    93,   138,   139,   136,   134,
     135,   129,   130,   131,   132,   133,    47,    44,    43,    48,
      45,    46,    42,    57,    54,    53,    55,    56,    52,    60,
      59,     0,   123,   125,   118,    79,     0,    64,     0,    63,
      89,    87,     0,     0,     0,     0,    82,    68,   110,   111,
       0,   108,     0,     0,     0,    98,     0,    99,   101,     0,
     106,     0,     0,    49,   102,     0,   103,    80,     0,   109,
       0,   100,     0,     0,     0,    50,   104,     0,    83,     0,
      81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   208,   251,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   224,   -74,   218,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    63,   -74,   -74,   193,
     -49,   -73,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   104,
     -74,   124,   -74,   -74,    85,   231,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,     7,    18,    34,    26,    29,    41,     8,
      16,    20,    22,    31,    32,    38,    39,    52,    53,    54,
     123,   172,   124,   178,   125,   180,    76,   138,   139,    77,
      96,    79,   195,   223,   209,   144,   143,   206,   207,   128,
     215,   147,   192,   200,   201,    80,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    92,    97,   133,     5,    94,    95,    98,    55,    85,
     102,   103,   212,   134,    86,   -39,   -37,   126,    12,   129,
     130,   131,   132,    93,   213,   145,   140,   210,     9,    19,
     198,   211,    42,   142,   199,    43,   135,   228,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    44,    45,   146,    17,   181,
      55,    56,    57,    58,    59,   204,    60,    61,    62,    63,
      21,    64,    46,   102,   103,    13,    14,    15,    65,    66,
      67,    68,   221,    23,    69,    99,   222,   100,   101,    70,
      71,    24,    25,    72,   190,   191,   120,   121,   122,    27,
     230,   166,     2,     3,    30,     4,    73,   -18,   -18,   -18,
      74,   102,   103,   -70,   -70,   197,    28,    75,   167,   168,
     169,   170,   171,    33,    37,    35,   203,   173,    40,    47,
      49,    55,    50,    57,    58,    59,   216,    60,    61,    62,
      63,     5,    64,    82,   174,   175,    51,   176,   177,    65,
      66,    67,    68,    55,   226,    57,    58,    59,    83,    60,
      61,    62,    63,    87,    64,   194,    84,    88,    89,   224,
     136,    65,    66,   104,   127,   141,    64,    73,   229,   179,
     185,    74,   118,   119,   120,   121,   122,   188,    90,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    73,
     187,   193,   103,    74,   202,   218,   196,   184,   220,   217,
      90,    10,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,  -112,   113,   114,   105,   106,   117,   118,   119,
     120,   121,   122,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,  -112,
     225,   227,   105,   106,    11,    36,    48,   137,   205,   186,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   219,   182,   148,   208,
      91,     0,     0,     0,     0,     0,     0,   183,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   189,
       0,     0,     0,     0,     0,     0,   137,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,   214,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   113,   114,     0,   116,
     117,   118,   119,   120,   121,   122,   113,   114,     0,     0,
       0,   118,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      49,    69,    75,     1,    39,    73,    74,    75,    11,    28,
      42,    43,    57,    11,    33,    21,    22,    85,    20,    87,
      88,    89,    90,    72,    69,    36,    99,    69,    63,    66,
      12,    73,    17,   101,    16,    20,    34,    69,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    40,    41,    68,    11,   127,
      11,    12,    13,    14,    15,    68,    17,    18,    19,    20,
      11,    22,    57,    42,    43,     5,     6,     7,    29,    30,
      31,    32,    69,    64,    35,    68,    73,    70,    71,    40,
      41,    11,     8,    44,   143,   144,    58,    59,    60,    66,
      69,     6,     0,     1,    11,     3,    57,     5,     6,     7,
      61,    42,    43,    42,    43,   188,     9,    68,    23,    24,
      25,    26,    27,    66,    12,    67,   194,     6,    10,    67,
      66,    11,    65,    13,    14,    15,   204,    17,    18,    19,
      20,    39,    22,    20,    23,    24,    17,    26,    27,    29,
      30,    31,    32,    11,   222,    13,    14,    15,    22,    17,
      18,    19,    20,    71,    22,     4,    21,    71,    68,   218,
      69,    29,    30,    34,    68,    11,    22,    57,   227,     6,
      33,    61,    56,    57,    58,    59,    60,    73,    68,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    57,
      69,    68,    43,    61,    17,    68,    66,    69,    17,    66,
      68,     3,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    34,    51,    52,    37,    38,    55,    56,    57,
      58,    59,    60,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    34,
      69,    68,    37,    38,     3,    31,    38,    69,   195,   135,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,   211,    72,   105,   195,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    72,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    51,    52,    -1,    -1,
      -1,    56,    57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     1,     3,    39,    76,    77,    83,    63,
      76,    77,    20,     5,     6,     7,    84,    11,    78,    66,
      85,    11,    86,    64,    11,     8,    80,    66,     9,    81,
      11,    87,    88,    66,    79,    67,    88,    12,    89,    90,
      10,    82,    17,    20,    40,    41,    57,    67,    90,    66,
      65,    17,    91,    92,    93,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    22,    29,    30,    31,    32,    35,
      40,    41,    44,    57,    61,    68,   100,   103,   104,   105,
     119,   120,    20,    22,    21,    28,    33,    71,    71,    68,
      68,   119,   120,   104,   120,   120,   104,   105,   120,    68,
      70,    71,    42,    43,    34,    37,    38,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    94,    96,    98,   120,    68,   113,   120,
     120,   120,   120,     1,    11,    34,    69,    69,   101,   102,
     105,    11,   120,   110,   109,    36,    68,   115,   103,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,     6,    23,    24,    25,
      26,    27,    95,     6,    23,    24,    26,    27,    97,     6,
      99,   120,    72,    72,    69,    33,   115,    69,    73,    72,
     104,   104,   116,    68,     4,   106,    66,   105,    12,    16,
     117,   118,    17,   120,    68,   100,   111,   112,   113,   108,
      69,    73,    57,    69,    69,   114,   120,    66,    68,   118,
      17,    69,    73,   107,   104,    69,   120,    68,    69,   104,
      69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    75,    75,    75,    75,    75,    76,
      78,    79,    77,    80,    80,    81,    81,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    91,    90,    92,    90,    93,
      90,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    98,    98,
      99,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     107,   105,   108,   105,   105,   105,   109,   105,   110,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   111,   111,
     112,   112,   113,   114,   114,   116,   115,   115,   117,   117,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     3,     3,     2,     2,
       0,     0,    11,     0,     3,     0,     3,     3,     0,     2,
       1,     1,     0,     2,     1,     2,     1,     2,     3,     3,
       4,     3,     3,     1,     2,     0,     5,     0,     5,     0,
       5,     0,     2,     1,     1,     1,     1,     1,     1,     4,
       6,     0,     2,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     3,     4,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     3,     0,
       0,    11,     0,     9,     3,     2,     0,     4,     0,     4,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     1,
       3,     1,     5,     1,     3,     0,     4,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     1,
       1,     1,     1,     4,     1,     4,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1
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
      yyerror (yyscanner, compiler, YY_("syntax error: cannot back up")); \
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
                  Type, Value, yyscanner, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yyscanner);
  YYUSE (compiler);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, compiler);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void *yyscanner, YR_COMPILER* compiler)
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
                                              , yyscanner, compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, yyscanner, compiler); \
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
    default: /* Avoid compiler warnings. */
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *yyscanner, YR_COMPILER* compiler)
{
  YYUSE (yyvaluep);
  YYUSE (yyscanner);
  YYUSE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 11: /* "identifier"  */
#line 251 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1390 "grammar.c" /* yacc.c:1258  */
        break;

    case 12: /* "string identifier"  */
#line 255 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1396 "grammar.c" /* yacc.c:1258  */
        break;

    case 13: /* "string count"  */
#line 252 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1402 "grammar.c" /* yacc.c:1258  */
        break;

    case 14: /* "string offset"  */
#line 253 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1408 "grammar.c" /* yacc.c:1258  */
        break;

    case 15: /* "string length"  */
#line 254 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1414 "grammar.c" /* yacc.c:1258  */
        break;

    case 16: /* "string identifier with wildcard"  */
#line 256 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1420 "grammar.c" /* yacc.c:1258  */
        break;

    case 20: /* "text string"  */
#line 257 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; }
#line 1426 "grammar.c" /* yacc.c:1258  */
        break;

    case 21: /* "hex string"  */
#line 258 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; }
#line 1432 "grammar.c" /* yacc.c:1258  */
        break;

    case 22: /* "regular expression"  */
#line 259 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; }
#line 1438 "grammar.c" /* yacc.c:1258  */
        break;

    case 101: /* arguments  */
#line 261 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1444 "grammar.c" /* yacc.c:1258  */
        break;

    case 102: /* arguments_list  */
#line 262 "grammar.y" /* yacc.c:1258  */
      { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; }
#line 1450 "grammar.c" /* yacc.c:1258  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *yyscanner, YR_COMPILER* compiler)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

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
      yychar = yylex (&yylval, yyscanner, compiler);
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
        case 8:
#line 287 "grammar.y" /* yacc.c:1663  */
    {
        _yr_compiler_pop_file_name(compiler);
      }
#line 1720 "grammar.c" /* yacc.c:1663  */
    break;

  case 9:
#line 295 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_import(yyscanner, (yyvsp[0].sized_string));

        yr_free((yyvsp[0].sized_string));

        fail_if_error(result);
      }
#line 1732 "grammar.c" /* yacc.c:1663  */
    break;

  case 10:
#line 307 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_rule_declaration_phase_1(
            yyscanner, (int32_t) (yyvsp[-2].integer), (yyvsp[0].c_string), &(yyval.rule)));
      }
#line 1741 "grammar.c" /* yacc.c:1663  */
    break;

  case 11:
#line 312 "grammar.y" /* yacc.c:1663  */
    {
        YR_RULE* rule = (yyvsp[-4].rule); // rule created in phase 1

        rule->tags = (yyvsp[-3].c_string);
        rule->metas = (yyvsp[-1].meta);
        rule->strings = (yyvsp[0].string);
      }
#line 1753 "grammar.c" /* yacc.c:1663  */
    break;

  case 12:
#line 320 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_rule_declaration_phase_2(
            yyscanner, (yyvsp[-7].rule)); // rule created in phase 1

        yr_free((yyvsp[-8].c_string));

        fail_if_error(result);
      }
#line 1766 "grammar.c" /* yacc.c:1663  */
    break;

  case 13:
#line 333 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.meta) = NULL;
      }
#line 1774 "grammar.c" /* yacc.c:1663  */
    break;

  case 14:
#line 337 "grammar.y" /* yacc.c:1663  */
    {
        int result;

        // Each rule have a list of meta-data info, consisting in a
        // sequence of YR_META structures. The last YR_META structure does
        // not represent a real meta-data, it's just a end-of-list marker
        // identified by a specific type (META_TYPE_NULL). Here we
        // write the end-of-list marker.

        YR_META null_meta;

        memset(&null_meta, 0xFF, sizeof(YR_META));
        null_meta.type = META_TYPE_NULL;

        result = yr_arena_write_data(
            compiler->metas_arena,
            &null_meta,
            sizeof(YR_META),
            NULL);

        (yyval.meta) = (yyvsp[0].meta);

        fail_if_error(result);
      }
#line 1803 "grammar.c" /* yacc.c:1663  */
    break;

  case 15:
#line 366 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.string) = NULL;
      }
#line 1811 "grammar.c" /* yacc.c:1663  */
    break;

  case 16:
#line 370 "grammar.y" /* yacc.c:1663  */
    {
        // Each rule have a list of strings, consisting in a sequence
        // of YR_STRING structures. The last YR_STRING structure does not
        // represent a real string, it's just a end-of-list marker
        // identified by a specific flag (STRING_FLAGS_NULL). Here we
        // write the end-of-list marker.

        YR_STRING null_string;

        memset(&null_string, 0xFF, sizeof(YR_STRING));
        null_string.g_flags = STRING_GFLAGS_NULL;

        fail_if_error(yr_arena_write_data(
            compiler->strings_arena,
            &null_string,
            sizeof(YR_STRING),
            NULL));

        (yyval.string) = (yyvsp[0].string);
      }
#line 1836 "grammar.c" /* yacc.c:1663  */
    break;

  case 18:
#line 399 "grammar.y" /* yacc.c:1663  */
    { (yyval.integer) = 0;  }
#line 1842 "grammar.c" /* yacc.c:1663  */
    break;

  case 19:
#line 400 "grammar.y" /* yacc.c:1663  */
    { (yyval.integer) = (yyvsp[-1].integer) | (yyvsp[0].integer); }
#line 1848 "grammar.c" /* yacc.c:1663  */
    break;

  case 20:
#line 405 "grammar.y" /* yacc.c:1663  */
    { (yyval.integer) = RULE_GFLAGS_PRIVATE; }
#line 1854 "grammar.c" /* yacc.c:1663  */
    break;

  case 21:
#line 406 "grammar.y" /* yacc.c:1663  */
    { (yyval.integer) = RULE_GFLAGS_GLOBAL; }
#line 1860 "grammar.c" /* yacc.c:1663  */
    break;

  case 22:
#line 412 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.c_string) = NULL;
      }
#line 1868 "grammar.c" /* yacc.c:1663  */
    break;

  case 23:
#line 416 "grammar.y" /* yacc.c:1663  */
    {
        // Tags list is represented in the arena as a sequence
        // of null-terminated strings, the sequence ends with an
        // additional null character. Here we write the ending null
        //character. Example: tag1\0tag2\0tag3\0\0

        int result = yr_arena_write_string(
            yyget_extra(yyscanner)->sz_arena, "", NULL);

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[0].c_string);
      }
#line 1886 "grammar.c" /* yacc.c:1663  */
    break;

  case 24:
#line 434 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_arena_write_string(
            yyget_extra(yyscanner)->sz_arena, (yyvsp[0].c_string), &(yyval.c_string));

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);
      }
#line 1899 "grammar.c" /* yacc.c:1663  */
    break;

  case 25:
#line 443 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        char* tag_name = (yyvsp[-1].c_string);
        size_t tag_length = tag_name != NULL ? strlen(tag_name) : 0;

        while (tag_length > 0)
        {
          if (strcmp(tag_name, (yyvsp[0].c_string)) == 0)
          {
            yr_compiler_set_error_extra_info(compiler, tag_name);
            result = ERROR_DUPLICATED_TAG_IDENTIFIER;
            break;
          }

          tag_name = (char*) yr_arena_next_address(
              yyget_extra(yyscanner)->sz_arena,
              tag_name,
              tag_length + 1);

          tag_length = tag_name != NULL ? strlen(tag_name) : 0;
        }

        if (result == ERROR_SUCCESS)
          result = yr_arena_write_string(
              yyget_extra(yyscanner)->sz_arena, (yyvsp[0].c_string), NULL);

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[-1].c_string);
      }
#line 1937 "grammar.c" /* yacc.c:1663  */
    break;

  case 26:
#line 481 "grammar.y" /* yacc.c:1663  */
    {  (yyval.meta) = (yyvsp[0].meta); }
#line 1943 "grammar.c" /* yacc.c:1663  */
    break;

  case 27:
#line 482 "grammar.y" /* yacc.c:1663  */
    {  (yyval.meta) = (yyvsp[-1].meta); }
#line 1949 "grammar.c" /* yacc.c:1663  */
    break;

  case 28:
#line 488 "grammar.y" /* yacc.c:1663  */
    {
        SIZED_STRING* sized_string = (yyvsp[0].sized_string);

        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_STRING,
            (yyvsp[-2].c_string),
            sized_string->c_string,
            0,
            &(yyval.meta));

        yr_free((yyvsp[-2].c_string));
        yr_free((yyvsp[0].sized_string));

        fail_if_error(result);
      }
#line 1970 "grammar.c" /* yacc.c:1663  */
    break;

  case 29:
#line 505 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_INTEGER,
            (yyvsp[-2].c_string),
            NULL,
            (yyvsp[0].integer),
            &(yyval.meta));

        yr_free((yyvsp[-2].c_string));

        fail_if_error(result);
      }
#line 1988 "grammar.c" /* yacc.c:1663  */
    break;

  case 30:
#line 519 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_INTEGER,
            (yyvsp[-3].c_string),
            NULL,
            -(yyvsp[0].integer),
            &(yyval.meta));

        yr_free((yyvsp[-3].c_string));

        fail_if_error(result);
      }
#line 2006 "grammar.c" /* yacc.c:1663  */
    break;

  case 31:
#line 533 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_BOOLEAN,
            (yyvsp[-2].c_string),
            NULL,
            true,
            &(yyval.meta));

        yr_free((yyvsp[-2].c_string));

        fail_if_error(result);
      }
#line 2024 "grammar.c" /* yacc.c:1663  */
    break;

  case 32:
#line 547 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_BOOLEAN,
            (yyvsp[-2].c_string),
            NULL,
            false,
            &(yyval.meta));

        yr_free((yyvsp[-2].c_string));

        fail_if_error(result);
      }
#line 2042 "grammar.c" /* yacc.c:1663  */
    break;

  case 33:
#line 564 "grammar.y" /* yacc.c:1663  */
    { (yyval.string) = (yyvsp[0].string); }
#line 2048 "grammar.c" /* yacc.c:1663  */
    break;

  case 34:
#line 565 "grammar.y" /* yacc.c:1663  */
    { (yyval.string) = (yyvsp[-1].string); }
#line 2054 "grammar.c" /* yacc.c:1663  */
    break;

  case 35:
#line 571 "grammar.y" /* yacc.c:1663  */
    {
        compiler->current_line = yyget_lineno(yyscanner);
      }
#line 2062 "grammar.c" /* yacc.c:1663  */
    break;

  case 36:
#line 575 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_declaration(
            yyscanner, (yyvsp[0].modifier), (yyvsp[-4].c_string), (yyvsp[-1].sized_string), &(yyval.string));

        yr_free((yyvsp[-4].c_string));
        yr_free((yyvsp[-1].sized_string));

        fail_if_error(result);
        compiler->current_line = 0;
      }
#line 2077 "grammar.c" /* yacc.c:1663  */
    break;

  case 37:
#line 586 "grammar.y" /* yacc.c:1663  */
    {
        compiler->current_line = yyget_lineno(yyscanner);
      }
#line 2085 "grammar.c" /* yacc.c:1663  */
    break;

  case 38:
#line 590 "grammar.y" /* yacc.c:1663  */
    {
        (yyvsp[0].modifier).flags |= STRING_GFLAGS_REGEXP;
        int result = yr_parser_reduce_string_declaration(
            yyscanner, (yyvsp[0].modifier), (yyvsp[-4].c_string), (yyvsp[-1].sized_string), &(yyval.string));

        yr_free((yyvsp[-4].c_string));
        yr_free((yyvsp[-1].sized_string));

        fail_if_error(result);

        compiler->current_line = 0;
      }
#line 2102 "grammar.c" /* yacc.c:1663  */
    break;

  case 39:
#line 603 "grammar.y" /* yacc.c:1663  */
    {
        compiler->current_line = yyget_lineno(yyscanner);
      }
#line 2110 "grammar.c" /* yacc.c:1663  */
    break;

  case 40:
#line 607 "grammar.y" /* yacc.c:1663  */
    {
        (yyvsp[0].modifier).flags |= STRING_GFLAGS_HEXADECIMAL;
        int result = yr_parser_reduce_string_declaration(
            yyscanner, (yyvsp[0].modifier), (yyvsp[-4].c_string), (yyvsp[-1].sized_string), &(yyval.string));

        yr_free((yyvsp[-4].c_string));
        yr_free((yyvsp[-1].sized_string));

        fail_if_error(result);

        compiler->current_line = 0;
      }
#line 2127 "grammar.c" /* yacc.c:1663  */
    break;

  case 41:
#line 624 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.modifier).flags = 0;
        (yyval.modifier).xor_min = 0;
        (yyval.modifier).xor_max = 0;
      }
#line 2137 "grammar.c" /* yacc.c:1663  */
    break;

  case 42:
#line 630 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.modifier) = (yyvsp[-1].modifier);

        set_flag_or_error((yyval.modifier).flags, (yyvsp[0].modifier).flags);

        // Only set the xor minimum and maximum if we are dealing with the
        // xor modifier. If we don't check for this then we can end up with
        // "xor wide" resulting in whatever is on the stack for "wide"
        // overwriting the values for xor.
        if ((yyvsp[0].modifier).flags & STRING_GFLAGS_XOR)
        {
          (yyval.modifier).xor_min = (yyvsp[0].modifier).xor_min;
          (yyval.modifier).xor_max = (yyvsp[0].modifier).xor_max;
        }
      }
#line 2157 "grammar.c" /* yacc.c:1663  */
    break;

  case 43:
#line 649 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_WIDE; }
#line 2163 "grammar.c" /* yacc.c:1663  */
    break;

  case 44:
#line 650 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_ASCII; }
#line 2169 "grammar.c" /* yacc.c:1663  */
    break;

  case 45:
#line 651 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_NO_CASE; }
#line 2175 "grammar.c" /* yacc.c:1663  */
    break;

  case 46:
#line 652 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_FULL_WORD; }
#line 2181 "grammar.c" /* yacc.c:1663  */
    break;

  case 47:
#line 653 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_PRIVATE; }
#line 2187 "grammar.c" /* yacc.c:1663  */
    break;

  case 48:
#line 655 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.modifier).flags = STRING_GFLAGS_XOR;
        (yyval.modifier).xor_min = 0;
        (yyval.modifier).xor_max = 255;
      }
#line 2197 "grammar.c" /* yacc.c:1663  */
    break;

  case 49:
#line 661 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[-1].integer) < 0 || (yyvsp[-1].integer) > 255)
        {
          yr_compiler_set_error_extra_info(compiler, "invalid xor range");
          result = ERROR_INVALID_MODIFIER;
        }

        fail_if_error(result);

        (yyval.modifier).flags = STRING_GFLAGS_XOR;
        (yyval.modifier).xor_min = (yyvsp[-1].integer);
        (yyval.modifier).xor_max = (yyvsp[-1].integer);
      }
#line 2217 "grammar.c" /* yacc.c:1663  */
    break;

  case 50:
#line 682 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[-3].integer) < 0)
        {
          yr_compiler_set_error_extra_info(
              compiler, "lower bound for xor range exceeded (min: 0)");
          result = ERROR_INVALID_MODIFIER;
        }

        if ((yyvsp[-1].integer) > 255)
        {
          yr_compiler_set_error_extra_info(
              compiler, "upper bound for xor range exceeded (max: 255)");
          result = ERROR_INVALID_MODIFIER;
        }

        if ((yyvsp[-3].integer) > (yyvsp[-1].integer))
        {
          yr_compiler_set_error_extra_info(
              compiler, "xor lower bound exceeds upper bound");
          result = ERROR_INVALID_MODIFIER;
        }

        fail_if_error(result);

        (yyval.modifier).flags = STRING_GFLAGS_XOR;
        (yyval.modifier).xor_min = (yyvsp[-3].integer);
        (yyval.modifier).xor_max = (yyvsp[-1].integer);
      }
#line 2252 "grammar.c" /* yacc.c:1663  */
    break;

  case 51:
#line 715 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = 0; }
#line 2258 "grammar.c" /* yacc.c:1663  */
    break;

  case 52:
#line 716 "grammar.y" /* yacc.c:1663  */
    { set_flag_or_error((yyval.modifier).flags, (yyvsp[0].modifier).flags); }
#line 2264 "grammar.c" /* yacc.c:1663  */
    break;

  case 53:
#line 720 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_WIDE; }
#line 2270 "grammar.c" /* yacc.c:1663  */
    break;

  case 54:
#line 721 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_ASCII; }
#line 2276 "grammar.c" /* yacc.c:1663  */
    break;

  case 55:
#line 722 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_NO_CASE; }
#line 2282 "grammar.c" /* yacc.c:1663  */
    break;

  case 56:
#line 723 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_FULL_WORD; }
#line 2288 "grammar.c" /* yacc.c:1663  */
    break;

  case 57:
#line 724 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_PRIVATE; }
#line 2294 "grammar.c" /* yacc.c:1663  */
    break;

  case 58:
#line 728 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = 0; }
#line 2300 "grammar.c" /* yacc.c:1663  */
    break;

  case 59:
#line 729 "grammar.y" /* yacc.c:1663  */
    { set_flag_or_error((yyval.modifier).flags, (yyvsp[0].modifier).flags); }
#line 2306 "grammar.c" /* yacc.c:1663  */
    break;

  case 60:
#line 733 "grammar.y" /* yacc.c:1663  */
    { (yyval.modifier).flags = STRING_GFLAGS_PRIVATE; }
#line 2312 "grammar.c" /* yacc.c:1663  */
    break;

  case 61:
#line 738 "grammar.y" /* yacc.c:1663  */
    {
        YR_EXPRESSION expr;

        int result = ERROR_SUCCESS;
        int var_index = yr_parser_lookup_loop_variable(yyscanner, (yyvsp[0].c_string), &expr);

        if (var_index >= 0)
        {
          // The identifier corresponds to a loop variable.
          result = yr_parser_emit_with_arg(
              yyscanner,
              OP_PUSH_M,
              var_index,
              NULL,
              NULL);

          // The expression associated to this identifier is the same one
          // associated to the loop variable.
          (yyval.expression) = expr;
        }
        else
        {
          // Search for identifier within the global namespace, where the
          // externals variables reside.

          YR_OBJECT* object = (YR_OBJECT*) yr_hash_table_lookup(
              compiler->objects_table, (yyvsp[0].c_string), NULL);

          if (object == NULL)
          {
            // If not found, search within the current namespace.
            char* ns = compiler->current_namespace->name;

            object = (YR_OBJECT*) yr_hash_table_lookup(
                compiler->objects_table, (yyvsp[0].c_string), ns);
          }

          if (object != NULL)
          {
            char* id;

            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[0].c_string), &id);

            if (result == ERROR_SUCCESS)
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_OBJ_LOAD,
                  id,
                  NULL,
                  NULL);

            (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
            (yyval.expression).value.object = object;
            (yyval.expression).identifier = object->identifier;
          }
          else
          {
            YR_RULE* rule = (YR_RULE*) yr_hash_table_lookup(
                compiler->rules_table,
                (yyvsp[0].c_string),
                compiler->current_namespace->name);

            if (rule != NULL)
            {
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_PUSH_RULE,
                  rule,
                  NULL,
                  NULL);

              (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
              (yyval.expression).value.integer = UNDEFINED;
              (yyval.expression).identifier = rule->identifier;
            }
            else
            {
              yr_compiler_set_error_extra_info(compiler, (yyvsp[0].c_string));
              result = ERROR_UNDEFINED_IDENTIFIER;
            }
          }
        }

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);
      }
#line 2405 "grammar.c" /* yacc.c:1663  */
    break;

  case 62:
#line 827 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT* field = NULL;

        if ((yyvsp[-2].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[-2].expression).value.object->type == OBJECT_TYPE_STRUCTURE)
        {
          field = yr_object_lookup_field((yyvsp[-2].expression).value.object, (yyvsp[0].c_string));

          if (field != NULL)
          {
            char* ident;

            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[0].c_string), &ident);

            if (result == ERROR_SUCCESS)
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_OBJ_FIELD,
                  ident,
                  NULL,
                  NULL);

            (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
            (yyval.expression).value.object = field;
            (yyval.expression).identifier = field->identifier;
          }
          else
          {
            yr_compiler_set_error_extra_info(compiler, (yyvsp[0].c_string));
            result = ERROR_INVALID_FIELD_NAME;
          }
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[-2].expression).identifier);

          result = ERROR_NOT_A_STRUCTURE;
        }

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);
      }
#line 2456 "grammar.c" /* yacc.c:1663  */
    break;

  case 63:
#line 874 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT_ARRAY* array;
        YR_OBJECT_DICTIONARY* dict;

        if ((yyvsp[-3].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[-3].expression).value.object->type == OBJECT_TYPE_ARRAY)
        {
          if ((yyvsp[-1].expression).type != EXPRESSION_TYPE_INTEGER)
          {
            yr_compiler_set_error_extra_info(
                compiler, "array indexes must be of integer type");
            result = ERROR_WRONG_TYPE;
          }

          fail_if_error(result);

          result = yr_parser_emit(
              yyscanner, OP_INDEX_ARRAY, NULL);

          array = object_as_array((yyvsp[-3].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = array->prototype_item;
          (yyval.expression).identifier = array->identifier;
        }
        else if ((yyvsp[-3].expression).type == EXPRESSION_TYPE_OBJECT &&
                 (yyvsp[-3].expression).value.object->type == OBJECT_TYPE_DICTIONARY)
        {
          if ((yyvsp[-1].expression).type != EXPRESSION_TYPE_STRING)
          {
            yr_compiler_set_error_extra_info(
                compiler, "dictionary keys must be of string type");
            result = ERROR_WRONG_TYPE;
          }

          fail_if_error(result);

          result = yr_parser_emit(
              yyscanner, OP_LOOKUP_DICT, NULL);

          dict = object_as_dictionary((yyvsp[-3].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = dict->prototype_item;
          (yyval.expression).identifier = dict->identifier;
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[-3].expression).identifier);

          result = ERROR_NOT_INDEXABLE;
        }

        fail_if_error(result);
      }
#line 2518 "grammar.c" /* yacc.c:1663  */
    break;

  case 64:
#line 933 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT_FUNCTION* function;
        char* args_fmt;

        if ((yyvsp[-3].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[-3].expression).value.object->type == OBJECT_TYPE_FUNCTION)
        {
          result = yr_parser_check_types(
              compiler, object_as_function((yyvsp[-3].expression).value.object), (yyvsp[-1].c_string));

          if (result == ERROR_SUCCESS)
            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[-1].c_string), &args_fmt);

          if (result == ERROR_SUCCESS)
            result = yr_parser_emit_with_arg_reloc(
                yyscanner,
                OP_CALL,
                args_fmt,
                NULL,
                NULL);

          function = object_as_function((yyvsp[-3].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = function->return_obj;
          (yyval.expression).identifier = function->identifier;
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[-3].expression).identifier);

          result = ERROR_NOT_A_FUNCTION;
        }

        yr_free((yyvsp[-1].c_string));

        fail_if_error(result);
      }
#line 2564 "grammar.c" /* yacc.c:1663  */
    break;

  case 65:
#line 978 "grammar.y" /* yacc.c:1663  */
    { (yyval.c_string) = yr_strdup(""); }
#line 2570 "grammar.c" /* yacc.c:1663  */
    break;

  case 66:
#line 979 "grammar.y" /* yacc.c:1663  */
    { (yyval.c_string) = (yyvsp[0].c_string); }
#line 2576 "grammar.c" /* yacc.c:1663  */
    break;

  case 67:
#line 984 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.c_string) = (char*) yr_malloc(YR_MAX_FUNCTION_ARGS + 1);

        if ((yyval.c_string) == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        switch((yyvsp[0].expression).type)
        {
          case EXPRESSION_TYPE_INTEGER:
            strlcpy((yyval.c_string), "i", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_FLOAT:
            strlcpy((yyval.c_string), "f", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_BOOLEAN:
            strlcpy((yyval.c_string), "b", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_STRING:
            strlcpy((yyval.c_string), "s", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_REGEXP:
            strlcpy((yyval.c_string), "r", YR_MAX_FUNCTION_ARGS);
            break;
          default:
            assert(false);
        }
      }
#line 2608 "grammar.c" /* yacc.c:1663  */
    break;

  case 68:
#line 1012 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if (strlen((yyvsp[-2].c_string)) == YR_MAX_FUNCTION_ARGS)
        {
          result = ERROR_TOO_MANY_ARGUMENTS;
        }
        else
        {
          switch((yyvsp[0].expression).type)
          {
            case EXPRESSION_TYPE_INTEGER:
              strlcat((yyvsp[-2].c_string), "i", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_FLOAT:
              strlcat((yyvsp[-2].c_string), "f", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_BOOLEAN:
              strlcat((yyvsp[-2].c_string), "b", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_STRING:
              strlcat((yyvsp[-2].c_string), "s", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_REGEXP:
              strlcat((yyvsp[-2].c_string), "r", YR_MAX_FUNCTION_ARGS);
              break;
            default:
              assert(false);
          }
        }

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[-2].c_string);
      }
#line 2648 "grammar.c" /* yacc.c:1663  */
    break;

  case 69:
#line 1052 "grammar.y" /* yacc.c:1663  */
    {
        SIZED_STRING* sized_string = (yyvsp[0].sized_string);
        RE* re;
        RE_ERROR error;

        int result = ERROR_SUCCESS;
        int re_flags = 0;

        if (sized_string->flags & SIZED_STRING_FLAGS_NO_CASE)
          re_flags |= RE_FLAGS_NO_CASE;

        if (sized_string->flags & SIZED_STRING_FLAGS_DOT_ALL)
          re_flags |= RE_FLAGS_DOT_ALL;

        result = yr_re_compile(
            sized_string->c_string,
            re_flags,
            compiler->re_code_arena,
            &re,
            &error);

        yr_free((yyvsp[0].sized_string));

        if (result == ERROR_INVALID_REGULAR_EXPRESSION)
          yr_compiler_set_error_extra_info(compiler, error.message);

        if (result == ERROR_SUCCESS)
          result = yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_PUSH,
              re,
              NULL,
              NULL);

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_REGEXP;
      }
#line 2691 "grammar.c" /* yacc.c:1663  */
    break;

  case 70:
#line 1095 "grammar.y" /* yacc.c:1663  */
    {
        if ((yyvsp[0].expression).type == EXPRESSION_TYPE_STRING)
        {
          if ((yyvsp[0].expression).value.sized_string != NULL)
          {
            yywarning(yyscanner,
              "Using literal string \"%s\" in a boolean operation.",
              (yyvsp[0].expression).value.sized_string->c_string);
          }

          fail_if_error(yr_parser_emit(
              yyscanner, OP_STR_TO_BOOL, NULL));
        }

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2712 "grammar.c" /* yacc.c:1663  */
    break;

  case 71:
#line 1115 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2723 "grammar.c" /* yacc.c:1663  */
    break;

  case 72:
#line 1122 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 0, NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2734 "grammar.c" /* yacc.c:1663  */
    break;

  case 73:
#line 1129 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_STRING, "matches");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_REGEXP, "matches");

        fail_if_error(yr_parser_emit(
            yyscanner,
            OP_MATCHES,
            NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2750 "grammar.c" /* yacc.c:1663  */
    break;

  case 74:
#line 1141 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_STRING, "contains");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_STRING, "contains");

        fail_if_error(yr_parser_emit(
            yyscanner, OP_CONTAINS, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2764 "grammar.c" /* yacc.c:1663  */
    break;

  case 75:
#line 1151 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner,
            (yyvsp[0].c_string),
            OP_FOUND,
            UNDEFINED);

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2782 "grammar.c" /* yacc.c:1663  */
    break;

  case 76:
#line 1165 "grammar.y" /* yacc.c:1663  */
    {
        int result;

        check_type_with_cleanup((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "at", yr_free((yyvsp[-2].c_string)));

        result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[-2].c_string), OP_FOUND_AT, (yyvsp[0].expression).value.integer);

        yr_free((yyvsp[-2].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2801 "grammar.c" /* yacc.c:1663  */
    break;

  case 77:
#line 1180 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[-2].c_string), OP_FOUND_IN, UNDEFINED);

        yr_free((yyvsp[-2].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 2816 "grammar.c" /* yacc.c:1663  */
    break;

  case 78:
#line 1191 "grammar.y" /* yacc.c:1663  */
    {
        if (compiler->loop_depth > 0)
        {
          compiler->loop_depth--;
        }

        YYERROR;
      }
#line 2829 "grammar.c" /* yacc.c:1663  */
    break;

  case 79:
#line 1251 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        // var_frame is used for accessing local variables used in this loop.
        // All local variables are accessed using var_frame as a reference,
        // like var_frame + 0, var_frame + 1, etc. Here we initialize var_frame
        // with the correct value, which depends on the number of variables
        // defined by any outer loops.

        int var_frame = _yr_compiler_get_var_frame(compiler);

        if (compiler->loop_depth == YR_MAX_LOOP_NESTING)
          result = ERROR_LOOP_NESTING_LIMIT_EXCEEDED;

        fail_if_error(result);

        if (yr_parser_lookup_loop_variable(yyscanner, (yyvsp[-1].c_string), NULL) >= 0)
        {
          yr_compiler_set_error_extra_info(compiler, (yyvsp[-1].c_string));
          result = ERROR_DUPLICATED_LOOP_IDENTIFIER;
        }

        fail_if_error(result);

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, var_frame + 1, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, var_frame + 2, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_POP_M, var_frame + 3, NULL, NULL));
      }
#line 2867 "grammar.c" /* yacc.c:1663  */
    break;

  case 80:
#line 1285 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        YR_EXPRESSION loop_var;

        uint8_t* loop_start_addr;
        void* jmp_arg_addr;

        int var_frame = _yr_compiler_get_var_frame(compiler);

        fail_if_error(yr_parser_emit(
            yyscanner, OP_ITER_NEXT, &loop_start_addr));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_POP_M, var_frame, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JTRUE_P,
            0,
            NULL,
            &jmp_arg_addr));

        // Push a new fixup entry in the fixup stack so that the jump
        // destination is set once we know it.

        fixup = (YR_FIXUP*) yr_malloc(sizeof(YR_FIXUP));

        if (fixup == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        fixup->address = jmp_arg_addr;
        fixup->next = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup;

        loop_var.identifier = (yyvsp[-4].c_string);
        loop_var.type = (yyvsp[-1].expression).type;
        loop_var.value = (yyvsp[-1].expression).value;

        compiler->loop[compiler->loop_depth].vars[0] = loop_var;

        loop_var.identifier = NULL;
        loop_var.type = EXPRESSION_TYPE_UNKNOWN;
        loop_var.value.integer = UNDEFINED;

        compiler->loop[compiler->loop_depth].vars[1] = loop_var;
        compiler->loop[compiler->loop_depth].vars[2] = loop_var;
        compiler->loop[compiler->loop_depth].vars[3] = loop_var;

        compiler->loop[compiler->loop_depth].vars_count = 4;
        compiler->loop[compiler->loop_depth].addr = loop_start_addr;
        compiler->loop_depth++;
      }
#line 2924 "grammar.c" /* yacc.c:1663  */
    break;

  case 81:
#line 1338 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        uint8_t* pop_addr;
        int var_frame;

        compiler->loop_depth--;

        var_frame = _yr_compiler_get_var_frame(compiler);

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_ADD_M, var_frame + 1, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_INCR_M, var_frame + 2, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 3, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JUNDEF_P,
            compiler->loop[compiler->loop_depth].addr,
            NULL,
            NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 1, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 3, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JL_P,
            compiler->loop[compiler->loop_depth].addr,
            NULL,
            NULL));

        fail_if_error(yr_parser_emit(
            yyscanner, OP_POP, &pop_addr));

        // Pop from the stack the fixup entry containing the jump's address
        // that needs to be fixed.

        fixup = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup->next;

        // Fix the jump's target address.
        *(void**)(fixup->address) = (void*)(pop_addr);

        yr_free(fixup);

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 1, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 3, NULL, NULL));

        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_SWAPUNDEF, var_frame + 2, NULL, NULL));

        fail_if_error(yr_parser_emit(
            yyscanner, OP_INT_GE, NULL));
      }
#line 2993 "grammar.c" /* yacc.c:1663  */
    break;

  case 82:
#line 1403 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;
        int var_frame = _yr_compiler_get_var_frame(compiler);;
        uint8_t* addr;

        if (compiler->loop_depth == YR_MAX_LOOP_NESTING)
          result = ERROR_LOOP_NESTING_LIMIT_EXCEEDED;

        if (compiler->loop_for_of_var_index != -1)
          result = ERROR_NESTED_FOR_OF_LOOP;

        fail_if_error(result);

        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, var_frame + 1, NULL, NULL);

        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, var_frame + 2, NULL, NULL);

        // Pop the first string.
        yr_parser_emit_with_arg(
            yyscanner, OP_POP_M, var_frame, &addr, NULL);

        compiler->loop_for_of_var_index = var_frame;

        for (int i = 0; i < 3; i++)
        {
          compiler->loop[compiler->loop_depth].vars[i].identifier = NULL;
          compiler->loop[compiler->loop_depth].vars[i].type = EXPRESSION_TYPE_UNKNOWN;
          compiler->loop[compiler->loop_depth].vars[i].value.integer = UNDEFINED;
        }

        compiler->loop[compiler->loop_depth].vars_count = 3;
        compiler->loop[compiler->loop_depth].addr = addr;
        compiler->loop_depth++;
      }
#line 3034 "grammar.c" /* yacc.c:1663  */
    break;

  case 83:
#line 1440 "grammar.y" /* yacc.c:1663  */
    {
        int var_frame = 0;

        compiler->loop_depth--;
        compiler->loop_for_of_var_index = -1;

        var_frame = _yr_compiler_get_var_frame(compiler);

        // Increment counter by the value returned by the
        // boolean expression (0 or 1). If the boolean expression
        // returned UNDEFINED the OP_ADD_M won't do anything.

        yr_parser_emit_with_arg(
            yyscanner, OP_ADD_M, var_frame + 1, NULL, NULL);

        // Increment iterations counter.
        yr_parser_emit_with_arg(
            yyscanner, OP_INCR_M, var_frame + 2, NULL, NULL);

        // If next string is not undefined, go back to the
        // beginning of the loop.
        yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JNUNDEF,
            compiler->loop[compiler->loop_depth].addr,
            NULL,
            NULL);

        // Pop end-of-list marker.
        yr_parser_emit(yyscanner, OP_POP, NULL);

        // At this point the loop quantifier (any, all, 1, 2,..)
        // is at top of the stack. Check if the quantifier is
        // undefined (meaning "all") and replace it with the
        // iterations counter in that case.
        yr_parser_emit_with_arg(
            yyscanner, OP_SWAPUNDEF, var_frame + 2, NULL, NULL);

        // Compare the loop quantifier with the number of
        // expressions evaluating to true.
        yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, var_frame + 1, NULL, NULL);

        yr_parser_emit(yyscanner, OP_INT_LE, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3086 "grammar.c" /* yacc.c:1663  */
    break;

  case 84:
#line 1488 "grammar.y" /* yacc.c:1663  */
    {
        yr_parser_emit(yyscanner, OP_OF, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3096 "grammar.c" /* yacc.c:1663  */
    break;

  case 85:
#line 1494 "grammar.y" /* yacc.c:1663  */
    {
        yr_parser_emit(yyscanner, OP_NOT, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3106 "grammar.c" /* yacc.c:1663  */
    break;

  case 86:
#line 1500 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        void* jmp_destination_addr;

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JFALSE,
            0,          // still don't know the jump destination
            NULL,
            &jmp_destination_addr));

        // create a fixup entry for the jump and push it in the stack
        fixup = (YR_FIXUP*) yr_malloc(sizeof(YR_FIXUP));

        if (fixup == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        fixup->address = jmp_destination_addr;
        fixup->next = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup;
      }
#line 3132 "grammar.c" /* yacc.c:1663  */
    break;

  case 87:
#line 1522 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        uint8_t* nop_addr;

        fail_if_error(yr_parser_emit(yyscanner, OP_AND, NULL));

        // Generate a do-nothing instruction (NOP) in order to get its address
        // and use it as the destination for the OP_JFALSE. We can not simply
        // use the address of the OP_AND instruction +1 because we can't be
        // sure that the instruction following the OP_AND is going to be in
        // the same arena page. As we don't have a reliable way of getting the
        // address of the next instruction we generate the OP_NOP.

        fail_if_error(yr_parser_emit(yyscanner, OP_NOP, &nop_addr));

        fixup = compiler->fixup_stack_head;
        *(void**)(fixup->address) = (void*) nop_addr;
        compiler->fixup_stack_head = fixup->next;
        yr_free(fixup);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3159 "grammar.c" /* yacc.c:1663  */
    break;

  case 88:
#line 1545 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        void* jmp_destination_addr;

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JTRUE,
            0,         // still don't know the jump destination
            NULL,
            &jmp_destination_addr));

        fixup = (YR_FIXUP*) yr_malloc(sizeof(YR_FIXUP));

        if (fixup == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        fixup->address = jmp_destination_addr;
        fixup->next = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup;
      }
#line 3184 "grammar.c" /* yacc.c:1663  */
    break;

  case 89:
#line 1566 "grammar.y" /* yacc.c:1663  */
    {
        YR_FIXUP* fixup;
        uint8_t* nop_addr;

        fail_if_error(yr_parser_emit(yyscanner, OP_OR, NULL));

        // Generate a do-nothing instruction (NOP) in order to get its address
        // and use it as the destination for the OP_JFALSE. We can not simply
        // use the address of the OP_OR instruction +1 because we can't be
        // sure that the instruction following the OP_AND is going to be in
        // the same arena page. As we don't have a reliable way of getting the
        // address of the next instruction we generate the OP_NOP.

        fail_if_error(yr_parser_emit(yyscanner, OP_NOP, &nop_addr));

        fixup = compiler->fixup_stack_head;
        *(void**)(fixup->address) = (void*)(nop_addr);
        compiler->fixup_stack_head = fixup->next;
        yr_free(fixup);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3211 "grammar.c" /* yacc.c:1663  */
    break;

  case 90:
#line 1589 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "<", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3222 "grammar.c" /* yacc.c:1663  */
    break;

  case 91:
#line 1596 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, ">", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3233 "grammar.c" /* yacc.c:1663  */
    break;

  case 92:
#line 1603 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "<=", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3244 "grammar.c" /* yacc.c:1663  */
    break;

  case 93:
#line 1610 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, ">=", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3255 "grammar.c" /* yacc.c:1663  */
    break;

  case 94:
#line 1617 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "==", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3266 "grammar.c" /* yacc.c:1663  */
    break;

  case 95:
#line 1624 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "!=", (yyvsp[-2].expression), (yyvsp[0].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
#line 3277 "grammar.c" /* yacc.c:1663  */
    break;

  case 96:
#line 1631 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.expression) = (yyvsp[0].expression);
      }
#line 3285 "grammar.c" /* yacc.c:1663  */
    break;

  case 97:
#line 1635 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.expression) = (yyvsp[-1].expression);
      }
#line 3293 "grammar.c" /* yacc.c:1663  */
    break;

  case 98:
#line 1643 "grammar.y" /* yacc.c:1663  */
    {
        // Initially we assume that the identifier is from a non-iterable type,
        // this will change later if it's iterable.
        int result = ERROR_WRONG_TYPE;

        if ((yyvsp[0].expression).type == EXPRESSION_TYPE_OBJECT)
        {
          switch((yyvsp[0].expression).value.object->type)
          {
            case OBJECT_TYPE_ARRAY:
              (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
              (yyval.expression).value.object = object_as_array((yyvsp[0].expression).value.object)->prototype_item;
              result = yr_parser_emit(yyscanner, OP_ITER_START_ARRAY, NULL);
              break;
          }
        }

        if (result == ERROR_WRONG_TYPE)
        {
          yr_compiler_set_error_extra_info_fmt(
              compiler,
              "identifier \"%s\" is not iterable",
              (yyvsp[0].expression).identifier);
        }

        fail_if_error(result);
      }
#line 3325 "grammar.c" /* yacc.c:1663  */
    break;

  case 99:
#line 1671 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3334 "grammar.c" /* yacc.c:1663  */
    break;

  case 100:
#line 1680 "grammar.y" /* yacc.c:1663  */
    {
        // $2 contains the number of integers in the enumeration
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, (yyvsp[-1].integer), NULL, NULL));

        fail_if_error(yr_parser_emit(
            yyscanner, OP_ITER_START_INT_ENUM, NULL));
      }
#line 3347 "grammar.c" /* yacc.c:1663  */
    break;

  case 101:
#line 1689 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit(
            yyscanner, OP_ITER_START_INT_RANGE, NULL));
      }
#line 3356 "grammar.c" /* yacc.c:1663  */
    break;

  case 102:
#line 1698 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[-3].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for range's lower bound");
          result = ERROR_WRONG_TYPE;
        }

        if ((yyvsp[-1].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for range's upper bound");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);
      }
#line 3380 "grammar.c" /* yacc.c:1663  */
    break;

  case 103:
#line 1722 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[0].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for enumeration item");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);

        (yyval.integer) = 1;
      }
#line 3399 "grammar.c" /* yacc.c:1663  */
    break;

  case 104:
#line 1737 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[0].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for enumeration item");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);

        (yyval.integer) = (yyvsp[-2].integer) + 1;
      }
#line 3418 "grammar.c" /* yacc.c:1663  */
    break;

  case 105:
#line 1756 "grammar.y" /* yacc.c:1663  */
    {
        // Push end-of-list marker
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, UNDEFINED, NULL, NULL);
      }
#line 3427 "grammar.c" /* yacc.c:1663  */
    break;

  case 107:
#line 1762 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, UNDEFINED, NULL, NULL));

        fail_if_error(yr_parser_emit_pushes_for_strings(
            yyscanner, "$*"));
      }
#line 3439 "grammar.c" /* yacc.c:1663  */
    break;

  case 110:
#line 1780 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_emit_pushes_for_strings(yyscanner, (yyvsp[0].c_string));
        yr_free((yyvsp[0].c_string));

        fail_if_error(result);
      }
#line 3450 "grammar.c" /* yacc.c:1663  */
    break;

  case 111:
#line 1787 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_emit_pushes_for_strings(yyscanner, (yyvsp[0].c_string));
        yr_free((yyvsp[0].c_string));

        fail_if_error(result);
      }
#line 3461 "grammar.c" /* yacc.c:1663  */
    break;

  case 112:
#line 1798 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.integer) = FOR_EXPRESSION_ANY;
      }
#line 3469 "grammar.c" /* yacc.c:1663  */
    break;

  case 113:
#line 1802 "grammar.y" /* yacc.c:1663  */
    {
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, UNDEFINED, NULL, NULL);
        (yyval.integer) = FOR_EXPRESSION_ALL;
      }
#line 3478 "grammar.c" /* yacc.c:1663  */
    break;

  case 114:
#line 1807 "grammar.y" /* yacc.c:1663  */
    {
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, 1, NULL, NULL);
        (yyval.integer) = FOR_EXPRESSION_ANY;
      }
#line 3487 "grammar.c" /* yacc.c:1663  */
    break;

  case 115:
#line 1816 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.expression) = (yyvsp[-1].expression);
      }
#line 3495 "grammar.c" /* yacc.c:1663  */
    break;

  case 116:
#line 1820 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit(
            yyscanner, OP_FILESIZE, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3507 "grammar.c" /* yacc.c:1663  */
    break;

  case 117:
#line 1828 "grammar.y" /* yacc.c:1663  */
    {
        yywarning(yyscanner,
            "Using deprecated \"entrypoint\" keyword. Use the \"entry_point\" "
            "function from PE module instead.");

        fail_if_error(yr_parser_emit(
            yyscanner, OP_ENTRYPOINT, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3523 "grammar.c" /* yacc.c:1663  */
    break;

  case 118:
#line 1840 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-1].expression), EXPRESSION_TYPE_INTEGER, "intXXXX or uintXXXX");

        // _INTEGER_FUNCTION_ could be any of int8, int16, int32, uint8,
        // uint32, etc. $1 contains an index that added to OP_READ_INT results
        // in the proper OP_INTXX opcode.

        fail_if_error(yr_parser_emit(
            yyscanner, (uint8_t) (OP_READ_INT + (yyvsp[-3].integer)), NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3541 "grammar.c" /* yacc.c:1663  */
    break;

  case 119:
#line 1854 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, (yyvsp[0].integer), NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = (yyvsp[0].integer);
      }
#line 3553 "grammar.c" /* yacc.c:1663  */
    break;

  case 120:
#line 1862 "grammar.y" /* yacc.c:1663  */
    {
        fail_if_error(yr_parser_emit_with_arg_double(
            yyscanner, OP_PUSH, (yyvsp[0].double_), NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
      }
#line 3564 "grammar.c" /* yacc.c:1663  */
    break;

  case 121:
#line 1869 "grammar.y" /* yacc.c:1663  */
    {
        SIZED_STRING* sized_string;

        int result = yr_arena_write_data(
            compiler->sz_arena,
            (yyvsp[0].sized_string),
            (yyvsp[0].sized_string)->length + sizeof(SIZED_STRING),
            (void**) &sized_string);

        yr_free((yyvsp[0].sized_string));

        if (result == ERROR_SUCCESS)
          result = yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_PUSH,
              sized_string,
              NULL,
              NULL);

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_STRING;
        (yyval.expression).value.sized_string = sized_string;
      }
#line 3593 "grammar.c" /* yacc.c:1663  */
    break;

  case 122:
#line 1894 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[0].c_string), OP_COUNT, UNDEFINED);

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3609 "grammar.c" /* yacc.c:1663  */
    break;

  case 123:
#line 1906 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[-3].c_string), OP_OFFSET, UNDEFINED);

        yr_free((yyvsp[-3].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3625 "grammar.c" /* yacc.c:1663  */
    break;

  case 124:
#line 1918 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL);

        if (result == ERROR_SUCCESS)
          result = yr_parser_reduce_string_identifier(
              yyscanner, (yyvsp[0].c_string), OP_OFFSET, UNDEFINED);

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3645 "grammar.c" /* yacc.c:1663  */
    break;

  case 125:
#line 1934 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[-3].c_string), OP_LENGTH, UNDEFINED);

        yr_free((yyvsp[-3].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3661 "grammar.c" /* yacc.c:1663  */
    break;

  case 126:
#line 1946 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL);

        if (result == ERROR_SUCCESS)
          result = yr_parser_reduce_string_identifier(
              yyscanner, (yyvsp[0].c_string), OP_LENGTH, UNDEFINED);

        yr_free((yyvsp[0].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
#line 3681 "grammar.c" /* yacc.c:1663  */
    break;

  case 127:
#line 1962 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)  // loop identifier
        {
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          (yyval.expression).value.integer = UNDEFINED;
        }
        else if ((yyvsp[0].expression).type == EXPRESSION_TYPE_BOOLEAN)  // rule identifier
        {
          (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
          (yyval.expression).value.integer = UNDEFINED;
        }
        else if ((yyvsp[0].expression).type == EXPRESSION_TYPE_OBJECT)
        {
          result = yr_parser_emit(
              yyscanner, OP_OBJ_VALUE, NULL);

          switch((yyvsp[0].expression).value.object->type)
          {
            case OBJECT_TYPE_INTEGER:
              (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
              (yyval.expression).value.integer = UNDEFINED;
              break;
            case OBJECT_TYPE_FLOAT:
              (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
              break;
            case OBJECT_TYPE_STRING:
              (yyval.expression).type = EXPRESSION_TYPE_STRING;
              (yyval.expression).value.sized_string = NULL;
              break;
            default:
              // In a primary expression any identifier that corresponds to an
              // object must be of type integer, float or string. If "foobar" is
              // either a function, structure, dictionary or array you can not
              // use it as:
              //   condition: foobar
              yr_compiler_set_error_extra_info_fmt(
                  compiler,
                  "wrong usage of identifier \"%s\"",
                  (yyvsp[0].expression).identifier);
              result = ERROR_WRONG_TYPE;
          }
        }
        else
        {
          assert(false);
        }

        fail_if_error(result);
      }
#line 3737 "grammar.c" /* yacc.c:1663  */
    break;

  case 128:
#line 2014 "grammar.y" /* yacc.c:1663  */
    {
        int result = ERROR_SUCCESS;

        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER | EXPRESSION_TYPE_FLOAT, "-");

        if ((yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          (yyval.expression).value.integer = ((yyvsp[0].expression).value.integer == UNDEFINED) ?
              UNDEFINED : -((yyvsp[0].expression).value.integer);
          result = yr_parser_emit(yyscanner, OP_INT_MINUS, NULL);
        }
        else if ((yyvsp[0].expression).type == EXPRESSION_TYPE_FLOAT)
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
          result = yr_parser_emit(yyscanner, OP_DBL_MINUS, NULL);
        }

        fail_if_error(result);
      }
#line 3762 "grammar.c" /* yacc.c:1663  */
    break;

  case 129:
#line 2035 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "+", (yyvsp[-2].expression), (yyvsp[0].expression));

        if ((yyvsp[-2].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[-2].expression).value.integer;
          int64_t i2 = (yyvsp[0].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                (i2 > 0 && i1 > INT64_MAX - i2) ||
                (i2 < 0 && i1 < INT64_MIN - i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " + %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(+, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
#line 3801 "grammar.c" /* yacc.c:1663  */
    break;

  case 130:
#line 2070 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "-", (yyvsp[-2].expression), (yyvsp[0].expression));

        if ((yyvsp[-2].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[-2].expression).value.integer;
          int64_t i2 = (yyvsp[0].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                (i2 < 0 && i1 > INT64_MAX + i2) ||
                (i2 > 0 && i1 < INT64_MIN + i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " - %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(-, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
#line 3840 "grammar.c" /* yacc.c:1663  */
    break;

  case 131:
#line 2105 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "*", (yyvsp[-2].expression), (yyvsp[0].expression));

        if ((yyvsp[-2].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[-2].expression).value.integer;
          int64_t i2 = (yyvsp[0].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                i2 != 0 && llabs(i1) > INT64_MAX / llabs(i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " * %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(*, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
#line 3878 "grammar.c" /* yacc.c:1663  */
    break;

  case 132:
#line 2139 "grammar.y" /* yacc.c:1663  */
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "\\", (yyvsp[-2].expression), (yyvsp[0].expression));

        if ((yyvsp[-2].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[0].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          if ((yyvsp[0].expression).value.integer != 0)
          {
            (yyval.expression).value.integer = OPERATION(/, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
          else
          {
            result = ERROR_DIVISION_BY_ZERO;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
#line 3907 "grammar.c" /* yacc.c:1663  */
    break;

  case 133:
#line 2164 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, "%");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "%");

        fail_if_error(yr_parser_emit(yyscanner, OP_MOD, NULL));

        if ((yyvsp[0].expression).value.integer != 0)
        {
          (yyval.expression).value.integer = OPERATION(%, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        }
        else
        {
          fail_if_error(ERROR_DIVISION_BY_ZERO);
        }
      }
#line 3928 "grammar.c" /* yacc.c:1663  */
    break;

  case 134:
#line 2181 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, "^");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "^");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_XOR, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(^, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);
      }
#line 3942 "grammar.c" /* yacc.c:1663  */
    break;

  case 135:
#line 2191 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, "^");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "^");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_AND, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(&, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);
      }
#line 3956 "grammar.c" /* yacc.c:1663  */
    break;

  case 136:
#line 2201 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, "|");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "|");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_OR, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(|, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);
      }
#line 3970 "grammar.c" /* yacc.c:1663  */
    break;

  case 137:
#line 2211 "grammar.y" /* yacc.c:1663  */
    {
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "~");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_NOT, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = ((yyvsp[0].expression).value.integer == UNDEFINED) ?
            UNDEFINED : ~((yyvsp[0].expression).value.integer);
      }
#line 3984 "grammar.c" /* yacc.c:1663  */
    break;

  case 138:
#line 2221 "grammar.y" /* yacc.c:1663  */
    {
        int result;

        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, "<<");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, "<<");

        result = yr_parser_emit(yyscanner, OP_SHL, NULL);

        if (!IS_UNDEFINED((yyvsp[0].expression).value.integer) && (yyvsp[0].expression).value.integer < 0)
          result = ERROR_INVALID_OPERAND;
        else if (!IS_UNDEFINED((yyvsp[0].expression).value.integer) && (yyvsp[0].expression).value.integer >= 64)
          (yyval.expression).value.integer = 0;
        else
          (yyval.expression).value.integer = OPERATION(<<, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;

        fail_if_error(result);
      }
#line 4008 "grammar.c" /* yacc.c:1663  */
    break;

  case 139:
#line 2241 "grammar.y" /* yacc.c:1663  */
    {
        int result;

        check_type((yyvsp[-2].expression), EXPRESSION_TYPE_INTEGER, ">>");
        check_type((yyvsp[0].expression), EXPRESSION_TYPE_INTEGER, ">>");

        result = yr_parser_emit(yyscanner, OP_SHR, NULL);

        if (!IS_UNDEFINED((yyvsp[0].expression).value.integer) && (yyvsp[0].expression).value.integer < 0)
          result = ERROR_INVALID_OPERAND;
        else if (!IS_UNDEFINED((yyvsp[0].expression).value.integer) && (yyvsp[0].expression).value.integer >= 64)
          (yyval.expression).value.integer = 0;
        else
          (yyval.expression).value.integer = OPERATION(<<, (yyvsp[-2].expression).value.integer, (yyvsp[0].expression).value.integer);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;

        fail_if_error(result);
      }
#line 4032 "grammar.c" /* yacc.c:1663  */
    break;

  case 140:
#line 2261 "grammar.y" /* yacc.c:1663  */
    {
        (yyval.expression) = (yyvsp[0].expression);
      }
#line 4040 "grammar.c" /* yacc.c:1663  */
    break;


#line 4044 "grammar.c" /* yacc.c:1663  */
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
      yyerror (yyscanner, compiler, YY_("syntax error"));
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
        yyerror (yyscanner, compiler, yymsgp);
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
                      yytoken, &yylval, yyscanner, compiler);
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
                  yystos[yystate], yyvsp, yyscanner, compiler);
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
  yyerror (yyscanner, compiler, YY_("memory exhausted"));
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
                  yytoken, &yylval, yyscanner, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yyscanner, compiler);
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
#line 2266 "grammar.y" /* yacc.c:1907  */

