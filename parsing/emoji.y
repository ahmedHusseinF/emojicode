%{
    #include <string>
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstdlib>
    #include <ctype.h>
    #include <unordered_map>
    #include <utility>
    #include <typeinfo>
    #include <stack>
    #include <string.h>

    #include "../parsing/symTable.hpp"
    using namespace std;
    // ////////////quadrauples/////////////
    void push(string);
    void gen_assign();
    void code_generate();
    void cond_if();
    void body_if();
    void else_if();
    void start_while ();
    void body_while ();
    void end_while ();
    void cond_for ();
    void loop_for ();
    void body_for ();
    void end_for ();
    void array_assign ();
    void print_array(char*);
    int label_number=0;
    string stack_for_quadruples[500];
    int label[50];
    int label_top=0;
    int top = 0;
    int temp_reg_count = 0;
    char temp [2]="t";
    /////////////////////
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
    | arithmetic TSEP
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
for_loop: TFOR TLPAREN optexpr {cond_for();} TSEP optexpr{loop_for();} TSEP optexpr{body_for();} TRPAREN TLBRACE {end_for();} { depth++;currScope++;} stmts TRBRACE {depth--;currScope++;}
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

expr: TIDENTIFIER  TCEQ TINTEGER {push($1); stack_for_quadruples[++top] = "=="; push(to_string($3)); code_generate();}
    | TIDENTIFIER  TCNE  TINTEGER {push($1); stack_for_quadruples[++top] = "!=";push(to_string($3)); code_generate();}
    | TIDENTIFIER  TCLT  TINTEGER {push($1);stack_for_quadruples[++top] = "<";push(to_string($3));code_generate();}
    | TIDENTIFIER  TCLE TINTEGER  {push($1);stack_for_quadruples[++top] = "<=";push(to_string($3));code_generate();}
    | TIDENTIFIER TCGT TINTEGER  {push($1);stack_for_quadruples[++top] = ">"; push(to_string($3));code_generate();}
    | TIDENTIFIER TCGE TINTEGER  {push($1);stack_for_quadruples[++top] = ">=";push(to_string($3));code_generate();}
    | TIDENTIFIER TAND TINTEGER  {push($1);stack_for_quadruples[++top] = "&&";push(to_string($3));code_generate();}
    | TIDENTIFIER TOR TINTEGER  {push($1);stack_for_quadruples[++top] = "||";push(to_string($3));code_generate();}
    | TIDENTIFIER TCEQ expr  {push($1);stack_for_quadruples[++top] = "==";code_generate();}
    | TIDENTIFIER TCNE expr {push($1);stack_for_quadruples[++top] = "!=";code_generate();}
    | TIDENTIFIER TCLT  expr {push($1);stack_for_quadruples[++top] = "<";code_generate();}
    | TIDENTIFIER TCLE  expr {push($1);stack_for_quadruples[++top] = "<=";code_generate();}
    | TIDENTIFIER TCGT  expr {push($1);stack_for_quadruples[++top] = ">";code_generate();}
    | TIDENTIFIER TCGE  expr {push($1);stack_for_quadruples[++top] = ">=";code_generate();}
    | TIDENTIFIER TAND  expr {push($1);stack_for_quadruples[++top] = "&&";code_generate();}
    | TIDENTIFIER TOR expr {push($1);stack_for_quadruples[++top] = "||";code_generate();}
    | expr TCEQ  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "==";code_generate();}
    | expr TCNE  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "!=";code_generate();}
    | expr TCLT  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "<";code_generate();}
    | expr TCLE  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "<=";code_generate();}
    | expr TCGT  TIDENTIFIER {push($3);stack_for_quadruples[++top] = ">";code_generate();}
    | expr TCGE  TIDENTIFIER {push($3);stack_for_quadruples[++top] = ">=";code_generate();}
    | expr TAND  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "&&";code_generate();}
    | expr TOR  TIDENTIFIER {push($3);stack_for_quadruples[++top] = "||";code_generate();}
    | func_call
    /* | arithmetic */
    | TNOT  TLPAREN expr TRPAREN {stack_for_quadruples[++top] = "!";code_generate();}
    ;

arithmetic: TIDENTIFIER  TPLUS {push($1);stack_for_quadruples[++top] = "+"; code_generate();} arithmetic
          | TIDENTIFIER  TMINUS {push($1);stack_for_quadruples[++top] = "-"; code_generate();} arithmetic
          | TIDENTIFIER  TMUL {push($1);stack_for_quadruples[++top] = "*"; code_generate();} arithmetic
          | TIDENTIFIER  TDIV {push($1);stack_for_quadruples[++top] = "/"; code_generate();} arithmetic
          | TINTEGER  TPLUS {push(to_string($1));stack_for_quadruples[++top] = "+"; code_generate();} arithmetic
          | TINTEGER  TMINUS {push(to_string($1));stack_for_quadruples[++top] = "-"; code_generate();} arithmetic
          | TINTEGER  TMUL {push(to_string($1));stack_for_quadruples[++top] = "*"; code_generate();} arithmetic
          | TINTEGER  TDIV {push(to_string($1));stack_for_quadruples[++top] = "/"; code_generate();} arithmetic
          | TLPAREN arithmetic TRPAREN
          | TMINUS TINTEGER {stack_for_quadruples[++top] = "-";push(to_string($2)); code_generate();} 
          | TMINUS TIDENTIFIER {stack_for_quadruples[++top] = "-"; push($2); code_generate();}
          | TIDENTIFIER TINC { stack_for_quadruples[++top] = "++"; push($1); code_generate();}
          | TIDENTIFIER TDEC {stack_for_quadruples[++top] = "--";push($1); code_generate();}
          | TINTEGER {push(to_string($1));  /* gen_assign(); */ }
          | TIDENTIFIER{push($1);}
          ;

assignment: TIDENTIFIER TEQUAL TSTRING {push($3);  stack_for_quadruples[++top] = "="; push($1);  gen_assign();        Values val; val.str = $3; handle_error(st->modify($1, Types::STRING, val, depth));}
          | TIDENTIFIER TEQUAL expr   { stack_for_quadruples[++top] = "=";push($1); Values val; val.Number = $3 ? 1 : 0; handle_error(st->modify($1, Types::BOOLEAN, val, depth));}
          | TIDENTIFIER TEQUAL arithmetic { stack_for_quadruples[++top] = "="; push($1);Values val; val.Number = $3; handle_error(st->modify($1, Types::INT, val, depth));}
          ;

optexpr: expr
       | assignment
       | %empty
       ;

%%

// ystaaaaaaaaaaaa
// ana zbt el increment b eny bdlt el order bta3 el push w sh8al bs t2rebn mkano 8lt 
// test 7agat tanya w lma t5ls PUSH PUSH PUSH ana da5l anam

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

// for quadruples
void push(string a)
{
    stack_for_quadruples[++top] = a;
}
void gen_assign()
{
    string variable = stack_for_quadruples[top];
    string value = stack_for_quadruples[top-2];
    std::cout<<"MOV "<< variable << " , "<<value<<endl;
    top-=2;
}
void code_generate()
{
    string variable1 = stack_for_quadruples[top-2];
    string operand = stack_for_quadruples[top-1];
    string variable2 = stack_for_quadruples[top];
    temp[1] = (char)(temp_reg_count+'0');
    // cout<<operand<<endl;
    if (operand == "+")
    {
        std::cout<<"ADD"<< " "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        top-=2;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "-")
    {
        std::cout<<"SUB "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "*")
    {
        std::cout<<"MUL "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "/")
    {
        std::cout<<"DIV "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "==" )
    {
        std::cout <<"SEQ "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "!=")
    {
        std::cout <<"SNQ"; print_array(temp); std::cout<< "  ," <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "<")
    {
        std::cout <<"SLT "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "<=")
    {
        std::cout <<"SLQ"; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == ">")
    {
        std::cout <<"GRT "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == ">=")
    {
        std::cout <<"GRQ"; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "&&")
    {
        std::cout <<"AND "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "||")
    {
        std::cout <<"OR "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "!")
    {
        std::cout <<"NOT "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "++")
    {
        std::cout <<"INC "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }
    else if (operand == "--")
    {
        std::cout <<"DEC "; print_array(temp); std::cout<< " , " <<variable1<<" , "<<variable2<<endl;
        stack_for_quadruples[top] = temp;
        temp_reg_count++;
    }

}
void cond_if ()
{
    label_number++;
    temp[1] = (char)(temp_reg_count+'0');
    std::cout<<"NOT"<<" ";print_array(temp);std::cout<<" , "<<stack_for_quadruples[top]<<endl;
    std::cout<<"IF"<<" ";print_array(temp);std::cout<<" "<<"goto Label"<<" "<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number; 
}
void body_if ()
{
    label_number++;
    std::cout<<"goto "<<label_number<<endl;
    std::cout<<"Label "<<label[label_top--]<<":"<<endl;
    label[++label_top] = label_number;
}
void else_if ()
{
    std::cout<<"Label "<<label[label_top--]<<":"<<endl;;
}
void start_while ()
{
    label_number++;
    label[++label_top] = label_number;
    std::cout<<"Label "<<label_number<<":"<<endl;
}
void body_while ()
{
    label_number++;
    temp[1] = (char)(temp_reg_count+'0');
    std::cout<<"NOT ";print_array(temp);std::cout<<" , "<<stack_for_quadruples[top--]<<endl;
    std::cout<<"IF ";print_array(temp);std::cout<<" goto Label"<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number;
}
void end_while ()
{
    int dumy = label[label_top--];
    std::cout<<"goto Label"<<label[label_top--]<<endl;;
    std::cout<<"Label "<<dumy << ":"<<endl;
}
void cond_for ()
{
    label_number++;
    label[++label_top] = label_number;
    std::cout<<"Label "<<label_number<<":"<<endl;
}
void loop_for ()
{
    label_number++;
    temp[1] = (char)(temp_reg_count+'0');
    std::cout<<"NOT ";print_array(temp);std::cout<<" , "<<stack_for_quadruples[top--]<<endl;
    std::cout<<"IF ";print_array(temp);std::cout<<" goto Label"<<label_number<<endl;
    temp_reg_count++;
    label[++label_top] = label_number++;
    std::cout<<"goto Label"<<label_number<<endl;
    label[++label_top] = label_number++;
    std::cout<<"Label"<<label_number<<":"<<endl;
    label[++label_top] = label_number; 
}
void body_for ()
{
    std::cout<<"goto Label"<<label[label_top-3]<<endl;
    std::cout<<"Label "<<label[label_top-1]<<":"<<endl;
}
void end_for ()
{
    std::cout<<"goto Label"<<label[label_top]<<endl;
    std::cout<<"Label "<<label[label_top-2] <<":" <<endl;
    label_top-=4;
}
void array_assign ()
{
    temp[1] = (char)(temp_reg_count+'0');
    std::cout<<"MOV ";print_array(temp);std::cout<<" , "<<stack_for_quadruples[top]<<endl;
    stack_for_quadruples[top] = temp;
    temp_reg_count++;
    temp[1] = (char)(temp_reg_count+'0');
    std::cout<<"MOV ";print_array(temp);std::cout<<" , "<<stack_for_quadruples[top-1]<<"["<<stack_for_quadruples[top]<<"]"<<endl;
    top--;
    stack_for_quadruples[top] = temp;
    temp_reg_count++;
}

int main(void) {
    
    st = new SymbolTable();

    yyparse();

    st->print();

    delete st;

    return 0;
}

void print_array(char* temp)
{
    for(int i=0 ; i < 2 ; i++)
    {   
        cout << temp[i];
    }
}