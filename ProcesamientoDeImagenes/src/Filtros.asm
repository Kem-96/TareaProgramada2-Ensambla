bits 64
default rel

global inicio, masBrillo, menosBrillo, negativo, brilloAux, contraste


section .data
	extern colores
	extern brillosito
	extern iteraciones
	extern opt
	
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
	
brilloAux:
	;cmp opt, 0
	;je 
	cmp r8, byte 0
	je fin
	jmp forBrillo
	
	
forBrillo:
	call masBrillo
	add r9, byte 32
	dec r8
	jmp brilloAux

 masBrillo:
	mov rcx, [colores]
	vmovups ymm0, [rcx+r9]
	vpbroadcastb ymm1, [brillosito]
	vpaddusb ymm2, ymm1, ymm0
	vmovups [rcx+r9], ymm2
	ret
	
menosBrillo:
	mov rcx, [colores]
	vmovups ymm0, [rcx]
	vpbroadcastb ymm1, [brillosito]
	vpsubusb ymm2, ymm0, ymm1
	vmovups [rcx], ymm2
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




