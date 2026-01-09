.model small
.stack 100h
.data

.code 

mov ax, @data
mov ds, ax

mov ax,0
mov es, ax

mov word ptr es:[384], isr96
mov word ptr es:[386], cs

mov ah, 0x1
int 0x60

mov ah, 0x2
int 0x60

mov ah, 0x0
int 0x60
hlt
.exit   

isr96 proc
    jmp start
    var db 0
    start:
    cmp ah, 0x0
    je clear
    cmp ah, 0x1
    je input
    cmp ah, 0x2
    je display
    
    clear:
    mov al, 0
    mov bh, 0x7
    mov ch, 0
    mov cl, 0
    mov dh, 24
    mov dl, 79
    mov ah, 0x6
    int 0x10
    jmp end
    
    input:
    mov ah, 0x1
    int 0x21
    mov [var], al
    jmp end
    
    display:
    mov dl, [var]
    mov ah, 0x2
    int 0x21
    jmp end
    
    end:
    iret
    isr96 endp
    
    