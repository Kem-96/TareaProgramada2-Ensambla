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

_negativo:
	mov rcx, [colores]
	vmovups ymm0, [rcx]
	mov [brillosito], byte 255
	vpbroadcastb ymm1, [brillosito]
	vpsubusb ymm2, ymm1, ymm0
	vmovups [rcx], ymm2
	ret

_contraste:
	mov rcx, [colores]
	vmovups ymm0, [rcx]

	ret
_factorDeCorreccion:
_escalado:




