%{
    #include <string>
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <unordered_map>
    #include <utility>
    #include <typeinfo>

    #include "../parsing/symbol.h"
    using namespace std;

    OPERATION_RETURN insert(int type, char* name, bool isConstant, Values value, Scope *currentTable);
    Scope *lookUp(char *name, Scope *currentTable);
    OPERATION_RETURN update(char *name, int newType, Values value, Scope *currentTable);

    void handle_error(OPERATION_RETURN ret);

    Scope* mainScope = nullptr;
    Scope* currentScope = nullptr;


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

var_type: TINTYPE
        | TSTRINGTYPE
        | TBOOLTYPE
        | TVOID
        ;

switch_statemnet: TSWITCH TLPAREN TIDENTIFIER TRPAREN TLBRACE case_blocks TRBRACE
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
for_loop: TFOR TLPAREN optexpr TSEP optexpr TSEP optexpr TRPAREN TLBRACE stmts TRBRACE
        ;

while_loop: TWHILE TLPAREN expr TRPAREN TLBRACE stmts TRBRACE
          ;

if_cond: TIF TLPAREN expr TRPAREN TLBRACE stmts TRBRACE
       ;

if_else_cond: if_cond TELSE TLBRACE stmts TRBRACE
            ;

const_decl: TCONST TINTYPE TIDENTIFIER
          | TCONST TSTRINGTYPE TIDENTIFIER
          | TCONST TBOOLTYPE TIDENTIFIER
          ;

var_decl: TINTYPE TIDENTIFIER           {Values val; val.Number=0;handle_error(insert(INT, $2, false, val, currentScope));}
        | TSTRINGTYPE TIDENTIFIER       {Values val; val.str="";handle_error(insert(STRING, $2, false, val, currentScope));}
        | TBOOLTYPE TIDENTIFIER         {Values val; val.Number=0;handle_error(insert(BOOLEAN, $2, false, val, currentScope));}
        ;


/* values: TINTEGER
      | TTRUE
      | TFALSE
      | TSTRING
      ; */

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

assignment: TIDENTIFIER TEQUAL TSTRING          {Values val; val.str = $3; update($1, STRING, val, currentScope);}
          | TIDENTIFIER TEQUAL expr             {Values val; val.Number = $3 ? 1 : 0; update($1, BOOLEAN, val, currentScope);}
          | TIDENTIFIER TEQUAL arithmetic       {Values val; val.Number = $3; update($1, INT, val, currentScope);}
          ;


optexpr: expr
       | %empty
       ;

%%

OPERATION_RETURN insert(int type, char* name, bool isConstant, Values value, Scope *currentTable)
{
    cout << name<<endl;
    // first check for duplication
    unordered_map<char *, Symbol>::iterator itr = currentTable->currentLockup.find(name);

    if (itr == currentTable->currentLockup.end())
    {
        
            Symbol*s = new Symbol();
            s->type = type;
            s->isConst = isConstant;
            s->value = value;
            pair <char*,Symbol> newP;
            // cout<<"HI";
            newP=make_pair(name,*s);
            currentTable->currentLockup.insert(newP);
            //currentTable->currentLockup[name]=move(s);

			Scope *Dum =  lookUp(name, currentTable);
			itr = currentTable->currentLockup.find(name);
			// cout<<"HI";
			cout<<"name:"<<name<<" | value:"<<itr->second.value.Number<<endl;
            return SUCCESSFUL_INSERTION;
        
    }
	//TEST ONLY
	
    return DUPLICATE_INSERTION;
}

Scope *lookUp(char *name, Scope *currentTable)
{

    // base case: not found in alllllll scopes: 2o7a
    if (currentTable == NULL)
        return NULL;

    if (currentTable->currentLockup.find(name) == currentTable->currentLockup.end())
    {
        return lookUp(name, currentTable->above);
    }
    return currentTable;
}

OPERATION_RETURN update(char *name, int newType, Values value, Scope *currentTable)
{
    cout<<name<<endl;
    Scope *currTable = lookUp(name, currentTable);

    if (currTable != NULL)
    {
        cout << "going to update"<<endl;
        unordered_map<char *, Symbol>::iterator itr = currentTable->currentLockup.find(name); //madaam mesh b null yeb2a wesh la2ah
        // check semantics errors:
        if (itr->second.isConst)
        {
            return SEMANTIC_ERROR_ATTEMPT_CHANGING_CONSTANT;
        }
        if (newType == itr->second.type)
        {
            itr->second.value = value;
            return SUCCESSFUL_UPDATE;
        }
        return SEMANTIC_ERROR_TYPE_INCOMPATIBLE;
    }
    return SYMBOL_NOT_FOUND;
}

Scope *createMainScope()
{
    Scope *mainScope = new Scope();
    mainScope->above = nullptr;
    return mainScope;
}

void print_table(Scope* scope) {
    for(const auto& p : scope->currentLockup) {
      cout << p.first;
    }
}

void handle_error(OPERATION_RETURN ret) {
    switch(ret){
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
    }
}

int main (void) {
	
	mainScope = createMainScope();
	currentScope = mainScope;

	cout << currentScope << endl;

    int ret = yyparse();

    //print_table(mainScope);

	return ret;
}
