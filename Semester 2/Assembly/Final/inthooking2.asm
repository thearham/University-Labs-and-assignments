.model small
.data
msg db "arham azam$"
.code

mov ax, @data
mov ds, ax

mov ax, 0
mov es, ax

mov word ptr es:[384], isr96
mov word ptr es:[386], cs

mov dx, offset msg
mov ah, 0x1
int 0x60




.exit

isr96 proc
    cmp ah, 0x0
    je clear
    
    cmp ah, 0x1
    je display
    
    clear:
    mov al, 0x0
    mov bh, 0x7
    mov ch, 0
    mov cl, 0
    mov dh, 24
    mov dl, 79
    mov ah, 0x6
    int 0x10
    jmp end
    
    display: 
    mov ah, 0x9
    int 0x21
    jmp end
    
    end:
    iret
    isr96 endp
    