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
	maskI resb 


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
	call contraste
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

contraste:
	;factor de correccion
	

	; contraste
	mov rcx, [colores]
	vmovups ymm3, [rcx + r9]
	
	;Acomodando para dar corrimiento al registro 
	mov [factorCorreccion], byte 255
	vpbroadcastb ymm2, [factorCorreccion]
	mov [x1], byte 128
	;vpsubusb ymm0, [x1]
	vpmulhuw ymm1, ymm2, ymm3
	
	vpaddusb ymm1, [x1]
	vmovups [rcx+r9], ymm1

	ret

fin:
	ret