global	ft__strdup
extern	ft__strlen
extern	ft__strcpy
extern	malloc

ft__strdup:
	call	ft__strlen
	add		rax, 1
	push	rdi
	mov		rdi, rax
	call	malloc WRT ..plt
	pop		rsi
	mov		rdi, rax
	call	ft__strcpy
	ret
