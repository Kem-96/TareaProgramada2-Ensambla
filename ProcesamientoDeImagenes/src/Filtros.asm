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

	
section .bss
	factorCorreccion resb 1
        nega resb 1
	x1 resb 1
        temp resw 1



section .text

inicio:
;--Areglar los pixeles sobrantes, o sea el caso donde se tratan mas o menos de 32 bytes.

	xor r8, r8
	xor r9, r9
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



fin:
	ret




