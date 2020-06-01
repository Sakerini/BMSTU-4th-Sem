.286
.model tiny  
.code
org     100h

start:  
        jmp load

decode  proc
        db 0D4h,10h
        add ax,'00'

        mov word ptr es:[di],0E00h+":"
        mov es:[di+2],ah
        mov byte ptr es:[di+3],0Fh    
        mov es:[di+4],al
        mov byte ptr es:[di+5],0Fh 

        
        add di,6
        ret           
decode  endp          

clock   proc          
        push es       
     	pusha
        

		push 0B800h  
        pop es       
        mov di,130    
		
get_time:   
        mov ah,2            
        int 1Ah                 
        mov al,ch           
        call decode               
        mov al,cl           
        call decode             
        mov al,dh          
        call   decode  
  	

    	popa
        pop es       
        
        db 0EAh
                     
        old_int_1Ch dd 0

clock   endp

load:   
    	mov ax,3      
    	int 10h       

    	mov ax,351Ch  
        int 21h       


    	mov word ptr old_int_1Ch,bx
        mov word ptr old_int_1Ch+2,es

        mov ax,251Ch  
        mov dx,offset clock
        int 21h
	
        mov ax,3100h  
        mov dx,(load - start + 10Fh)/16
        int 21h
end start   