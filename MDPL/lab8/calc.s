	.text
	.globl	calculate
calculate:
	cmpb	$43, %dil
	je      .fadd
	cmpb	$45, %dil
	je	.fsub
	cmpb	$42, %dil
	je	.fmul
	cmpb	$47, %dil
	je	.fdiv
        pxor %xmm0, %xmm0
        ret
.fdiv:
	divss	%xmm1, %xmm0
        ret
.fsub:
	subss	%xmm1, %xmm0
	ret
.fadd:
	addss	%xmm1, %xmm0
	ret
.fmul:
	mulss	%xmm1, %xmm0
	ret
