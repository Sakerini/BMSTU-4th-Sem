.globl my_str_cpy
.intel_syntax noprefix
.text

my_str_cpy:
    mov rcx, rdx

    cmp rdi, rsi
    jne not_equal
    jmp quit

not_equal:
    cmp rdi, rsi
    cld
    jl copy

    add rsi, rdx
    dec rsi
    add rdi, rdx
    dec rdi
    std
    
copy:
    rep movsb
    cld
quit:
    ret
