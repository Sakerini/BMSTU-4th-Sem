public toBin
extern number: word

cseg segment para public 'code'
	assume CS:cseg
	
toBin proc near
	mov ax, number

    push ax  
    shl ax,1 
              
    pop ax
    jnc pos   

    mov cx, ax
    mov     ah, 02h
    mov     dl, '-'
    int     21h
    mov ax, cx
    neg     ax

pos:  
    xor     cx, cx 
    mov     bx, 2 
mloop:
    xor     dx,dx
    div     bx
    push    dx  
    inc     cx
    cmp     ax, 0
    jne     mloop 
    mov     ah, 02h
print:
    pop     dx
    add     dl, '0'
    int     21h
    loop    print
    ret
	
toBin endp

cseg ends
end