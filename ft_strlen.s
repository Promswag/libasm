global	ft_strlen

ft_strlen:
	xor		rax, rax				; clear content of rax

loop:
	cmp		BYTE [rdi + rax], 0		; compare current byte to 0
	je		end						; if 0 jmp to end
	inc		rax						; else increment rax
	jmp		loop					; jmp to loop

end:
	ret 