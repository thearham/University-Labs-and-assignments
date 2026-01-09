.model small
.data

.code
mov ax, @data
mov ds,ax

mov ax, 0
mov es, ax  

mov word ptr es:[576], isr144
mov word ptr es:[578], cs

mov ah, 0x2
int 0x90

mov ah, 0x1
int 0x90

mov ah, 0x3
int 0x90


.exit


isr144 PROC
          
          cmp ah, 0x1
          je service1
          
          cmp ah, 0x2
          je service2
          
          cmp ah, 0x3
          je service3
          
          service1:
          mov al, 0x0
          mov bh, 0x7
          mov ch, 0
          mov cl, 0
          mov dh, 24
          mov dl, 79
          mov ah, 0x6
          int 0x10
          jmp exit
          
          
          
          
          service2:
          jmp start
          value db 4 dup(?)
          start:
          mov ah,0x1
          int 0x21
          
          mov [value+0], al
          
          mov ah, 0x1
          int 0x21
          
          mov [value+1], al
          
          mov ah,0x1
          int 0x21
          
          mov [value+2],al
          
          mov ah, 0x1
          int 0x21
          
          mov [value+3], al
          jmp exit 
          
          
          service3:
          mov dl, [value+0]
          mov ah, 0x2
          int 0x21
          
          mov dl, [value+1]
          mov ah, 0x2
          int 0x21
          
          mov dl, [value+2]
          mov ah, 0x2
          int 0x21
          
          mov dl, [value+3]
          mov ah, 0x2
          int 0x21
          jmp exit
          
          
          exit:
          iret
 isr144 endp
