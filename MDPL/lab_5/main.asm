extern input_number: far
extern toHex: near
extern toBin: near
public number

sseg  SEGMENT PARA STACK 'STACK'
	DB	200h DUP (?)
sseg  ENDS

dseg segment para public 'data'
		number dw 1
		answer db 0
		menu	db	'MENU:', 10, 13
		db	'   1. Input number', 10, 13
		db	'   2. Output number in 16 unsigned', 10, 13
		db	'   3. Output number in 2 signed', 10, 13
		db	'   4. Exit', 10, 13, '$'
		
		ent	db	'--> $'
		empty_line db	10, 13, '$'
dseg ends

cseg segment para public 'code'
	assume cs: cseg, ds: dseg, ss:sseg
main:
	mov ax, dseg
	mov ds, ax
	
	call controller
	
	mov ax, 4C00h
    int 21h
	

controller proc

	;Menu output in Console
print_menu:
	mov  ah, 9
	mov  dx, offset empty_line
	int  21h
	
	mov  ah, 9
	mov  dx, offset menu
	int  21h
	
	mov  ah, 9
	mov  dx, offset empty_line
	int  21h

	mov  ah, 9
	mov  dx, offset ent
	int  21h
	;Do a Switch Case implementation in Assembler Language
Input_answer:	
	mov ah, 01h
	int 21h
	mov answer, al
	
	mov al, '1'
	cmp al, answer
	je in_number
	
	mov al, '2'
	cmp al, answer
	je toHex_number
	
	mov al, '3'
	cmp al, answer
	je toBin_number
	
	mov al, '4'
	cmp al, answer
	je quit
	
	jmp Input_answer


quit:
	ret
in_number:
	call input_number
	mov number, ax
	;call OutInt
	jmp print_menu

toHex_number:
	mov  ah, 9
	mov  dx, offset empty_line
	int  21h
	
	call toHex
	jmp print_menu

toBin_number:
	mov  ah, 9
	mov  dx, offset empty_line
	int  21h
	
	call toBin
	jmp print_menu
	
controller endp

OutInt proc
    aam 
    add ax,3030h 
    mov dl,ah 
    mov dh,al 
    mov ah,02 
    int 21h 
    mov dl,dh 
    int 21h
	ret
OutInt endp

cseg ends
end main