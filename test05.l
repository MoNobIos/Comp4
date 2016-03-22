
%{
#include <stdio.h>
#include <stdlib.h>
#include "test05.tab.h"

int hexToDecimal(char* hex);
int pow(int base,int n);
void errorMunch();

int line;
%}

%%

"while"					{ return WHILE; }
"if"					{ return IF; }
"else"					{ return ELSE; }
"print"					{ return PRINT; }

"=="					{ return EQ; }
"!="					{ return NEQ; }
">"						{ return GREAT; }
"<"						{ return LESS; }
("{"|"}")				{ return *yytext; }

("\"")[a-zA-Z0-9]*("\"")	{ yylval.str = strdup(yytext); return MSG; }
[0-9]+					{ yylval.val = atoi(yytext); return NUMBER; }
"0x"[0-9a-f]+			{ yylval.val = hexToDecimal(yytext); ;return NUMBER; }
[_a-zA-Z][_a-zA-Z0-9]*	{ yylval.str = strdup(yytext); printf("%s\n", "variable"); return VARIABLE; }
[-+()*/\\]		{ return *yytext; }
[=]				{ return ASSIGN; }
[;]				{ return SEMICOLON; }
[_a-zA-Z0-9]+	{ printf("%s\n", "text");return TEXT; }


[\n]			{line++;}
[ \t\f\v]		; /* ignore */
.				{ errorMunch(); return ERR; }

%%


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
