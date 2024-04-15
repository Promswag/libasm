global	ft_read
extern	__errno_location

ft_read:
	mov		rax, 0						; 0 = read
	syscall								; syscall, rdi = fd, rsi = buf, rdx = size
	test	rax, rax					; rest return
	jns		end							; if not signed jmp to end
	neg		rax							; get absolue of rax
	mov		rdi, rax					; cpy rax into rdi
	call	__errno_location WRT ..plt	; call errno
	mov		[rax], rdi					; cpy rdi into memory of rax
	mov		rax, -1						; cpy -1 into rax
end
	ret