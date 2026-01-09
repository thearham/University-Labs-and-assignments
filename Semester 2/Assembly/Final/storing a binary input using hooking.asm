.model small
.stack 100h
.data

.code
mov ax, @data
mov ds, ax

mov ax,0
mov es,ax 

mov word ptr es:[404], isr101
mov word ptr es:[406], cs

int 0x65

hlt
.exit

isr101 proc
    mov cx, 16 
    mov bx, 1111111111111111b
   
    
    loop1:
    call input
    sub al, 30h
    cmp al, 0 
    je shift
    cmp al, 1
    je rotate 
    loop loop1
    
    shift:
    shl bx, 1
    loop loop1
    jmp end
    
    rotate:
    rol bx,1
    loop loop1
    
    end:
    mov ax,bx 
    
    iret
isr101 endp

input proc
    mov ah, 0x1
    int 0x21
    ret
input endp