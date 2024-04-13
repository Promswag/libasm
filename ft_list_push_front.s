global	ft_list_push_front
extern	malloc

ft_list_push_front:
	; rdi = list ptr ptr
	; rsi = data ptr
	test	rdi, rdi
	jz		end
	
	push	rdi
	push	rsi
	mov		rdi, 16
	call	malloc WRT ..plt
	pop		rsi
	pop		rdi

	test	rax, rax
	jz		end
	
	mov		[rax], rsi
	mov		rdx, [rdi]
	mov		[rax + 8], rdx
	mov		[rdi], rax
	
end:
	ret