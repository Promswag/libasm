global	ft__atoi_base
extern	ft__strlen

ft__atoi_base:
	; rdi str, rsi base
	; usable rax rcx rdx r8-r11
	
	# Check if len is valid 
	push	rdi
	mov		rdi, rsi
	call	ft__strlen
	cmp		rax, 2
	pop		rdi
	jl		exit_error
	
	# Check if base is valid
	call	base_validator	
	cmp		rax, 0
	je		exit_error
	
	# Whitespace Handler
	xor		rcx, rcx
	call	whitespace_handler
	
	# Sign Handler
	xor		rdx, rdx
	call	sign_handler
	
converter: 
	; rax = result
	; rdi = str
	; rsi = base
	; rcx = i
	; rdx = sign
	; r8 = j
	; r9 = size
	; r10 = is_in_base
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	
	# Put size of ( str + i ) in r9
	push	rdi
	lea		rdi, [rdi + rcx]
	call	ft__strlen
	mov		r9, rax
	pop		rdi
	
	xor		rax, rax

	
exit_error:
	xor		rax, rax
	ret

base_validator:
	xor		rax, rax
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	
base_validator_outer_loop:
	cmp		BYTE [rsi + r8], '+'
	je		base_validator_end
	cmp		BYTE [rsi + r8], '-'
	je		base_validator_end
	xor		r9, r9
	xor		r10, r10
	
base_validator_inner_loop:
	mov		r12b, [rsi + r8]
	cmp		r12b, [rsi + r9]
	jne		base_validator_loop_end
	inc		r10

base_validator_loop_end:	
	cmp		r10, 1
	jg		base_validator_end
	
	inc		r9
	cmp		BYTE [rsi + r9], 0
	jne		base_validator_inner_loop
	
	inc		r8
	cmp		BYTE [rsi + r8], 0
	jne		base_validator_outer_loop
	
	mov		rax, 1

base_validator_end:
	ret
	
whitespace_handler:
	cmp		[rdi + rcx], ' '
	je		whitespace_handler_loop
	cmp		[rdi + rcx], '\f'
	je		whitespace_handler_loop
	cmp		[rdi + rcx], '\n'
	je		whitespace_handler_loop
	cmp		[rdi + rcx], '\r'
	je		whitespace_handler_loop
	cmp		[rdi + rcx], '\t'
	je		whitespace_handler_loop
	cmp		[rdi + rcx], '\v'
	je		whitespace_handler_loop
	ret

whitespace_handler_loop
	inc		rcx
	jmp		whitespace_handler
	
sign_handler:
	cmp		[rdi + rcx], '-'
	je		sign_handler_loop_minus
	cmp		[rdi + rcx], '+'
	je		sign_handler_loop_plus

sign_handler_loop_minus:
	inc		rcx
	neg		rdx
	jmp		sign_handler
	
sign_handler_loop_plus:
	inc		rcx
	jmp		sign_handler