	.text
	.globl	calculate
calculate:
	cmpb	$43, %dil
	je	.add
	cmpb	$45, %dil
	je	.sub
	cmpb	$42, %dil
	je	.mul
	pxor	%xmm2, %xmm2
	cmpb	$47, %dil
	je	.div
	jmp	.exit
.sub:
	movaps	%xmm0, %xmm2
	subss	%xmm1, %xmm2
	jmp .exit
.add:
	movaps	%xmm0, %xmm2
	addss	%xmm1, %xmm2
	jmp .exit
.mul:
	movaps	%xmm0, %xmm2
	mulss	%xmm1, %xmm2
	jmp .exit
.div:
	movaps	%xmm0, %xmm2
	divss	%xmm1, %xmm2
	jmp .exit
.exit:
	movaps	%xmm2, %xmm0
	ret
