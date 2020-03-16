	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
_main:                                  ## @main
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
	xorl	%eax, %eax
	callq	_lvInit
	movq	_lv@GOTPCREL(%rip), %rbx
	movl	$1, %edi
	movl	$7, %esi
	callq	*4848(%rbx)
	xorl	%edi, %edi
	movl	$4, %esi
	callq	*4848(%rbx)
	xorl	%eax, %eax
	callq	*4864(%rbx)
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
