global	ft__write

ft__write:
	mov		rax, 1
	syscall
	test	rax, rax
	js		error
	ret
	
error:
	mov		rax, -1
	ret