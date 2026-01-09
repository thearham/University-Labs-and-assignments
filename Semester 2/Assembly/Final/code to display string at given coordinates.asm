.model small
.stack 100h
.data
msg db "Arham Azam", 0
x dw 12
y dw 39

.code
mov ax, @data
mov ds, ax

mov ax, 0xb800
mov es, ax

mov bx, offset msg
push bx  

call print

pop bx


.exit

print proc
    push bp
    push si
    push cx  
    
    call location 
    mov si, ax
    mov bx, sp
    mov bx, bx+8
    
    mov di, 0
    
display:
    mov al, [bx+di]
    cmp al,0
    je end
    
    mov es:[si], al
    add si, 2
    inc di
    jmp display
end:
    pop bp
    pop si
    pop cx      
    ret
print endp

location proc
    mov ax, [x]
    mov dx, 80
    mul dx
    
    mov dx, 2
    mul dx
    
    mov bx, ax
    
    mov ax, [y]
    mov dx, 2
    mul dx
    
    add ax, bx
    
    ret
location endp
    
    