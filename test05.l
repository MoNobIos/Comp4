
%{
#include <stdio.h>
#include <stdlib.h>
#include "test05.tab.h"

void resetReg();
void errorMunch();

int line;
int check_else=0;
int check_if=0;
int check_while=0;
int check_assign = 0;
%}

%%

"while"					{ check_while=1; return WHILE; }
"if"					{ check_if=1; return IF; }
"else"					{ check_else = 1; return ELSE; }
"print"					{ return PRINT; }
"print_hex"				{ return PRINT_HEX; }
"newline"				{ return NEWLINE; }

"=="					{ return EQ; }
"!="					{ return NEQ; }
">"					{ return GREAT; }
"<"					{ return LESS; }
"{"					{ return *yytext; }
"}"					{ resetReg(); return *yytext; }
"("					{ return *yytext;}
")"					{ return *yytext;}

("\"")[a-zA-Z0-9=:]*("\"")		{ yylval.str = strdup(yytext); return MSG; }
[0-9]+					{ yylval.str = strdup(yytext) ; return NUMBER; }
"0x"[0-9a-f]+				{ yylval.str = strdup(yytext); ;return NUMBER; }
[_a-zA-Z][_a-zA-Z0-9]*			{ yylval.str = strdup(yytext); return VARIABLE; }
[-+*/\\]				{ return *yytext; }
[=]					{ check_assign=1; return ASSIGN; }
[;]					{ check_assign = 0; return SEMICOLON;}


[\n]					{line++;}
[ \t\f\v]				; /* ignore */
.					{ errorMunch(); return ERR; }

%%

void resetReg(){
	check_if = 0;
	check_while = 0;
	check_else = 0;
}

void errorMunch()
{
	while (input() != '\n');
}

int yywrap(){
	return 1;
}
