#ifndef JASPION_H
#define JASPION_H

/*Gramática Abstrata:

programa : declaracaolista
;

declaracaolista : declaracaolista declaracao | declaracao
;

declaracao : vardeclaracao | fundeclaracao
;

vardeclaracao : tipoespecificador ID PVIRG | tipoespecificador ID ABCOLC NUM FECOLC PVIRG	
;

tipoespecificador : INT | VOID 
;

fundeclaracao : tipoespecificador ID ABPAREN params FEPAREN compostodecl
;

params : paramslista | VOID
;

paramlista : paramslista VIRG param | param				
;

param : tipoespecificador ID | tipoespecificador ID ABCOLC FECOLC
;

compostodecl : ABCHA localdecla statementlista FECHA
;

localdecla : localdecla vardecla | vazio
;

statementlista : statementlista statement | vazio
;

statement : expressaodecl | compostodecl |selecaodecl | iteracaodecl | retornodecl
;

espressaodecl : expressao PVIRG | PVIRG
;

selecaodecl : IF ABPAREN expressao FEPAREN statement | IF ABPAREN expressao FEPAREN statement ELSE statement 
;

iteracaodecl : WHILE ABPAREN expressao FEPAREN statement
;

retornodecl : RETURN PVIRG | RETURN expressao PVIRG
;

expressao : var IGUAL expressao | simplesexpressao
;

var : ID | ID ABCOLC expressao FECOLC
;

simplesexpressao : somaexpressao relacional somaexpressao | somaexpressao
;

relacional : MEI|ME|MA|MAI|II|DIF
;

somaexpressao : somaexpressao soma termo | termo
;

soma : SOMA | SUBT
;

termo : termo mult fator | fator
;

mult : MULT | DIVI
;

fator : ABPAREN expressao FEPAREN | var | ativacao | NUM
;

ativacao : ID ABPAREN args FEPAREN
;

args : argslista | vazio
;

argslista : argslista VIRG expressao | expressao
;

sstringvalue : stringvalue
;

*/

typedef char* string;

typedef struct programa *programa;
typedef struct declaracaolista *declaracaolista;
typedef struct declaracao *declaracao;
typedef struct vardeclaracao *vardeclaracao;
typedef struct tipoespecificador *tipoespecificador;
typedef struct fundeclaracao *fundeclaracao;
typedef struct params *params;
typedef struct paramslista *paramslista;
typedef struct param *param;
typedef struct compostodecl *compostodecl;
typedef struct localdecla *localdecla;
typedef struct statementlista *statementlista;
typedef struct statement *statement;
typedef struct expressaodecl *expressaodecl;
typedef struct selecaodecl *selecaodecl;
typedef struct iteracaodecl *iteracaodecl;
typedef struct retornodecl *retornodecl;
typedef struct expressao *expressao;
typedef struct var *var;
typedef struct simplesexpressao *simplesexpressao;
typedef struct relacional *relacional;
typedef struct somaexpressao *somaexpressao;
typedef struct soma *soma;
typedef struct termo *termo;
typedef struct mult *mult;
typedef struct fator *fator;
typedef struct ativacao *ativacao;
typedef struct args *args;
typedef struct argslista *argslista;
typedef struct vazio *vazio;

//programa : declaracaolista
struct programa {enum{Numero1} kind;
					union{	struct {declaracaolista Declaracaolista;} numero1;
					} u;
};
programa numero1(declaracaolista Declaracaolista);

//declaracaolista : declaracaolista declaracao | declaracao
struct declaracaolista {	enum {Numero2, Numero3} kind;
						union{	struct {declaracaolista Declaracaolista; declaracao Declaracao;} numero2;
								struct {declaracao Declaracao;} numero3;
					} u;
};
declaracaolista numero2(declaracaolista Declaracaolista, declaracao Declaracao);
declaracaolista numero3(declaracao Declaracao);

//declaracao : vardeclaracao | fundeclaracao
struct declaracao {	enum{Numero4, Numero5} kind;
						union{
							struct{ vardeclaracao Vardeclaracao;} numero4;
							struct{ fundeclaracao Fundeclaracao;} numero5;
					} u;
};
declaracao numero4(vardeclaracao Vardeclaracao);
declaracao numero5(fundeclaracao Fundeclaracao);

//vardeclaracao : tipoespecificador ID PVIRG | tipoespecificador ID ABCOLC NUM FECOLC PVIRG	
struct vardeclaracao {	enum{Numero6, Numero7} kind;
					union{
						struct {tipoespecificador Tipoespecificador; string ID;  } numero6;
						struct { tipoespecificador Tipoespecificador; string ID; int NUM;} numero7;
					} u;
};
vardeclaracao numero6(tipoespecificador Tipoespecificador, string ID);
vardeclaracao numero7(tipoespecificador Tipoespecificador, string ID, int NUM);

//tipoespecificador : INT | VOID 
struct tipoespecificador {	enum{Numero8, Numero9, Numero60} kind;
						union{
							struct{} numero8;
							struct{} numero9;
							struct{} numero60;
						} u;
};
tipoespecificador numero8();
tipoespecificador numero9();
tipoespecificador numero60();

//fundeclaracao : tipoespecificador ID ABPAREN params FEPAREN compostodecl
struct fundeclaracao{	enum{Numero10} kind;
						union{
							struct{tipoespecificador Tipoespecificador; string ID;  params Params;  compostodecl Compostodecl;} numero10;
						} u;
};
fundeclaracao numero10(tipoespecificador Tipoespecificador, string ID,  params Params,  compostodecl Compostodecl);

//params : paramslista | VOID
struct params{	enum{Numero11,Numero12} kind;
						union{
							struct{paramslista Paramslista;} numero11;
							struct{} numero12;
						} u;
};
params numero11(paramslista Paramslista);
params numero12();

//paramlista : paramslista VIRG param | param
struct paramslista{ 	enum{Numero13, Numero14} kind;
							union{
								struct{paramslista Paramslista;  param Param;} numero13;
								struct{param Param;} numero14;
							} u;						
};
paramslista numero13(paramslista Paramslista,  param Param);
paramslista numero14(param Param);

//param : tipoespecificador ID | tipoespecificador ID ABCOLC FECOLC
struct param{ 	enum{Numero15,Numero16} kind;
					union{
						struct{tipoespecificador Tipoespecificador; string ID;} numero15;
						struct{tipoespecificador Tipoespecificador; string ID; } numero16;
					} u;
};
param numero15(tipoespecificador Tipoespecificador, string ID);
param numero16(tipoespecificador Tipoespecificador, string ID);

//compostodecl : ABCHA localdecla statementlista FECHA
struct compostodecl{enum{Numero17} kind;
					union{
						struct{ localdecla Localdecla; statementlista Statementlista; } numero17;
					} u;
};
compostodecl numero17( localdecla Localdecla, statementlista Statementlista);

//localdecla : localdecla vardeclaracao | vazio
struct localdecla{	enum{Numero18,Numero19} kind;
						union{
							struct{localdecla Localdecla; vardeclaracao Vardeclaracao;} numero18;
							struct{vazio Vazio;} numero19;
						} u;
};
localdecla numero18(localdecla Localdecla, vardeclaracao Vardeclaracao);
localdecla numero19(vazio Vazio);

//statementlista : statementlista statement | vazio
struct statementlista{	enum{Numero20,Numero21} kind;
					union{
						struct{statementlista Statementlista; statement Statement;}numero20;
						struct{vazio Vazio;}numero21;
					} u;
};
statementlista numero20(statementlista Statementlista, statement Statement);
statementlista numero21(vazio Vazio);

//statement : expressaodecl | compostodecl | selecaodecl | iteracaodecl | retornodecl
struct statement{	enum{Numero22,Numero23,Numero24,Numero25,Numero26} kind;
					union{
						struct{expressaodecl Expressaodecl;}numero22;
						struct{compostodecl Compostodecl;}numero23;
						struct{selecaodecl Selecaodecl;}numero24;
						struct{iteracaodecl Iteracaodecl;}numero25;
						struct{retornodecl Retornodecl;}numero26;
					} u;
};
statement numero22(expressaodecl Expressaodecl);
statement numero23(compostodecl Compostodecl);
statement numero24(selecaodecl Selecaodecl);
statement numero25(iteracaodecl Iteracaodecl);
statement numero26(retornodecl Retornodecl);

//expressaodecl : expressao PVIRG | PVIRG
struct expressaodecl{	enum{Numero27,Numero28} kind;
					union{
						struct{expressao Expressao;}numero27;
						struct{}numero28;
					} u;
};
expressaodecl numero27(expressao Expressao);
expressaodecl numero28();

//selecaodecl : IF ABPAREN expressao FEPAREN statement | IF ABPAREN expressao FEPAREN statement ELSE statement 
struct selecaodecl{	enum{Numero29,Numero30} kind;
					union{
						struct{ expressao Expressao;  statement Statement;}numero29;
						struct{ expressao Expressao;  statement Statement; statement Statement2;}numero30;
					} u;
};
selecaodecl numero29(  expressao Expressao, statement Statement);
selecaodecl numero30(  expressao Expressao, statement Statement, statement Statement2);

//iteracaodecl : WHILE ABPAREN expressao FEPAREN statement
struct iteracaodecl{enum{Numero31} kind;
					union{
						struct{ expressao Expressao; statement Statement;}numero31;
					} u;
};
iteracaodecl numero31(  expressao Expressao,  statement Statement);

//retornodecl : RETURN PVIRG | RETURN expressao PVIRG
struct retornodecl{	enum{Numero32,Numero33} kind;
				union{
					struct{ }numero32;
					struct{ expressao Expressao; }numero33;
				} u;
};
retornodecl numero32( );
retornodecl numero33( expressao Expressao);

//expressao : var IGUAL expressao | simplesexpressao
struct expressao{enum{Numero34,Numero35} kind;
				union{
					struct{var Var; expressao Expressao;}numero34;
					struct{simplesexpressao Simplesexpressao;}numero35;
				} u;
};
expressao numero34(var Var, expressao Expressao);
expressao numero35(simplesexpressao Simplesexpressao);

//var : ID | ID ABCOLC expressao FECOLC
struct var{	enum{Numero36,Numero37} kind;
				union{
					struct{string ID;}numero36; 
					struct{string ID; expressao Expressao;}numero37;
				} u;
};
var numero36(string ID);
var numero37(string ID,  expressao Expressao);

//simplesexpressao : somaexpressao relacional somaexpressao | somaexpressao
struct simplesexpressao{enum{Numero38,Numero39} kind;
				union{
					struct{somaexpressao Somaexpressao; relacional Relacional; somaexpressao Somaexpressao2;}numero38;
					struct{somaexpressao Somaexpressao;}numero39;
				} u;
};
simplesexpressao numero38(somaexpressao Somaexpressao, relacional Relacional, somaexpressao Somaexpressao2);
simplesexpressao numero39(somaexpressao Somaexpressao);

//relacional : MEI|ME|MA|MAI|II|DIF
struct relacional{enum{Numero40, Numero41,Numero401, Numero411,Numero402, Numero412} kind;
				union{
					struct{} numero40;
					struct{} numero41;
					struct{} numero401;
					struct{} numero411;
					struct{} numero402;
					struct{} numero412;
				} u;
};
relacional numero40();
relacional numero41();
relacional numero401();
relacional numero411();
relacional numero402();
relacional numero412();

//somaexpressao : somaexpressao soma termo | termo
struct somaexpressao{enum{Numero42, Numero43} kind;
				union{
					struct{somaexpressao Somaexpressao; soma Somar; termo Termo;}numero42;
					struct{termo Termo;}numero43;
				} u;
};
somaexpressao numero42(somaexpressao Somaexpressao, soma Somar, termo Termo);
somaexpressao numero43(termo Termo);

//soma : SOMA | SUBT
struct soma{enum{Numero44,Numero45} kind;
				union{
					struct{}numero44;
					struct{}numero45;
				} u;
};
soma numero44();
soma numero45();

//termo : termo mult fator | fator
struct termo{enum{Numero46,Numero47} kind;
				union{
					struct{termo Termo; mult Mult; fator Fator;}numero46;
					struct{fator Fator;}numero47;
				} u;
};
termo numero46(termo Termo, mult Mult, fator Fator);
termo numero47(fator Fator);

//mult : MULT | DIVI
struct mult{enum{Numero48,Numero49} kind;
				union{
					struct{}numero48;
					struct{}numero49;
				} u;
};
mult numero48();
mult numero49();

//fator : ABPAREN expressao FEPAREN | var | ativacao | NUM
struct fator{enum{Numero50,Numero51,Numero52,Numero53,Numero59} kind;
				union{
					struct{ expressao Expressao; }numero50;
					struct{var Var;}numero51;
					struct{ativacao Ativacao;}numero52;
					struct{int NUM;}numero53;
					struct{string stringvalue;}numero59;
				} u;
};
fator numero50( expressao Expressao);
fator numero51(var Var);
fator numero52(ativacao Ativacao);
fator numero53(int NUM);
fator numero59(string stringvalue);

//ativacao : ID ABPAREN args FEPAREN
struct ativacao{enum{Numero54} kind;
				union{
					struct{string ID;  args Args;}numero54;
				} u;
};
ativacao numero54(string ID, args Args);

//args : argslista | vazio
struct args{enum{Numero55,Numero56} kind;
				union{
					struct{argslista Argslista;}numero55;
					struct{vazio Vazio;}numero56;
				} u;
};
args numero55(argslista Argslista);
args numero56(vazio Vazio);

//argslista : argslista VIRG expressao | expressao
struct argslista{enum{Numero57,Numero58} kind;
				union{
					struct{argslista Argslista; expressao Expressao;}numero57;
					struct{expressao Expressao;}numero58;
				} u;
};
argslista numero57(argslista Argslista,  expressao Expressao);
argslista numero58(expressao Expressao);


struct vazio{};
vazio Vazio();

#endif
