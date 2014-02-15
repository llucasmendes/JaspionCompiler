/********************************************************
 * ex1.ypp 
 ********************************************************/
%{

#include "jaspion.h"

programa p;
/*
//-- Lexer prototype required by bison, aka getNextToken()
int yylex(); 
int yyerror(const char *p) { cerr << "Error!" << endl; }
*/
//declara??o do yytext
extern char *yytext;
extern int yylex();
extern int yyparse();
 
void yyerror(char *s);
%}

%expect 1

//-- SYMBOL SEMANTIC VALUES -----------------------------
%union {
  int intei; 
  char c;
  float real;
  string s;
programa Programa;
declaracaolista Declaracaolista;
declaracao Declaracao;
vardeclaracao Vardeclaracao;
tipoespecificador Tipoespecificador;
fundeclaracao Fundeclaracao;
params Params;
paramlista Paramlista;
param Param;
compostodecl Compostodecl;
localdecla Localdecla;
statementlista Statementlista;
statement Statement;
espressaodecl Espressaodecl;
selecaodecl Selecaodecl;
iteracaodecl Iteracaodecl;
retornodecl Retornodecl;
expressao Expressao;
var Var;
simplesexpressao Simplesexpressao;
relacional Relacional;
somaexpressao Somaexpressao;
soma Soma;
termo Termo;
mult Mult;
fator Fator;
ativacao Ativacao;
args Args;
argslista Argslista;
};

%token PTVIRG
%token IF
%token ELSE
%token SOMA
%token SUBT
%token MULT
%token DIVI
%token ID
%token NUM
%token STRING
%token ABPAREN
%token FEPAREN
%token ABCOLC
%token FECOLC
%token ABCHA
%token FECHA
%token VIRG
%token PVIRG
%token INT
%token VOID
%token WHILE
%token RETURN
%token IGUAL
%token MEI
%token ME
%token MA
%token MAI
%token II
%token DIF

%type <programa> Programa Declaracaolista
%type <declaracaolista> Declaracaolista Declaracaolista Declaracao Declaracao
%type <declaracao> Declaracao Vardeclaracao Fundeclaracao
%type <vardeclaracao> Vardeclaracao Tipoespecificador ID PVIRG Tipoespecificador ID ABCOLC NUM FECOLC PVIRG
%type <tipoespecificador> Tipoespecificador INT VOID
%type <fundeclaracao> Fundeclaracao Tipoespecificador ID ABPAREN Params FEPAREN Compostodecl
%type <params> Params Paramslista VOID
%type <paramlista> Paramlista Paramslista VIRG Param Param
%type <param> Param Tipoespecificador ID Tipoespecificador ID ABCOLC FECOLC
%type <compostodecl> Compostodecl ABCHA Localdecla Statementlista FECHA
%type <localdecla> Localdecla Localdecla Vardecla Vazio
%type <statementlista> Statementlista Statementlista Statement Vazio
%type <statement> Statement Expressaodecl Compostodecl Selecaodecl Iteracaodecl Retornodecl
%type <espressaodecl> Espressaodecl Expressao PVIRG PVIRG
%type <selecaodecl> Selecaodecl IF ABPAREN Expressao FEPAREN Statement IF ABPAREN Expressao FEPAREN Statement ELSE Statement
%type <iteracaodecl> Iteracaodecl WHILE ABPAREN Expressao FEPAREN Statement
%type <retornodecl> Retornodecl RETURN PVIRG RETURN Expressao PVIRG
%type <expressao> Expressao Var IGUAL Expressao Simplesexpressao
%type <var> Var ID ID ABCOLC Expressao FECOLC
%type <simplesexpressao> Simplesexpressao Somaexpressao Relacional Somaexpressao Somaexpressao
%type <relacional> Relacional MEI ME MA MAI II DIF
%type <somaexpressao> Somaexpressao Somaexpressao Soma Termo Termo
%type <soma> Soma SOMA SUBT
%type <termo> Termo Termo Mult Fator Fator
%type <mult> Mult MULT DIVI
%type <fator> Fator ABPAREN Expressao FEPAREN Var Ativacao NUM
%type <ativacao> Ativacao ID ABPAREN Args FEPAREN
%type <args> Args Argslista Vazio
%type <argslista> Argslista Argslista VIRG Expressao Expressao
%type <vazio> Vazio

%start programa;
//-- GRAMMAR RULES ---------------------------------------
%%

Programa : Declaracaolista {p = Numero1($1); p = $$;}
;

Declaracao : Declaracaolista Declaracao {$$ = Numero2($1,$2);}
			| Declaracao {$$ = Numero3($1);}
;

Declaracao : Vardeclaracao	{$$ = Numero4($1);}
;			| Fundeclaracao {$$ = Numero5($1);}

Vardeclaracao : Tipoespecificador ID PVIRG	{$$ = Numero6($1);}
			| Tipoespecificador ID ABCOLC NUM FECOLC PVIRG {$$ = Numero7($1);}
;

Tipoespecificador : INT	{$$ = Numero8();}
					| VOID	{$$ = Numero9();}
;

Fundeclaracao  : Tipoespecificador ID ABPAREN Params FEPAREN Compostodecl	{$$ = Numero10($1,$4,$6);}	
;

Params : Paramslista {$$ = Numero11($1);}
			| VOID {$$ = Numero12();}	
;

Paramlista: Paramslista VIRG Param	{$$ = Numero13($1,$3);}
				| Param	{$$ = Numero14($1,$2);}
;

Param: Tipoespecificador ID {$$ = Numero15($1);}
				| Tipoespecificador ID ABCOLC FECOLC {$$ = Numero16($1);}
;

Compostodecl: ABCHA Localdecla Statementlista FECHA	{$$ = Numero17($2,$3);}
;

Localdecla : Localdecla Vardecla	{$$ = Numero18($1,$2);}
	   | Vazio {$$ = Numero19($1);}
;

Statementlista: Statementlista Statement	{$$ = Numero20($1,$2);}
			| Vazio	{$$ = Numero21($1);}
;

Statement: Expressaodecl	{$$ = Numero22($1);}
			| Compostodecl	{$$ = Numero23($1);}
			| Selecaodecl	{$$ = Numero24($1);}
			| Iteracaodecl	{$$ = Numero25($1);}
			| Retornodecl	{$$ = Numero26($1);}
;

Espressaodecl: Expressao PVIRG	{$$ = Numero27($1);}
		| PVIRG				{$$ = Numero28();}
;

Selecaodecl: IF ABPAREN Expressao FEPAREN Statement			{$$ = Numero29($3,$5);}
		| IF ABPAREN Expressao FEPAREN Statement ELSE Statement	{$$ = Numero30($3,$5,$7);}
;

Iteracaodecl: WHILE ABPAREN Expressao FEPAREN Statement	{$$ = Numero31($3,$5);}
;

Retornodecl: RETURN PVIRG			{$$ = Numero32($1);}
			| RETURN Expressao PVIRG	{$$ = Numero33($2);}
;

Expressao: Var IGUAL Expressao			{$$ = Numero34($1,$3);}
			| Simplesexpressao{$$ = Numero35($1);}
;

Var: ID		{$$ = Numero36();}
	| ID ABCOLC Expressao FECOLC	{$$ = Numero37($3);}
;

Simplesexpressao: Somaexpressao Relacional Somaexpressao	{$$ = Numero38($1,$2,$3);}
		| Somaexpressao		{$$ = Numero39($1);}
;

Relacional: MEI	{$$ = Numero40();}
	| ME	{$$ = Numero41();}
	| MA	{$$ = Numero401();}
	| MAI	{$$ = Numero411();}
	| II	{$$ = Numero402();}
	| DIF	{$$ = Numero412();}
;

Somaexpressao:  Somaexpressao Soma Termo {$$ = Numero42($1,$2,$3);}
		| Termo {$$ = Numero43($1);}
;

Soma: SOMA {$$ = Numero44();}
		| SUBT	{$$ = Numero45();}
;

Termo: Termo Mult Fator		{$$ = Numero46($1,$2,$3);}
		| Fator	{$$ = Numero47($1);}
;

Mult: MULT		{$$ = Numero48();}
		| DIVI	{$$ = Numero49();}
;

Fator: ABPAREN Expressao FEPAREN	{$$ = Numero50($2);}
		| Var	{$$ = Numero51($1);}
		| Ativacao	{$$ = Numero52($1);}
		| NUM	{$$ = Numero53();}
;

Ativacao: ID ABPAREN Args FEPAREN	{$$ = Numero54($3);}
;


Args: Argslista {$$ = Numero55($1);}
		| Vazio	{$$ = Numero56($1);}
;

Argslista: Argslista VIRG Expressao {$$ = Numero57($1,$3);}
		| Expressao	{$$ = Numero58($1);}
;
Vazio: {$$ = A_Vazio();}
;

%%
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;

main( int argc, char **argv )
{
 yyparse();
 }
