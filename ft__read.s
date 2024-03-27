global	ft__read

ft__read:
	mov		rax, 0
	syscall
	test	rax, rax
	js		error
	ret

error:
	mov		rax, -1
	ret