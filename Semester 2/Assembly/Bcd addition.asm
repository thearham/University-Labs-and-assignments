.model small
.code 

mov ax, 7543h
mov bx, 1562h
mov cx, 1784h
mov dx, 9358h

;bl + dl
mov di, ax
mov al,bl
add al,dl
daa
mov dl, al

;bh + dh
mov al, bh
adc al, dh ;adding with carry if from previous addition
daa
mov dh, al 

;al + cl
mov ax, di
adc al, cl ;adding with carry if from previous addition
daa
mov cl, al

;ah + ch
mov al, ah
adc al, ch ;adding with carry if from previous addition
daa
mov ch, al

.exit

 

