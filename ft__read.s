global	ft__read
extern	__errno_location

ft__read:
	mov		rax, 0
	syscall
	test	rax, rax
	js		error
	ret

error:
	neg		rax
	mov		rdi, rax
	call	__errno_location WRT ..plt
	mov		[rax], rdi
	mov		rax, -1
	ret