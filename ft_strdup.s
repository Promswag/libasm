global	ft_strdup
extern	ft_strlen
extern	ft_strcpy
extern	malloc

ft_strdup:
	call	ft_strlen
	add		rax, 1
	push	rdi
	mov		rdi, rax
	call	malloc WRT ..plt
	pop		rsi
	cmp		rax, 0
	je		end
	mov		rdi, rax
	call	ft_strcpy
	ret	
end:
	ret
