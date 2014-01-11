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
%%
%{
/* * * * * * * * *
* * * RULES * * *
* * * * * * * * */
%}
\n {printf("\n"); linhas++;}
\t
" "
"int" { printf("PRESERV(%s) ",yytext) ; }
"string" { printf("PRESERV(%s) ",yytext); }
"if" { printf("PRESERV(%s) ",yytext); }
"else" { printf("PRESERV(%s) ",yytext); }
"while" { printf("PRESERV(%s) ",yytext); }
"return" { printf("PRESERV(%s) ",yytext); }
"void" { printf("PRESERV(%s) ",yytext); }

["] {BEGIN(STRING); printf("STRING(");}
<STRING>\. ECHO;
<STRING>[\\][\"] ECHO;
<STRING>\n {printf("ERROLEX(String)"); BEGIN(INITIAL);}
<STRING>["] {printf(") "); BEGIN(INITIAL);}

[/][*] {BEGIN(COMENT); printf("COMENT(");}
<COMENT>\. ECHO;
<COMENT>[\/][\*] {ECHO; coment++;}
<COMENT>[\*][\/] {if(coment==0){printf(") "); BEGIN(INITIAL);}else {coment=coment-1;ECHO;}}
<COMENT><<EOF>> {printf("ERROLEX(COMENT)"); BEGIN(INITIAL);}

{digit} {BEGIN(DIGITOS); printf("NUMER(%s",yytext); }
<DIGITOS>{digit} {ECHO;} 
<DIGITOS>[\;] {printf(") PVIRGULA ");BEGIN(INITIAL);}
<DIGITOS>[ |\n|\]] {printf(") ");BEGIN(INITIAL);}
<DIGITOS>. { printf(") ERRO(NUM) "); BEGIN(INITIAL);}

{letras} {BEGIN(LETRAS); printf("ID(%s",yytext); }
<LETRAS>{letras} {ECHO;} 
<LETRAS>[(] {printf(") ABPAREN ");BEGIN(INITIAL);}
<LETRAS>[)] {printf(") FEPAREN ");BEGIN(INITIAL);}
<LETRAS>[;] {printf(") PVIRGULA ");BEGIN(INITIAL);}
<LETRAS> {printf(") ");BEGIN(INITIAL);}
<LETRAS>[^\t|\n| ] { printf(") ERRO(ID) "); BEGIN(INITIAL);}

[\+|\,|\-|\*|\/]|(\<\=)|[\<]|(\>=)|[\>]|(\!=)|[\!]|(\==)|[\=] { printf("OPERADOR(%s) ",yytext); }
[\#|\$|\&] { printf("CARACESPEC(%s) ",yytext); }

[\:] { printf("DOISP "); }
[\;] { printf("PVIRGULA\n"); }
[\(] { printf("ABPAREN "); }
[\)] { printf("FEPAREN "); }
[\{] { printf("ABCHAVE\n"); }
[\}] { printf("FECHAVE "); }
[\[] { printf("ABCOLC "); }
[\]] { printf("FECOLC "); }

<<EOF>> {printf("\nFIM\n"); return 0;}


%%
/* * * * * * * * * * *
 * * * USER CODE * * *
 * * * * * * * * * * *
 */
int main(int argc,char *argv[]) {

yylex();
}

