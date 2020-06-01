public input_number

dseg segment para public 'data'
	ent db ">>$"
	empty_line db 10, 13, '$'
	error db "incorrect nubmer$"
	buff db 100 DUP('$')
dseg ends

cseg segment para public 'code'
	assume CS:cseg, DS: dseg
	
input_number proc far
	mov ah, 09
	mov dx, offset empty_line
	int 21h
	
	mov ah, 09
	mov dx, offset ent
	int 21h
	
	mov ah, 0ah
	xor di, di
	mov dx, offset buff;
	int 21h
	
	mov dl, 0ah
	mov ah, 02
	int 21h
	
	mov si,offset buff+2 
label_1:
	xor ax, ax
	mov bx, 8
check:
	mov cl, [si]
	cmp cl, 0dh
	jz endin
	
	cmp cl,'0'
    jb er
    cmp cl,'7'
    ja er
	
	sub cl,'0'
    mul bx    
    add ax,cx  
	inc si
    jmp check
	
er:
    mov dx, offset error
    mov ah,09
    int 21h
	ret

endin:
	ret
input_number endp

cseg ends
end

