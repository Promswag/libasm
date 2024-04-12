global	ft__list_remove_if
extern	free

ft__list_remove_if:
	; rdi = **begin_list
	; rsi = *data_ref
	; rdx = int (*cmp)()
	; rcx = void (*free_fct)(void *)
		
	test	rdi, rdi		; rdi tested for null
	jz		end
	cmp		QWORD [rdi], 0	; [rdi] tested for null
	je		end
	test	rdx, rdx		; rdx tested for null
	jz		end
	test	rcx, rcx		; rcx tested for null
	jz		end
	
	push	r12
	push	r13
	push	r14
	push	r15
	
	mov		r12, rdi
	mov		r13, rsi
	mov		r14, rdx
	mov		r15, rcx
	
	push	rcx
	push	rdx
	push	rsi
	push	rdi

	xor		rdx, rdx
	mov		rcx, [r12]
	; r12	= **begin_list
	; r13	= *data_ref
	; r14	= int (*cmp)()
	; r15	= void (*free_fct)(void *)
	
loop:
	test	rcx, rcx
	jz		restore
	mov		rdi, [rcx]
	mov		rsi, r13
	
	push	rdx
	push	rcx
	call	r14
	pop		rcx
	pop		rdx
	
	cmp		eax, 0
	je		remove
	
	mov		rdx, rcx		; rdx = prev
	mov		rcx, [rcx + 8]	; rcx = cur
	jmp		loop
	
restore:
	pop		rdi
	pop		rsi
	pop		rdx
	pop		rcx
	
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	
end:
	ret
remove:
	cmp		rdx, 0
	je		overwrite_begin
	
	mov		r9, [rcx + 8]	; cur->next
	mov		[rdx + 8], r9	; prev->next
	mov		r9, rcx
	mov		rcx, [rcx + 8]
	
	jmp		next
	
overwrite_begin:
	mov		r9, [rcx + 8]
	mov		[r12], r9		; overwrite *begin_list
	mov		r9, rcx
	mov		rcx, [r12]
	
next:
	push	rdx
	push	rcx
	
	push	r9
	mov		rdi, [r9]
	call	r15
	pop		r9
	
	mov		rdi, r9
	call	free WRT ..plt
	
	pop		rcx
	pop		rdx
	
	jmp		loop
	