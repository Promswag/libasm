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
	cmp		rax, 0
	je		end
	mov		rdi, rax
	call	ft__strcpy
	ret	
end:
	ret
