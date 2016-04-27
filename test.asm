section .text
	extern printf
	global main

main:
	push    rbp
	mov rax,0 ; init
	mov r8,-1 ;
	mov	rdi,string_0
	mov	rsi,string_0
	mov	rax,0
	call printf
	mov r8,-1 ;
	mov	rdi,string_1
	mov	rsi,string_1
	mov	rax,0
	call printf
	mov r8,-1 ;


EXIT:
	pop rbp
	ret

section .data
	string_num: db "%d",0,0
	string_num_newline: db "%d",10,0
	string_hex: db "0x%x",0,0
	string_hex_newline: db "0x%x",10,0
	array :	dq	1,2,3,4,5
	string_0: db "aasdjfkljasdlkjfoijioweje",0,0
	string_1: db "a1231123",0,0
