global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc

ft_strdup:
	call	ft_strlen			; call strlen, rdi = str
	add		rax, 1				; add 1 into rax for trailing 0
	push	rdi					; store str on the stack
	mov		rdi, rax			; cpy len into rdi
	call	malloc WRT ..plt	; call malloc, rdi = len
	pop		rsi					; pop str from the stack into rsi
	cmp		rax, 0				; check if malloc failed
	je		end					; if 0 then jmp to end
	mov		rdi, rax			; cpy mem_ptr into rdi
	call	ft_strcpy			; call strcpy, rdi = mem_ptr, rsi = str
end:
	ret
