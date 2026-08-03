bits 64

global distance_x64

section .text

; ECX = n
; RDX = x1
; R8 = x2
; R9 = y1
; [RSP + 40] = y2
; [RSP + 48] = z
distance_x64:
    mov R11D, ECX
    mov R10,  qword [RSP + 40]
    mov RCX,  qword [RSP + 48]

    xor RAX, RAX

.loop:
	cmp RAX, R11
	jae .done

	movss XMM0, dword [R8 + RAX * 4]
	subss XMM0, dword [RDX + RAX * 4]
	mulss XMM0, XMM0

	movss XMM1, dword [R10 + RAX * 4]
	subss XMM1, dword [R9 + RAX * 4]
	mulss XMM1, XMM1

	addss  XMM0, XMM1
	sqrtss XMM0, XMM0

	movss dword [RCX + RAX * 4], XMM0

	inc RAX
	jmp .loop

.done:
	ret
