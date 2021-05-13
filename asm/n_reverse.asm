; v1.1 made by Zorro; zorropride gmail
EXITAFTER_NPLUSRES	equ 1
WRITE_RESULTS2FILE	equ 1
; ; one million results benchmark
; EXITAFTER_NPLUSRES	equ 1_000_000
; WRITE_RESULTS2FILE	equ 1

SAVE_RESULTS_EVERYN	equ 100_000
maxresultbsize		equ SAVE_RESULTS_EVERYN*32
maxchecklistbytesize	equ 4*1024*1_048_576
secondblocksize		equ 32
checklistblocksize	equ (32+secondblocksize)

format PE64 console
entry start

include 'win64a.inc'

section '.data' data readable writeable

include 'n_data.inc'

StartTick		dq 0

ResultFileName		db '__n_res_asm.bin',0
ResultFileH		dq 0
BytesWritten		dq 0

ConsoleHandle		dq 0

errorStr		db 'error',0
timeStr			db 'Time in ms = ',0
ResCounterStr		db 'ResCounter = ',0
TryCounterStr		db 'TryCounter = ',0
MaxPointerStr		db 'MaxPointer = ',0
nStr			db 0dh,0ah

loadingStr		db ' _____',0dh,0ah,'|[___]|',0dh,0ah,'|+asm+|',0dh,0ah,'`-----''',0dh,0ah,'loading',0dh,0ah,0dh,0ah

TempStringStartAddr:
rb 256

align 10h
trycounterLOW64bits	dq -1
trycounterHIGH64bits	dq -1

ResultAddr		dq 0
ResultPointer		dq 0

ResCounter		dq 0
ResMemCounter		dq 0
MaxPointer		dq 0

checklistAddr		dq 0
checklistFirstAddr	dq 0

section '.text' code readable executable

start:
	sub	esp, 8

	invoke	GetStdHandle, STD_OUTPUT_HANDLE
	test	rax, rax
	jz	ErrExit
	mov	[ConsoleHandle], rax

	mov	rdx, loadingStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	test	rax, rax
	jz	ErrExit

	invoke	VirtualAlloc, 0, maxresultbsize, MEM_COMMIT, PAGE_READWRITE
	mov	[ResultAddr], rax
	mov	[ResultPointer], rax

	invoke	VirtualAlloc, 0, maxchecklistbytesize, MEM_COMMIT, PAGE_READWRITE
	mov	[checklistAddr], rax
	add	rax, checklistblocksize
	mov	[checklistFirstAddr], rax

if WRITE_RESULTS2FILE = 1
	invoke	CreateFileA, ResultFileName, GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
	test	rax, rax
	jz	ErrExit
	cmp	eax, 0FFFFFFFFh
	jz	ErrExit
	mov	[ResultFileH], rax
end if

	xor	r12, r12
	xor	r13, r13

	invoke	GetTickCount
	mov	[StartTick], rax

align 10h
tryagain:
	;increment 128bit trycounter
	mov	rax, 1
	add	[trycounterLOW64bits], rax
	adc	[trycounterHIGH64bits], 0

	;fill last32 good bytes based on 128bit trycounter
	mov	rdi, [checklistFirstAddr]

	mov	rbx, [trycounterLOW64bits]
	repeat 8
	movzx	rdx, bl
	add	rdx, rdx
	shr	rbx, 8
	mov	ax, word [goodpairs+((%-1)*256*2)+rdx]
	stosw
	end repeat

	mov	rbx, [trycounterHIGH64bits]
	repeat 8
	movzx	rdx, bl
	add	rdx, rdx
	shr	rbx, 8
	mov	ax, word [goodpairs+((8+%-1)*256*2)+rdx]
	stosw
	end repeat

	mov	word [rdi], 256

	mov	r14, 2 		;r14 = checklistPointer
	jmp	do_next

align 10h
do_next:
	dec	r14
	test	r14, r14
	jz	reverse_end

	cmp	r14, [MaxPointer]
	jbe	notmax
	mov	[MaxPointer], r14
notmax:

	mov	rsi, r14
	shl	rsi, 6
	add	rsi, [checklistAddr]

	mov	r15w, [rsi+32]

	test	r15w, r15w
	jne	not_end

	mov	rdi, [ResultPointer]
	movsq
	movsq
	movsq
	movsq
	mov	[ResultPointer], rdi

	inc	[ResCounter]
	inc	[ResMemCounter]

if WRITE_RESULTS2FILE = 1
	cmp	[ResMemCounter], SAVE_RESULTS_EVERYN
	jb	notsaveyet

	mov	rdx, [ResultAddr]
	mov	r8, [ResultPointer]
	sub	r8, rdx
	invoke	WriteFile, [ResultFileH], rdx, r8, BytesWritten, 0
	test	rax, rax
	jz	ErrExit

	xor	rax, rax
	mov	[ResMemCounter], rax
	mov	rax, [ResultAddr]
	mov	[ResultPointer], rax
notsaveyet:
end if

	jmp	do_next

not_end:

	mov	ecx,  [rsi   ]
	mov	edx,  [rsi+ 4]
	mov	r8d,  [rsi+ 8]
	mov	r9d,  [rsi+12]
	mov	r10d, [rsi+16]
	mov	r11d, [rsi+20]
	mov	r12d, [rsi+24]
	mov	r13d, [rsi+28]
	mov	rdi, rsi

	include 'n_xor.inc'

	mov	rdx, rsi
	xor	rcx, rcx
	repeat 32
	mov	al, [rdx]
	cmp	byte [rev2+rax], 1
	sbb	cl, 0ffh
	inc	rdx
	end repeat

	mov	r8, 1
	shl	r8, cl	 	; r8  revscnt

 	mov	r9, 1    	; r9  periodval
	mov	r10, r9		; r10 periodcnt

rept 32 i
{
local rev2loop, rev1loop, donextb
	mov	rcx, r8
	mov	rdx, rsi

	lodsb
	mov	r12b, [rev1+rax]
	mov	r13b, [rev2+rax]
	test	r13b , r13b
	je	rev1loop

	xor	r11, r11
rev2loop:
	mov	bx, r12w
	bt	r11, 0
	cmovc	bx, r13w
	mov	[rdx], bl

	dec	r10
	setz	al
	cmovz	r10, r9
	add	r11, rax

	add	rdx, 64
	dec	rcx
	jnz	rev2loop

	add	r9, r9
	jmp	donextb

align 10h
rev1loop:
	mov	[rdx], r12b
	add	rdx, 64
	dec	rcx
	jnz	rev1loop

donextb:
}

	dec	r15w
	mov	rcx, r8
	mov	rdx, rsi
fillcntloop:
	mov	[rdx], r15w
	add	rdx, 64
	dec	rcx
	jnz	fillcntloop

	add	r14, r8
	jmp	do_next

reverse_end:

if EXITAFTER_NPLUSRES > 0
	cmp	[ResCounter], EXITAFTER_NPLUSRES
	jae	WriteResultAndExit
end if

Last32WasNotGood:
	jmp	tryagain


WriteResultAndExit:

	mov	rdx, timeStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	invoke	GetTickCount
	sub	rax, [StartTick]
	mov	rdi, TempStringStartAddr + 13
	mov	rbx, 1
	call	UInt2DecStrRev
	mov	byte [rbx+rax], 0
	mov	rdx, rbx
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

if WRITE_RESULTS2FILE = 1
	mov	rdx, [ResultAddr]
	mov	r8, [ResultPointer]
	sub	r8, rdx
	invoke	WriteFile, [ResultFileH], rdx, r8, BytesWritten, 0
	test	rax, rax
	jz	ErrExit
end if

	mov	rdx, TryCounterStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rax, [trycounterLOW64bits]
	mov	rdi, TempStringStartAddr + 13
	mov	rbx, 1
	call	UInt2DecStrRev
	mov	byte [rbx+rax],0
	mov	rdx, rbx
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdx, ResCounterStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rax, [ResCounter]
	mov	rdi, TempStringStartAddr + 13
	mov	rbx, 1
	call	UInt2DecStrRev
	mov	byte [rbx+rax], 0
	mov	rdx, rbx
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdx, MaxPointerStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rax, [MaxPointer]
	mov	rdi, TempStringStartAddr + 13
	mov	rbx, 1
	call	UInt2DecStrRev
	mov	byte [rbx+rax],0
	mov	rdx, rbx
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

Exit:
if WRITE_RESULTS2FILE = 1
	invoke	CloseHandle, [ResultFileH]
end if
	invoke	VirtualFree, [ResultAddr], 0, MEM_COMMIT, MEM_RELEASE
	invoke	VirtualFree, [checklistAddr], 0, MEM_COMMIT, MEM_RELEASE

	invoke	ExitProcess, 0

ErrExit:
	mov	rdx, errorStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	jmp	Exit


;rax - uint
;edi - dest addr
;if rbx == 1 : output with comma separation
;if rbx == 0 : output without comma separation
;result:
;rbx = pointer to string out
;rax = string out len
UInt2DecStrRev:
	std
	cmp	rbx, 1
	jbe	@f
	xor	rbx, rbx
@@:
	mov	r8, 10
	xor	rcx, rcx
UInt2DecStrRev_loop:
	bt	rbx, 0
	jnc	UInt2DecStrRev_nocomma
	cmp	rbx, 27
	jb	@f
	push	rax
	mov	al, '_'
	stosb
	pop	rax
	mov	rbx, 1
	inc	rcx
@@:
	imul	rbx, 3
UInt2DecStrRev_nocomma:
	xor	rdx, rdx
	div	r8
	push	rax
	mov	al, dl
	add	al, '0'
	stosb
	inc	rcx
	pop	rax
	test	rax, rax
	jnz	UInt2DecStrRev_loop
	mov	rax, rcx
	mov	rbx, rdi
	inc	rbx
	cld
	ret


calcstrlen:
	mov	r8, -1
calcstrlen_loop:
	inc	r8
	mov	al, [rdx+r8]
	test	al, al
	jnz	calcstrlen_loop
	ret


data import
library kernel32, 'kernel32.dll'
include 'api\kernel32.inc'
end data
