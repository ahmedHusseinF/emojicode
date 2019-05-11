%{
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

    #include "../parsing/symbol.h"
    using namespace std;

    OPERATION_RETURN insert(int type, char* name, bool isConstant, Values value, Scope *currentTable);
    Scope *lookUp(char *name, Scope *currentTable);
    OPERATION_RETURN update(char *name, int newType, Values value, Scope *currentTable);

    void handle_error(OPERATION_RETURN ret);

    Scope* mainScope = nullptr;
    Scope* currentScope = nullptr;
    // ////////////quadrauples/////////////
    void push(string);
    void gen_assign();
    void code_generate();
    void cond_if();
    void body_if();
    void else_if();
    label_number=0;
    std::string stack_for_quadruples[500];
    int label[50];
    label_top=0;
    int top = 0;
    int temp_reg_count = 0;
    char temp [2]="t";
    /////////////////////

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

var_type: TINTYPE {std::cout<<"var type"<<endl;}
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

var_decl: TINTYPE  {std::cout<<"var decl_tintype" << endl;} TIDENTIFIER {std::cout<<"var decl_Tidentifier"<<endl;}    { Values val; val.Number=0;handle_error(insert(INT, $3, false, val, currentScope)); }
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

assignment: TIDENTIFIER {push($1); std::cout<<"identifier";} TEQUAL {stack_for_quadruples[++top] = "=";} TSTRING {gen_assign();}       
            {
               
            }
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
body_while ()
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
cond_for ()
{
    label_number++;
    label[++label_top] = label_number;
    std::cout<<"Label: "<<label_number<<endl;
}
loop_for ()
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
body_for ()
{
    std::cout<<"goto Label"<<label[label_top-3]<<endl;
    std::cout<<"Label: "<<label[label_top-1]<<endl;
}
end_for ()
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

int main (void) {
	
	mainScope = createMainScope();
	currentScope = mainScope;

	cout << currentScope << endl;

    int ret = yyparse();

    //print_table(mainScope);

	return ret;
}
