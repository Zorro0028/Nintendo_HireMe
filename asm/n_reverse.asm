; v1.2 made by Zorro; zorropride gmail

; EXIT_AFTER_NPLUSRES	equ 1
; WRITE_2FILE		equ 1
; WRITE_2FILE_SHOWC	equ 1

; one million benchmark
EXIT_AFTER_NPLUSRES	equ 1_000_000
WRITE_2FILE		equ 0
WRITE_2FILE_SHOWC	equ 0

START_TRY_LO64		equ 0h
START_TRY_HI64		equ 0h

SAVE_RESULTS_EVERYN	equ 50_000
maxresultbsize		equ SAVE_RESULTS_EVERYN*32
maxchecklistbytesize	equ 64*900_000
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

errorStr		db 'ERROR',0
errorNoLimitStr		db 'ERROR: EXIT_AFTER_NPLUSRES < 1',0dh,0ah,0
LimitStr		db 'EXIT_AFTER_NPLUSRES = ',0
startTryCounterStr	db 'start TryCounter = 0x',0
finalStr		db 'FINAL:',0
timeStr			db 'Time in ms = ',0
ResCounterStr		db 'ResCounter = ',0
MaxPointerStr		db 'MaxPointer = ',0
nStr			db 0dh,0ah
tStr			db 09h
loadingStr		db ' _____',0dh,0ah,'|[___]|',0dh,0ah,'|+asm+|',0dh,0ah,'`-----''',0dh,0ah,'reverse',0dh,0ah,0dh,0ah,0

TempStringStartAddr:
rb 256

align 10h
TryCounterLOW64		dq 0
TryCounterHIGH64	dq 0

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

if EXIT_AFTER_NPLUSRES < 1
	mov	rdx, errorNoLimitStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	invoke	CloseHandle, [ConsoleHandle]
	invoke	ExitProcess, 0
end if

	mov	rdx, loadingStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	test	rax, rax
	jz	ErrExit

	invoke	VirtualAlloc, 0, maxchecklistbytesize, MEM_COMMIT, PAGE_READWRITE
	mov	[checklistAddr], rax
	add	rax, checklistblocksize
	mov	[checklistFirstAddr], rax

if WRITE_2FILE = 1
	invoke	VirtualAlloc, 0, maxresultbsize, MEM_COMMIT, PAGE_READWRITE
	mov	[ResultAddr], rax
	mov	[ResultPointer], rax

	invoke	CreateFileA, ResultFileName, GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
	test	rax, rax
	jz	ErrExit
	cmp	eax, 0FFFFFFFFh
	jz	ErrExit
	mov	[ResultFileH], rax
end if

	mov	rdx, LimitStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdi, TempStringStartAddr + 40
	mov	rax, EXIT_AFTER_NPLUSRES
	mov	rbx, 1
	call	UInt2DecStrRev
	mov	byte [rbx+rax], 0
	mov	rdx, rbx
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rax, START_TRY_LO64
	mov	[TryCounterLOW64], rax
	mov	rax, START_TRY_HI64
	mov	[TryCounterHIGH64], rax

	mov	rdx, startTryCounterStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdi, TempStringStartAddr + 32
	std
	mov	al, 0
	stosb

	mov	rbx, [TryCounterLOW64]
	mov	rcx, 16
writehexcharsloop1:
	mov	al, bl
	and	al, 0fh
	cmp	al, 10
	jb	nothexletter1
	add	al, -'0'+'a'-10
nothexletter1:
	add	al, '0'
	stosb
	shr	rbx, 4
	dec	rcx
	jnz	writehexcharsloop1

	mov	rbx, [TryCounterHIGH64]
	mov	rcx, 16
writehexcharsloop2:
	mov	al, bl
	and	al, 0fh
	cmp	al, 10
	jb	nothexletter2
	add	al, -'0'+'a'-10
nothexletter2:
	add	al, '0'
	stosb
	shr	rbx, 4
	dec	rcx
	jnz	writehexcharsloop2

	cld

	mov	rdx, TempStringStartAddr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	xor	r12, r12
	xor	r13, r13

	invoke	GetTickCount
	mov	[StartTick], rax

align 10h
tryagain:
	;fill last32 good bytes based on 128bit TryCounter
	mov	rdi, [checklistFirstAddr]

	mov	rbx, [TryCounterLOW64]
	repeat 8
	movzx	rdx, bl
	add	rdx, rdx
	shr	rbx, 8
	mov	ax, word [goodpairs+((%-1)*256*2)+rdx]
	stosw
	end repeat

	mov	rbx, [TryCounterHIGH64]
	repeat 8
	movzx	rdx, bl
	add	rdx, rdx
	shr	rbx, 8
	mov	ax, word [goodpairs+((8+%-1)*256*2)+rdx]
	stosw
	end repeat

	mov	word [rdi], 256

	;increment 128bit TryCounter
	mov	rax, 1
	add	[TryCounterLOW64], rax
	adc	[TryCounterHIGH64], 0

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

	inc	[ResCounter]

if WRITE_2FILE = 1
	mov	rdi, [ResultPointer]
	movsq
	movsq
	movsq
	movsq
	mov	[ResultPointer], rdi

	inc	[ResMemCounter]

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

	if	WRITE_2FILE_SHOWC = 1
		call	WriteConsoleStatus
	end if

	cmp	[ResCounter], EXIT_AFTER_NPLUSRES
	jae	WriteResultAndExit

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
fillcntloop:
	mov	[rsi], r15w
	add	rsi, 64
	dec	rcx
	jnz	fillcntloop

	add	r14, r8
	jmp	do_next

reverse_end:

	cmp	[ResCounter], EXIT_AFTER_NPLUSRES
	jae	WriteResultAndExit

Last32WasNotGood:
	jmp	tryagain


WriteResultAndExit:
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, finalStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	call	WriteConsoleStatus

if WRITE_2FILE = 1
	mov	rdx, [ResultAddr]
	mov	r8, [ResultPointer]
	sub	r8, rdx
	test	r8, r8
	jz	skip_last_write
	invoke	WriteFile, [ResultFileH], rdx, r8, BytesWritten, 0
	test	rax, rax
	jz	ErrExit
skip_last_write:
end if

Exit:
if WRITE_2FILE = 1
	invoke	CloseHandle, [ResultFileH]
	invoke	VirtualFree, [ResultAddr], 0, MEM_COMMIT, MEM_RELEASE
end if

	invoke	VirtualFree, [checklistAddr], 0, MEM_COMMIT, MEM_RELEASE

	invoke	CloseHandle, [ConsoleHandle]

	invoke	ExitProcess, 0


ErrExit:
	mov	rdx, errorStr
	call	calcstrlen
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0
	mov	rdx, nStr
	mov	r8, 2
	invoke	WriteFile, [ConsoleHandle], rdx, r8, BytesWritten, 0

	jmp	Exit


WriteConsoleStatus:
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

	mov	rdx, tStr
	mov	r8, 1
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

	mov	rdx, tStr
	mov	r8, 1
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

	ret


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
	xor	r8, r8
	dec	r8
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
