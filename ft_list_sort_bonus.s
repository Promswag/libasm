global	ft_list_sort
ft_list_sort:
	; rdi = t_list **begin_list
	; rsi = int (*cmp)()
	test	rdi, rdi		; rdi tested for null
	jz		return
	cmp		QWORD [rdi], 0	; [rdi] tested for null
	je		return
	test	rsi, rsi		; rsi tested for null
	jz		return
	push	rdi
	push	rsi
	push	r12
	push	r13
	push	r14
	push	r15
	mov		r12, rdi		; **begin_list stored in r12
	mov		r13, rsi		; function ptr stored in r13
loop_reset:
	; rdi	= arg 1 and tmp for swap
	; rsi	= arg 2 and tmp for swap
	; r12	= **begin_list
	; r13	= function ptr
	; r14	= cur
	; r15	= next
	mov		r14, [r12]		; r14 = *begin_list
loop:
	mov		r15, [r14 + 8]	; r15 = cur->next
	test	r15, r15		; r15 tested for 0
	jz		restore
	mov		rdi, [r14]		; rdi = cur->data
	mov		rsi, [r15]		; rsi = next->data
	call	r13				; call the function ptr
	cmp		eax, 0			; eax (32 bits) compared to 0
	jg		swap
	mov		r14, r15 ; cur = cur->next
	jmp		loop
restore:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rsi
	pop		rdi
return:
	ret
swap:
	mov		rdi, [r14]
	mov		rsi, [r15]
	mov		[r14], rsi
	mov		[r15], rdi
	jmp		loop_reset