%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOP 26
#define S_PRITN 1
#define S_UPDATE 2
#define S_IF 3

extern int yylex();
extern int check_else;
extern int check_assign;
extern int check_condition;
extern int check_namevar;
extern int line;
extern int check_while;
extern int check_if; 


/* variable */
struct var{
	char *name;
	int val;
};

char data[512];


char temp_state[2048];
char temp_state_else[255]="";
char temp_exp[1024];
char temp_condition[255];
char temp_condition_while[255];
char temp_condition_if[255];
char temp_namevar[255];
char temp_state_if[512];


void yyerror();
void updateVariable(char *name,int val);
int getVar(char *name);
void asm_print_alloc(char *msg);
void asm_print_init();
void asm_print_string(char *msg);
void asm_print_exp(int innum);
void asm_assign_var(char *name_var,int number);
void asm_if(int condi);
void asm_mov_num(int val);
void asm_mov_var(char *name);
void asm_add();
void asm_sub();
void asm_mul();
void asm_div();
void reset_flag();
void asm_loop();
void reset_flag_condition();


int STATE;

struct var myVar[26];
int top=-1;
int count_string=0;
int count_if=0;
int count_loop = 0;

int flag_rcx = 0;
int flag_rdx = 0;
int flag_op = 0;
int flag_op_mul_div=0;

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


%left GREAT LESS EQ NEQ
%left '+' '-'
%left '*' '/' '\\'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%type<val> expression condition statement NUMBER
%type<str> VARIABLE MSG


%%

prog : statement							{ asm_statement(); reset_flag();}
	| prog statement						{ asm_statement(); reset_flag();}
	;

statement :	expression SEMICOLON					{ $$ = $1;  }
	| IF '(' condition ')' '{' group_command '}' %prec IFX		{printf("IF\n"); asm_if($3);}
	| IF '(' condition ')' '{' group_command '}' else_statement { asm_if($3);}
	| WHILE '(' condition ')' '{' group_command '}'			{  asm_loop();}
	| WHILE '(' condition ')' '{' statement '}'			{ asm_loop();}
	| group_command 			{}
	| statement group_command	{}
	| error 							{ yyerror(); }
	;

else_statement : ELSE '{' group_command '}'		{printf("ELSE\n");}
	;

group_command : command		{}
	| group_command command 		{}
	;

command :  PRINT MSG SEMICOLON						{ asm_print_alloc((char*)$2); asm_print_string((char*)$2); }
	| PRINT expression SEMICOLON 					{ asm_print_exp($2);  }
	| VARIABLE ASSIGN expression SEMICOLON				{ updateVariable((char*)$1,$3); reset_flag();}

expression : expression '+' expression		{ $$ = $1 + $3; asm_add(); flag_op=1; }
	| expression '-' expression 		{ $$ = $1 - $3; asm_sub(); flag_op=1;}
	| expression '*' expression 		{ $$ = $1 * $3; asm_mul(); flag_op=1; flag_op_mul_div=1; }
	| expression '/' expression 		{ $$ = $1 / $3; asm_div(); flag_op=1; flag_op_mul_div=1;}
	| expression '\\' expression 		{ $$ = $1 % $3; }
	| '-' expression %prec UMINUS		{ $$ = -$2; }
	| '(' expression ')'			{ $$ = $2; }
	| NUMBER				{ $$ = $1; asm_mov_num($1);}
	| VARIABLE 				{ $$ = getVar((char*)$1); asm_mov_var((char*)$1); }
	;

condition : expression EQ expression  	{ printf("%d\n",$1==$3); reset_flag_condition();}
	| expression LESS expression  	{ printf("%d\n",$1==$3); reset_flag_condition();}
	;

%%

/*  syntax error */
void yyerror(){
	printf("error has occured line : %d\n",line);
}


void updateVariable(char *name,int val){
	int i , flag=1;
	char temp_string[255];
	char temp[255];
	char num[15];
	for(i=0 ; i<=top ; i++){
		if(strcmp(name,myVar[i].name)==0){
			myVar[top].val = val;
			flag = 0;

			if(!flag_op) asm_add();
			if(!flag_op_mul_div){
				strcat(temp_exp,"\tmov rax,0\n");
				strcat(temp_exp,"\tadd rax,rcx\n");
			}
			else {
				strcat(temp_exp,"\tadd rax,rcx\n");
			}
			strcat(temp_exp,"\tmov rcx,0 ;reset rcx\n");
			strcat(temp_exp,"\tmov rdx,0 ;reset rdx\n");

			strcat(temp_exp,"\tmov [");
			strcat(temp_exp,name);
			strcat(temp_exp,"],rax\n");
			strcat(temp_state,temp_exp);
			strcat(temp_state,"\tmov rax,0 ; reset rax\n");
			check_assign = 0;
			for(i=0 ; i<1024 ; i++) temp_exp[i] = 0;
			flag_op_mul_div = 0;
			break;
		}
	}

	/* declare variable */
	if(flag){
		++top;
		/* write data to section .data */
		myVar[top].name = name;
		myVar[top].val = val;
		sprintf(num,"%d",val);
		strcpy(temp_string,"\t");
		strcat(temp_string,name);
		strcpy(temp,":\tdq\t");
		strcat(temp_string,temp);
		strcat(temp_string,num);
		strcat(temp_string,"\n");
		strcat(data,temp_string);

		for(i=0 ; i<1024 ; i++) temp_exp[i] = 0;
	}
}

int getVar(char *name){
	int i;
	for(i=0 ; i<=top ; i++){
		if(strcmp(name,myVar[i].name)==0) return myVar[i].val;
	}
	printf("var %s is valid\n",name);
	return 0;
}

void reset_flag(){
	flag_rcx = 0;
	flag_rdx = 0;
	flag_op = 0;
}

void reset_flag_condition(){
	check_while = check_if = 0;
}

void asm_statement(){
	
	/* write all statement to file */
	fprintf(file,temp_state);
	int i;
	for(i=0 ; i<2048 ; i++) temp_state[i] = 0;
}

void asm_add(){
	strcat(temp_exp,"\tadd rcx,rdx\n");
}

void asm_sub(){
	strcat(temp_exp,"\tsub rcx,rdx\n");
}

void asm_mul(){
	strcat(temp_exp,"\tmov rax,rcx\n");
	strcat(temp_exp,"\timul qword rdx\n");
	strcat(temp_exp,"\tmov rcx,0 ;reset rcx\n");
	strcat(temp_exp,"\tmov rdx,0 ;reset rdx\n");
}

void asm_div(){
	strcat(temp_exp,"\tmov rax,rcx\n");
	strcat(temp_exp,"\tmov rcx,rdx\n");
	strcat(temp_exp,"\tmov rdx,0\n");
	strcat(temp_exp,"\tidiv qword rcx\n");
	strcat(temp_exp,"\tmov rcx,0 ;reset rcx\n");
	strcat(temp_exp,"\tmov rdx,0 ;reset rdx\n");
}


void asm_mov_var(char *name){
char tempMovVar[255];
	strcpy(temp_namevar,name);
	if(check_assign==1 && (check_condition != 2)){ 
		/* use store temp value of variable to register , use in op */
		if(!flag_rcx){
			strcpy(tempMovVar,"\tmov rcx,[");
			flag_rcx = 1;
		}
		else {
			strcpy(tempMovVar,"\tmov rdx,[");
		}
		strcat(tempMovVar,name);
		strcat(tempMovVar,"] ; variable\n");
		strcat(temp_exp,tempMovVar);
	}
	if(check_condition==2){
		/* store temp value of variable , use in condition */
		strcpy(tempMovVar,"\tmov rcx,[");
		strcat(tempMovVar,name);
		strcat(tempMovVar,"] ; variable\n");
		strcat(temp_condition,tempMovVar);
		if(check_while) strcat(temp_condition_while,tempMovVar);
		if(check_if) strcat(temp_condition_if,tempMovVar);
	}
}

void asm_mov_num(int val){
	char num[15];
	char tempMovNum[255];
	if(check_assign==1 && (check_condition != 2)){
		/* use store temp value of Number to register , use in op */
		sprintf(num,"%d",val);
		if(!flag_rdx){
			strcpy(tempMovNum,"\tmov rdx,");
			flag_rdx = 1;
		} 
		else {
			strcpy(tempMovNum,"\tmov rcx,");
		}
		strcat(tempMovNum,num);
		strcat(tempMovNum," ; number\n");
		strcat(temp_exp,tempMovNum);
	}
	if(check_condition == 2){
		/* store temp value of Number , use in condition */
		sprintf(num,"%d",val);
		strcpy(tempMovNum,"\tmov rdx,");
		strcat(tempMovNum,num);
		strcat(tempMovNum," ; number\n");
		strcat(temp_condition,tempMovNum);
		if(check_while) strcat(temp_condition_while,tempMovNum);
		if(check_if) strcat(temp_condition_if,tempMovNum);
	}
}

void asm_loop(){
	char temp_string[1024] = "\nLOOP_";
	int num_loop[2] , i;

	sprintf(num_loop,"%d",count_loop++);
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");
	/* LOOP_0: */

	strcat(temp_string,temp_condition_while);
	/* mov rcx,[i] ;a
	/* mov rdx,10 ;b
	/* a<b
	*/

	strcat(temp_string,"\tcmp rcx,rdx\n");
	strcat(temp_string,"\tje END_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");
	/*
		cmp rcx,rdx
		je END_LOOP_0 ;if(a<b) jump end loop
	*/

	strcat(temp_string,"\nSTATE_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n");
	strcat(temp_string,temp_state);
	/* statement */
	for(i=0 ; i<255 ; i++) temp_state[i] = 0;

	strcat(temp_string,"\tjmp LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,"\n");
	strcat(temp_string,"\nEND_LOOP_");
	strcat(temp_string,num_loop);
	strcat(temp_string,":\n\n");

	strcat(temp_string,"\tmov rax,0 ; reset\n");
	strcat(temp_string,"\tmov rcx,0 ;\n");
	strcat(temp_string,"\tmov rdx,0 ;\n\n");

	fprintf(file,temp_string);
	for(i=0 ; i<255 ; i++) temp_condition_while[i]= 0;

}

void asm_if(int condi){
	char temp_string[1024] = "STATE_IF_";
	int num_if[2] , i;
	int num_con[1];
	sprintf(num_if,"%d",count_if++);
	strcat(temp_string,num_if);
	strcat(temp_string,":\n");

	sprintf(num_con,"%d",condi);

	strcat(temp_string,temp_condition_if);

	strcat(temp_string,"\tcmp rcx,rdx\n");
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

	printf("%s\n",temp_string);
	strcat(temp_state,temp_string);

	//fprintf(file,temp_state);
	strcpy(temp_state,temp_string);
	//for(i=0 ; i<255 ; i++) temp_state[i] = 0;

	/* reset value */
	check_else = 0;
	check_condition = 0;
	for(i=0 ; i<255 ; i++) temp_condition_if[i]=0;

}

void asm_assign_var(char *name_var,int number){
	int i , flag=1;
	char temp_string[255];
	char temp[255];
	char num[15];

	for(i=0 ; i<=top ; i++){
		if(strcmp(name_var,myVar[i].name)==0){

			myVar[top].val = number;
			flag = 0;

			sprintf(num,"%d",number);
			strcpy(temp_string,"\t");
			strcat(temp_string,"mov rax,[");
			strcat(temp_string,name_var);
			strcat(temp_string,"]\n");
			strcat(temp_string,"\tadd rax,");
			strcat(temp_string,num);
			strcat(temp_string,"\n");
			strcat(temp_string,"\tmov [");
			strcat(temp_string,name_var);
			strcat(temp_string,"],rax\n\n");
			fprintf(file, temp_string);

			break;
		}
	}

	if(flag){
		sprintf(num,"%d",number);
		strcpy(temp_string,"\t");
		strcat(temp_string,name_var);
		strcpy(temp,":\tdq\t");
		strcat(temp_string,temp);
		strcat(temp_string,num);
		strcat(data,temp_string);
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

	if(check_else==0){
		strcat(temp_state,temp_str);
	}
	else strcat(temp_state_else,temp_str);
}

void asm_print_exp(int innum){

	char temp_str[255];
	char temp_string[255];
	strcpy(temp_str,"string_num");
	char num[15];
	sprintf(num, "%d", innum);

	strcpy(temp_string,"\tmov\trdi,");
	strcat(temp_string,temp_str);
	strcat(temp_string,"\n");
	strcat(temp_string,"\tmov\trsi,[");

	/* edit to num display value */
	strcat(temp_string,temp_namevar);
	strcat(temp_string,"]\n");

	strcat(temp_string,"\tmov\trax,0\n");
	strcat(temp_string,"\tcall printf\n");
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

	strcpy(temp2,",10,0\n");
	strcat(temp,temp2);

	strcat(data,temp);
}

void asm_print_init(){
	char temp[255];
	strcpy(data,"\n\nEXIT:\n\tpop rbp\n\tret\n\n");
	strcpy(temp,"section .data\n");
	strcat(data,temp);
	strcpy(temp,"\tstring_num: db \"%%d\",10,0\n");
	strcat(data,temp);
}


int main(void) {
printf(" < start\n");
	file = fopen("test.asm", "a");
	fprintf(file, "section .text\n");
	fprintf(file, "\textern printf\n");
	fprintf(file, "\tglobal main\n\n");
	fprintf(file, "main:\n");
	fprintf(file, "\tpush    rbp\n");
	fprintf(file, "\tmov rax,0 ; init\n");
	fprintf(file, "\tmov rcx,0 ;\n");
	fprintf(file, "\tmov rdx,0 ;\n");

	asm_print_init();

    yyparse();

    fprintf(file, data);
    fclose(file);
    return 0;
}
