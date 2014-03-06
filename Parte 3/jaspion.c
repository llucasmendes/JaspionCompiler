#include <stdlib.h>
#include "jaspion.h"

/********************************************************************************/
/*				Implementação da Tabela de Símbolos				  */
/********************************************************************************/

#define SIZE 127

typedef struct S_binder_ *S_binder;
struct S_binder_ {S_symbol sym; void *value; S_binder next; S_binder prevtop;};
struct S_table_ {S_binder table[SIZE]; S_binder top;};

S_binder Binder(S_symbol sym, S_symbol value, S_binder next, S_binder prevtop){
	S_binder b = malloc(sizeof(*b));
	b->sym = sym; b->value=value; b->next=next; b->prevtop = prevtop; 
	return b;
}

S_symbol mksymbol(string name, S_symbol next){
	S_symbol s=malloc(sizeof(*s));
	s->name = name; s->next=next;
	return s;
}

unsigned int hash(char *s0){
	unsigned int h=0;
	char *s;
	for(s=s0; *s; s++)
		h = h*65599 + *s;
	return h;
}

static S_symbol stringTable[SIZE];

S_symbol S_Symbol(string name) {
	int index = hash(name) % SIZE;
	S_symbol syms = stringTable[index];
//if(syms)printf("debug syms: %x", syms);else printf("debug syms: NULL");
//if(syms)printf(" syms->name: %s", syms->name);else printf(" syms->name: NULL");
//printf(" name: %s\n", name);
	S_symbol sym;
	for(sym=syms; sym; sym=sym->next)
		if(0==strcmp(sym->name, name))return sym;
	sym = mksymbol(name, syms);
	stringTable[index]=sym;
	return sym;
}

string S_name(S_symbol sym){
	return sym->name;
}

S_table S_empty(){
	S_table t = malloc(sizeof(*t));
	int i; t->top = NULL;
	for (i = 0; i < SIZE; i++)
		t->table[i] = NULL;
	return t;
}
void S_push(S_table t, S_symbol sym, void *value){
	int index;
	index = ((unsigned)sym) % SIZE;
	S_binder binder = Binder(sym, value,t->table[index], t->top);
//printf("debug sym->name: %s sym: %x index: %d\n", S_name(sym), sym, index);
	t->table[index] = binder;
	t->top = binder;
}
void *S_look(S_table t, S_symbol sym){
	int index;
	S_binder b;
	index=((unsigned)sym) % SIZE;
	for(b=t->table[index]; b; b=b->next)
		if (b->sym==sym) return b->value;
	return NULL;
}

static struct S_symbol_ marksym = {"<mark>",NULL};

void S_beginScope(S_table t){
	S_push(t, &marksym, NULL);
}

void S_endScope(S_table t) {
	S_symbol sym; S_binder b; int index;
	do {		
		b = t->top;
		sym = b->sym;
		index = ((unsigned)sym) % SIZE;
		t->table[index] = b->next;
		t->top = b->prevtop;
		free(b);
	}while(sym != &marksym);
}

int S_nivel(S_table t, S_symbol s){
	S_symbol atual = s;
	S_binder b; int index;
	int cont = -1;
	index = ((unsigned)s) %SIZE;
	for(b=t->table[index]; b && b->sym != atual; b=b->next);
	while(b != NULL){	
		if(atual == &marksym) cont++;		
		b = b->prevtop;		
		if(b!=NULL)atual = b->sym;
	}
	return cont;
}

bool S_defined(S_table t, S_symbol s){
	S_binder b = t->top;	
	S_symbol atual = (t->top)->sym;
	while(atual!=s && atual!=NULL && atual!=&marksym){
		b = b->prevtop;
		atual = b->sym;
	}
	if(atual == s)return TRUE;
	else return FALSE;
}

void S_print(S_table t){
	S_binder b = t->top;
	while(b != NULL){	
		printf("%s->", S_name(b->sym));		
		b = b->prevtop;
	}
	printf("\n");
}

void S_dump(S_table t, void (*show)(S_symbol sym, void *value)) {
	void *s = t->top;
	int index = ((unsigned)s) % SIZE;
	S_binder b = t->table[index];
	if (b==NULL) return;
	t->table[index]=b->next;
	t->top=b->prevtop;
	show(b->sym,b->value);
	S_dump(t,show);
	t->top=s;
	t->table[index]=b;
}


programa numero1(declaracaolista Declaracaolista){
	programa p = malloc(sizeof(*p));
	p->u.numero1.Declaracaolista = Declaracaolista;
	p->kind = Numero1;
	return p;
}

declaracaolista numero2(declaracaolista Declaracaolista, declaracao Declaracao){
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
declaracao numero4(vardeclaracao Vardeclaracao){
	declaracao d = malloc(sizeof(*d));
	d->u.numero4.Vardeclaracao = Vardeclaracao;
	d->kind = Numero4;
	return d;
}
//
declaracao numero5(fundeclaracao Fundeclaracao){
	declaracao d = malloc(sizeof(*d));
	d->u.numero5.Fundeclaracao = Fundeclaracao;
	d->kind = Numero5;
	return d;
}
//

vardeclaracao numero6(tipoespecificador Tipoespecificador, string ID){
	vardeclaracao d = malloc(sizeof(*d));
	d->u.numero6.Tipoespecificador = Tipoespecificador;
	d->u.numero6.ID = ID;
	d->kind = Numero6;
	return d;
}

//
vardeclaracao numero7(tipoespecificador Tipoespecificador, string ID, 
 int NUM){
	vardeclaracao d = malloc(sizeof(*d));
	d->u.numero7.Tipoespecificador = Tipoespecificador;
	d->u.numero7.ID = ID;
	d->u.numero7.NUM = NUM;
	d->kind = Numero7;
	return d;
}

/*
tipoespecificador numero8(){
	tipoespecificador t = malloc(sizeof(*t));
	t->kind = Numero8;
	return t;
}
//
tipoespecificador numero9(){
	tipoespecificador t = malloc(sizeof(*t));
	t->kind = Numero9;
	return t;
}

tipoespecificador numero60(){
	tipoespecificador p = malloc(sizeof(*p));
	p->kind = Numero60;
	return p;
}


fundeclaracao numero10(tipoespecificador Tipoespecificador, string ID, params Params, compostodecl Compostodecl){
	fundeclaracao t = malloc(sizeof(*t));
	t->u.numero10.Tipoespecificador = Tipoespecificador;
	t->u.numero10.ID = ID;
	t->u.numero10.Compostodecl= Compostodecl;
	t->u.numero10.Params = Params;
	t->kind = Numero10;
	return t;
}
*/
params numero11(paramslista Paramslista){
	params t = malloc(sizeof(*t));
	t->u.numero11.Paramslista = Paramslista;
	t->kind = Numero11;
	return t;
}
//
params numero12(){
	params t = malloc(sizeof(*t));
	t->kind = Numero12;
	return t;
}

//
paramslista numero13(paramslista Paramslista, param Param){
	paramslista l = malloc(sizeof(*l));
	l->u.numero13.Paramslista = Paramslista;
	l->u.numero13.Param = Param;
	l->kind = Numero14;
	return l;
}
//
paramslista numero14(param Param){
	paramslista l = malloc(sizeof(*l));
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
param numero16(tipoespecificador Tipoespecificador, string ID){
	param p = malloc(sizeof(*p));
	p->u.numero16.Tipoespecificador = Tipoespecificador;
	p->u.numero16.ID = ID;
	p->kind = Numero16;
	return p;
}

//
compostodecl numero17(localdecla Localdecla, 
	statementlista Statementlista){
	compostodecl p = malloc(sizeof(*p));
	p->u.numero17.Localdecla = Localdecla;
	p->u.numero17.Statementlista = Statementlista;
	p->kind = Numero17;
	return p;
}
//
localdecla numero18(localdecla Localdecla, vardeclaracao Vardeclaracao){
	localdecla p = malloc(sizeof(*p));
	p->u.numero18.Localdecla = Localdecla;
	p->u.numero18.Vardeclaracao = Vardeclaracao;
	p->kind = Numero18;
	return p;
}

//
localdecla numero19(vazio Vazio){
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
statement numero22(expressaodecl Expressaodecl){
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
expressaodecl numero27(expressao Expressao){	
	expressaodecl c = malloc(sizeof(*c));
	c->u.numero27.Expressao = Expressao;
	c->kind = Numero27;
	return c;
}
//
expressaodecl numero28(){
	expressaodecl c = malloc(sizeof(*c));
	c->kind = Numero28;
	return c;
}
//
selecaodecl numero29( expressao Expressao, statement Statement){
	selecaodecl c = malloc(sizeof(*c));
	c->u.numero29.Expressao = Expressao;
	c->u.numero29.Statement = Statement;
	c->kind = Numero29;
	return c;
}
//
selecaodecl numero30(expressao Expressao, statement Statement, statement Statement2){
	selecaodecl c = malloc(sizeof(*c));

	c->u.numero30.Expressao = Expressao;
	c->u.numero30.Statement = Statement;

	c->u.numero30.Statement2 = Statement2;
	c->kind = Numero30;
	return c;
}
//
iteracaodecl numero31( expressao Expressao, statement Statement){
	iteracaodecl c = malloc(sizeof(*c));

	c->u.numero31.Expressao = Expressao;
	c->u.numero31.Statement = Statement;
	c->kind = Numero31;
	return c;
}

//
retornodecl numero32(){
	retornodecl d = malloc(sizeof(*d));

	d->kind = Numero32;
	return d;
}
//
retornodecl numero33( expressao Expressao){
	retornodecl d = malloc(sizeof(*d));

	d->u.numero33.Expressao = Expressao;
	d->kind = Numero33;
	return d;
}

//
expressao numero34(var Var, expressao Expressao){
	expressao c = malloc(sizeof(*c));
	c->u.numero34.Var = Var;
	c->u.numero34.Expressao = Expressao;
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
var numero36(string ID){
	var l = malloc(sizeof(*l));
	l->u.numero36.ID = ID;
	l->kind = Numero36;
	return l;
}

//
var numero37(string ID, expressao Expressao){
	var l = malloc(sizeof(*l));
	l->u.numero37.ID = ID;
	l->u.numero37.Expressao = Expressao;
	l->kind = Numero37;
	return l;
}
//
simplesexpressao numero38(somaexpressao Somaexpressao, relacional Relacional, 
	somaexpressao Somaexpressao2){
	simplesexpressao l = malloc(sizeof(*l));
	l->u.numero38.Somaexpressao = Somaexpressao;
	l->u.numero38.Relacional = Relacional;
	l->u.numero38.Somaexpressao2 = Somaexpressao2;
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
relacional numero40(){
	relacional v = malloc(sizeof(*v));

	v->kind = Numero40;
	return v;
}

//relacional numero41(string ME);
relacional numero41(){
	relacional e = malloc(sizeof(*e));

	e->kind = Numero41;
	return e;
}

//relacional numero401(string MA);
relacional numero401(){
	relacional v = malloc(sizeof(*v));

	v->kind = Numero401;
	return v;
}

//relacional numero411(string MAI);
relacional numero411(){
	relacional v = malloc(sizeof(*v));

	v->kind = Numero411;
	return v;
}

//relacional numero402(string II);
relacional numero402(){
	relacional v = malloc(sizeof(*v));

	v->kind = Numero402;
	return v;
}

//relacional numero412(string DIF);
relacional numero412(){
	relacional v = malloc(sizeof(*v));

	v->kind = Numero412;
	return v;
}

//
somaexpressao numero42(somaexpressao Somaexpressao, soma Somar, termo Termo){
	somaexpressao e = malloc(sizeof(*e));
	e->u.numero42.Somaexpressao = Somaexpressao;
	e->u.numero42.Somar = Somar;
	e->u.numero42.Termo = Termo;
	e->kind = Numero42;
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
soma numero44(){
	soma e = malloc(sizeof(*e));
	e->kind = Numero44;
	return e;
}

//
soma numero45(){
	soma p = malloc(sizeof(*p));
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
mult numero48(){
	mult p = malloc(sizeof(*p));

	p->kind = Numero48;
	return p;
}

//
mult numero49(){
	mult p = malloc(sizeof(*p));

	p->kind = Numero49;
	return p;
}
//
fator numero50(expressao Expressao){
	fator p = malloc(sizeof(*p));
	p->u.numero50.Expressao = Expressao;
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
fator numero52(ativacao Ativacao){
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

fator numero59(string stringvalue){
	fator p = malloc(sizeof(*p));
	p->u.numero59.stringvalue = stringvalue;
	p->kind = Numero59;
	return p;
}

//
ativacao numero54(string ID, args Args){
	ativacao p = malloc(sizeof(*p));
	p->u.numero54.ID = ID;
	p->u.numero54.Args = Args;
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
args numero56(vazio Vazio){
	args p = malloc(sizeof(*p));
	p->u.numero56.Vazio = Vazio;
	p->kind = Numero56;
	return p;
}

//
argslista numero57(argslista Argslista, expressao Expressao){
	argslista p = malloc(sizeof(*p));
	p->u.numero57.Argslista = Argslista;
	p->u.numero57.Expressao = Expressao;
	p->kind = Numero57;
	return p;
}
//
argslista numero58(expressao Expressao){
	argslista p = malloc(sizeof(*p));
	p->u.numero58.Expressao = Expressao;
	p->kind = Numero58;
	return p;
}

vazio Vazio(){
	vazio v = malloc(sizeof(*v));
	return v;
}

