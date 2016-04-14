
%{
#include <stdio.h>
#include <stdlib.h>
#include "test05.tab.h"

int hexToDecimal(char* hex);
int pow(int base,int n);
void errorMunch();

int line;
int check_else=0;
int check_if=0;
int check_while=0;
int check_assign = 0;
int check_condition = 0;
int check_numvar = 0;
%}

%%

"while"					{ check_condition = 1; check_while=1; return WHILE; }
"if"					{ check_condition = 1; check_if=1; return IF; }
"else"					{ check_else = 1; return ELSE; }
"print"					{ return PRINT; }

"=="					{ return EQ; }
"!="					{ return NEQ; }
">"					{ return GREAT; }
"<"					{ return LESS; }
"{"					{ return *yytext; }
"}"					{ check_else=0; return *yytext; }
"("					{ if(check_condition==1) check_condition=2; return *yytext;}
")"					{ if(check_condition==2) check_condition=0; return *yytext;}

("\"")[a-zA-Z0-9=:]*("\"")		{ yylval.str = strdup(yytext); return MSG; }
[0-9]+					{ yylval.val = atoi(yytext); return NUMBER; }
"0x"[0-9a-f]+				{ yylval.val = hexToDecimal(yytext); ;return NUMBER; }
[_a-zA-Z][_a-zA-Z0-9]*			{ check_numvar=1; yylval.str = strdup(yytext); return VARIABLE; }
[-+*/\\]				{ return *yytext; }
[=]					{ check_assign=1; return ASSIGN; }
[;]					{ resetReg(); return SEMICOLON;}


[\n]					{line++;}
[ \t\f\v]				; /* ignore */
.					{ errorMunch(); return ERR; }

%%

void resetReg(){
	check_condition = 0;
	check_assign = 0;
	check_numvar = 0;
	check_if = 0;
	check_while = 0;
}


int hexToDecimal(char* hex){ /* base 16 to base 10 */
	int num = 0;
	int i;
	char temp;
	int len = strlen(hex);

	for(i=2 ; i<len ; i++){
		temp = hex[i];

		if(temp>='a' && temp<='f'){
			num += (10 + temp-'a')*pow(16,len-1-i);
		}
		else {
			num += (temp-'0')*pow(16,len-1-i);
		}
	}
	return num;
}

int pow(int base,int n){
	if(n == 0) return 1;
	else return base * pow(base,n-1);
}

void errorMunch()
{
	while (input() != '\n');
}

int yywrap(){
	return 1;
}
