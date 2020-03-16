	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function lvInit
LCPI0_0:
	.quad	4612504055078453248     ## double 2.36328125
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_lvInit
_lvInit:                                ## @lvInit
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	_lv@GOTPCREL(%rip), %rbx
	movl	$1610613249, (%rbx)     ## imm = 0x60000201
	xorl	%eax, %eax
	callq	_makeSystem
	movq	%rax, 4856(%rbx)
	movq	%rdx, 4864(%rbx)
	leaq	_ui_drawPixel(%rip), %rax
	movq	%rax, 4848(%rbx)
	movzbl	(%rbx), %esi
	movzbl	1(%rbx), %edx
	movzbl	2(%rbx), %ecx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movb	$1, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ui_drawPixel           ## -- Begin function ui_drawPixel
_ui_drawPixel:                          ## @ui_drawPixel
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, %eax
	sarl	$16, %eax
	imull	$110, %eax, %ecx
	movswl	%di, %eax
	addl	%ecx, %eax
	shrq	%rax
	movq	_lv@GOTPCREL(%rip), %rcx
	testb	$1, %dil
	je	LBB1_1
## %bb.2:
	shlb	$4, %sil
	movb	$15, %dl
	jmp	LBB1_3
LBB1_1:
	andb	$15, %sil
	movb	$-16, %dl
LBB1_3:
	andb	8(%rcx,%rax), %dl
	orb	%sil, %dl
	movb	%dl, 8(%rcx,%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_lv,4872,3              ## @lv
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"lv engine version %d.%d.%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"frame buffer size is %.1fkb\n"


.subsections_via_symbols
