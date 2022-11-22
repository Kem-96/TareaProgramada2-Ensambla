bits 64
default rel

global _brillo
global _contraste
global _negativo
global _escalado
global _espejado

section .data 

	extern colores
	extern brillosito
	
section .bss

    constante resb 1

section .text

 _brillo:
    ;--Areglar los pixeles sobrantes, o sea el caso donde se tratan mas o menos de 32 bytes.
	mov rcx, [colores]
	vmovups ymm0, [rcx]
	mov [brillosito], byte 20
	vpbroadcastb ymm1, [brillosito]
	vpaddusb ymm2, ymm1, ymm0
	vmovups [rcx], ymm2
	ret

_contraste:
	vmovups ymm0, [rcx]
	mov r9b, 0 
	ciclo:
		vpaddusb ymm0, ymm0, ymm0
		inc r9b
		cmp r9b, 6 
		jl ciclo

	vmovups [rcx], ymm0
	ret

_negativo:
	mov rcx, [colores]
	vmovups ymm0, [rcx]
	vpbroadcastb ymm1, byte 255
	vpsubusb ymm2, ymm1, ymm0
	vmovups [rcx], ymm2
	ret



_escalado:




