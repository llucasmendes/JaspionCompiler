#include <stdlib.h>
#include "jaspion.h"

programa numero1(declaracaolista Declaracaolista){
	programa p = malloc(sizeof(*p));
	p->u.numero1.Declaraçãolista = Declaracaolista;
	p->kind = Numero1;
	return p;
}

declaracaolista numero2(declaracaolista Declaracaolista, declaracao Declaracao);{
	declaracaolista p = malloc(sizeof(*p));
	p->u.numero2.Declaracaolista = Declaracaolista;
	p->u.numero2.Declaracao = Declaracao;
	p->kind = Numero2;
	return p;
}

declaracaolista numero3(declaracao Declaracao){
	declaracaolista d = malloc(sizeof(*d));
	d->u.numero3.Declaracao = Declaracao;
	d->kind = Numero3;
	return d;
}
//
declaracao numero4(vardeclaracao Vardeclaracao);{
	declaracao d = malloc(sizeof(*d));
	d->u.numero4.Vardeclaracao = Vardeclaracao;
	d->kind = Numero4;
	return d;
}
//
declaracao numero5(fundeclaracao Vundeclaracao){
	declaracao d = malloc(sizeof(*d));
	d->u.numero5.Fundeclaracao = Fundeclaracao;
	d->kind = Numero5;
	return d;
}
//
vardeclaracao numero6(tipoespecificador Tipoespecificador, string ID, char PVIRG){
	vardeclaracao d = malloc(sizeof(*d));
	d->u.numero6.Tipoespecificador = Tipoespecificador;
	d->u.numero6.Tipoespecificador = ID;
	d->u.numero6.Tipoespecificador = PVIRG;
	d->kind = Numero6;
	return d;
}

//
vardeclaracao numero7(tipoespecificador Tipoespecificador, string ID, char ABCOLC,
 int NUM, char, char FECOLC, char PVIRG){
	vardeclaracao d = malloc(sizeof(*d));
	d->u.numero7.Tipoespecificador = Tipoespecificador;
	d->u.numero7.ID = ID;
	d->u.numero7.ABCOLC = ABCOLC;
	d->u.numero7.NUM = NUM;
	d->u.numero7.FECOLC = FECOLC;
	d->u.numero7.PVIRG = PVIRG;
	d->kind = Numero7;
	return d;
}

//
tipoespecificador numero8(string INT);{
	tipoespecificador t = malloc(sizeof(*t));
	t->u.numero8.INT = INT;
	t->kind = Numero8;
	return t;
}
//
tipoespecificador numero9(string VOID){
	tipoespecificador t = malloc(sizeof(*t));
	t->u.numero9.VOID = VOID;
	t->kind = Numero9;
	return t;
}

//
fundeclaracao numero10(tipoespecificador Tipoespecificador, string ID,
	char ABPAREN, params Params, char FEPAREN, compostodecl Compostodecl){
	fundeclaracao t = malloc(sizeof(*t));
	t->u.numero10.Tipoespecificador = Tipoespecificador;
	t->u.numero10.ID = ID;
	t->u.numero10.ABPAREN = ABPAREN;
	t->u.numero10.FEPAREN = FEPAREN;
	t->u.numero10.Compostodecl= Compostodecl;
	t->u.numero10.Params = Params;
	t->kind = Numero10;
	return t;
}
//
params numero11(paramslista Paramslista){
	params t = malloc(sizeof(*t));
	t->u.numero11.Paramslista = Paramslista;
	t->kind = Numero11;
	return t;
}
//
params numero12(string VOID){
	params t = malloc(sizeof(*t));
	t->u.numero12.VOID = VOID;
	t->kind = Numero12;
	return t;
}

//
paramlista numero13(paramslista Paramslista, char VIRG, param Param);{
	paramlista l = malloc(sizeof(*l));
	l->u.numero13.Paramslista = Paramslista;
	l->u.numero13.VIRG = VIRG;
	l->u.numero13.Param = Param;
	l->kind = Numero14;
	return l;
}
//
paramlista numero14(param Param){
	paramlista l = malloc(sizeof(*l));
	l->u.numero14.Param = Param;
	l->kind = Numero14;
	return l;
}

//
param numero15(tipoespecificador Tipoespecificador, string ID){
	param p = malloc(sizeof(*p));
	p->u.numero15.Tipoespecificador = Tipoespecificador;
	p->u.numero15.ID = ID;
	p->kind = Numero15;
	return p;
}
//
param numero16(tipoespecificador Tipoespecificador, string ID, char ABCOLC, char FECOLC){
	param p = malloc(sizeof(*p));
	p->u.numero16.Tipoespecificador = Tipoespecificador;
	p->u.numero16.ID = ID;
	p->u.numero16.ABCOLC = ABCOLC;
	p->u.numero16.FECOLC = FECOLC;
	p->kind = Numero16;
	return p;
}

//
compostodecl numero17(char ABCHA, localdecla Localdecla, 
	statementlista Statementlista, char FECHA);{
	compostodecl p = malloc(sizeof(*p));
	p->u.numero17.ABCHA = ABCHA;
	p->u.numero17.Localdecla = Localdecla;
	p->u.numero17.Statementlista = Statementlista;
	p->u.numero17.FECHA = FECHA;
	p->kind = Numero17;
	return p;
}
//
localdecla numero18(localdecla Localdecla, vardecla Vardecla){
	localdecla p = malloc(sizeof(*p));
	p->u.numero18.Localdecla = Localdecla;
	p->u.numero18.Vardecla = Vardecla;
	p->kind = Numero18;
	return p;
}

//
localdecla numero19(vazio Vazio);{
	localdecla p = malloc(sizeof(*p));
	p->u.numero19.Vazio = Vazio;
	p->kind = Numero19;
	return p;
}

//
statementlista numero20(statementlista Statementlista, statement Statement){
	statementlista b = malloc(sizeof(*b));
	b->u.numero20.Statementlista = Statementlista;
	b->u.numero20.Statement = Statement;
	b->kind = Numero20;
	return b;
}
//
statementlista numero21(vazio Vazio){
	statementlista b = malloc(sizeof(*b));
	b->u.numero21.Vazio = Vazio;
	b->kind = Numero21;
	return b;
}

//
statement numero22(expressaodecl Expressaodecl)){
	statement c = malloc(sizeof(*c));
	c->u.numero22.Expressaodecl = Expressaodecl;
	c->kind = Numero22;
	return c;
}
//
statement numero23(compostodecl Compostodecl){
	statement c = malloc(sizeof(*c));
	c->u.numero23.Compostodecl = Compostodecl;
	c->kind = Numero23;
	return c;
}

//
statement numero24(selecaodecl Selecaodecl){
	statement d = malloc(sizeof(*d));
	d->u.numero24.Selecaodecl = Selecaodecl;
	d->kind = Numero24;
	return d;
}
//
statement numero25(iteracaodecl Iteracaodecl){
	statement d = malloc(sizeof(*d));
	d->u.numero25.Iteracaodecl = Iteracaodecl;
	d->kind = Numero25;
	return d;
}

//
statement numero26(retornodecl Retornodecl){
	statement c = malloc(sizeof(*c));
	c->u.numero26.Retornodecl = Retornodecl;
	c->kind = Numero26;
	return c;
}
//
espressaodecl numero27(expressao Expressao, char PVIRG){	
	espressaodecl c = malloc(sizeof(*c));
	c->u.numero27.Expressao = Expressao;
	c->u.numero27.PVIRG = PVIRG;
	c->kind = Numero27;
	return c;
}
//
espressaodecl numero28(char PVIRG){
	espressaodecl c = malloc(sizeof(*c));
	c->u.numero28.VIRG = VIRG;
	c->kind = Numero28;
	return c;
}
//
selecaodecl numero29(string IF, char ABPAREN, expressao Expressao, 
	char FEPAREN, statement Statement){
	selecaodecl c = malloc(sizeof(*c));
	c->u.numero29.IF = IF;
	c->u.numero29.ABPAREN = ABPAREN;
	c->u.numero29.Expressao = Expressao;
	c->u.numero29.FEPAREN = FEPAREN;
	c->u.numero29.Statement = Statement;
	c->kind = Numero29;
	return c;
}
//
selecaodecl numero30(string IF, char ABPAREN, expressao Expressao, 
	char FEPAREN, statement Statement, string ELSE, statement Statement2){
	selecaodecl c = malloc(sizeof(*c));
	c->u.numero30.IF = IF;
	c->u.numero30.ABPAREN = ABPAREN;
	c->u.numero30.Expressao = Expressao;
	c->u.numero30.FEPAREN = FEPAREN;
	c->u.numero30.Statement = Statement;
	c->u.numero30.ELSE = ELSE;
	c->u.numero30.Statement2 = Statement2;
	c->kind = Numero30;
	return c;
}
//
iteracaodecl numero31(string WHILE, char ABPAREN, 
	expressao Expressao, string FEPAREN, statement Statement){
	iteracaodecl c = malloc(sizeof(*c));
	c->u.numero31.WHILE = WHILE;
	c->u.numero31.ABPAREN = ABPAREN;
	c->u.numero31.Expressao = Expressao;
	c->u.numero31.FEPAREN = FEPAREN;
	c->u.numero31.Statement = Statement;
	c->kind = Numero31;
	return c;
}

//
retornodecl numero32(string RETURN, char PVIRG){
	retornodecl d = malloc(sizeof(*d));
	d->u.numero32.RETURN = RETURN;
	d->u.numero32.PVIRG = PVIRG;
	d->kind = Numero32;
	return d;
}
//
retornodecl numero33(string RETURN, expressao Expressao, char PVIRG){
	retornodecl d = malloc(sizeof(*d));
	d->u.numero33.RETURN = RETURN;
	d->u.numero33.Expressao = Expressao;
	d->u.numero33.PVIRG = PVIRG;
	d->kind = Numero33;
	return d;
}

//
expressao numero34(var Var, char IGUAL, expressao Expressao){
	expressao c = malloc(sizeof(*c));
	c->u.numero34. = Var;
	c->u.numero34. = IGUAL;
	c->u.numero34. = Expressao;
	c->kind = Numero34;
	return c;
}

//
expressao numero35(simplesexpressao Simplesexpressao){
	expressao l = malloc(sizeof(*l));
	l->u.numero35.Simplesexpressao = Simplesexpressao;
	l->kind = Numero35;
	return l;
}
//
var numero36(String ID){
	var l = malloc(sizeof(*l));
	l->u.numero36.ID = ID;
	l->kind = Numero36;
	return l;
}

//
var numero37(string ID, char ABCOLC, expressao Expressao, char FECOLC){
	var l = malloc(sizeof(*l));
	l->u.numero37.ID = ID;
	l->unumero37.ABCOLC = ABCOLC;
	l->u.numero37.Expressao = Expressao;
	l->u.numero37.FECOLC = FECOLC;
	l->kind = Numero37;
	return l;
}
//
simplesexpressao numero38(somaexpressao Somaexpressao, relacional Relacional, 
	somaexpressao Somaexpressao){
	simplesexpressao l = malloc(sizeof(*l));
	l->u.numero38.Somaexpressao = Somaexpressao;
	l->u.numero38.Relacional = Relacional;
	l->u.numero38.Somaexpressao = Somaexpressao;
	l->kind = Numero38;
	return l;
}

//
simplesexpressao numero39(somaexpressao Somaexpressao){
	simplesexpressao v = malloc(sizeof(*v));
	v->u.numero39.Somaexpressao = Somaexpressao;
	v->kind = Numero39;
	return v;
}
//relacional numero40(string MEI);
relacional numero40(string MEI){
	relacional v = malloc(sizeof(*v));
	v->u.numero40.MEI = MEI;
	v->kind = Numero40;
	return v;
}

//relacional numero41(string ME);
relacional numero41(termo ME){
	relacional e = malloc(sizeof(*e));
	e->u.numero41.ME = ME;
	e->kind = Numero41;
	return e;
}

//relacional numero401(string MA);
relacional numero401(string MA){
	relacional v = malloc(sizeof(*v));
	v->u.numero401.MA = MA;
	v->kind = Numero401;
	return v;
}

//relacional numero411(string MAI);
relacional numero411(string MAI){
	relacional v = malloc(sizeof(*v));
	v->u.numero411.MAI = MAI;
	v->kind = Numero411;
	return v;
}

//relacional numero402(string II);
relacional numero402(string II){
	relacional v = malloc(sizeof(*v));
	v->u.numero402.II = II;
	v->kind = Numero402;
	return v;
}

//relacional numero412(string DIF);
relacional numero412(string DIF){
	relacional v = malloc(sizeof(*v));
	v->u.numero412.DIF = DIF;
	v->kind = Numero412;
	return v;
}

//
somaexpressao numero42(somaexpressao Somaexpressao, soma Somar, termo Termo){
	somaexpressao e = malloc(sizeof(*e));
	e->u.numero42.Somaexpressao = Somaexpressao;
	e->u.numero42.Somar = Somar;
	e->u.numero42.Termo = Termo;
	e->kind = numero42;
	return e;
}

//
somaexpressao numero43(termo Termo){
	somaexpressao e = malloc(sizeof(*e));
	e->u.numero43.Termo = Termo;
	e->kind = Numero43;
	return e;
}
//
soma numero44(char SOMA){
	soma e = malloc(sizeof(*e));
	e->u.numero44.SOMA = SOMA;
	e->kind = Numero44;
	return e;
}

//
soma numero45(char SUBT){
	soma p = malloc(sizeof(*p));
	p->u.numero45.SUBT = SUBT;
	p->kind = Numero45;
	return p;
}
//
termo numero46(termo Termo, mult Mult, fator Fator){
	termo p = malloc(sizeof(*p));
	p->u.numero46.Termo = Termo;
	p->u.numero46.Mult = Mult;
	p->u.numero46.Fator = Fator;
	p->kind = Numero46;
	return p;
}

//
termo numero47(fator Fator){
	termo p = malloc(sizeof(*p));
	p->u.numero47.Fator = Fator;
	p->kind = Numero47;
	return p;
}
//
mult numero48(string MULT);{
	mult p = malloc(sizeof(*p));
	p->u.numero48.MULT = MULT;
	p->kind = Numero48;
	return p;
}

//
mult numero49(string DIVI){
	mult p = malloc(sizeof(*p));
	p->u.numero49.DIVI = DIVI;
	p->kind = Numero49;
	return p;
}
//
fator numero50(char ABPAREN, expressao Expressao, char FEPAREN){
	fator p = malloc(sizeof(*p));
	p->u.numero50.ABPAREN = ABPAREN;
	p->u.numero50.Expressao = Expressao;
	p->u.numero50.FEPAREN = FEPAREN;
	p->kind = Numero50;
	return p;
}
//
fator numero51(var Var){
	fator p = malloc(sizeof(*p));
	p->u.numero51.Var = Var;
	p->kind = Numero51;
	return p;
}
//
fator numero52(ativacao Ativacao)){
	fator p = malloc(sizeof(*p));
	p->u.numero52.Ativacao = Ativacao;
	p->kind = Numero52;
	return p;
}
//
fator numero53(int NUM){
	fator p = malloc(sizeof(*p));
	p->u.numero53.NUM = NUM;
	p->kind = Numero53;
	return p;
}

//
ativacao numero54(string ID, char ABPAREN, args Args, char FEPAREN){
	ativacao p = malloc(sizeof(*p));
	p->u.numero54.ID = ID;
	p->u.numero54.ABPAREN = ABPAREN;
	p->u.numero54.Args = Args;
	p->u.numero54.FEPAREN = FEPAREN;
	p->kind = Numero54;
	return p;
}
//
args numero55(argslista Argslista){
	args p = malloc(sizeof(*p));
	p->u.numero55.Argslista = Argslista;
	p->kind = Numero55;
	return p;
}
//
args numero56(vazio Vazio);{
	args p = malloc(sizeof(*p));
	p->u.numero56.Vazio = Vazio;
	p->kind = Numero56;
	return p;
}

//
argslista numero57(argslista Argslista, char VIRG, expressao Expressao){
	argslista p = malloc(sizeof(*p));
	p->u.numero57.Argslista = Argslista;
	p->u.numero57.VIRG = VIRG;
	p->u.numero57.Expressao = Expressao;
	p->kind = Numero57;
	return p;
}
//
argslista numero58(expressao Expressao);{
	argslista p = malloc(sizeof(*p));
	p->u.numero58.Expressao = Expressao;
	p->kind = Numero58;
	return p;
}

A_vazio A_Vazio(){
	A_vazio v = malloc(sizeof(*v));
	return v;
}
