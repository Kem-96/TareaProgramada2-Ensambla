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
	extern contraste
	
section .bss

    constante resb 1
	factorCorreccion resb 1

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
	;factor de correccion
	mov r9, 255
	add r9, [contraste]
	mul r9, 259
	mov r8, 259
	sub r8, [contraste]
	mul r8, 255
	mov [factorCorreccion], r8
	div factorCorreccion, r9

	mov [r10], byte 255
	add [r10], byte 50
	mul [r10], byte 255
	mov [r11], byte 255
	sub [r11], byte 50
	mul [r11], byte 255
	mov [factorCorreccion], r10
	div [factorCorreccion], r11

	; contraste
	mov rcx, [colores]
	vmovups ymm0, [rcx]
	vpbroadcastb ymm1, [factorCorreccion]
	vpsubusb ymm0, 128
	vpmuldq ymm0, ymm1
	vpaddusb ymm0, 128

	ret




_escalado:




