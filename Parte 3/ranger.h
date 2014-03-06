/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PTVIRG = 258,
     IF = 259,
     ELSE = 260,
     SOMA = 261,
     SUBT = 262,
     MULT = 263,
     DIVI = 264,
     ID = 265,
     NUM = 266,
     STRINGVALUE = 267,
     STRINGE = 268,
     ABPAREN = 269,
     FEPAREN = 270,
     ABCOLC = 271,
     FECOLC = 272,
     ABCHA = 273,
     FECHA = 274,
     VIRG = 275,
     PVIRG = 276,
     INT = 277,
     VOID = 278,
     WHILE = 279,
     RETURN = 280,
     IGUAL = 281,
     MEI = 282,
     ME = 283,
     MA = 284,
     MAI = 285,
     II = 286,
     DIF = 287
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 17 "jaspion.y"

  int intei; 
  char c;
  float real;
  string Iid;
  string s;
programa Programa1;
declaracaolista Declaracaolista1;
declaracao Declaracao1;
vardeclaracao Vardeclaracao1;
tipoespecificador Tipoespecificador1;
fundeclaracao Fundeclaracao1;
params Params1;
paramslista Paramslista1;
param Param1;
compostodecl Compostodecl1;
localdecla Localdecla1;
statementlista Statementlista1;
statement Statement1;
expressaodecl Expressaodecl1;
selecaodecl Selecaodecl1;
iteracaodecl Iteracaodecl1;
retornodecl Retornodecl1;
expressao Expressao1;
var Var1;
simplesexpressao Simplesexpressao1;
relacional Relacional1;
somaexpressao Somaexpressao1;
soma Soma1;
termo Termo1;
mult Mult1;
fator Fator1;
ativacao Ativacao1;
args Args1;
argslista Argslista1;
vazio Vazio1;


/* Line 2068 of yacc.c  */
#line 122 "ranger.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


