.model small
.data
A db 'Hello World$'
.code
mov ax, @data
mov ds, ax

mov dx, offset A
mov ah, 0x9
int 0x21


mov al,0
mov bh, 0x40
mov cx, 0
mov dh, 24
mov dl, 79
mov ah, 0x6
int 0x10
.exit