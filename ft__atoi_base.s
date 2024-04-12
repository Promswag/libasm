global	ft__atoi_base
extern	ft__strlen

ft__atoi_base:
	; rdi str, rsi base
	; usable rax rcx rdx r8-r11
	
	test	rsi, rsi	; check rsi for NULL
	jz		exit_error
	
	; Check if len is valid
	push	rdi
	mov		rdi, rsi
	call	ft__strlen
	cmp		rax, 2
	pop		rdi
	jl		exit_error
	
	; Check if base is valid
	call	base_validator	
	cmp		rax, 0
	je		exit_error
	
	; Whitespace Handler
	xor		rcx, rcx
	call	whitespace_handler
	
	; Sign Handler
	mov		rdx, 1
	call	sign_handler
	
	; Start A to I
	jmp		converter
	
converter: 
	; rax = result
	; rdi = str
	; rsi = base
	; rcx = i
	; rdx = sign
	; r8 = size
	; r9 = j
	; r10 = is_in_base
	; r11 = tmp
	
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	
	; Put size of base in r8
	push	rdi
	mov		rdi, rsi
	call	ft__strlen
	mov		r8, rax
	pop		rdi
	
	push	rdx
	xor		rax, rax

converter_outer_loop:
	xor		r9, r9
	xor		r10, r10
	
converter_inner_loop:
	mov		r11b, [rdi + rcx]
	cmp		r11b, [rsi + r9]
	jne		converter_end_loop
	jmp		converter_operation
	
converter_operation:
	mul		r8
	add		rax, r9
	mov		r10, 1
	jmp		converter_end_loop

converter_end_loop:
	inc		r9
	cmp		BYTE [rsi + r9], 0
	jne		converter_inner_loop 

	cmp		r10, 0
	je		end
	
	inc		rcx
	cmp		BYTE [rdi + rcx], 0
	jne		converter_outer_loop
	
	jmp		end
	
end:
	pop		rdx
	mul		rdx
	ret
	
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
	cmp		BYTE [rdi + rcx], 9
	je		whitespace_handler_loop
	cmp		BYTE [rdi + rcx], 10
	je		whitespace_handler_loop
	cmp		BYTE [rdi + rcx], 11
	je		whitespace_handler_loop
	cmp		BYTE [rdi + rcx], 12
	je		whitespace_handler_loop
	cmp		BYTE [rdi + rcx], 13
	je		whitespace_handler_loop
	cmp		BYTE [rdi + rcx], 32
	je		whitespace_handler_loop
	ret

whitespace_handler_loop:
	inc		rcx
	jmp		whitespace_handler
	
sign_handler:
	cmp		BYTE [rdi + rcx], '-'
	je		sign_handler_loop_minus
	cmp		BYTE [rdi + rcx], '+'
	je		sign_handler_loop_plus
	ret

sign_handler_loop_minus:
	inc		rcx
	neg		rdx
	jmp		sign_handler
	
sign_handler_loop_plus:
	inc		rcx
	jmp		sign_handler