global ft__strcmp

ft__strcmp:
    xor rcx, rcx
    
loop:
    movzx rax, BYTE [rdi + rcx]
    movzx rdx, BYTE [rsi + rcx]
    cmp rax, rdx
    je if_equal

end:
    sub rax, rdx 
    ret
    
if_equal:
    cmp rdx, 0
    je end
    inc rcx
    jmp loop
    