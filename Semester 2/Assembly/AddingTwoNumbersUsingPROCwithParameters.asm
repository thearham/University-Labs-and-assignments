.model small
.stack 100h

.data

.code
Main proc
Mov ax,@data
mov ds,ax

mov ax,5
mov bx,10

push ax
push bx

call Addition

pop bx
pop bx
.exit
Main endp
Addition proc
    push bp
    
    mov bp,sp
    
    mov ax,0
    Add ax, [bp+6]
    Add ax,[bp+4]
    
    pop bp
    
    ret 
    Addition endp

