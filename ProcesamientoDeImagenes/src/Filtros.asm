bits 64
default rel

global inicio, masBrilloAux, menosBrilloAux, negativo, brilloAux, contraste


section .data
	extern colores
	extern brillosito
	extern iteraciones
	
section .bss
	factorCorreccion resb 1
	x1 resb 1



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

negativo:
	mov rcx, [colores]
	vmovups ymm0, [rcx+r9]
	mov [brillosito], byte 255
	vpbroadcastb ymm1, [brillosito]
	vpsubusb ymm2, ymm1, ymm0
	vmovups [rcx+r9], ymm2
	ret

fin:
	ret




