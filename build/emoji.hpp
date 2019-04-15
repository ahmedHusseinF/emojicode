/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BUILD_EMOJI_HPP_INCLUDED
# define YY_YY_BUILD_EMOJI_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIDENTIFIER = 258,
    TINTEGER = 259,
    TFLOAT = 260,
    TCONST = 261,
    TIF = 262,
    TELSE = 263,
    TFLOATYPE = 264,
    TINTYPE = 265,
    TSTRINGTYPE = 266,
    TFOR = 267,
    TWHILE = 268,
    TDO = 269,
    TBOOLTYPE = 270,
    TCEQ = 271,
    TCNE = 272,
    TCLT = 273,
    TCLE = 274,
    TCGT = 275,
    TCGE = 276,
    TEQUAL = 277,
    TTRUE = 278,
    TFALSE = 279,
    TLPAREN = 280,
    TRPAREN = 281,
    TLBRACE = 282,
    TRBRACE = 283,
    TCOMMA = 284,
    TDOT = 285,
    TSEP = 286,
    TPLUS = 287,
    TMINUS = 288,
    TMUL = 289,
    TDIV = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "parsing/emoji.y" /* yacc.c:1921  */

    std::string *string;
    int token;

#line 99 "build/emoji.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BUILD_EMOJI_HPP_INCLUDED  */
