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

OPERATION_RETURN insert(int type, char* name, bool isConstant, Values value, Scope *currentTable)
{

    // first check for duplication
    unordered_map<char *, Symbol>::iterator itr = currentTable->currentLockup.find(name);

    if (itr == currentTable->currentLockup.end())
    {
        
            Symbol*s = new Symbol();
            s->type = type;
            s->isConst = isConstant;
            s->value = value;
			pair <char*,Symbol> newP;
			cout<<"HI";
			newP=make_pair(name,*s);
			currentTable->currentLockup.insert(newP);
            //currentTable->currentLockup[name]=move(s);

			Scope *Dum =  lookUp(name, currentTable);
			itr = currentTable->currentLockup.find(name);
			cout<<"HI";
			cout<<"name:"<<name<<"value:"<<itr->second.value.Number<<endl;
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

    Scope *currTable = lookUp(name, currentTable);

    if (currTable != NULL)
    {
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
    mainScope->parent = NULL;
    return mainScope;
}



int main (void) {
    mainscope=createMainScope();
    currentcope=mainscope;

    cout<<currentcope;

    int retType = yyparse();
    if (retType == 0){
        std::cout << "Finished all file" << std::endl;
    }else{
        return retType;
    }

    return 0;
}

void yyerror (char *s) { // open file in write mode, and add the error to it!
	extern int yylineno;
	FILE* f;
	f = fopen("lexerOut2.txt","w");
	fprintf(f, "%s at line %d\n", s, yylineno);
	fclose(f);
} 