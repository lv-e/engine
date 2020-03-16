	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_makeSystem             ## -- Begin function makeSystem
_makeSystem:                            ## @makeSystem
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	_update(%rip), %rax
	leaq	_draw(%rip), %rdx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_update                 ## -- Begin function update
_update:                                ## @update
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_draw                   ## -- Begin function draw
_draw:                                  ## @draw
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$448, %rsp              ## imm = 0x1C0
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	_lv@GOTPCREL(%rip), %r9
	addq	$8, %r9
	xorl	%ecx, %ecx
	leaq	_palette(%rip), %r8
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movzbl	(%r9), %esi
	movl	%esi, %edi
	andl	$15, %edi
	leaq	(%rdi,%rdi,2), %rdi
	movzbl	(%r8,%rdi), %edx
	andl	$31, %edx
	shll	$19, %edx
	movzbl	1(%r8,%rdi), %eax
	andl	$63, %eax
	shll	$10, %eax
	orl	%edx, %eax
	movb	2(%r8,%rdi), %dl
	shlb	$3, %dl
	movzbl	%dl, %edx
	orl	%eax, %edx
	movl	%edx, -448(%rbp,%rcx,4)
	shrq	$4, %rsi
	leaq	(%rsi,%rsi,2), %rax
	movzbl	(%r8,%rax), %edx
	andl	$31, %edx
	shll	$19, %edx
	movzbl	1(%r8,%rax), %esi
	andl	$63, %esi
	shll	$10, %esi
	orl	%edx, %esi
	movb	2(%r8,%rax), %al
	shlb	$3, %al
	movzbl	%al, %eax
	orl	%esi, %eax
	movl	%eax, -444(%rbp,%rcx,4)
	addq	$2, %rcx
	incq	%r9
	cmpq	$110, %rcx
	jb	LBB2_1
## %bb.2:
	movq	_driver_draw_hline@GOTPCREL(%rip), %rax
	leaq	-448(%rbp), %rsi
	xorl	%edi, %edi
	movl	$110, %edx
	callq	*(%rax)
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB2_4
## %bb.3:
	addq	$448, %rsp              ## imm = 0x1C0
	popq	%rbp
	retq
LBB2_4:
	callq	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4               ## @palette
_palette:
	.space	3
	.byte	3                       ## 0x3
	.byte	10                      ## 0xa
	.byte	10                      ## 0xa
	.byte	15                      ## 0xf
	.byte	9                       ## 0x9
	.byte	10                      ## 0xa
	.byte	0                       ## 0x0
	.byte	33                      ## 0x21
	.byte	10                      ## 0xa
	.byte	21                      ## 0x15
	.byte	20                      ## 0x14
	.byte	6                       ## 0x6
	.byte	11                      ## 0xb
	.byte	21                      ## 0x15
	.byte	9                       ## 0x9
	.byte	24                      ## 0x18
	.byte	48                      ## 0x30
	.byte	24                      ## 0x18
	.byte	31                      ## 0x1f
	.byte	60                      ## 0x3c
	.byte	29                      ## 0x1d
	.byte	31                      ## 0x1f
	.byte	0                       ## 0x0
	.byte	9                       ## 0x9
	.byte	31                      ## 0x1f
	.byte	40                      ## 0x28
	.byte	0                       ## 0x0
	.byte	31                      ## 0x1f
	.byte	60                      ## 0x3c
	.byte	4                       ## 0x4
	.byte	0                       ## 0x0
	.byte	57                      ## 0x39
	.byte	10                      ## 0xa
	.byte	5                       ## 0x5
	.byte	43                      ## 0x2b
	.byte	31                      ## 0x1f
	.byte	16                      ## 0x10
	.byte	29                      ## 0x1d
	.byte	19                      ## 0x13
	.byte	31                      ## 0x1f
	.byte	29                      ## 0x1d
	.byte	21                      ## 0x15
	.byte	31                      ## 0x1f
	.byte	51                      ## 0x33
	.byte	21                      ## 0x15


.subsections_via_symbols
