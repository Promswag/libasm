global  ft_strcpy

ft_strcpy:
	xor     rax, rax				; zeroing rax
loop:
	cmp     BYTE [rsi + rax], 0		; cmp *(str + i) to 0
	je      end						; if 0 jmp to end
	mov     cl, [rsi + rax]			; cpy *(str + i) into cl (tmp)
	mov     [rdi + rax], cl			; cpy cl (tmp) into *(dest + i)
	inc     rax						; i++
	jmp     loop					; jmp to loop
end:
	mov     BYTE [rdi + rax], 0		; terminate dest by '\0'
	mov     rax, rdi				; cpy dest into rax
	ret