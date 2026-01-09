.model small
.stack 100h
.data
A db 2,2,3,3,1
B db 1,1,3,0,2
C db 5 dup(0)

.code
Main proc
    mov ax,@data
    mov ds,ax
    
    mov bx, offset C
    mov di, offset B
    mov si, offset A
    mov ax,5
    
    push ax
    push si
    push di
    push bx
    
    call SumArrays
    pop bx
    pop di
    pop si
    pop ax
    .exit
    Main endp
SumArrays proc
    
    
    push bp
    push cx
    
    
    
    mov bp,sp
    mov cx, [bp+12]
    mov si, [bp+10]
    mov di,[bp+8]
    mov bx, [bp+6]
    mov ax,0
    
    
    L1:
    mov al, [si]
    add al, [di]
    mov [bx], al
    add si,1
    add di,1
    add bx,1
    loop L1
    
    pop cx
    pop bp
    
    
    ret
    SumArrays endp
    