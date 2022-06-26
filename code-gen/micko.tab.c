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
  char* enum_values[128];
  int* enums[128];
  int enum_values_counter = 0;
  int current_enum = -1;
  int generating_lambda = 0;

#line 108 "micko.tab.c"

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
  YYSYMBOL__ENUM = 25,                     /* _ENUM  */
  YYSYMBOL__DOT = 26,                      /* _DOT  */
  YYSYMBOL_ONLY_IF = 27,                   /* ONLY_IF  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_program = 29,                   /* program  */
  YYSYMBOL_enum_list = 30,                 /* enum_list  */
  YYSYMBOL_function_list = 31,             /* function_list  */
  YYSYMBOL_function = 32,                  /* function  */
  YYSYMBOL_33_1 = 33,                      /* $@1  */
  YYSYMBOL_lambda_statement = 34,          /* lambda_statement  */
  YYSYMBOL_35_2 = 35,                      /* $@2  */
  YYSYMBOL_lambda_exp = 36,                /* lambda_exp  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_lambda_parameters = 38,         /* lambda_parameters  */
  YYSYMBOL_lambda_parameter = 39,          /* lambda_parameter  */
  YYSYMBOL_parameter = 40,                 /* parameter  */
  YYSYMBOL_body = 41,                      /* body  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_variable_list = 43,             /* variable_list  */
  YYSYMBOL_variable = 44,                  /* variable  */
  YYSYMBOL_enumeration = 45,               /* enumeration  */
  YYSYMBOL_46_5 = 46,                      /* $@5  */
  YYSYMBOL_enum_values = 47,               /* enum_values  */
  YYSYMBOL_enum_value = 48,                /* enum_value  */
  YYSYMBOL_statement_list = 49,            /* statement_list  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_compound_statement = 51,        /* compound_statement  */
  YYSYMBOL_assignment_statement = 52,      /* assignment_statement  */
  YYSYMBOL_num_exp = 53,                   /* num_exp  */
  YYSYMBOL_exp = 54,                       /* exp  */
  YYSYMBOL_literal = 55,                   /* literal  */
  YYSYMBOL_function_call = 56,             /* function_call  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_lambda_call = 58,               /* lambda_call  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_lambda_arguments = 60,          /* lambda_arguments  */
  YYSYMBOL_lambda_argument = 61,           /* lambda_argument  */
  YYSYMBOL_argument = 62,                  /* argument  */
  YYSYMBOL_if_statement = 63,              /* if_statement  */
  YYSYMBOL_if_part = 64,                   /* if_part  */
  YYSYMBOL_65_8 = 65,                      /* @8  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_rel_exp = 67,                   /* rel_exp  */
  YYSYMBOL_shift_literal = 68,             /* shift_literal  */
  YYSYMBOL_lshitf_exp = 69,                /* lshitf_exp  */
  YYSYMBOL_rshitf_exp = 70,                /* rshitf_exp  */
  YYSYMBOL_return_statement = 71           /* return_statement  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    85,    86,    90,    91,    96,    95,   120,
     119,   146,   145,   165,   166,   170,   193,   195,   205,   204,
     214,   215,   219,   230,   229,   248,   249,   253,   262,   263,
     267,   268,   269,   270,   271,   275,   279,   291,   292,   293,
     322,   323,   342,   344,   355,   361,   366,   370,   374,   379,
     382,   388,   387,   407,   406,   434,   435,   439,   451,   453,
     465,   468,   474,   479,   473,   492,   503,   504,   511,   522,
     533
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
  "_RSHIFT", "_ENUM", "_DOT", "ONLY_IF", "$accept", "program", "enum_list",
  "function_list", "function", "$@1", "lambda_statement", "$@2",
  "lambda_exp", "$@3", "lambda_parameters", "lambda_parameter",
  "parameter", "body", "$@4", "variable_list", "variable", "enumeration",
  "$@5", "enum_values", "enum_value", "statement_list", "statement",
  "compound_statement", "assignment_statement", "num_exp", "exp",
  "literal", "function_call", "$@6", "lambda_call", "$@7",
  "lambda_arguments", "lambda_argument", "argument", "if_statement",
  "if_part", "@8", "$@9", "rel_exp", "shift_literal", "lshitf_exp",
  "rshitf_exp", "return_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -67,    24,     0,   -67,    37,    49,    28,   -67,   -67,   -67,
     -67,   -67,    19,    53,    66,    73,    74,    71,   -67,    10,
     -67,   -67,    72,    68,    73,   -67,   -67,   -67,   -67,    83,
      80,   -67,   -67,    75,     3,   -67,    78,    54,    26,   -67,
     -67,    82,   -67,   -67,   -67,   -67,   -67,    86,    77,    79,
     -67,   -67,    22,   -67,   -67,    54,    12,   -67,   -67,   -67,
     -67,   -67,   -67,    67,    50,    50,    35,   -67,    48,   -67,
     -67,    54,   -67,    85,    -3,   -67,    54,    -4,    52,   -67,
     -67,   -67,   -67,    84,   -67,    -5,   -67,    87,    54,   -67,
     -67,    89,   -67,    81,    54,    90,    54,    88,    91,    92,
      93,   -67,    88,    48,    88,    -6,   -67,   -67,   -67,    97,
     -67,   -67,    54,    98,    94,   -67,   -67,   -67,    97,    95,
     -67,    96,    54,    56,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     2,     5,     4,     7,
      23,     6,     0,     0,    16,     0,     0,     0,    27,     0,
      25,    17,     0,     0,     0,    20,     8,    24,    26,    18,
       0,    28,    21,     0,     0,    22,     0,     0,     0,    28,
      19,     0,    34,    29,    30,    31,    32,    60,     0,     0,
      33,    62,    43,    49,    50,     0,     0,    40,    42,    45,
      44,    46,    47,     0,    66,    66,     0,     9,     0,    37,
      38,     0,    53,     0,     0,    70,     0,    43,     0,    67,
      68,    69,    35,     0,    61,     0,    63,     0,    58,    48,
      41,     0,    36,     0,     0,     0,     0,    59,     0,     0,
       0,    10,    65,     0,    57,     0,    55,    52,    39,     0,
      64,    54,     0,     0,    11,    13,    56,    15,     0,     0,
      14,     0,     0,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   102,   -67,   -67,   -67,   -67,   -67,
     -67,   -25,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
      99,    70,   -66,   -67,   -67,   -37,    34,    14,   -67,   -67,
     -67,   -67,   -67,    -1,   -67,   -67,   -67,   -67,   -67,   -67,
      47,   -33,   -30,   -67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    12,    42,    83,   101,   119,
     114,   115,    17,    26,    31,    29,    32,     8,    13,    19,
      20,    34,    43,    44,    45,   104,    57,    58,    59,    73,
      60,    87,   105,   106,    98,    46,    47,    71,    95,    86,
      80,    61,    62,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    48,    84,     4,    49,   111,   -51,    36,    89,    37,
      38,    76,    94,    76,   112,    39,    40,    72,    74,    64,
      65,    41,    91,    23,     3,     5,    78,    75,    76,    14,
      24,     4,   -51,    48,    85,    48,    49,   110,    49,    36,
      63,    37,    38,    72,     9,    64,    65,    39,    82,    64,
      65,    97,    36,    41,    37,    38,    10,   102,    53,    54,
      39,    52,    53,    54,    55,    15,    41,    92,    76,    16,
      48,   124,    76,    49,    77,    53,    54,    55,    79,    79,
      18,    21,    22,    27,    25,   123,    30,    33,    51,    67,
      35,    68,    69,   120,    70,    88,    99,    96,    93,   100,
     113,   103,   107,   109,    76,   117,   121,   108,    11,    66,
      90,   116,    81,     0,   118,   122,     0,     0,     0,     0,
       0,     0,     0,    28
};

static const yytype_int8 yycheck[] =
{
      37,    34,    68,     3,    34,    11,    10,     4,    11,     6,
       7,    16,    17,    16,    20,    12,    13,    21,    55,    23,
      24,    18,    26,    13,     0,    25,    63,    15,    16,    10,
      20,     3,    10,    66,    71,    68,    66,   103,    68,     4,
      14,     6,     7,    21,     7,    23,    24,    12,    13,    23,
      24,    88,     4,    18,     6,     7,     7,    94,     8,     9,
      12,     7,     8,     9,    10,    12,    18,    15,    16,     3,
     103,    15,    16,   103,     7,     8,     9,    10,    64,    65,
       7,     7,    11,    15,    12,   122,     3,     7,    10,     7,
      15,     5,    15,   118,    15,    10,     7,    10,    14,    18,
       3,    11,    11,    10,    16,     7,    11,    15,     6,    39,
      76,   112,    65,    -1,    20,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,     0,     3,    25,    31,    32,    45,     7,
       7,    32,    33,    46,    10,    12,     3,    40,     7,    47,
      48,     7,    11,    13,    20,    12,    41,    15,    48,    43,
       3,    42,    44,     7,    49,    15,     4,     6,     7,    12,
      13,    18,    34,    50,    51,    52,    63,    64,    69,    70,
      71,    10,     7,     8,     9,    10,    53,    54,    55,    56,
      58,    69,    70,    14,    23,    24,    49,     7,     5,    15,
      15,    65,    21,    57,    53,    15,    16,     7,    53,    55,
      68,    68,    13,    35,    50,    53,    67,    59,    10,    11,
      54,    26,    15,    14,    17,    66,    10,    53,    62,     7,
      18,    36,    53,    11,    53,    60,    61,    11,    15,    10,
      50,    11,    20,     3,    38,    39,    61,     7,    20,    37,
      39,    11,    19,    53,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    33,    32,    35,
      34,    37,    36,    38,    38,    39,    40,    40,    42,    41,
      43,    43,    44,    46,    45,    47,    47,    48,    49,    49,
      50,    50,    50,    50,    50,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    57,    56,    59,    58,    60,    60,    61,    62,    62,
      63,    63,    65,    66,    64,    67,    68,    68,    69,    70,
      71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     2,     0,     7,     0,
       5,     0,     8,     1,     3,     2,     0,     2,     0,     5,
       0,     2,     3,     0,     7,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     1,     3,     4,     2,     2,     6,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     5,     0,     6,     1,     3,     1,     0,     1,
       1,     3,     0,     0,     7,     3,     0,     1,     3,     3,
       3
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
  case 2: /* program: enum_list function_list  */
#line 78 "micko.y"
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1259 "micko.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 96 "micko.y"
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
#line 1275 "micko.tab.c"
    break;

  case 8: /* function: _TYPE _ID $@1 _LPAREN parameter _RPAREN body  */
#line 108 "micko.y"
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1288 "micko.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 120 "micko.y"
    {
      lambda_counter++;
      lambda_idx = lookup_symbol((yyvsp[0].s), LFUN);
      if (lambda_idx == NO_INDEX) {
        int* param_types = (int*) malloc(sizeof(int)*128);
        // _ID, LFUN, TYPE, NUM_PARAMS, LAMDA_COUNTER
        lambda_idx = insert_symbol((yyvsp[0].s), LFUN, NO_TYPE, NO_ATR, lambda_counter);
        lambda_parameter_map[lambda_idx] = param_types;
        code("\n\t\tJMP \t@main_body_%d", lambda_main);
      }
      else
        err("Redefinition of lambda function '%s'", (yyvsp[0].s));
    }
#line 1306 "micko.tab.c"
    break;

  case 10: /* lambda_statement: _LAMBDA _ID $@2 _ASSIGN lambda_exp  */
#line 134 "micko.y"
   {
     set_type(lambda_idx, lambda_type);
     code("\n@lambda_%s_%d_exit:", (yyvsp[-3].s), lambda_main);
     code("\n\t\tMOV \t%%14, %%15");
     code("\n\t\tPOP \t%%14");
     code("\n\t\tRET");
     code("\n@main_body_%d:", lambda_main);
     lambda_main++;
   }
#line 1320 "micko.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 146 "micko.y"
    {
      // ovaj flag koristim jer mogu biti dve promenljive istog naziva
      // jedna van lambde a jedna kao lambda parameter, tako da moram imati flag da znam koji da gledam
      generating_lambda = 1;
      code("\n@lambda_%s_%d:", get_name(lambda_idx), lambda_main);
      code("\n\t\tPUSH \t%%14");
      code("\n\t\tMOV \t%%15,%%14");
      code("\n\t\tJMP \t@lambda_%s_%d_body", get_name(lambda_idx), lambda_main);
      code("\n@lambda_%s_%d_body:", get_name(lambda_idx), lambda_main);
    }
#line 1335 "micko.tab.c"
    break;

  case 12: /* lambda_exp: _LAMBDA _LPAREN lambda_parameters $@3 _RPAREN _COLON num_exp _SEMICOLON  */
#line 157 "micko.y"
    {
      generating_lambda = 0;
      gen_mov((yyvsp[-1].i), FUN_REG);
      code("\n\t\tJMP \t@lambda_%s_%d_exit", get_name(lambda_idx), lambda_main);
    }
#line 1345 "micko.tab.c"
    break;

  case 15: /* lambda_parameter: _TYPE _ID  */
#line 171 "micko.y"
    {
      if (lookup_symbol((yyvsp[0].s), LPAR) != NO_INDEX) {
        err("Redefinition of parameter %s ", (yyvsp[0].s));
      }
      lambda_type = (yyvsp[-1].i);
      // lambda par u TS _ID, LPAR, _TYPE, broj lambde kojoj pripada, broj trenutnog parametra (koristim u codegen.c)
      int num_params = get_atr1(lambda_idx);
      insert_symbol((yyvsp[0].s), LPAR, (yyvsp[-1].i), lambda_idx, num_params+1);
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
#line 1368 "micko.tab.c"
    break;

  case 16: /* parameter: %empty  */
#line 193 "micko.y"
      { set_atr1(fun_idx, 0); }
#line 1374 "micko.tab.c"
    break;

  case 17: /* parameter: _TYPE _ID  */
#line 196 "micko.y"
      {
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[-1].i));
      }
#line 1384 "micko.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 205 "micko.y"
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1394 "micko.tab.c"
    break;

  case 22: /* variable: _TYPE _ID _SEMICOLON  */
#line 220 "micko.y"
      {
        if(lookup_symbol((yyvsp[-1].s), VAR|PAR) == NO_INDEX)
           insert_symbol((yyvsp[-1].s), VAR, (yyvsp[-2].i), ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", (yyvsp[-1].s));
      }
#line 1405 "micko.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 230 "micko.y"
    {
      current_enum = get_last_element()+1;
      int idx = lookup_symbol((yyvsp[0].s), ENUM);
      if (idx != NO_INDEX) {
        err("redefenition of enum %s", (yyvsp[0].s));
      }
      // ubaci u tabelu simbola
      insert_symbol((yyvsp[0].s), ENUM, NO_TYPE, NO_ATR, NO_ATR);
    }
#line 1419 "micko.tab.c"
    break;

  case 24: /* enumeration: _ENUM _ID $@5 _LBRACKET enum_values _RBRACKET _SEMICOLON  */
#line 240 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[-5].s), ENUM);
      set_atr1(idx, enum_values_counter);
      enum_values_counter = 0;
    }
#line 1429 "micko.tab.c"
    break;

  case 27: /* enum_value: _ID  */
#line 254 "micko.y"
    {
      // _ID, _ENUM_VAL, indeks enuma kojem vrednost pripada, redni broj vrednosti, NO_ATR
      insert_symbol((yyvsp[0].s), ENUM_VAL, NO_TYPE, current_enum, enum_values_counter++);
      ;
    }
#line 1439 "micko.tab.c"
    break;

  case 36: /* assignment_statement: _ID _ASSIGN num_exp _SEMICOLON  */
#line 280 "micko.y"
      {
        print_symtab();
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid value in assignment '%s'", (yyvsp[-3].s));
        else {
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
        }
        gen_mov((yyvsp[-1].i), idx);
      }
#line 1455 "micko.tab.c"
    break;

  case 39: /* assignment_statement: _ID _ASSIGN _ID _DOT _ID _SEMICOLON  */
#line 294 "micko.y"
    {
      int idx = lookup_symbol(((yyvsp[-5].s)), VAR|PAR);
      if (idx == NO_INDEX)
        err("variable not defined: '%s'", (yyvsp[-5].s));
      if(get_type(idx) != INT)
        err("enum value %s must be int type", (yyvsp[-3].s));
      int enum_idx = lookup_symbol((yyvsp[-3].s), ENUM);
      if (enum_idx == NO_INDEX)
        err("enum not defined: '%s'", (yyvsp[-3].s));
      int enum_val_idx = lookup_symbol((yyvsp[-1].s), ENUM_VAL);
      if (enum_val_idx == NO_INDEX) {
        err("enum value not defined: '%s'", (yyvsp[-1].s));
      }
      int contains = 0;
      for (int i = 0; i< get_atr1(enum_idx); i++) {
        int current_idx = enum_idx + i + 1;
        if (get_name(current_idx) == get_name(enum_val_idx)) {
          // generisi kod
          contains = 1;
        }
      }
      if (contains == 0) {
        err("enum %s, doesn't contain value %s", (yyvsp[-3].s), (yyvsp[-1].s));
      }
    }
#line 1485 "micko.tab.c"
    break;

  case 41: /* num_exp: num_exp _AROP exp  */
#line 324 "micko.y"
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
#line 1505 "micko.tab.c"
    break;

  case 43: /* exp: _ID  */
#line 345 "micko.y"
      {
        if (generating_lambda == 1) {
          (yyval.i) = lookup_symbol((yyvsp[0].s), LPAR);
        }
        else
          (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1519 "micko.tab.c"
    break;

  case 44: /* exp: lambda_call  */
#line 356 "micko.y"
    {
      (yyval.i) = take_reg();
      gen_mov(FUN_REG, (yyval.i));
    }
#line 1528 "micko.tab.c"
    break;

  case 45: /* exp: function_call  */
#line 362 "micko.y"
      {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1537 "micko.tab.c"
    break;

  case 46: /* exp: lshitf_exp  */
#line 367 "micko.y"
    {
      (yyval.i) = (yyvsp[0].i);
    }
#line 1545 "micko.tab.c"
    break;

  case 47: /* exp: rshitf_exp  */
#line 371 "micko.y"
    {
      (yyval.i) = (yyvsp[0].i);
    }
#line 1553 "micko.tab.c"
    break;

  case 48: /* exp: _LPAREN num_exp _RPAREN  */
#line 375 "micko.y"
      { (yyval.i) = (yyvsp[-1].i); }
#line 1559 "micko.tab.c"
    break;

  case 49: /* literal: _INT_NUMBER  */
#line 380 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1565 "micko.tab.c"
    break;

  case 50: /* literal: _UINT_NUMBER  */
#line 383 "micko.y"
      { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1571 "micko.tab.c"
    break;

  case 51: /* $@6: %empty  */
#line 388 "micko.y"
      {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1581 "micko.tab.c"
    break;

  case 52: /* function_call: _ID $@6 _LPAREN argument _RPAREN  */
#line 394 "micko.y"
      {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1595 "micko.tab.c"
    break;

  case 53: /* $@7: %empty  */
#line 407 "micko.y"
    {
      lcall_idx = lookup_symbol((yyvsp[-1].s), LFUN);
      if (lcall_idx == NO_INDEX)
        err("'%s' is not a lambda function", (yyvsp[-1].s));
      int* arg_list = (int*) malloc(sizeof(int)*128);
      lambda_argument_map[lcall_idx] = arg_list;
    }
#line 1607 "micko.tab.c"
    break;

  case 54: /* lambda_call: _ID _RARROW $@7 _LPAREN lambda_arguments _RPAREN  */
#line 415 "micko.y"
    {
      int* arg_list = lambda_argument_map[lcall_idx];
      for (int i = 0; i < lambda_arg_counter; i++) {
        code("\n\t\tPUSH\t");
        gen_sym_name(arg_list[i]);
      }
      if (get_atr1(lcall_idx) != lambda_arg_counter)
        err("wrong number of args to function '%s'", get_name(lambda_idx));

      int idx_of_lambda_to_call = get_atr2(lcall_idx);
      code("\n\t\tCALL\t@lambda_%s_%d", get_name(lcall_idx), idx_of_lambda_to_call);
      code("\n\t\tADDS \t%%15,$%d,%%15", lambda_arg_counter*4);
      lambda_arg_counter = 0;
      set_type(FUN_REG, get_type(lcall_idx));
      (yyval.i) = FUN_REG;
    }
#line 1628 "micko.tab.c"
    break;

  case 57: /* lambda_argument: num_exp  */
#line 440 "micko.y"
    {
      if (lambda_parameter_map[lcall_idx][lambda_arg_counter] != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'", get_name(lcall_idx));
      int* arg_list = lambda_argument_map[lcall_idx];
      arg_list[lambda_arg_counter] = (yyvsp[0].i);
      lambda_arg_counter += 1;
    }
#line 1640 "micko.tab.c"
    break;

  case 58: /* argument: %empty  */
#line 451 "micko.y"
    { (yyval.i) = 0; }
#line 1646 "micko.tab.c"
    break;

  case 59: /* argument: num_exp  */
#line 454 "micko.y"
    { 
      if(get_atr2(fcall_idx) != get_type((yyvsp[0].i)))
        err("incompatible type for argument");
      free_if_reg((yyvsp[0].i));
      code("\n\t\t\tPUSH\t");
      gen_sym_name((yyvsp[0].i));
      (yyval.i) = 1;
    }
#line 1659 "micko.tab.c"
    break;

  case 60: /* if_statement: if_part  */
#line 466 "micko.y"
      { code("\n@exit%d:", (yyvsp[0].i)); }
#line 1665 "micko.tab.c"
    break;

  case 61: /* if_statement: if_part _ELSE statement  */
#line 469 "micko.y"
      { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 1671 "micko.tab.c"
    break;

  case 62: /* @8: %empty  */
#line 474 "micko.y"
      {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 1680 "micko.tab.c"
    break;

  case 63: /* $@9: %empty  */
#line 479 "micko.y"
      {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
        code("\n@true%d:", (yyvsp[-1].i));
      }
#line 1689 "micko.tab.c"
    break;

  case 64: /* if_part: _IF _LPAREN @8 rel_exp $@9 _RPAREN statement  */
#line 484 "micko.y"
      {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1699 "micko.tab.c"
    break;

  case 65: /* rel_exp: num_exp _RELOP num_exp  */
#line 493 "micko.y"
      {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));
      }
#line 1710 "micko.tab.c"
    break;

  case 66: /* shift_literal: %empty  */
#line 503 "micko.y"
    { (yyval.i) = 2; }
#line 1716 "micko.tab.c"
    break;

  case 67: /* shift_literal: literal  */
#line 505 "micko.y"
    {
      (yyval.i) = atoi(get_name((yyvsp[0].i))); 
    }
#line 1724 "micko.tab.c"
    break;

  case 68: /* lshitf_exp: _ID _LSHIFT shift_literal  */
#line 512 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
      if (idx == NO_INDEX)
        err("%s undeclared", (yyvsp[-2].s));
      gen_shift(idx, (yyvsp[0].i), 0);
      (yyval.i) = idx;
    }
#line 1736 "micko.tab.c"
    break;

  case 69: /* rshitf_exp: _ID _RSHIFT shift_literal  */
#line 523 "micko.y"
    {
      int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR);
      if (idx == NO_INDEX)
        err("%s undeclared", (yyvsp[-2].s));
      gen_shift(idx, (yyvsp[0].i), 1);
      (yyval.i) = idx;
    }
#line 1748 "micko.tab.c"
    break;

  case 70: /* return_statement: _RETURN num_exp _SEMICOLON  */
#line 534 "micko.y"
      {
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 1759 "micko.tab.c"
    break;


#line 1763 "micko.tab.c"

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

#line 542 "micko.y"


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

