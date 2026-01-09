.model small 
.data 
array db 1,2,3,4,5
MaxNum db 0

.code

Main proc
    mov ax,@data
    mov ds,ax
    
    mov ax, offset array
    mov bx, 5
    mov bp, offset MaxNum
    
    push bp
    push bx
    push ax
    
    call LargestNumber
    
    pop bp
    pop bx
    pop ax
    .exit
    Main endp
LargestNumber proc
    push bp
    push si
    push cx
    
    mov bp,sp
    mov cx,[bp+10]
    mov bx, [bp+12]
    mov ax, [bp+8]
    mov bp,ax
    mov si,0
    
    Loop1:
    start:
    mov al, ds:[bp+si]
    mov dl, ds:[bp+si+1]
    cmp al, dl
    ja Max
    
    
    inc si
    Loop Loop1
    Max:
    mov ds:[bx], al
    
    
    pop cx
    pop si
    pop bp
    
    ret
    LargestNumber endp