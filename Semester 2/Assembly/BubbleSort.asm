.model small
.stack 100h
.data
A dw 9,8,7,6,5,4,3,2,1,0
swap db 0

.code
mov ax,@data
mov ds,ax

start:
    mov bx,0
    mov [swap], 0
loop1:
    mov ax, [A+bx]
    cmp ax, [A+bx+2]
    jbe noswap
    
    mov dx, [A+bx+2]
    mov [A+bx+2], ax
    mov [A+bx], dx
    mov [swap],1
    
noswap:
    add bx,2
    cmp bx,18
    jne loop1
    
    cmp [swap],1
    je start
     
    
.exit
       