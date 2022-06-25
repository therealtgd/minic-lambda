/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "micko.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  int* lambda_parameter_map[128];
  int* lambda_argument_map[128];
  int lambda_arg_counter = 0;
  int lambda_idx = -1;
  int lcall_idx = -1;
  unsigned lambda_type;
  int lambda_main = 0;
  int lambda_counter = -1;

#line 103 "micko.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "micko.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__TYPE = 3,                      /* _TYPE  */
  YYSYMBOL__IF = 4,                        /* _IF  */
  YYSYMBOL__ELSE = 5,                      /* _ELSE  */
  YYSYMBOL__RETURN = 6,                    /* _RETURN  */
  YYSYMBOL__ID = 7,                        /* _ID  */
  YYSYMBOL__INT_NUMBER = 8,                /* _INT_NUMBER  */
  YYSYMBOL__UINT_NUMBER = 9,               /* _UINT_NUMBER  */
  YYSYMBOL__LPAREN = 10,                   /* _LPAREN  */
  YYSYMBOL__RPAREN = 11,                   /* _RPAREN  */
  YYSYMBOL__LBRACKET = 12,                 /* _LBRACKET  */
  YYSYMBOL__RBRACKET = 13,                 /* _RBRACKET  */
  YYSYMBOL__ASSIGN = 14,                   /* _ASSIGN  */
  YYSYMBOL__SEMICOLON = 15,                /* _SEMICOLON  */
  YYSYMBOL__AROP = 16,                     /* _AROP  */
  YYSYMBOL__RELOP = 17,                    /* _RELOP  */
  YYSYMBOL__LAMBDA = 18,                   /* _LAMBDA  */
  YYSYMBOL__COLON = 19,                    /* _COLON  */
  YYSYMBOL__COMMA = 20,                    /* _COMMA  */
  YYSYMBOL__RARROW = 21,                   /* _RARROW  */
  YYSYMBOL__TEST = 22,                     /* _TEST  */
  YYSYMBOL__LSHIFT = 23,                   /* _LSHIFT  */
  YYSYMBOL__RSHIFT = 24,                   /* _RSHIFT  */
  YYSYMBOL_ONLY_IF = 25,                   /* ONLY_IF  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_program = 27,                   /* program  */
  YYSYMBOL_function_list = 28,             /* function_list  */
  YYSYMBOL_function = 29,                  /* function  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_lambda_statement = 31,          /* lambda_statement  */
  YYSYMBOL_32_2 = 32,                      /* $@2  */
  YYSYMBOL_lambda_exp = 33,                /* lambda_exp  */
  YYSYMBOL_34_3 = 34,                      /* $@3  */
  YYSYMBOL_lambda_parameters = 35,         /* lambda_parameters  */
  YYSYMBOL_lambda_parameter = 36,          /* lambda_parameter  */
  YYSYMBOL_parameter = 37,                 /* parameter  */
  YYSYMBOL_body = 38,                      /* body  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_variable_list = 40,             /* variable_list  */
  YYSYMBOL_variable = 41,                  /* variable  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_compound_statement = 44,        /* compound_statement  */
  YYSYMBOL_assignment_statement = 45,      /* assignment_statement  */
  YYSYMBOL_num_exp = 46,                   /* num_exp  */
  YYSYMBOL_exp = 47,                       /* exp  */
  YYSYMBOL_literal = 48,                   /* literal  */
  YYSYMBOL_function_call = 49,             /* function_call  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_lambda_call = 51,               /* lambda_call  */
  YYSYMBOL_52_6 = 52,                      /* $@6  */
  YYSYMBOL_lambda_arguments = 53,          /* lambda_arguments  */
  YYSYMBOL_lambda_argument = 54,           /* lambda_argument  */
  YYSYMBOL_argument = 55,                  /* argument  */
  YYSYMBOL_if_statement = 56,              /* if_statement  */
  YYSYMBOL_if_part = 57,                   /* if_part  */
  YYSYMBOL_58_7 = 58,                      /* @7  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_rel_exp = 60,                   /* rel_exp  */
  YYSYMBOL_shift_literal = 61,             /* shift_literal  */
  YYSYMBOL_lshitf_exp = 62,                /* lshitf_exp  */
  YYSYMBOL_rshitf_exp = 63,                /* rshitf_exp  */
  YYSYMBOL_return_statement = 64           /* return_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   95

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    78,    79,    84,    83,   109,   108,   135,
     134,   150,   151,   155,   177,   179,   189,   188,   198,   199,
     203,   213,   214,   218,   219,   220,   221,   222,   226,   230,
     240,   241,   245,   246,   265,   267,   274,   280,   285,   289,
     293,   298,   301,   307,   306,   326,   325,   352,   353,   357,
     368,   370,   382,   385,   391,   396,   390,   409,   420,   421,
     428,   439,   450
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_TYPE", "_IF",
  "_ELSE", "_RETURN", "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN",
  "_RPAREN", "_LBRACKET", "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP",
  "_RELOP", "_LAMBDA", "_COLON", "_COMMA", "_RARROW", "_TEST", "_LSHIFT",
  "_RSHIFT", "ONLY_IF", "$accept", "program", "function_list", "function",
  "$@1", "lambda_statement", "$@2", "lambda_exp", "$@3",
  "lambda_parameters", "lambda_parameter", "parameter", "body", "$@4",
  "variable_list", "variable", "statement_list", "statement",
  "compound_statement", "assignment_statement", "num_exp", "exp",
  "literal", "function_call", "$@5", "lambda_call", "$@6",
  "lambda_arguments", "lambda_argument", "argument", "if_statement",
  "if_part", "@7", "$@8", "rel_exp", "shift_literal", "lshitf_exp",
  "rshitf_exp", "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,    12,     3,    10,   -51,   -51,   -51,   -51,    15,    37,
      42,    33,   -51,    40,   -51,   -51,    51,    59,   -51,   -51,
      41,     2,   -51,    61,    20,   -12,   -51,   -51,    65,   -51,
     -51,   -51,   -51,   -51,    68,    60,    62,   -51,   -51,     0,
     -51,   -51,    20,    16,   -51,   -51,   -51,   -51,   -51,   -51,
      20,    50,    50,    35,   -51,    39,   -51,   -51,    20,   -51,
      64,     6,   -51,    20,    45,   -51,   -51,   -51,   -51,    66,
     -51,    46,   -51,    69,    20,   -51,   -51,   -51,    58,    20,
      67,    20,    70,    71,    73,   -51,    70,    39,    70,    -4,
     -51,   -51,    81,   -51,   -51,    20,    78,    72,   -51,   -51,
     -51,    81,    76,   -51,    74,    20,    49,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     5,     1,     4,     0,    14,
       0,     0,    15,     0,    18,     6,    16,     0,    21,    19,
       0,     0,    20,     0,     0,     0,    21,    17,     0,    27,
      22,    23,    24,    25,    52,     0,     0,    26,    54,    35,
      41,    42,     0,     0,    32,    34,    37,    36,    38,    39,
       0,    58,    58,     0,     7,     0,    30,    31,     0,    45,
       0,     0,    62,     0,     0,    59,    60,    61,    28,     0,
      53,     0,    55,     0,    50,    40,    33,    29,     0,     0,
       0,     0,    51,     0,     0,     8,    57,     0,    49,     0,
      47,    44,     0,    56,    46,     0,     0,     9,    11,    48,
      13,     0,     0,    12,     0,     0,     0,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,    85,   -51,   -51,   -51,   -51,   -51,   -51,
     -11,   -51,   -51,   -51,   -51,   -51,    63,   -50,   -51,   -51,
     -24,    28,    17,   -51,   -51,   -51,   -51,   -51,    -1,   -51,
     -51,   -51,   -51,   -51,   -51,    43,   -20,   -17,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     8,    29,    69,    85,   102,    97,
      98,    11,    15,    18,    16,    19,    21,    30,    31,    32,
      88,    44,    45,    46,    60,    47,    73,    89,    90,    83,
      33,    34,    58,    80,    72,    66,    48,    49,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    35,    50,     6,    36,    70,    23,    94,    24,    25,
     -43,    51,    52,     1,    26,    27,    95,    75,    61,     5,
      28,    59,    63,    51,    52,     9,    64,    39,    40,    41,
      42,    62,    63,    35,    71,    35,    36,    93,    36,    23,
      10,    24,    25,    23,    13,    24,    25,    26,    68,    12,
      82,    26,    14,    28,    17,    86,    22,    28,    40,    41,
      77,    63,    63,    79,   107,    63,    20,    35,    65,    65,
      36,    38,    54,    55,    74,    56,    84,    57,    87,    81,
      78,   106,    91,    92,    96,   100,    63,   104,     7,    53,
     103,    76,   101,   105,    99,    67
};

static const yytype_int8 yycheck[] =
{
      24,    21,    14,     0,    21,    55,     4,    11,     6,     7,
      10,    23,    24,     3,    12,    13,    20,    11,    42,     7,
      18,    21,    16,    23,    24,    10,    50,     7,     8,     9,
      10,    15,    16,    53,    58,    55,    53,    87,    55,     4,
       3,     6,     7,     4,    11,     6,     7,    12,    13,     7,
      74,    12,    12,    18,     3,    79,    15,    18,     8,     9,
      15,    16,    16,    17,    15,    16,     7,    87,    51,    52,
      87,    10,     7,     5,    10,    15,    18,    15,    11,    10,
      14,   105,    11,    10,     3,     7,    16,    11,     3,    26,
     101,    63,    20,    19,    95,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    27,    28,    29,     7,     0,    29,    30,    10,
       3,    37,     7,    11,    12,    38,    40,     3,    39,    41,
       7,    42,    15,     4,     6,     7,    12,    13,    18,    31,
      43,    44,    45,    56,    57,    62,    63,    64,    10,     7,
       8,     9,    10,    46,    47,    48,    49,    51,    62,    63,
      14,    23,    24,    42,     7,     5,    15,    15,    58,    21,
      50,    46,    15,    16,    46,    48,    61,    61,    13,    32,
      43,    46,    60,    52,    10,    11,    47,    15,    14,    17,
      59,    10,    46,    55,    18,    33,    46,    11,    46,    53,
      54,    11,    10,    43,    11,    20,     3,    35,    36,    54,
       7,    20,    34,    36,    11,    19,    46,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    28,    28,    30,    29,    32,    31,    34,
      33,    35,    35,    36,    37,    37,    39,    38,    40,    40,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    45,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    50,    49,    52,    51,    53,    53,    54,
      55,    55,    56,    56,    58,    59,    57,    60,    61,    61,
      62,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     7,     0,     5,     0,
       8,     1,     3,     2,     0,     2,     0,     5,     0,     2,
       3,     0,     2,     1,     1,     1,     1,     1,     3,     4,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     0,     5,     0,     6,     1,     3,     1,
       0,     1,     1,     3,     0,     0,     7,     3,     0,     1,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: function_list  */
#line 71 "micko.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1229 "micko.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 84 "micko.y"
      {
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH \t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1245 "micko.tab.c"
    break;

  case 6: /* function: _TYPE _ID $@1 _LPAREN parameter _RPAREN body  */
#line 96 "micko.y"
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1259 "micko.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 109 "micko.y"
    {
      lambda_counter++;
      lambda_idx = lookup_symbol((yyvsp[0].s), LFUN);
      if (lambda_idx == NO_INDEX) {
        int* param_types = (int*) malloc(sizeof(int)*128);
        lambda_idx = insert_symbol((yyvsp[0].s), LFUN, NO_ATR, NO_ATR, NO_ATR);
        lambda_parameter_map[lambda_idx] = param_types;
        code("\n\t\tJMP \t@main_body_%d", lambda_main);
      }
      else
        err("Redefinition of lambda function '%s'", (yyvsp[0].s));
    }
#line 1276 "micko.tab.c"
    break;

  case 8: /* lambda_statement: _LAMBDA _ID $@2 _ASSIGN lambda_exp  */
#line 122 "micko.y"
   {
     set_type(lambda_idx, lambda_type);
     printf("%d  ", lambda_main);
     code("\n@lambda_%s_%d_exit:", (yyvsp[-3].s), lambda_main);
     code("\n\t\tMOV \t%%14, %%15");
     code("\n\t\tPOP \t%%14");
     code("\n\t\tRET");
     code("\n@main_body_%d:", lambda_main);
     lambda_main++;
   }
#line 1291 "micko.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 135 "micko.y"
    {
      code("\n@lambda_%s_%d:", get_name(lambda_idx), lambda_main);
      code("\n\t\tPUSH \t%%14");
      code("\n\t\tMOV \t%%15,%%14");
      code("\n\t\tJMP \t@lambda_%s_%d_body", get_name(lambda_idx), lambda_main);
      code("\n@lambda_%s_%d_body:", get_name(lambda_idx), lambda_main);
    }
#line 1303 "micko.tab.c"
    break;

  case 10: /* lambda_exp: _LAMBDA _LPAREN lambda_parameters $@3 _RPAREN _COLON num_exp _SEMICOLON  */
#line 143 "micko.y"
    {
      gen_mov((yyvsp[-1].i), FUN_REG);
      code("\n\t\tJMP \t@lambda_%s_%d_exit", get_name(lambda_idx), lambda_main);
    }
#line 1312 "micko.tab.c"
    break;

  case 13: /* lambda_parameter: _TYPE _ID  */
#line 156 "micko.y"
    {
      if (lookup_symbol((yyvsp[0].s), PAR) != NO_INDEX) {
        err("Redefinition of parameter %s ", (yyvsp[0].s));
      }
      lambda_type = (yyvsp[-1].i);
      insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, NO_ATR);
      int num_params = get_atr1(lambda_idx);
      int* param_types = lambda_parameter_map[lambda_idx];
      if (num_params > 0) {
        if (param_types[num_params - 1] != (yyvsp[-1].i)) {
          err("Incompatible parameters in lambda function");
        }
      }
      param_types[num_params] = (yyvsp[-1].i);
      num_params += 1;
      set_atr1(lambda_idx, num_params);
    }
#line 1334 "micko.tab.c"
    break;

  case 14: /* parameter: %empty  */
#line 177 "micko.y"
      { set_atr1(fun_idx, 0); }
#line 1340 "micko.tab.c"
    break;

  case 15: /* parameter: _TYPE _ID  */
#line 180 "micko.y"
      {
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[-1].i));
      }
#line 1350 "micko.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 189 "micko.y"
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1360 "micko.tab.c"
    break;

  case 20: /* variable: _TYPE _ID _SEMICOLON  */
#line 204 "micko.y"
      {
        if(lookup_symbol((yyvsp[-1].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[-1].s), VAR, (yyvsp[-2].i), ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-1].s));
      }
#line 1371 "micko.tab.c"
    break;

  case 29: /* assignment_statement: _ID _ASSIGN num_exp _SEMICOLON  */
#line 231 "micko.y"
      {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR);
        if(idx == NO_INDEX) {
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment '%s'", get_type((yyvsp[-1].i)));

        }
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1385 "micko.tab.c"
    break;

  case 33: /* num_exp: num_exp _AROP exp  */
#line 247 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
        int t1 = get_type((yyvsp[-2].i));    
        code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name((yyvsp[-2].i));
        code(",");
        gen_sym_name((yyvsp[0].i));
        code(",");
        free_if_reg((yyvsp[0].i));
        free_if_reg((yyvsp[-2].i));
        (yyval.i) = take_reg();
        gen_sym_name((yyval.i));
        set_type((yyval.i), t1);
      }
#line 1405 "micko.tab.c"
    break;

  case 35: /* exp: _ID  */
#line 268 "micko.y"
      {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1415 "micko.tab.c"
    break;

  case 36: /* exp: lambda_call  */
#line 275 "micko.y"
    {
      (yyval.i) = take_reg();
      gen_mov(FUN_REG, (yyval.i));
    }
#line 1424 "micko.tab.c"
    break;

  case 37: /* exp: function_call  */
#line 281 "micko.y"
      {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1433 "micko.tab.c"
    break;

  case 38: /* exp: lshitf_exp  */
#line 286 "micko.y"
    {
      (yyval.i) = (yyvsp[0].i);
    }
#line 1441 "micko.tab.c"
    break;

  case 39: /* exp: rshitf_exp  */
#line 290 "micko.y"
    {
      (yyval.i) = (yyvsp[0].i);
    }
#line 1449 "micko.tab.c"
    break;

  case 40: /* exp: _LPAREN num_exp _RPAREN  */
#line 294 "micko.y"
      { (yyval.i) = (yyvsp[-1].i); }
#line 1455 "micko.tab.c"
    break;

  case 41: /* literal: _INT_NUMBER  */
#line 299 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1461 "micko.tab.c"
    break;

  case 42: /* literal: _UINT_NUMBER  */
#line 302 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1467 "micko.tab.c"
    break;

  case 43: /* $@5: %empty  */
#line 307 "micko.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1477 "micko.tab.c"
    break;

  case 44: /* function_call: _ID $@5 _LPAREN argument _RPAREN  */
#line 313 "micko.y"
      {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1491 "micko.tab.c"
    break;

  case 45: /* $@6: %empty  */
#line 326 "micko.y"
    {
      lcall_idx = lookup_symbol((yyvsp[-1].s), LFUN);
      if (lcall_idx == NO_INDEX)
        err("'%s' is not a lambda function", (yyvsp[-1].s));
      int* arg_list = (int*) malloc(sizeof(int)*128);
      lambda_argument_map[lcall_idx] = arg_list;
    }
#line 1503 "micko.tab.c"
    break;

  case 46: /* lambda_call: _ID _RARROW $@6 _LPAREN lambda_arguments _RPAREN  */
#line 334 "micko.y"
    {
      int* arg_list = lambda_argument_map[lcall_idx];
      for (int i = 0; i < lambda_arg_counter; i++) {
        code("\n\t\tPUSH\t");
        gen_sym_name(arg_list[i]);
      }
      if (get_atr1(lcall_idx) != lambda_arg_counter)
        err("wrong number of args to function '%s'", get_name(lambda_idx));

      code("\n\t\tCALL\t@lambda_%s_%d", get_name(lcall_idx), lambda_main);
      code("\n\t\tADDS \t%%15,$%d,%%15", lambda_arg_counter*4);
      lambda_arg_counter = 0;
      set_type(FUN_REG, get_type(lcall_idx));
      (yyval.i) = FUN_REG;
    }
#line 1523 "micko.tab.c"
    break;

  case 49: /* lambda_argument: num_exp  */
#line 358 "micko.y"
    {
      if (lambda_parameter_map[lcall_idx][lambda_arg_counter] != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'", get_name(lcall_idx));
      int* arg_list = lambda_argument_map[lcall_idx];
      arg_list[lambda_arg_counter] = (yyvsp[0].i);
      lambda_arg_counter += 1;
    }
#line 1535 "micko.tab.c"
    break;

  case 50: /* argument: %empty  */
#line 368 "micko.y"
    { (yyval.i) = 0; }
#line 1541 "micko.tab.c"
    break;

  case 51: /* argument: num_exp  */
#line 371 "micko.y"
    { 
      if(get_atr2(fcall_idx) != get_type((yyvsp[0].i)))
        err("incompatible type for argument");
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = 1;
    }
#line 1554 "micko.tab.c"
    break;

  case 52: /* if_statement: if_part  */
#line 383 "micko.y"
      { code("\n@exit%d:", (yyvsp[0].i)); }
#line 1560 "micko.tab.c"
    break;

  case 53: /* if_statement: if_part _ELSE statement  */
#line 386 "micko.y"
      { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 1566 "micko.tab.c"
    break;

  case 54: /* @7: %empty  */
#line 391 "micko.y"
      {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 1575 "micko.tab.c"
    break;

  case 55: /* $@8: %empty  */
#line 396 "micko.y"
      {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 1584 "micko.tab.c"
    break;

  case 56: /* if_part: _IF _LPAREN @7 rel_exp $@8 _RPAREN statement  */
#line 401 "micko.y"
      {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1594 "micko.tab.c"
    break;

  case 57: /* rel_exp: num_exp _RELOP num_exp  */
#line 410 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 1605 "micko.tab.c"
    break;

  case 58: /* shift_literal: %empty  */
#line 420 "micko.y"
    { (yyval.i) = 2; }
#line 1611 "micko.tab.c"
    break;

  case 59: /* shift_literal: literal  */
#line 422 "micko.y"
    {
      (yyval.i) = atoi(get_name((yyvsp[0].i))); 
    }
#line 1619 "micko.tab.c"
    break;

  case 60: /* lshitf_exp: _ID _LSHIFT shift_literal  */
#line 429 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
      if (idx == NO_INDEX)
        err("%s undeclared", (yyvsp[-2].s));
      gen_shift(idx, (yyvsp[0].i), 0);
      (yyval.i) = idx;
    }
#line 1631 "micko.tab.c"
    break;

  case 61: /* rshitf_exp: _ID _RSHIFT shift_literal  */
#line 440 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
      if (idx == NO_INDEX)
        err("%s undeclared", (yyvsp[-2].s));
      gen_shift(idx, (yyvsp[0].i), 1);
      (yyval.i) = idx;
    }
#line 1643 "micko.tab.c"
    break;

  case 62: /* return_statement: _RETURN num_exp _SEMICOLON  */
#line 451 "micko.y"
      {
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 1654 "micko.tab.c"
    break;


#line 1658 "micko.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 459 "micko.y"


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

