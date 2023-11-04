	.file	"walkHome.cpp"
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.align 4
__ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
__ZStL10defer_lock:
	.space 1
__ZStL11try_to_lock:
	.space 1
__ZStL10adopt_lock:
	.space 1
	.align 4
__ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
__ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
__ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
__ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
__ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
__ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
__ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
__ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
__ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
__ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
__ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
__ZNSt15regex_constantsL13match_defaultE:
	.space 4
	.align 4
__ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
__ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
__ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
__ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
__ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
__ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
__ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
__ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
__ZNSt15regex_constantsL14format_defaultE:
	.space 4
	.align 4
__ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
__ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
__ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
__ZNSt15regex_constantsL13error_collateE:
	.space 4
	.align 4
__ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
__ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
__ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
__ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
__ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
__ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
__ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
__ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
__ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
__ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
__ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
__ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 4
__ZNSt8__detailL19_S_invalid_state_idE:
	.long	-1
	.globl	_grid
	.bss
	.align 32
_grid:
	.space 2500
	.globl	_k
	.align 4
_k:
	.space 4
	.globl	_n
	.align 4
_n:
	.space 4
	.text
	.globl	__Z10hasReachedii
	.def	__Z10hasReachedii;	.scl	2;	.type	32;	.endef
__Z10hasReachedii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	_n, %eax
	subl	$1, %eax
	cmpl	%eax, 8(%ebp)
	jne	L2
	movl	_n, %eax
	subl	$1, %eax
	cmpl	%eax, 12(%ebp)
	jne	L2
	movl	$1, %eax
	jmp	L3
L2:
	movl	$0, %eax
L3:
	popl	%ebp
	ret
	.globl	__Z9recursiveiiic
	.def	__Z9recursiveiiic;	.scl	2;	.type	32;	.endef
__Z9recursiveiiic:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	20(%ebp), %eax
	movb	%al, -12(%ebp)
	movl	_n, %eax
	cmpl	%eax, 8(%ebp)
	jge	L6
	cmpl	$0, 8(%ebp)
	js	L6
	movl	_n, %eax
	cmpl	%eax, 12(%ebp)
	jge	L6
	cmpl	$0, 12(%ebp)
	jns	L7
L6:
	movl	$0, %eax
	jmp	L8
L7:
	movl	8(%ebp), %eax
	imull	$50, %eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	addl	$_grid, %eax
	movzbl	(%eax), %eax
	cmpb	$72, %al
	jne	L9
	movl	$0, %eax
	jmp	L8
L9:
	movl	_k, %eax
	cmpl	%eax, 16(%ebp)
	jle	L10
	movl	$0, %eax
	jmp	L8
L10:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10hasReachedii
	testb	%al, %al
	je	L11
	movl	$1, %eax
	jmp	L8
L11:
	cmpb	$0, -12(%ebp)
	jne	L12
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	$68, 12(%esp)
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z9recursiveiiic
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	$82, 12(%esp)
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9recursiveiiic
	addl	%ebx, %eax
	jmp	L8
L12:
	cmpb	$68, -12(%ebp)
	jne	L13
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	$68, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z9recursiveiiic
	movl	%eax, %ebx
	movl	16(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	$82, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9recursiveiiic
	addl	%ebx, %eax
	jmp	L8
L13:
	movl	16(%ebp), %eax
	addl	$1, %eax
	movl	8(%ebp), %edx
	addl	$1, %edx
	movl	$68, 12(%esp)
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__Z9recursiveiiic
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	leal	1(%eax), %edx
	movl	$82, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9recursiveiiic
	addl	%ebx, %eax
L8:
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	ret
	.globl	__Z5solvev
	.def	__Z5solvev;	.scl	2;	.type	32;	.endef
__Z5solvev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$_n, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$_k, (%esp)
	movl	%eax, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$0, -12(%ebp)
L18:
	movl	_n, %eax
	cmpl	%eax, -12(%ebp)
	jge	L15
	movl	$0, -16(%ebp)
L17:
	movl	_n, %eax
	cmpl	%eax, -16(%ebp)
	jge	L16
	movl	-12(%ebp), %eax
	imull	$50, %eax, %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	addl	$_grid, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	addl	$1, -16(%ebp)
	jmp	L17
L16:
	addl	$1, -12(%ebp)
	jmp	L18
L15:
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$0, (%esp)
	call	__Z9recursiveiiic
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "walkHome.txt\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	call	___main
	movl	$0, (%esp)
	movl	__imp____acrt_iob_func, %eax
	call	*%eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_freopen
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$0, -12(%ebp)
L21:
	movl	-16(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jge	L20
	call	__Z5solvev
	addl	$1, -12(%ebp)
	jmp	L21
L20:
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L26
	cmpl	$65535, 12(%ebp)
	jne	L26
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L26:
	nop
	leave
	ret
	.def	__GLOBAL__sub_I_grid;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_grid:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_grid
	.ident	"GCC: (i686-win32-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_freopen;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
