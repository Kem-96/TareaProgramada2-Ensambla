bits 64
default rel

global inicio, masBrilloAux, menosBrilloAux, negativo, negativoAux, brilloAux, contrasteAux, escala2


section .data
	extern colores
        extern escalado
	extern brillosito
	extern iteraciones
        extern nuevoAncho
        extern nuevoAlto
        extern valCont
        extern posx
        extern posy
        extern cont1
        extern cont2

	
section .bss
	factorCorreccion resb 1
        nega resb 1
	x1 resb 1
        temp resw 1



section .text

inicio:
	xor r8, r8
	xor r9, r9
        xor r10, r10
        xor rdx, rdx
        xor rbx, rbx
        xor rcx, rcx
	mov r8, [iteraciones]
        ret

masBrilloAux:
        cmp r8, byte 0
        je fin
        jmp forMasBrillo

forMasBrillo:
        call masBrillo
	add r9, byte 32
	dec r8
        jmp masBrilloAux

masBrillo:
	mov rcx, [colores]
	vmovups ymm0, [rcx+r9]
	vpbroadcastb ymm1, [brillosito]
	vpaddusb ymm2, ymm1, ymm0
	vmovups [rcx+r9], ymm2
	ret

menosBrilloAux:
        cmp r8, byte 0
        je fin
        jmp forMenosBrillo

forMenosBrillo:
        call menosBrillo
        add r9, byte 32
        dec r8
        jmp menosBrilloAux
	
menosBrillo:
        mov rcx, [colores]
        vmovups ymm0, [rcx+r9]
        vpbroadcastb ymm1, [brillosito]
        vpsubusb ymm2, ymm0, ymm1
        vmovups [rcx+r9], ymm2
        ret

negativoAux:
        cmp r8, byte 0
        je fin
        jmp forNegativo

forNegativo:
        call negativo
        add r9, byte 32
        dec r8
        jmp negativoAux

negativo:
	mov rcx, [colores]
	vmovups ymm0, [rcx+r9]
        mov [nega], byte 255
        vpbroadcastb ymm1, [nega]
	vpsubusb ymm2, ymm1, ymm0
	vmovups [rcx+r9], ymm2
	ret


contrasteAux:
        cmp r8, byte 0
        je fin
        jmp forContraste

forContraste:
        call contraste
        add r9, byte 32
        dec r8
        jmp contrasteAux

contraste:
        ;Mueve el vecto de colores a rcx
        mov rcx, [colores]
        vmovups ymm0, [rcx+r9]

        ;Crea un vector en ymm0 con el byte 128
        mov [x1], byte 128
        vpbroadcastb ymm1, [x1]
        vpaddusb ymm0, ymm0, ymm1

        ;Crea un vector con valor de contraste
        vpbroadcastb ymm5, [valCont]
        vpmullw ymm0, ymm0, ymm5

        vpsubusb ymm0, ymm0, ymm1
        ;Guarda el resultado de vuelta en el vector de colores.
        vmovups [rcx+r9], ymm0
        ret

escala2:
        ;Solo cambia los dos primeros pixeles...
        call offset
        mov rcx, [colores]
        mov rax, [escalado]
        mov cl, [rcx+r9]
        mov [rax+r9], cl
        add r9, 3
        mov [rax+r9], cl
        sub r9, 2
        mov rax,[cont2]
        inc rax
        mov [cont2], rax
        cmp rax, 3
        jl escala2
        jge fin

offset:
        ;Calcula el offset de los pixeles en relacion con la imagen original.
        mov r8, [posx]
        mov r9, [posy]
        mov rax, 3
        mul r9
        mov r9, rax
        mov rax, [nuevoAncho]
        mul r9
        mov r9, rax
        add r9, r8
        ret

fin:
	ret




