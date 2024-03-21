global ft__strlen

ft__strlen:
	xor rax, rax

loop:
	cmp BYTE [rdi + rax], 0
	je end
	inc rax
	jmp loop

end:	
	ret