.model small
.stack 100h
.data

A dw 10,9,8,7,6,5,4,3,2,1
Min dw 0

.code
Main proc
    Mov ax,@data
    mov ds,ax
    mov ax,[A]
    mov dx, 9
    call  sort 
    .exit
    Main endp 

sort proc 
    mov si,0
    
    Iteration:
    mov cx,dx
    mov di,si
    mov ax, [A+si]
    mov [Min], ax
    mov bx,di
    
    l1:
    Add di,2
    mov ax, [A+di]
    cmp [Min], ax
    jb notgreater
    mov [min],ax
    mov bx,di
    
    notgreater:
    loop l1
    
    mov ax, [A+si]
    mov [A+bx], ax
    mov ax, [min]
    mov [A+si],ax
    add si,2
    sub dx,1
    cmp si,18
    jne Iteration
    
    ret
    sort endp