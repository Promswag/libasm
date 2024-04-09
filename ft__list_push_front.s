global	ft__list_push_front
extern	malloc


ft__list_push_front:
	; rdi = list ptr ptr
	; rsi = data ptr
	push	rdi
	mov		rdi, 16
	call	malloc WRT ..plt
	pop		rdi

	cmp		rax, 0
	je		end
	
	mov		[rax], rsi
	mov		rdx, [rdi]
	mov		[rax + 8], rdx
	mov		[rdi], rax
	
end:
	ret
	