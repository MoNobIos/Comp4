%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define YYSTYPE int
#define TOP 25
extern int yylex();


/* variable */
struct var{
	char *name;
	int val;
};

void yyerror();
void updateVariable(char *name,int val);
int getVar(char *name);

struct var myVar[25];
int top=-1;

%}

%union{
	int val;
	char *str;
};

%token NUMBER
%token SEMICOLON
%token VARIABLE
%token ASSIGN
%token WHILE
%token IF
%token ELSE
%token PRINT
%token MSG
%token ERR
%token TEXT

%left GREAT LESS EQ NEQ
%left '+' '-'
%left '*' '/' '\\'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%type<val> expression statement condition
%type<str> MSG VARIABLE

%%

prog : statement							{}
	| prog statement						{}
	;

statement :	expression SEMICOLON				{ $$ = $1; printf("%d\n",$1); }
	| IF '(' condition ')' else_part	{ printf("go to else_part\n"); }
	| WHILE '(' condition ')' '{' statement '}'		{}
	| WHILE '(' condition ')' statement		{}

	| PRINT MSG SEMICOLON		{ printf("%s",(char*)$2); }
	| PRINT expression SEMICOLON { printf("%d",$2); }
	| VARIABLE ASSIGN expression SEMICOLON				{ updateVariable((char*)$1,$3); }
	;

else_part : statement else_st		{ }
	| '{' statement '}' else_st 		{ }
	| %prec IFX {printf("statement has lost\n");}
	| TEXT					{ printf("text errors\n"); }
	;

else_st : %prec IFX	{ printf("OK\n");}
  | ELSE statement { printf("OK\n"); }
	| ELSE '{' statement '}' {printf("OK\n");}

expression : expression '+' expression	{ $$ = $1 + $3; }
	| expression '-' expression 		{ $$ = $1 - $3; }
	| expression '*' expression 		{ $$ = $1 * $3; }
	| expression '/' expression 		{ $$ = $1 / $3; }
	| expression '\\' expression 		{ $$ = $1 % $3; }
	| '-' expression %prec UMINUS		{ $$ = -$2; }
	| '(' expression ')'				{ $$ = $2; }
	| NUMBER										{ }
	| VARIABLE 							{ $$ = getVar((char*)$1);}
	;

condition : expression EQ expression  	{ printf("%d\n",$1==$3); }
	| expression GREAT expression  { printf("%d\n",$1>$3); }
	| expression LESS expression  { printf("%d\n",$1<$3); }
	| expression NEQ expression  { printf("%d\n",$1<$3); }
	| TEXT	{ printf("%s\n", "condition has lost"); yyerror();}
	;


%%

/*  syntax error */
void yyerror(){
	printf("error has occured\n");
}

void updateVariable(char *name,int val){
	int i , flag=1;
	for(i=0 ; i<=top ; i++){
		if(strcmp(name,myVar[i].name)==0){
			myVar[top].val = val;
			flag = 0;
			break;
		}
	}

	if(flag){
		++top;
		myVar[top].name = name;
		myVar[top].val = val;
	}
}

int getVar(char *name){
	int i;
	for(i=0 ; i<=top ; i++){
		if(strcmp(name,myVar[i].name)==0) return myVar[i].val;
	}
	printf("var %s is valid\n",name);
	//exit(1);
	return 0;
}


int main(void) {
    yyparse();
    return 0;
}
