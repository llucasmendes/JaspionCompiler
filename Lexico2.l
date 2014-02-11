%option noyywrap
%x STRING
%x COMENT
%x LETRAS
%x DIGITOS
%{
/* * * * * * * * * * * *
* * * DEFINITIONS * * *
* * * * * * * * * * * */
#include <stdio.h>
int coment = 0;
int linhas = 1;
%}
%{
// recognize whether or not a credit card number is valid
int line_num = 1;
%}
digit [0-9]
letras [a-zA-Z]
cesp[\!|\@|\#|\$|\&|\*|\'|\?|\.|\,|\^|\~|\_]
%%
%{
/* * * * * * * * *
* * * RULES * * *
* * * * * * * * */
%}
\n {printf("\n"); linhas++;}
\t
" "
"int" { printf("PRESERV(%s) ",yytext) ; return INT; }
"string" { printf("PRESERV(%s) ",yytext); return STRING;  }
"if" { printf("PRESERV(%s) ",yytext); return IF;}
"else" { printf("PRESERV(%s) ",yytext); return ELSE;}
"while" { printf("PRESERV(%s) ",yytext); return WHILE; }
"return" { printf("PRESERV(%s) ",yytext); return RETURN;}
"void" { printf("PRESERV(%s) ",yytext); return VOID; }

["] {BEGIN(STRING); printf("STRING(");}
<STRING>\. ECHO;
<STRING>[\\][\"] ECHO;
<STRING>\n {printf("ERROLEX(String)"); BEGIN(INITIAL);}
<STRING><<EOF>> {printf("ERROLEX(String)"); BEGIN(INITIAL);}
<STRING>["] {printf(") "); return STRING; BEGIN(INITIAL);}

[/][*] {BEGIN(COMENT); printf("COMENT(");}
<COMENT>\. ECHO;
<COMENT>[\/][\*] {ECHO; coment++;}
<COMENT>[\*][\/] {if(coment==0){printf(") "); BEGIN(INITIAL);}else {coment=coment-1;ECHO;}}
<COMENT><<EOF>> {printf("ERROLEX(COMENT)"); BEGIN(INITIAL);}

{digit} {BEGIN(DIGITOS); printf("NUMER(%s",yytext); }
<DIGITOS>{digit} {ECHO;} 
<DIGITOS>[;] {printf(") PVIRGULA "); return NUM; BEGIN(INITIAL);}
<DIGITOS>[\]] {printf(") FECOLC "); return NUM; BEGIN(INITIAL);}
<DIGITOS>[)] {printf(") FEPAREN "); return NUM; BEGIN(INITIAL);}
<DIGITOS>[ |\n|\]] {printf(") "); return NUM; BEGIN(INITIAL);}
<DIGITOS>. { printf(") ERROLEX(NUM) "); BEGIN(INITIAL);}

{letras} {BEGIN(LETRAS); printf("ID(%s",yytext); }
<LETRAS>{letras} {ECHO;} 
<LETRAS>[(] {printf(") ABPAREN "); return ID; BEGIN(INITIAL);}
<LETRAS>[)] {printf(") FEPAREN "); return ID; BEGIN(INITIAL);}
<LETRAS>[;] {printf(") PVIRG "); return ID; BEGIN(INITIAL);}
<LETRAS>[[] {printf(") ABCOLC "); return ID; BEGIN(INITIAL);}
<LETRAS>["] {printf(") ");return ID; BEGIN(INITIAL);printf("STRING("); BEGIN(STRING);}
<LETRAS>[" "|\n|\t] {printf(") "); return ID; BEGIN(INITIAL);}
<LETRAS>{digit}|{cesp} { printf(") ERROLEX(ID) ");BEGIN(INITIAL);}


[\<=] { printf("COMPARADOR(%s) ",yytext); return MEI; }
[\<] { printf("COMPARADOR(%s) ",yytext); return ME; }
[\>] { printf("COMPARADOR(%s) ",yytext); return MA; }
[\>=] { printf("COMPARADOR(%s) ",yytext); return MAI; }
[\==] { printf("COMPARADOR(%s) ",yytext); return II; }
[\!=] { printf("COMPARADOR(%s) ",yytext); return DIF; }

[\+] { printf("SOMA "); return SOMA; }
[\-] { printf("SUBT "); return SUBT;}
[\*] { printf("MULT "); return MULT;}
[\\] { printf("DIVI "); return DIVI;}
[\=] { printf("IGUAL "); return IGUAL;}

[\;] { printf("PVIRG\n"); return PVIRG; }
[\(] { printf("ABPAREN "); return ABPAREN; }
[\)] { printf("FEPAREN "); return FEPAREN; }
[\{] { printf("ABCHA\n");return ABCHA; }
[\}] { printf("FECHA ");return FECHA; }
[\[] { printf("ABCOLC ");return ABCOLC; }
[\]] { printf("FECOLC ");return FECOLC; }

<<EOF>> {printf("\nFIM\n"); return 0;}


%%
/* * * * * * * * * * *
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
int main(int argc,char *argv[]) {

yylex();
}
