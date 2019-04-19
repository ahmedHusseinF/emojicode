%{
#include <string>
#include "emoji.hpp"
#define TOKEN(t) (yylval.token = t)        // save numeric token value in token for bison
extern "C" int yywrap() { return 1; }
%}

%option yylineno


%%

[ \t\n]                   ;
"const"                   return TOKEN(TCONST);
"pass"                    return TOKEN(TPASS);
"if"                      return TOKEN(TIF);
"else"                    return TOKEN(TELSE);
"for"                     return TOKEN(TFOR);
"while"                   return TOKEN(TWHILE);
"do"                      return TOKEN(TDO);
"switch"                  return TOKEN(TSWITCH);
"break"                   return TOKEN(TBREAK);
"case"                    return TOKEN(TCASE);
"default"                 return TOKEN(TDEFAULT);
"int"                     return TOKEN(TINTYPE);
"float"                   return TOKEN(TFLOATYPE);
"string"                  return TOKEN(TSTRINGTYPE);
"bool"                    return TOKEN(TBOOLTYPE);
"true"                    return TOKEN(TTRUE);
"false"                   return TOKEN(TFALSE);
\".\"                     {yylval.string = new std::string(yytext, yyleng); return TSTRING;}
[a-zA-Z_$][a-zA-Z0-9_$]*  {yylval.string = new std::string(yytext, yyleng); return TIDENTIFIER;}
[0-9]+.[0-9]+             {yylval.floaty = atof(yytext); return TFLOAT;}
[0-9]+                    {yylval.token = atof(yytext); return TINTEGER;}
"=="                      return TOKEN(TCEQ);
"&&"                      return TOKEN(TAND);
"||"                      return TOKEN(TOR);
"!"                       return TOKEN(TNOT);
"="                       return TOKEN(TEQUAL);
":"                       return TOKEN(TCOLON);
";"                       return TOKEN(TSEP);
"!="                      return TOKEN(TCNE);
"<"                       return TOKEN(TCLT);
"<="                      return TOKEN(TCLE);
">"                       return TOKEN(TCGT);
">="                      return TOKEN(TCGE);
"("                       return TOKEN(TLPAREN);
")"                       return TOKEN(TRPAREN);
"{"                       return TOKEN(TLBRACE);
"}"                       return TOKEN(TRBRACE);
"."                       return TOKEN(TDOT);
","                       return TOKEN(TCOMMA);
"++"                      return TOKEN(TINC);
"--"                      return TOKEN(TDEC);
"+"                       return TOKEN(TPLUS);
"-"                       return TOKEN(TMINUS);
"*"                       return TOKEN(TMUL);
"/"                       return TOKEN(TDIV);
.                         printf("Unknown token at %s\n", yylineno); yyterminate();

%%