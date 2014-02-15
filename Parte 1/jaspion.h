#ifndef jaspion_h
#define jaspion_h

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

*/

typedef char* string;

typedef struct programa *programa;
typedef struct declaracaolista *declaracaolista;
typedef struct declaracao *declaracao;
typedef struct vardeclaracao *vardeclaracao;
typedef struct tipoespecificador *tipoespecificador;
typedef struct fundeclaracao *fundeclaracao;
typedef struct params *params;
typedef struct paramlista *paramlista;
typedef struct param *param;
typedef struct compostodecl *compostodecl;
typedef struct localdecla *localdecla;
typedef struct statementlista *statementlista;
typedef struct statement *statement;
typedef struct espressaodecl *espressaodecl;
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
						struct {tipoespecificador Tipoespecificador; string ID; char PVIRG; } numero6;
						struct { tipoespecificador Tipoespecificador; string ID; char ABCOLC; int NUM; char; char FECOLC; char PVIRG;} numero7;
					} u;
};
vardeclaracao numero6(tipoespecificador Tipoespecificador, string ID, char PVIRG);
vardeclaracao numero7(tipoespecificador Tipoespecificador, string ID, char ABCOLC, int NUM, char, char FECOLC, char PVIRG);

//tipoespecificador : INT | VOID 
struct tipoespecificador {	enum{Numero8, Numero9} kind;
						union{
							struct{string INT;} numero8;
							struct{string VOID;} numero9;
						} u;
};
tipoespecificador numero8(string INT);
tipoespecificador numero9(string VOID);

//fundeclaracao : tipoespecificador ID ABPAREN params FEPAREN compostodecl
struct fundeclaracao{	enum{Numero10} kind;
						union{
							struct{tipoespecificador Tipoespecificador; string ID; char ABPAREN; params Params; char FEPAREN; compostodecl Compostodecl;} numero10;
						} u;
};
fundeclaracao numero10(tipoespecificador Tipoespecificador, string ID, char ABPAREN, params Params, char FEPAREN, compostodecl Compostodecl);

//params : paramslista | VOID
struct params{	enum{Numero11,Numero12} kind;
						union{
							struct{paramslista Paramslista;} numero11;
							struct{string VOID;} numero12;
						} u;
};
params numero11(paramslista Paramslista);
params numero12(string VOID);

//paramlista : paramslista VIRG param | param
struct paramlista{ 	enum{Numero13, Numero14} kind;
							union{
								struct{paramslista Paramslista; char VIRG; param Param;} numero13;
								struct{param Param;} numero14;
							} u;						
};
paramlista numero13(paramslista Paramslista, char VIRG, param Param);
paramlista numero14(param Param);

//param : tipoespecificador ID | tipoespecificador ID ABCOLC FECOLC
struct param{ 	enum{Numero15,Numero16} kind;
					union{
						struct{tipoespecificador Tipoespecificador; string ID;} numero15;
						struct{tipoespecificador Tipoespecificador; string ID; char ABCOLC; char FECOLC;} numero16;
					} u;
};
param numero15(tipoespecificador Tipoespecificador, string ID);
param numero16(tipoespecificador Tipoespecificador, string ID, char ABCOLC, char FECOLC);

//compostodecl : ABCHA localdecla statementlista FECHA
struct compostodecl{enum{Numero17} kind;
					union{
						struct{char ABCHA; localdecla Localdecla; statementlista Statementlista; char FECHA;} numero17;
					} u;
};
compostodecl numero17(char ABCHA, localdecla Localdecla, statementlista Statementlista, char FECHA);

//localdecla : localdecla vardecla | vazio
struct localdecla{	enum{Numero18,Numero19} kind;
						union{
							struct{localdecla Localdecla; vardecla Vardecla;} numero18;
							struct{vazio Vazio;} numero19;
						} u;
};
localdecla numero18(localdecla Localdecla, vardecla Vardecla);
localdecla numero19(vazio Vazio);

//statementlista : statementlista statement | vazio
struct statementlista{	enum{Numero20,NUmero21} kind;
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
						struct{retornodecl Retornodecl}numero26;
					} u;
};
statement numero22(expressaodecl Expressaodecl);
statement numero23(compostodecl Compostodecl);
statement numero24(selecaodecl Selecaodecl);
statement numero25(iteracaodecl Iteracaodecl);
statement numero26(retornodecl Retornodecl);

//espressaodecl : expressao PVIRG | PVIRG
struct espressaodecl{	enum{Numero27,Numero28} kind;
					union{
						struct{expressao Expressao; char PVIRG;}numero27;
						struct{char PVIRG;}numero28;
					} u;
};
espressaodecl numero27(expressao Expressao, char PVIRG);
espressaodecl numero28(char PVIRG);

//selecaodecl : IF ABPAREN expressao FEPAREN statement | IF ABPAREN expressao FEPAREN statement ELSE statement 
struct selecaodecl{	enum{Numero29,Numero30} kind;
					union{
						struct{string IF; char ABPAREN; expressao Expressao; char FEPAREN; statement Statement;}numero29;
						struct{string IF; char ABPAREN; expressao Expressao; char FEPAREN; statement Statement; string ELSE; statement Statement2;}numero30;
					} u;
};
selecaodecl numero29(string IF, char ABPAREN, expressao Expressao, char FEPAREN, statement Statement);
selecaodecl numero30(string IF, char ABPAREN, expressao Expressao, char FEPAREN, statement Statement, string ELSE, statement Statement2);

//iteracaodecl : WHILE ABPAREN expressao FEPAREN statement
struct iteracaodecl{enum{Numero31} kind;
					union{
						struct{string WHILE; char ABPAREN; expressao Expressao; string FEPAREN; statement Statement;}numero31;
					} u;
};
iteracaodecl numero31(string WHILE, char ABPAREN, expressao Expressao, string FEPAREN, statement Statement);

//retornodecl : RETURN PVIRG | RETURN expressao PVIRG
struct retornodecl{	enum{Numero32,Numero33} kind;
				union{
					struct{string RETURN; char PVIRG;}numero32;
					struct{string RETURN; expressao Expressao; char PVIRG;}numero33;
				} u;
};
retornodecl numero32(string RETURN, char PVIRG);
retornodecl numero33(string RETURN, expressao Expressao, char PVIRG);

//expressao : var IGUAL expressao | simplesexpressao
struct expressao{enum{Numero34,Numero35} kind;
				union{
					struct{var Var; char IGUAL; expressao Expressao;}numero34;
					struct{simplesexpressao Simplesexpressao;}numero35;
				} u;
};
expressao numero34(var Var, char IGUAL, expressao Expressao);
expressao numero35(simplesexpressao Simplesexpressao);

//var : ID | ID ABCOLC expressao FECOLC
struct var{	enum{Numero36,Numero37} kind;
				union{
					struct{String ID;}numero36;
					struct{string ID; char ABCOLC; expressao Expressao; char FECOLC;}numero37;
				} u;
};
var numero36(String ID);
var numero37(string ID, char ABCOLC, expressao Expressao, char FECOLC);

//simplesexpressao : somaexpressao relacional somaexpressao | somaexpressao
struct simplesexpressao{enum{Numero38,Numero39} kind;
				union{
					struct{somaexpressao Somaexpressao; relacional Relacional; somaexpressao Somaexpressao;}numero38;
					struct{somaexpressao Somaexpressao;}numero39;
				} u;
};
simplesexpressao numero38(somaexpressao Somaexpressao, relacional Relacional, somaexpressao Somaexpressao);
simplesexpressao numero39(somaexpressao Somaexpressao);

//relacional : MEI|ME|MA|MAI|II|DIF
struct relacional{enum{Numero40, Numero41,Numero401, Numero411,Numero402, Numero412} kind;
				union{
					struct{string MEI;} numero40;
					struct{string ME;} numero41;
					struct{string MA;} numero401;
					struct{string MAI;} numero411;
					struct{string II;} numero402;
					struct{string DIF;} numero412;
				} u;
};
relacional numero40(string MEI);
relacional numero41(string ME);
relacional numero401(string MA);
relacional numero411(string MAI);
relacional numero402(string II);
relacional numero412(string DIF);

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
					struct{char SOMA;}numero44;
					struct{char SUBT;}numero45;
				} u;
};
soma numero44(char SOMA);
soma numero45(char SUBT);

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
					struct{string MULT;}numero48;
					struct{string DIVI;}numero49;
				} u;
};
mult numero48(string MULT);
mult numero49(string DIVI);

//fator : ABPAREN expressao FEPAREN | var | ativacao | NUM
struct fator{enum{Numero50,Numero51,Numero52,Numero53} kind;
				union{
					struct{char ABPAREN; expressao Expressao; char FEPAREN;}numero50;
					struct{var Var;}numero51;
					struct{ativacao Ativacao;}numero52;
					struct{int NUM;}numero53;
				} u;
};
fator numero50(char ABPAREN, expressao Expressao, char FEPAREN);
fator numero51(var Var);
fator numero52(ativacao Ativacao);
fator numero53(int NUM);

//ativacao : ID ABPAREN args FEPAREN
struct ativacao{enum{Numero54} kind;
				union{
					struct{string ID; char ABPAREN; args Args; char FEPAREN}numero54;
				} u;
};
ativacao numero54(string ID, char ABPAREN, args Args, char FEPAREN);

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
					struct{argslista Argslista; char VIRG; expressao Expressao;}numero57;
					struct{expressao Expressao;}numero58;
				} u;
};
argslista numero57(argslista Argslista, char VIRG, expressao Expressao);
argslista numero58(expressao Expressao);

struct A_vazio_{};
A_vazio A_Vazio();
#endif
