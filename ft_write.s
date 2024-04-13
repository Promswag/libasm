global	ft_write
extern	__errno_location

ft_write:
	; test	rsi, rsi
	; jz		error_null
	mov		rax, 1
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
	
; error_null:
; 	mov		rdi, 17
; 	call	__errno_location WRT ..plt
; 	mov		[rax], rdi
; 	mov		rax, -1
; 	ret