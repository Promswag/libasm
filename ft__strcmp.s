global ft__strcpy

ft__strcpy:
    xor rax, rax
    
loop:
    cmp BYTE [rsi + rax], 0
    je end
    mov rcx, [rsi + rax]
    mov [rdi + rax], rcx
    inc rax
    jmp loop
    
end:
    mov BYTE [rdi + rax], 0
    mov rax, rdi
    mov rcx, 0
    ret