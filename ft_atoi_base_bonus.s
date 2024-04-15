global	ft_atoi_base
extern	ft_strlen

ft_atoi_base:
	; rdi str, rsi base
	; usable rax rcx rdx r8-r11
	; xor		rax, rax
	test	rsi, rsi	; check rsi for NULL
	jz		exit_error
	
	; Check if len is valid
	push	rdi
	mov		rdi, rsi
	call	ft_strlen
	cmp		rax, 2
	pop		rdi
	jl		exit_error
	
	; Check if base is valid
	call	base_validator	
	cmp		rax, 0
	je		exit_error
	
	; Whitespace Handler
	xor		rcx, rcx			; zeroing i
	call	whitespace_handler
	
	; Sign Handler
	mov		rdx, 1				; init sign to 1 (*1, *-1)
	call	sign_handler
	
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
	
	push	rdi
	mov		rdi, rsi
	call	ft_strlen
	mov		r8, rax;				; Put size of base in r8
	pop		rdi
	
	push	rdx						; store sign
	xor		rax, rax				; result = 0

converter_outer_loop:
	xor		r9, r9					; reset j
	xor		r10, r10				; reset is_in_base
	
converter_inner_loop:
	mov		r11b, [rdi + rcx]		; cpy *(str + i) into low 8 bit registery r11b
	cmp		r11b, [rsi + r9]		; cmp *(str + i) to *(base + j)
	jne		converter_end_loop
	
converter_operation:
	mul		r8						; result *= size
	add		rax, r9					; result += j
	mov		r10, 1					; is_in_base = true
	jmp		converter_end_loop

converter_end_loop:
	inc		r9						; j++
	cmp		BYTE [rsi + r9], 0		; cmp *(base + j) to 0
	jne		converter_inner_loop 	;

	cmp		r10, 0					; if is_inbase == false
	je		end						; jmp to end
	
	inc		rcx						; i++;
	cmp		BYTE [rdi + rcx], 0		; cmp *(str + i) to 0
	jne		converter_outer_loop	
	
end:
	pop		rdx						; restore sign
	mul		rdx						; result *= sign
	ret
	
exit_error:
	xor		rax, rax
	ret

base_validator:
	xor		rax, rax				; zeroing rax, base invalid
	xor		r8, r8					; i
	xor		r9, r9					; j
	xor		r10, r10				; count
	
base_validator_outer_loop:
	cmp		BYTE [rsi + r8], '+'
	je		base_validator_end
	cmp		BYTE [rsi + r8], '-'
	je		base_validator_end
	cmp		BYTE [rsi + r8], 9
	je		base_validator_end
	cmp		BYTE [rsi + r8], 10
	je		base_validator_end
	cmp		BYTE [rsi + r8], 11
	je		base_validator_end
	cmp		BYTE [rsi + r8], 12
	je		base_validator_end
	cmp		BYTE [rsi + r8], 13
	je		base_validator_end
	cmp		BYTE [rsi + r8], 32
	je		base_validator_end
	xor		r9, r9						; reset j
	xor		r10, r10					; reset count
	
base_validator_inner_loop:
	mov		r12b, [rsi + r8]			; cpy *(base + i) into low 8 bit registery r12b
	cmp		r12b, [rsi + r9]			; cmp with *(base + j)
	jne		base_validator_loop_end		; if not equal, skips count++
	inc		r10							; count++

base_validator_loop_end:	
	cmp		r10, 1						; cmp count with 1
	jg		base_validator_end			; if more than 1, means doublons
	
	inc		r9							; j++
	cmp		BYTE [rsi + r9], 0			; cmp *(base + j) to 0
	jne		base_validator_inner_loop	; if not 0, jmp inner_loop
	
	inc		r8							; i++
	cmp		BYTE [rsi + r8], 0			; cmp *(base + i) to 0
	jne		base_validator_outer_loop	; if not 0, jmp outer_loop

	mov		rax, 1						; base is valid

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
	inc		rcx				; i++
	jmp		whitespace_handler
	
sign_handler:
	cmp		BYTE [rdi + rcx], '-'
	je		sign_handler_loop_minus
	cmp		BYTE [rdi + rcx], '+'
	je		sign_handler_loop_plus
	ret

sign_handler_loop_minus:
	inc		rcx				; i++
	neg		rdx				; rdx *= -1
	jmp		sign_handler
	
sign_handler_loop_plus:
	inc		rcx				; i++
	jmp		sign_handler