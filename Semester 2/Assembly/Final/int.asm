.model small
.data
.code

;to set the position of cursor
mov bh, 0 
mov dh, 0x12
mov dl, 0x39
mov ah, 0x2
int 0x10  



;program to display a character specific number of times     
mov al, 0x38 ; store the ascii of character to be displayed 

mov bh, 0 ; page number, always set to 0
mov cx,10 ; store number of times character to be displayed
mov bl, 0x7 ; attributes

mov ah, 0x9
int 0x10
;--------------------------------------------------------------------


;to clear the screen
mov al, 0x0
mov bh, 01110111b
mov ch, 0 
mov cl, 0
mov dh, 24
mov dl, 79
mov ah, 0x6
int 0x10

.exit
