section .text
	extern printf
	global main

main:
	push    rbp
	mov rax,0 ; init
	mov r8,-1 ;
		;div
	mov rax,8
	mov r10,2
	mov rdx,0
	idiv dword r10
		;push
	add r8,1
	mov [array+8*r8],rax
	mov r9,[array+8*r8]
	sub r8,1
	mov [x],r9
	mov	rdi,string_num
	mov	rsi,[x]
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
	x:	dq	11
