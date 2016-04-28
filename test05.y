%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP 26

extern int yylex();
extern int check_else; // 1 when else , 0 when }
extern int line;
extern int check_while; // 1 when while , 0 when }
extern int check_if; // 1 when if , 0 when }


/* variable */
struct var{
	char *name;
	int val;
};

char data[512];
char temp_state[2048];
char temp_state_else[255]="";
char temp_exp[1024];
char temp_condition_if[255];


void yyerror();
int getVar(char *name);
void asm_print_alloc(char *msg);
void asm_print_alloc_newline(char *msg);
void asm_print_init();
void asm_print_string(char *msg);
void asm_print_exp(char* num);
void asm_print_exp_newline(char* num);
void asm_print_hex(char* num);
void asm_print_hex_newline(char* num);
void asm_if(char* a,char* b);
void asm_add(char* a,char* b);
void asm_sub(char* a,char* b);
void asm_div(char* a,char* b);
void asm_mod(char* a,char* b);
void asm_loop(char* a,char* b);
void reset_flag_condition();
void asm_statement();

void asm_mul(char* a,char* b);
void asm_assign(char* var,char* val);
char* minus(char* a);

int STATE;

struct var myVar[26];
int top=-1;
int count_string=0;
int count_if=0;
int count_loop = 0;
int count_mod=0;

FILE *file;

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
%token NEWLINE
%token PRINT_HEX


%left GREAT LESS EQ NEQ
%left '+' '-'
%left '*' '/' '\\'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%type<val> statement
%type<str> VARIABLE MSG NUMBER expression


%%

prog : statement							{ asm_statement();}
	| prog statement						{ asm_statement();}
	;

statement :	expression SEMICOLON					{  }
	| IF '(' expression EQ expression ')' '{' group_command '}' %prec IFX										{ asm_if((char*)$3,(char*)$5); }
	| IF '(' expression EQ expression ')' '{' group_command '}' ELSE '{' group_command '}' 	{ asm_if((char*)$3,(char*)$5); }
	| WHILE '(' expression LESS expression ')' '{' statement '}'														{ asm_loop((char*)$3,(char*)$5); }
	| group_command 			{}
	| error 							{ yyerror(); }
	;

group_command : command		{}
	| statement command		{}
	;

command :  PRINT MSG SEMICOLON							{ asm_print_alloc((char*)$2); asm_print_string((char*)$2); }
	| PRINT MSG NEWLINE SEMICOLON 						{ asm_print_alloc_newline((char*)$2); asm_print_string((char*)$2); }
	| PRINT expression SEMICOLON 							{ asm_print_exp($2); }
	| PRINT expression NEWLINE SEMICOLON 			{ asm_print_exp_newline($2); }
	| PRINT_HEX expression SEMICOLON 					{ asm_print_hex($2); }
	| PRINT_HEX expression NEWLINE SEMICOLON 	{ asm_print_hex_newline($2); }
	| VARIABLE ASSIGN expression SEMICOLON		{ asm_assign((char*)$1,(char*)$3); }

expression : expression '+' expression			{ $$ = "pop"; asm_add($1,$3); }
	| expression '-' expression 							{ $$ = "pop"; asm_sub($1,$3); }
	| expression '*' expression 							{ $$ = "pop"; asm_mul((char*)$1,(char*)$3); }
	| expression '/' expression 							{ $$ = "pop"; asm_div((char*)$1,(char*)$3); ; }
	| expression '\\' expression 							{ $$ = "pop"; asm_mod((char*)$1,(char*)$3); }
	| '-' expression %prec UMINUS							{ $$ = minus($2); printf("t %s\n",$$); }
	| '(' expression ')'											{ $$ = "pop"; }
	| NUMBER																	{ $$ = (char*)$1; }
	| VARIABLE 																{ $$ = (char*)$1; }
	;
%%

/*  syntax error */
void yyerror(){
	printf("error has occured line : %d\n",line);
}


void reset_flag_condition(){
	check_while = check_if = 0;
}

char* minus(char* a){
	char* temp = (char*)malloc(sizeof(char)*strlen(a)+1);
	sprintf(temp,"-%s",a);
	printf("%s\n",temp);
	return temp;
}

void asm_assign(char* var,char* val){
	int i;
	int flag=0;
	char temp_string[255];
	char temp[255];
	for(i=0 ; i<=top ; i++){
		if(strcmp(var,myVar[i].name)==0){
			if(strcmp(val,"pop")==0){
				strcpy(temp_string,"\tmov r9,[array+8*r8]\n");
				strcat(temp_string,"\tsub r8,1\n");
				strcat(temp_string,"\tmov [");
				strcat(temp_string,var);
				strcat(temp_string,"],r9\n");
			}
			else {
				strcpy(temp_string,"\tmov r9,");
				strcat(temp_string,val);
				strcat(temp_string,"\n");
				strcat(temp_string,"\tmov [");
				strcat(temp_string,var);
				strcat(temp_string,"],r9\n");
			}
			printf("%s\n\n",temp_string);
			if(check_else==0){
				strcat(temp_state,temp_string);
			}
			else{
				strcat(temp_state_else,temp_string);
			}

			flag = 1;
			break;
		}
	}
	if(!flag){
		++top;
		myVar[top].name = var;

		strcpy(temp_string,"\t");
		strcat(temp_string,var);
		strcpy(temp,":\tdq\t");
		strcat(temp_string,temp);
		strcat(temp_string,val);
		strcat(temp_string,"\n");
		strcat(data,temp_string);
	}
}

void asm_statement(){

	/* write all statement to file */
	fprintf(file,"%s",temp_state);

	int i;
	for(i=0 ; i<2048 ; i++) temp_state[i] = 0;
}

void asm_add(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;add\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tadd rax,r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}

}

void asm_sub(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;sub\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tsub rax,r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_mul(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;mul\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\timul dword r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_div(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;div\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	strcat(temp_exp,"\tmov rdx,0\n");
	strcat(temp_exp,"\tidiv dword r10\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");

	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_mod(char* a,char* b){
	char* pop = "pop";
	strcat(temp_exp,"\t\t;nod\n");
	/* load a */
	if(strcmp(a,pop)==0){
		strcat(temp_exp,"\tmov rax,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_exp,"\tmov rax,");
		strcat(temp_exp,a);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov rax,[");
		strcat(temp_exp,a);
		strcat(temp_exp,"]\n");
	}

	/* load b */
	if(strcmp(b,pop)==0){
		strcat(temp_exp,"\tmov r10,[array+8*r8]\n");
		strcat(temp_exp,"\tsub r8,1\n");
	}
	else if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_exp,"\tmov r10,");
		strcat(temp_exp,b);
		strcat(temp_exp,"\n");
	}
	else {
		strcat(temp_exp,"\tmov r10,[");
		strcat(temp_exp,b);
		strcat(temp_exp,"]\n");
	}

	/* op */
	char num_mod[2];
	sprintf(num_mod,"%d",count_mod++);
	strcat(temp_exp,"MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,":\n");
	strcat(temp_exp,"\tcmp rax,r10\n");
	strcat(temp_exp,"\tjl END_MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,"\n");
	strcat(temp_exp,"\tsub rax,r10\n");
	strcat(temp_exp,"\tjmp MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,"\n");
	strcat(temp_exp,"END_MOD_");
	strcat(temp_exp,num_mod);
	strcat(temp_exp,":\n");
	strcat(temp_exp,"\t\t;push\n");
	strcat(temp_exp,"\tadd r8,1\n");
	strcat(temp_exp,"\tmov [array+8*r8],rax\n");
	if(check_else==0){
		strcat(temp_state,temp_exp);
	}
	else{
		strcat(temp_state_else,temp_exp);
	}
}

void asm_loop(char* a,char* b){
	char temp_string[1024] = "\nLOOP_";
	char num_loop[2];
	int i;

	sprintf(num_loop,"%d",count_loop++);
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");
	/* LOOP_0: */

	if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_string,"\tmov r10,");
		strcat(temp_string,a);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r10,[");
		strcat(temp_string,a);
		strcat(temp_string,"]\n");
	}

	if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_string,"\tmov r11,");
		strcat(temp_string,b);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r11,[");
		strcat(temp_string,b);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tcmp r10,r11\n");
	strcat(temp_string,"\tjge END_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");

	strcat(temp_string,"\nSTATE_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");

	strcat(temp_string,temp_state);
	strcat(temp_string,"\tmov r8,0\n");
	/* statement */
	for(i=0 ; i<255 ; i++) temp_state[i] = 0;

	strcat(temp_string,"\tjmp LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");
	strcat(temp_string,"\nEND_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n\n");

	fprintf(file,"%s",temp_string);

}

void asm_if(char* a,char* b){
	char temp_string[1024] = "\nSTATE_IF_";
	char num_if[2];
	int i;
	printf("if%s\nelse%s\n",temp_state,temp_state_else);
	sprintf(num_if,"%d",count_if++);
	strcat(temp_string,num_if);
	strcat(temp_string,":\n");

	strcat(temp_string,temp_condition_if);
	if((a[0]>='0' && a[0]<='9') || (a[0]=='-')){
		strcat(temp_string,"\tmov r10,");
		strcat(temp_string,a);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r10,[");
		strcat(temp_string,a);
		strcat(temp_string,"]\n");
	}

	if((b[0]>='0' && b[0]<='9') || (b[0]=='-')){
		strcat(temp_string,"\tmov r11,");
		strcat(temp_string,b);
		strcat(temp_string,"\n");
	}
	else {
		strcat(temp_string,"\tmov r11,[");
		strcat(temp_string,b);
		strcat(temp_string,"]\n");
	}
	strcat(temp_string,"\tcmp r10,r11\n");
	strcat(temp_string,"\tje STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_TRUE\n");
	strcat(temp_string,"\tjmp STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_FALSE");
	strcat(temp_string,"\n");

	strcat(temp_string,"\nSTATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_TRUE:\n");
	strcat(temp_string,temp_state);
	strcat(temp_string,"\tjmp NEXT_STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"\n");

	/* add ELSE */
	strcat(temp_string,"\nSTATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,"_FALSE:\n");
	strcat(temp_string,temp_state_else);
	strcat(temp_string,"\n");

	/* END */
	strcat(temp_string,"\nNEXT_STATE_IF_");
	strcat(temp_string,num_if);
	strcat(temp_string,":\n");


	strcat(temp_state,temp_string);

	strcpy(temp_state,temp_string);


	/* reset value */
	check_else = 0;

	for(i=0 ; i<255 ; i++){
		temp_condition_if[i]=0;
	}
}

void asm_print_string(char *msg){
	char temp_str[255];
	char num[2];
	sprintf(num,"%d",count_string-1);

	strcpy(temp_str,"\tmov\trdi,string_");
	strcat(temp_str,num);
	strcat(temp_str,"\n");
	strcat(temp_str,"\tmov\trsi,string_");
	strcat(temp_str,num);
	strcat(temp_str,"\n");
	strcat(temp_str,"\tmov\trax,0\n");
	strcat(temp_str,"\tcall printf\n");
	strcat(temp_str,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_str);
	}
	else strcat(temp_state_else,temp_str);
}

void asm_print_exp(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_num");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_exp_newline(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_num_newline");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_hex(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_hex");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_hex_newline(char* num){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_hex_newline");

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	if(strcmp(num,"pop")==0){
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,"array+8*r8");
		strcat(temp_string,"]\n");
		strcat(temp_string,"\tsub r8,1\n");
	}
	else if((num[0]>='0' && num[0]<=9) || num[0]=='-') {
		strcat(temp_string,"\tmov\trsi,");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"\n");
	}
	else{
		strcat(temp_string,"\tmov\trsi,[");

		/* edit to num display value */
		strcat(temp_string,num);
		strcat(temp_string,"]\n");
	}

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
	strcat(temp_string,"\tmov r8,-1 ;\n");
	if(check_else==0){
		strcat(temp_state,temp_string);
	}
	else strcat(temp_state_else,temp_string);

}

void asm_print_alloc(char *msg){
	char temp[255];
	char temp2[255];
	char num[2];
	strcpy(temp,"\t");
	strcpy(temp2,"string_");
	strcat(temp,temp2);

	sprintf(num,"%d",count_string++);
	strcat(temp,num);

	strcpy(temp2,": db ");
	strcat(temp,temp2);

	strcpy(temp2,msg);
	strcat(temp,temp2);

	strcpy(temp2,",0,0\n");
	strcat(temp,temp2);

	strcat(data,temp);
}

void asm_print_alloc_newline(char *msg){
	char temp[255];
	char temp2[255];
	char num[2];
	strcpy(temp,"\t");
	strcpy(temp2,"string_");
	strcat(temp,temp2);

	sprintf(num,"%d",count_string++);
	strcat(temp,num);

	strcpy(temp2,": db ");
	strcat(temp,temp2);

	strcpy(temp2,msg);
	strcat(temp,temp2);

	strcpy(temp2,",10,0\n");
	strcat(temp,temp2);

	strcat(data,temp);
}

void asm_print_init(){
	char temp[255];
	strcpy(data,"\n\nEXIT:\n\tpop rbp\n\tret\n\n");
	strcpy(temp,"section .data\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_num: db \"%d\",0,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_num_newline: db \"%d\",10,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_hex: db \"0x%x\",0,0\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_hex_newline: db \"0x%x\",10,0\n");
	strcat(data,temp);
	strcpy(temp,"\tarray :	dq	1,2,3,4,5\n");
	strcat(data,temp);
}


int main(void) {
printf(" < b start\n");
	file = fopen("test.asm", "w+");
	fprintf(file,"%s", "section .text\n");
	fprintf(file,"%s", "\textern printf\n");
	fprintf(file,"%s", "\tglobal main\n\n");
	fprintf(file,"%s", "main:\n");
	fprintf(file,"%s", "\tpush    rbp\n");
	fprintf(file,"%s", "\tmov rax,0 ; init\n");
	fprintf(file,"%s", "\tmov r8,-1 ;\n");

	asm_print_init();

    yyparse();

    fprintf(file,"%s", data);
    fclose(file);
    return 0;
}
