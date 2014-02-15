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
#include "jaspion.h"
#include "ranger.h"
int coment = 0;
%}
%{
// recognize whether or not a credit card number is valid
int line_num = 1;
%}
digit [0-9]*
letras [a-z|A-Z]*
cesp[\@|\#|\$|\&|\'|\?|\^|\~|\_]
%%
%{
/* * * * * * * * *
* * * RULES * * *
* * * * * * * * */
%}
\t
" "
"int" { printf("PRESERV(%s) ",yytext) ; return INT; }
"string" { printf("PRESERV(%s) ",yytext); return STRINGE;  }
"if" { printf("PRESERV(%s) ",yytext); return IF;}
"else" { printf("PRESERV(%s) ",yytext); return ELSE;}
"while" { printf("PRESERV(%s) ",yytext); return WHILE; }
"return" { printf("PRESERV(%s) ",yytext); return RETURN;}
"void" { printf("PRESERV(%s) ",yytext); return VOID; }

"," { printf("VIRG ",yytext); return VIRG; }
"<=" { printf("COMPARADOR(%s) ",yytext); return MEI; }
[\<] { printf("COMPARADOR(%s) ",yytext); return ME; }
[\>] { printf("COMPARADOR(%s) ",yytext); return MA; }
">=" { printf("COMPARADOR(%s) ",yytext); return MAI; }
"==" { printf("COMPARADOR(%s) ",yytext); return II; }
"!=" { printf("COMPARADOR(%s) ",yytext); return DIF; }

[\+] { printf("SOMA "); return SOMA; }
[\-] { printf("SUBT "); return SUBT;}
[\*] { printf("MULT "); return MULT;}
[\\] { printf("DIVI "); return DIVI;}
[\=] { printf("IGUAL "); return IGUAL;}

[\(] { printf("ABPAREN "); return ABPAREN; }
[\)] { printf("FEPAREN "); return FEPAREN; }
[\{] { printf("ABCHA\n");return ABCHA; }
[\}] { printf("FECHA ");return FECHA; }
[\[] { printf("ABCOLC ");return ABCOLC; }
[\]] { printf("FECOLC ");return FECOLC; }

{digit} { printf("NUM(%s)",yytext); return NUM; }

{letras} { printf("ID(%s)",yytext); return ID; }
({digit}{letras}({digit}|{letras})*) {printf("ERROLEX");}

({letras}{digit}({letras}|{digit})*) {printf("ERROLEX");}

[\"][^\n]*[\"] { printf("%s",yytext); return STRINGVALUE;}

[/][*] {BEGIN(COMENT); printf("COMENT(");}
<COMENT>\. ECHO;
<COMENT>[\/][\*] {ECHO; coment++;}
<COMENT>[\*][\/] {if(coment==0){printf(") "); BEGIN(INITIAL);}else {coment=coment-1;ECHO;}}
<COMENT><<EOF>> {printf("ERROLEX(COMENT)"); BEGIN(INITIAL);}


<<EOF>> {printf("\nFIM\n"); return 0;}

[\;] { printf("PVIRG\n"); return PVIRG; }

.|\n|\r

%%
/* * * * * * * * * * *
 * * * USER CODE * * *
 * * * * * * * * * * *
 */

