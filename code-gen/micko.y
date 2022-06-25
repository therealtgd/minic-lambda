%{
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
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP
%token _LAMBDA
%token _COLON
%token _COMMA
%token _RARROW
%token _TEST

%type <i> num_exp exp literal lambda_parameter
%type <i> function_call argument rel_exp if_part lambda_argument lambda_call 

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH \t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

lambda_statement
  : _LAMBDA _ID 
    {
      lambda_counter++;
      lambda_idx = lookup_symbol($2, LFUN);
      if (lambda_idx == NO_INDEX) {
        int* param_types = (int*) malloc(sizeof(int)*128);
        lambda_idx = insert_symbol($2, LFUN, NO_ATR, NO_ATR, NO_ATR);
        lambda_parameter_map[lambda_idx] = param_types;
        code("\n\t\tJMP \t@main_body_%d", lambda_main);
      }
      else
        err("Redefinition of lambda function '%s'", $2);
    }
  _ASSIGN lambda_exp
   {
     set_type(lambda_idx, lambda_type);
     printf("%d  ", lambda_main);
     code("\n@lambda_%s_%d_exit:", $2, lambda_main);
     code("\n\t\tMOV \t%%14, %%15");
     code("\n\t\tPOP \t%%14");
     code("\n\t\tRET");
     code("\n@main_body_%d:", lambda_main);
     lambda_main++;
   }

lambda_exp
  : _LAMBDA _LPAREN lambda_parameters
    {
      code("\n@lambda_%s_%d:", get_name(lambda_idx), lambda_main);
      code("\n\t\tPUSH \t%%14");
      code("\n\t\tMOV \t%%15,%%14");
      code("\n\t\tJMP \t@lambda_%s_%d_body", get_name(lambda_idx), lambda_main);
      code("\n@lambda_%s_%d_body:", get_name(lambda_idx), lambda_main);
    }
   _RPAREN _COLON num_exp _SEMICOLON
    {
      gen_mov($7, FUN_REG);
      code("\n\t\tJMP \t@lambda_%s_%d_exit", get_name(lambda_idx), lambda_main);
    }
  ;

lambda_parameters
  : lambda_parameter
  | lambda_parameters _COMMA lambda_parameter
  ;

lambda_parameter
  : _TYPE _ID
    {
      if (lookup_symbol($2, PAR) != NO_INDEX) {
        err("Redefinition of parameter %s ", $2);
      }
      lambda_type = $1;
      insert_symbol($2, PAR, $1, 1, NO_ATR);
      int num_params = get_atr1(lambda_idx);
      int* param_types = lambda_parameter_map[lambda_idx];
      if (num_params > 0) {
        if (param_types[num_params - 1] != $1) {
          err("Incompatible parameters in lambda function");
        }
      }
      param_types[num_params] = $1;
      num_params += 1;
      set_atr1(lambda_idx, num_params);
    }
  ;  

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, $1);
      }
  ;

body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE _ID _SEMICOLON
      {
        if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
           insert_symbol($2, VAR, $1, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
      }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | lambda_statement
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else {
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment '%s'", get_type($3));

        }
        gen_mov($3, idx);
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        int t1 = get_type($1);    
        code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  ;

exp
  : literal

  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }

  | lambda_call
    {
      $$ = take_reg();
      gen_mov(FUN_REG, $$);
    }

  | function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
  
  
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

lambda_call
  : _ID _RARROW
    {
      lcall_idx = lookup_symbol($1, LFUN);
      if (lcall_idx == NO_INDEX)
        err("'%s' is not a lambda function", $1);
      int* arg_list = (int*) malloc(sizeof(int)*128);
      lambda_argument_map[lcall_idx] = arg_list;
    }
   _LPAREN lambda_arguments _RPAREN
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
      $$ = FUN_REG;
    }
  ;

lambda_arguments
  : lambda_argument
  | lambda_arguments _COMMA lambda_argument
  ;

lambda_argument
  : num_exp
    {
      if (lambda_parameter_map[lcall_idx][lambda_arg_counter] != get_type($1))
        err("incompatible type for argument in '%s'", get_name(lcall_idx));
      int* arg_list = lambda_argument_map[lcall_idx];
      arg_list[lambda_arg_counter] = $1;
      lambda_arg_counter += 1;
    }

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    { 
      if(get_atr2(fcall_idx) != get_type($1))
        err("incompatible type for argument");
      free_if_reg($1);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($1);
      $$ = 1;
    }
  ;

if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
  ;

%%

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

