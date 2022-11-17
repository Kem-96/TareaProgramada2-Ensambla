bits 64
default rel

global _brillo
global _contraste
global _negativo
global _escalado
global _espejado

section .bss

    constante resb 1

section .text

 _brillo:
    vmovups ymm0, [rcx]
    mov [constante], byte 5
    vpbroadcastb ymm1, [constante]
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
	subq 32, rsp
	movl 0xffffffff, (rsp)
	vbroadcastss (rsp), ymm1
	mov $0, rax
	loop:
	vmovups (rdi, rax), ymm0
	rpvxos ymm0, ymm1, ymm0
	vmovups ymm0, (rdi,rax)
	add $32, rax
	cmp rax, rsi
	ja loop
	ret


_espejado:
vmovups xmm0, [rcx+15]
vmovups [rcx+16], xmm0
vmovups ymm0, [rcx]
mov al, 0
mov [aux], al
vpbroadcastb ymm2, [aux]

mov al, 0
mov [aux], al
vpbroadcastb ymm1, [aux]
mov bl, 0

cicloEspejado: 
vmovups [aux2], ymm0 
; falta



