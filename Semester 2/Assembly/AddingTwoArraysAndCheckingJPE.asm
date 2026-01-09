.model small
.data
A db 1,2,3,4
B db 2,4,5,6
C db 4 dup(0)

.code 
mov ax, @data
mov ds, ax

mov si,0
mov cx,4

L1:
mov al, A[si]
add al, B[si]
mov C[si], al
jpe L2
inc si 
L2:
mov C[si],0
inc si

loop L1



.exit