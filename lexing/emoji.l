%{
#include <string>
#include "emoji.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng) // save token value in string for bison
#define TOKEN(t) (yylval.token = t)        // save numeric token value in token for bison
extern "C" int yywrap() { return 1; }
%}


%%

[ \t\n]                   ;
"const"                 SAVE_TOKEN; return TCONST;
"if"                    SAVE_TOKEN; return TIF;
"else"                  SAVE_TOKEN; return TELSE;
"for"                   SAVE_TOKEN; return TFOR;
"while"                 SAVE_TOKEN; return TWHILE;
"do"                    SAVE_TOKEN; return TDO;
"int"                   SAVE_TOKEN; return TINTYPE;
"float"                 SAVE_TOKEN; return TFLOATYPE;
"string"                SAVE_TOKEN; return TSTRINGTYPE;
"bool"                  SAVE_TOKEN; return TBOOLTYPE;
"true"                  return TOKEN(TTRUE);
"false"                 return TOKEN(TFALSE);
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+.[0-9]+           SAVE_TOKEN; return TFLOAT;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
"="                     return TOKEN(TEQUAL);
";"                     return TOKEN(TSEP);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"."                     return TOKEN(TDOT);
","                     return TOKEN(TCOMMA);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
.                       printf("Unknown token at %s\n", yylineno); yyterminate();

%%