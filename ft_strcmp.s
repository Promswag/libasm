global  ft_strcmp

ft_strcmp:
	xor		rcx, rcx				; zeroing rcx
loop:
	movzx	rax, BYTE [rdi + rcx]	; cpy *(s1 + i) into rax
	movzx	rdx, BYTE [rsi + rcx]	; cpy *(s2 + i) into rdx
	cmp		rax, rdx				; cmp rax to rdx
	je		if_equal				; if equal jmp to if_equal
end:
	sub		rax, rdx 				; rax -= rdx
	ret
if_equal:
	cmp		rdx, 0					; cmp rdx to 0
	je		end						; if 0 jmp to end
	inc		rcx						; i++
	jmp		loop					; jmp to loop
	