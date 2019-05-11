%{
    #include <string>
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <unordered_map>
    #include <utility>
    #include <typeinfo>

    #include "../parsing/symTable.hpp"
    using namespace std;

    SymbolTable* st;
    int currScope = 0; // the unique
    int depth = 0;
    void handle_error(Status ret);

    extern int yylex();
    extern int yylineno;
    void yyerror(const char *err) { cerr<<"Syntax Error: "<< err << " at line " << yylineno << endl; }
%}

/* Represents the many different ways we can access our data */
%union {
    char* str;
    int token;
    float floaty;
    bool boolean;
}

/* Define our terminal symbols (tokens). This should
   match our emoji.l lex file. We also define the node type
   they represent.
 */
%token <str> TIDENTIFIER TSTRING
%token <token> TINTEGER
%token <floaty> TFLOAT


%token <token> TCONST TIF TELSE TINTYPE TSTRINGTYPE TFLOATYPE TFOR TWHILE TBOOLTYPE TPASS TVOID
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

%type <boolean> expr
%type <token> arithmetic

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
    | assignment TSEP
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

func_decl: TINTYPE TIDENTIFIER TLPAREN args TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
         | TSTRINGTYPE TIDENTIFIER TLPAREN args TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
         | TBOOLTYPE TIDENTIFIER TLPAREN args TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
         | TVOID TIDENTIFIER TLPAREN args TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
         ;

args: %empty
    | TINTYPE
    | TSTRINGTYPE
    | TBOOLTYPE
    | TVOID
    | args TCOMMA TINTYPE
    | args TCOMMA TSTRINGTYPE
    | args TCOMMA TBOOLTYPE
    | args TCOMMA TVOID
    ;

func_call: TIDENTIFIER TLPAREN call_args TRPAREN TSEP
         ;

call_args: %empty
         | expr
         | call_args TCOMMA expr
         ;

/* var_type: TINTYPE
        | TSTRINGTYPE
        | TBOOLTYPE
        | TVOID
        ; */

switch_statemnet: TSWITCH TLPAREN TIDENTIFIER TRPAREN TLBRACE {depth++;currScope++;} case_blocks TRBRACE {depth--;currScope++;}
                ;

case_blocks: case_stmt
           | case_blocks case_stmt
           ;

case_stmt: TCASE TINTEGER TCOLON stmts TSEP
         | TCASE TINTEGER TCOLON TBREAK TSEP
         | TDEFAULT TCOLON stmts TSEP
         | TDEFAULT TCOLON TBREAK TSEP
         | TBREAK TSEP
         ;

/* handle breaks inside loops */
for_loop: TFOR TLPAREN optexpr TSEP optexpr TSEP optexpr TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
        ;

while_loop: TWHILE TLPAREN expr TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
          ;

if_cond: TIF TLPAREN expr TRPAREN TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
       ;

if_else_cond: if_cond TELSE TLBRACE {depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
            ;

const_decl: TCONST TINTYPE TIDENTIFIER TEQUAL arithmetic        {Values val; val.Number=$5;handle_error(st->insert($3, currScope, depth, Types::INT, val, true));}
          | TCONST TSTRINGTYPE TIDENTIFIER TEQUAL TSTRING       {Values val; val.str=$5;handle_error(st->insert($3, currScope, depth, Types::STRING, val, true));}
          | TCONST TBOOLTYPE TIDENTIFIER TEQUAL expr            {Values val; val.Number=$5;handle_error(st->insert($3, currScope, depth, Types::BOOLEAN, val, true));}
          ;

var_decl: TINTYPE TIDENTIFIER                                   {Values val; val.Number=0;handle_error(st->insert($2, currScope, depth, Types::INT, val, false));}
        | TSTRINGTYPE TIDENTIFIER                               {Values val; val.str=strdup("");handle_error(st->insert($2, currScope, depth, Types::STRING, val, false));}
        | TBOOLTYPE TIDENTIFIER                                 {Values val; val.Number=0;handle_error(st->insert($2, currScope, depth, Types::BOOLEAN, val, false));}
        ;

/* values: TINTEGER
      | TTRUE
      | TFALSE
      | TSTRING
      ; */

expr: TIDENTIFIER TCEQ TINTEGER
    | TIDENTIFIER TCNE TINTEGER
    | TIDENTIFIER TCLT TINTEGER
    | TIDENTIFIER TCLE TINTEGER
    | TIDENTIFIER TCGT TINTEGER
    | TIDENTIFIER TCGE TINTEGER
    | TIDENTIFIER TAND TINTEGER
    | TIDENTIFIER TOR TINTEGER
    | TIDENTIFIER TCEQ expr
    | TIDENTIFIER TCNE expr
    | TIDENTIFIER TCLT expr
    | TIDENTIFIER TCLE expr
    | TIDENTIFIER TCGT expr
    | TIDENTIFIER TCGE expr
    | TIDENTIFIER TAND expr
    | TIDENTIFIER TOR expr
    | expr TCEQ TIDENTIFIER
    | expr TCNE TIDENTIFIER
    | expr TCLT TIDENTIFIER
    | expr TCLE TIDENTIFIER
    | expr TCGT TIDENTIFIER
    | expr TCGE TIDENTIFIER
    | expr TAND TIDENTIFIER
    | expr TOR TIDENTIFIER
    | func_call
    /* | arithmetic */
    | TNOT TLPAREN expr TRPAREN
    ;

arithmetic: TIDENTIFIER TPLUS arithmetic
          | TIDENTIFIER TMINUS arithmetic
          | TIDENTIFIER TMUL arithmetic
          | TIDENTIFIER TDIV arithmetic
          | TINTEGER TPLUS arithmetic
          | TINTEGER TMINUS arithmetic
          | TINTEGER TMUL arithmetic
          | TINTEGER TDIV arithmetic
          | TLPAREN arithmetic TRPAREN
          | TMINUS TINTEGER
          | TMINUS TIDENTIFIER
          | TIDENTIFIER TINC
          | TIDENTIFIER TDEC
          | TINTEGER
          | TIDENTIFIER
          ;

assignment: TIDENTIFIER TEQUAL TSTRING          {Values val; val.str = $3; handle_error(st->modify($1, Types::STRING, val, depth));}
          | TIDENTIFIER TEQUAL expr             {Values val; val.Number = $3 ? 1 : 0; handle_error(st->modify($1, Types::BOOLEAN, val, depth));}
          | TIDENTIFIER TEQUAL arithmetic       {cout<<"in int ass";Values val; val.Number = $3; handle_error(st->modify($1, Types::INT, val, depth));}
          ;

optexpr: expr
       | %empty
       ;

%%

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

int main(void) {

    st = new SymbolTable();

    yyparse();

    st->print();

    delete st;

    return 0;
}