%{
    #include <string>
    #include <iostream>
    extern int yylex();
    extern int yylineno;
    void yyerror(const char *err) { std::cerr<<"Syntax Error: "<< err << " at line " << yylineno <<std::endl; }
%}

/* Represents the many different ways we can access our data */
%union {
    std::string *string;
    int token;
    float floaty;
}

/* Define our terminal symbols (tokens). This should
   match our emoji.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TSTRING
%token <token> TINTEGER
%token <floaty> TFLOAT


%token <token> TCONST TIF TELSE TFLOATYPE TINTYPE TSTRINGTYPE TFOR TWHILE TBOOLTYPE TPASS TVOID
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TTRUE TFALSE TSWITCH TDEFAULT TCASE TBREAK
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TSEP TCOLON
%token <token> TPLUS TMINUS TMUL TDIV TINC TDEC
%token <token> TAND TOR TNOT

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above.
 */
/* %type ident
%type numeric expr
%type program stmts
%type stmt var_decl const_decl
%type comparison */

/* Operator precedence for mathematical operators */
%left TAND TOR TCEQ TCNE TCLT TCLE TCGT TCGE
%left TPLUS TMINUS
%left TMUL TDIV TINC TDEC

%locations

%start program

%%

program: stmts 
       ;

stmts: stmt 
     | stmts stmt
     ;

stmt: var_decl TSEP
    | const_decl TSEP
    | if_cond
    | if_else_cond
    | while_loop
    | for_loop
    | switch_statemnet
    | func_decl
    | func_call
    | TPASS TSEP
    | error TSEP
    ;

func_decl: var_type TIDENTIFIER TLPAREN args TRPAREN TLBRACE stmts TRBRACE
         ;

args: %empty
    | var_type
    | args TCOMMA var_type
    ;

func_call: TIDENTIFIER TLPAREN call_args TRPAREN TSEP
         ;

call_args: %empty
         | expr
         | call_args TCOMMA expr
         ;

switch_statemnet: TSWITCH TLPAREN TIDENTIFIER TRPAREN TLBRACE case_blocks TRBRACE
                ;

case_blocks: case_stmt
           | case_blocks case_stmt
           ;

case_stmt: TCASE values TCOLON stmts TSEP
         | TCASE values TCOLON TBREAK TSEP
         | TDEFAULT TCOLON stmts TSEP
         | TDEFAULT TCOLON TBREAK TSEP
         | TBREAK TSEP
         ;

/* handle breaks inside loops */
for_loop: TFOR TLPAREN optexpr TSEP optexpr TSEP optexpr TRPAREN TLBRACE stmts TRBRACE
        ;

while_loop: TWHILE TLPAREN expr TRPAREN TLBRACE stmts TRBRACE
          ;

if_cond: TIF TLPAREN expr TRPAREN TLBRACE stmts TRBRACE
       ;

if_else_cond: if_cond TELSE TLBRACE stmts TRBRACE
            ;

const_decl: TCONST var_type TIDENTIFIER
          | TCONST var_type TIDENTIFIER TEQUAL expr
          ;

var_decl: var_type TIDENTIFIER
        | var_type TIDENTIFIER TEQUAL expr
        ;


values: TINTEGER
      | TFLOAT
      | TTRUE
      | TFALSE
      | TSTRING
      ;

expr: expr TCEQ expr
    | expr TCNE expr
    | expr TCLT expr
    | expr TCLE expr
    | expr TCGT expr
    | expr TCGE expr
    | expr TAND expr
    | expr TOR expr
    | func_call
    | TNOT TLPAREN expr TRPAREN
    | assignment
    ;

assignment: TIDENTIFIER TPLUS assignment
          | TIDENTIFIER TMINUS assignment
          | TIDENTIFIER TMUL assignment
          | TIDENTIFIER TDIV assignment
          | values TPLUS assignment
          | values TMINUS assignment
          | values TMUL assignment
          | values TDIV assignment
          | TLPAREN assignment TRPAREN
          | TMINUS values
          | TMINUS TIDENTIFIER
          | TIDENTIFIER TINC
          | TIDENTIFIER TDEC
          | TIDENTIFIER TEQUAL values
          | values
          | TIDENTIFIER
          ;


optexpr: expr
       | %empty
       ;

var_type: TFLOATYPE
        | TINTYPE
        | TSTRINGTYPE
        | TBOOLTYPE
        | TVOID
        ;

%%
