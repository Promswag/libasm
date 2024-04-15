global	ft_write
extern	__errno_location

ft_write:
	mov		rax, 1						; 1 = write
	syscall								; syscall, rdi = fd, rsi = str, rdx = len
	test	rax, rax					; test return
	jns		end							; if not signed jmp to end
	neg		rax							; get absolute of rax
	mov		rdi, rax					; cpy rax into rdi
	call	__errno_location WRT ..plt	; call errno
	mov		[rax], rdi					; cpy rdi into memory of rax
	mov		rax, -1						; cpy -1 into rax
end:
	ret