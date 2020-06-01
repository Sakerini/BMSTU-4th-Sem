public toHex
extern number: word

cseg segment para public 'code'
	assume CS:cseg
	
toHex proc near
	mov ax, number     
    xor cx, cx 
    mov bx, 16
label_2:
    xor dx,dx
    div bx


    push dx
    inc cx
	
    test ax, ax
    jnz label_2

    mov ah, 02h
label_3:
    pop dx

   cmp dl, 9
   jbe label_4
   add dl, 7
label_4:
    add dl, '0'
    int 21h

    loop label_3
    
	ret
toHex endp

cseg ends
end