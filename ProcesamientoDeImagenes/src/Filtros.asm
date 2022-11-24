bits 64
default rel

global inicio, masBrilloAux, menosBrilloAux, negativo, negativoAux, brilloAux, contrasteAux, escaladoAux


section .data
	extern colores
	extern brillosito
	extern iteraciones
        extern nuevoAncho
        extern nuevoAlto
        extern valCont

	
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
        ;Mascara de bits bajos
        mov [temp], word 255
        vpbroadcastw ymm1, [temp]
        ;Mascara de bits altos
        mov [temp], word 65280
        vpbroadcastw ymm2, [temp]

        mov rcx, [colores]
        vmovups ymm0, [rcx+r9]
        ;Bits bajos
        vpand ymm3, ymm0, ymm1
        ;Bts altos
        vpand ymm4, ymm0, ymm2
        ;Shift logical right
        vpsrlw ymm4, ymm4, 1

        vpbroadcastb ymm5, [valCont]
        vpmullw ymm3, ymm5, ymm3
        vpmullw ymm4, ymm5, ymm4

        ;Shift logical left
        vpsllw ymm4, ymm4, 1

        vpaddusb ymm6, ymm3, ymm4
        vmovups [rcx+r9], ymm6
        ret

escalado:
        xor r8, r8
        xor r9, r9


fin:
	ret




