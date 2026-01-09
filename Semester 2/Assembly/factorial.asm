.model small
.stack 100h
.data 
b dw 5 
c dw 0
.code



mov ax,@data
mov ds,ax
mov ax,[b]
mov cx,ax
dec cx
l1:
mul cx
loop l1
mov [c],ax
.exit