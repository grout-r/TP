[BITS 64]
	
	global main
	extern printf

	section .text

main:
	push rbp
	mov rbp, rsp

	mov rdi, FormatStr
	call printf

	mov rsp, rbp
	pop rbp

	mov rax, 60
	xor rdi, rdi
	syscall

	ret

	section .rodata

	FormatStr db 'Hello World!',0Ah,0
