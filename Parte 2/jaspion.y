/********************************************************
 * ex1.ypp 
 ********************************************************/
%{

#include "jaspion.h"
#include "jaspion.c"

void yyerror(char *s);

programa p;
%}

%expect 1

//-- SYMBOL SEMANTIC VALUES -----------------------------
%union {
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
};

%token PTVIRG
%token IF
%token ELSE
%token SOMA
%token SUBT
%token MULT
%token DIVI
%token <Iid> ID
%token <intei> NUM
%token <Iid> STRINGVALUE
%token STRINGE
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

%type <Programa1> Programa
%type <Declaracaolista1> Declaracaolista
%type <Declaracao1> Declaracao
%type <Vardeclaracao1> Vardeclaracao
%type <Tipoespecificador1> Tipoespecificador
%type <Fundeclaracao1> Fundeclaracao
%type <Params1> Params
%type <Paramslista1> Paramslista
%type <Param1> Param
%type <Compostodecl1> Compostodecl
%type <Localdecla1> Localdecla
%type <Statementlista1> Statementlista
%type <Statement1> Statement
%type <Expressaodecl1> Expressaodecl
%type <Selecaodecl1> Selecaodecl
%type <Iteracaodecl1> Iteracaodecl
%type <Retornodecl1> Retornodecl
%type <Expressao1> Expressao
%type <Var1> Var
%type <Simplesexpressao1> Simplesexpressao
%type <Relacional1> Relacional
%type <Somaexpressao1> Somaexpressao
%type <Soma1> Soma
%type <Termo1> Termo
%type <Mult1> Mult
%type <Fator1> Fator
%type <Ativacao1> Ativacao
%type <Args1> Args
%type <Argslista1> Argslista
%type <Vazio1> Vazio

%start Programa;
//-- GRAMMAR RULES ---------------------------------------
%%

Programa : Declaracaolista {p = numero1($1); $$ = p;}
;

Declaracaolista : Declaracaolista Declaracao {$$ = numero2($1,$2);}
			| Declaracao {$$ = numero3($1);}
;

Declaracao : Vardeclaracao	{$$ = numero4($1);}
			| Fundeclaracao {$$ = numero5($1);}
;

Vardeclaracao : Tipoespecificador ID PVIRG	{$$ = numero6($1,$2);}
			| Tipoespecificador ID ABCOLC NUM FECOLC PVIRG {$$ = numero7($1,$2,$4);}
;

Tipoespecificador : INT	{$$ = numero8();}
					| VOID	{$$ = numero9();}
					| STRINGE {$$ = numero60();}
;

Fundeclaracao  : Tipoespecificador ID ABPAREN Params FEPAREN Compostodecl	{$$ = numero10($1,$2,$4,$6);}	
;

Params : Paramslista {$$ = numero11($1);}
			| VOID {$$ = numero12();}	
;

Paramslista: Paramslista VIRG Param	{$$ = numero13($1,$3);}
				| Param	{$$ = numero14($1);}
;

Param: Tipoespecificador ID {$$ = numero15($1,$2);}
				| Tipoespecificador ID ABCOLC FECOLC {$$ = numero16($1,$2);}
;

Compostodecl: ABCHA Localdecla Statementlista FECHA	{$$ = numero17($2,$3);}
;

Localdecla : Localdecla Vardeclaracao {$$ = numero18($1,$2);}
	   | Vazio {$$ = numero19($1);}
;

Statementlista: Statementlista Statement	{$$ = numero20($1,$2);}
			| Vazio	{$$ = numero21($1);}
;

Statement: Expressaodecl	{$$ = numero22($1);}
			| Compostodecl	{$$ = numero23($1);}
			| Selecaodecl	{$$ = numero24($1);}
			| Iteracaodecl	{$$ = numero25($1);}
			| Retornodecl	{$$ = numero26($1);}
;

Expressaodecl: Expressao PVIRG	{$$ = numero27($1);}
		| PVIRG				{$$ = numero28();}
;

Selecaodecl: IF ABPAREN Expressao FEPAREN Statement			{$$ = numero29($3,$5);}
		| IF ABPAREN Expressao FEPAREN Statement ELSE Statement	{$$ = numero30($3,$5,$7);}
;

Iteracaodecl: WHILE ABPAREN Expressao FEPAREN Statement	{$$ = numero31($3,$5);}
;

Retornodecl: RETURN PVIRG	{$$ = numero32();}
			| RETURN Expressao PVIRG	{$$ = numero33($2);}
;

Expressao: Var IGUAL Expressao			{$$ = numero34($1,$3);}
			| Simplesexpressao{$$ = numero35($1);}
;

Var: ID		{$$ = numero36($1);}
	| ID ABCOLC Expressao FECOLC	{$$ = numero37($1,$3);}
;

Simplesexpressao: Somaexpressao Relacional Somaexpressao	{$$ = numero38($1,$2,$3);}
		| Somaexpressao		{$$ = numero39($1);}
;

Relacional: MEI	{$$ = numero40();}
	| ME	{$$ = numero41();}
	| MA	{$$ = numero401();}
	| MAI	{$$ = numero411();}
	| II	{$$ = numero402();}
	| DIF	{$$ = numero412();}
;

Somaexpressao:  Somaexpressao Soma Termo {$$ = numero42($1,$2,$3);}
		| Termo {$$ = numero43($1);}
;

Soma: SOMA {$$ = numero44();}
		| SUBT	{$$ = numero45();}
;

Termo: Termo Mult Fator		{$$ = numero46($1,$2,$3);}
		| Fator	{$$ = numero47($1);}
;

Mult: MULT		{$$ = numero48();}
		| DIVI	{$$ = numero49();}
;

Fator: ABPAREN Expressao FEPAREN	{$$ = numero50($2);}
		| Var	{$$ = numero51($1);}
		| Ativacao	{$$ = numero52($1);}
		| NUM	{$$ = numero53($1);}
		| STRINGVALUE	{$$ = numero59($1);}
;

Ativacao: ID ABPAREN Args FEPAREN	{$$ = numero54($1,$3);}
;


Args: Argslista {$$ = numero55($1);}
		| Vazio	{$$ = numero56($1);}
;

Argslista: Argslista VIRG Expressao {$$ = numero57($1,$3);}
		| Expressao	{$$ = numero58($1);}
;
Vazio: {$$ = Vazio();}
;

%%
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;

void yyerror(char *s){
	fprintf(stderr,"Erro de Sintaxe ¬¬");
	exit(1);
 }


main( int argc, char **argv )
{
 yyparse();
 }
