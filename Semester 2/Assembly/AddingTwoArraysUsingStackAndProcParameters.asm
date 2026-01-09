.model small
.stack 100h
.data
A db 1,2,3,4,5
.code
Main proc
    mov ax,@data
    mov ds,ax
    
    mov bx,offset A
    mov ax,5
    
    push bx
    push ax
    
    call AddArray
    
    pop bx
    pop bx
    .exit
    Main endp

AddArray proc
    push bp
    push cx
    push si
    
    mov bp,sp
    mov cx, [bp+8]
    mov ax, [bp+10]
    mov bp,ax
    mov ax,0
    mov si,0
    
    L1:
    Add al, ds:[bp+si]
    inc si
    loop L1
    
    pop si
    pop cx
    pop si
    
    ret 
    AddArray endp