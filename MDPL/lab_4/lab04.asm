stk segment stack
        db 200h dup (0)
stk ends

data segment
        n db 0
        m db 0
		max_sum db 0
        matrix db 81 dup (?)
        string1 db 13, 10, 'Enter number of rows:   $'
        string2 db 13, 10, 'Enter number of columns:  $'
        string3 db 13, 10, 'Enter elements of matrix:  $'
		string4 db 13, 10, 'Matrix:   $'
        newline db 13, 10, '$'
data ends

code segment
assume cs: code, ds: data, ss:stk
main:

	mov ax, data
	mov ds, ax
	
	call read_matrix
	call delete_max_row
	call output
	
	mov ax, 4C00h
    int 21h

read_matrix proc
	mov ah, 09h
	mov dx, offset string1
	int 21h

	mov ah, 01h
	int 21h

	sub al, 30h
	mov n, al
	
	mov ah, 09h
	mov dx, offset string2
	int 21h

	mov ah, 01h
	int 21h

	sub al, 30h
	mov m, al
	
	mov ah, 09h
	mov dx, offset string3
    int 21h
   
    mov al, n
    mov bl, m
    mul bl
    mov cx, ax

input_matrix:
   mov ah,01h                      
   int 21h
   
   mov matrix[si], al
   inc si
   
   mov ah,01h                      
   int 21h

   loop input_matrix
   
   ret
read_matrix endp

delete_max_row proc

	mov si, 0
    mov cx, 0
    mov cl, n
loop_mtr1:
   mov bx, cx
   mov cx, 0
   mov cl, m
   mov dl, 0
loop_mtr2:

   sub matrix[si], 30h
   
   add dl, matrix[si]

   inc si
   loop loop_mtr2
   
   ;compare
   cmp dl, max_sum
   jl skip_update
max_sum_update:
	mov max_sum, dl
	mov di, si
skip_update:
   mov dl, 0
   mov cx, bx
   loop loop_mtr1
   
   mov ax, di
   mov bl, m
   div bl
   
   inc di
   mov si, di
   mov ax, 0
   mov al, m
   sub di, ax ; nastroil di nachalo stroka
   
   mov cx, 0
   mov cl, al
   ;sub cl, al
row_loop:
    mov bx, cx
	mov cx, 0
	mov cl, m
col_loop:
	mov ax, 0
	dec si
	mov al, matrix[si]
	inc si
	dec di
	mov matrix[di], al
	inc di
	inc si
	inc di
	loop col_loop
	mov cx, bx
	loop row_loop
   
    ret
	
delete_max_row endp

output proc
   mov ah, 09h
   mov dx, offset string4
   int 21h

   mov ah, 09h
   mov dx, offset newline
   int 21h  

   mov si, 0
   mov cx, 0
   sub n, 1
   mov cl, n
   
loop1:
   mov bx, cx
   mov cx, 0
   mov cl, m
loop2:
   mov ah, 02h
   mov dl, matrix[si]
   add dl, 30h
   int 21h

   mov ah, 02h
   mov dl, ' '
   int 21h

   inc si
   loop loop2

   mov ah, 09h
   mov dx, offset newline
   int 21h

   mov cx, bx
   loop loop1
   
   ret
output endp

code ends
end main