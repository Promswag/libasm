global	ft_list_size

ft_list_size:
	; rdi = list ptr
	xor		rax, rax
	push	rdi
	test	rdi, rdi ; check rdi for 0
	jz		end
	
loop:
	inc		rax
	mov		rdi, [rdi + 8]
	test	rdi, rdi
	jnz		loop	
	
end:
	pop		rdi
	ret