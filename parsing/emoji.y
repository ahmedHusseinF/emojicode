%{
    #include <string>
    #include <iostream>
    extern int yylex();
    int currScope = 0;
    void yyerror(const char *err) { std::cerr<<"Parser Error: "<< err <<std::endl; }
%}

/* Represents the many different ways we can access our data */
%union {
    std::string *string;
    int token;
}

/* Define our terminal symbols (tokens). This should
   match our emoji.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TFLOAT TCONST TIF TELSE TFLOATYPE TINTYPE TSTRINGTYPE TFOR TWHILE TDO TBOOLTYPE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TTRUE TFALSE
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TSEP
%token <token> TPLUS TMINUS TMUL TDIV

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above.
 */

%type <string> ident
%type numeric expr
%type program stmts
%type stmt var_decl const_decl
%type comparison

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmts { ; }
        ;
        
stmts : stmt { ; }
      | stmts stmt TSEP { ; }
      ;

stmt : var_decl TSEP
     | const_decl TSEP
     | if_cond
     | if_else_cond
     | while_loop
     | for_loop
     | %empty
     ;

for_loop :
           TFOR TLPAREN optexpr TSEP optexpr TSEP optexpr TRPAREN TLBRACE stmts TRBRACE   { ; }
         ;

while_loop : TWHILE TLPAREN expr TRPAREN TLBRACE stmts TRBRACE   { ; }
           ;

if_cond : TIF TLPAREN expr TRPAREN TLBRACE stmts TRBRACE  { ; }
        ;

if_else_cond : if_cond TELSE TLBRACE stmts TRBRACE        { ; }
             ;

const_decl : TCONST var_type ident { ; }
           | TCONST var_type ident TEQUAL expr { ; }
           ;

var_decl : var_type ident { ; }
         | var_type ident TEQUAL expr { ; }
         ;

ident : TIDENTIFIER { ; }
      ;

numeric : TINTEGER { ; }
        | TFLOAT { ; }
        | TTRUE   { ; }
        | TFALSE   { ; }
        ;
    
expr : ident TEQUAL expr { ; }
     | ident { ; }
     | numeric  { ; }
     | expr comparison expr { ; }
     | TLPAREN expr TRPAREN { ; }
     ;

optexpr : expr
        | %empty
        ;

var_type : TFLOATYPE        { ; }
         | TINTYPE          { ; }
         | TSTRINGTYPE      { ; }
         | TBOOLTYPE        { ; }
         ;

comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE
           | TPLUS | TMINUS | TMUL | TDIV
           ;

%%
