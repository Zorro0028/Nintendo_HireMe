	mov	eax, ecx
	xor	eax, r9d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r13d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r13d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, edx
	xor	eax, r8d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, edx
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r12d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, edx
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r12d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, edx
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r8d
	xor	eax, edx
	xor	eax, r11d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r9d
	xor	eax, ecx
	xor	eax, r10d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r9d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r13d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r10d
	xor	eax, r9d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r10d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r11d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r10d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r10d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r11d
	xor	eax, r8d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r11d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r10d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r11d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r12d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r11d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r12d
	xor	eax, edx
	xor	eax, r11d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r12d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r13d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r12d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r13d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r12d
	xor	eax, ecx
	xor	eax, r9d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r11d
	xor	eax, r13d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r13d
	xor	eax, ecx
	xor	eax, r10d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r13d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, r8d
	xor	eax, r10d
	xor	eax, r11d
	xor	eax, r12d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r13d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, edx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	ror	eax, 8
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

	mov	eax, r13d
	xor	eax, edx
	xor	eax, r8d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, edx
	xor	eax, r8d
	xor	eax, r10d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r8d
	xor	eax, r9d
	xor	eax, r11d
	rol	eax, 8
	xor	eax, ecx
	xor	eax, r9d
	xor	eax, r10d
	xor	eax, r12d
	rol	eax, 16
	movzx	rax, al
	cmp	byte [banned+rax], 1
	je	do_next
	stosb

