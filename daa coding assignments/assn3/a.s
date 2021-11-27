	.file	"a.cpp"
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZSt4__lgi,"x"
	.linkonce discard
	.globl	__ZSt4__lgi
	.def	__ZSt4__lgi;	.scl	2;	.type	32;	.endef
__ZSt4__lgi:
LFB620:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	bsrl	%eax, %eax
	xorl	$31, %eax
	movl	$31, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE620:
	.section .rdata,"dr"
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
	.section	.text$_ZN6vertexC1Eiii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN6vertexC1Eiii
	.def	__ZN6vertexC1Eiii;	.scl	2;	.type	32;	.endef
__ZN6vertexC1Eiii:
LFB7827:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-4(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE7827:
	.text
	.globl	__Z10comparatorP6vertexS0_
	.def	__Z10comparatorP6vertexS0_;	.scl	2;	.type	32;	.endef
__Z10comparatorP6vertexS0_:
LFB7828:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jl	L5
	movl	$0, %eax
	jmp	L6
L5:
	movl	$1, %eax
L6:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7828:
	.section	.text$_ZN8SolutionC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8SolutionC1Ev
	.def	__ZN8SolutionC1Ev;	.scl	2;	.type	32;	.endef
__ZN8SolutionC1Ev:
LFB7831:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	-28(%ebp), %edx
	addl	$4, %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	$536870911, %eax
	ja	L8
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	$0, -12(%ebp)
	jmp	L11
L8:
	call	___cxa_throw_bad_array_new_length
L11:
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	cmpl	%eax, -12(%ebp)
	jge	L10
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	%eax, %edx
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$12, (%esp)
	call	__Znwj
	movl	%eax, %ebx
	movl	-24(%ebp), %ecx
	movl	-20(%ebp), %edx
	movl	-16(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZN6vertexC1Eiii
	subl	$12, %esp
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%ebx, (%eax)
	addl	$1, -12(%ebp)
	jmp	L11
L10:
	movl	-28(%ebp), %eax
	movl	8(%eax), %edx
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	sall	$2, %eax
	addl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	8(%eax), %eax
	movl	$__Z10comparatorP6vertexS0_, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4sortIPP6vertexPFbS1_S1_EEvT_S5_T0_
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7831:
	.section	.text$_ZN8Solution4findEiPi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Solution4findEiPi
	.def	__ZN8Solution4findEiPi;	.scl	2;	.type	32;	.endef
__ZN8Solution4findEiPi:
LFB7832:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	%eax, 8(%ebp)
	je	L13
	movl	8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN8Solution4findEiPi
	subl	$8, %esp
	jmp	L15
L13:
	movl	8(%ebp), %eax
L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE7832:
	.section	.text$_ZN8Solution5solveEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Solution5solveEv
	.def	__ZN8Solution5solveEv;	.scl	2;	.type	32;	.endef
__ZN8Solution5solveEv:
LFB7833:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	%ecx, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	subl	$1, %eax
	cmpl	$536870911, %eax
	ja	L17
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, -28(%ebp)
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$536870911, %eax
	ja	L19
	jmp	L26
L17:
	call	___cxa_throw_bad_array_new_length
L26:
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znaj
	movl	%eax, -32(%ebp)
	movl	$0, -12(%ebp)
	jmp	L22
L19:
	call	___cxa_throw_bad_array_new_length
L22:
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, -12(%ebp)
	jge	L21
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
	jmp	L22
L21:
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
L25:
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	subl	$1, %eax
	cmpl	%eax, -16(%ebp)
	je	L23
	movl	-60(%ebp), %eax
	movl	8(%eax), %eax
	movl	-24(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	-32(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN8Solution4findEiPi
	subl	$8, %esp
	movl	%eax, -40(%ebp)
	movl	-36(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	-32(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN8Solution4findEiPi
	subl	$8, %esp
	movl	%eax, -44(%ebp)
	movl	-40(%ebp), %eax
	cmpl	-44(%ebp), %eax
	je	L24
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -16(%ebp)
	leal	0(,%eax,4), %edx
	movl	-28(%ebp), %eax
	addl	%eax, %edx
	movl	-36(%ebp), %eax
	movl	%eax, (%edx)
	movl	-40(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%eax, (%edx)
	movl	-36(%ebp), %eax
	movl	8(%eax), %eax
	addl	%eax, -20(%ebp)
L24:
	addl	$1, -24(%ebp)
	jmp	L25
L23:
	movl	-20(%ebp), %eax
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
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7833:
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7834:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA7834
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	call	___main
	movl	$12, (%esp)
LEHB0:
	call	__Znwj
LEHE0:
	movl	%eax, %ebx
	movl	%ebx, %ecx
LEHB1:
	call	__ZN8SolutionC1Ev
LEHE1:
	movl	%ebx, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, %ecx
LEHB2:
	call	__ZN8Solution5solveEv
	movl	$0, %eax
	jmp	L31
L30:
	movl	%eax, %esi
	movl	$12, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvj
	movl	%esi, %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE2:
L31:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE7834:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA7834:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE7834-LLSDACSB7834
LLSDACSB7834:
	.uleb128 LEHB0-LFB7834
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB7834
	.uleb128 LEHE1-LEHB1
	.uleb128 L30-LFB7834
	.uleb128 0
	.uleb128 LEHB2-LFB7834
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
LLSDACSE7834:
	.text
	.section	.text$_ZSt4sortIPP6vertexPFbS1_S1_EEvT_S5_T0_,"x"
	.linkonce discard
	.globl	__ZSt4sortIPP6vertexPFbS1_S1_EEvT_S5_T0_
	.def	__ZSt4sortIPP6vertexPFbS1_S1_EEvT_S5_T0_;	.scl	2;	.type	32;	.endef
__ZSt4sortIPP6vertexPFbS1_S1_EEvT_S5_T0_:
LFB8233:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx5__ops16__iter_comp_iterIPFbP6vertexS3_EEENS0_15_Iter_comp_iterIT_EES7_
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt6__sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8233:
	.section	.text$_ZN9__gnu_cxx5__ops16__iter_comp_iterIPFbP6vertexS3_EEENS0_15_Iter_comp_iterIT_EES7_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx5__ops16__iter_comp_iterIPFbP6vertexS3_EEENS0_15_Iter_comp_iterIT_EES7_
	.def	__ZN9__gnu_cxx5__ops16__iter_comp_iterIPFbP6vertexS3_EEENS0_15_Iter_comp_iterIT_EES7_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops16__iter_comp_iterIPFbP6vertexS3_EEENS0_15_Iter_comp_iterIT_EES7_:
LFB8374:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_
	movl	(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEC1ES5_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8374:
	.section	.text$_ZSt6__sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt6__sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	.def	__ZSt6__sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt6__sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_:
LFB8375:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L37
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, (%esp)
	call	__ZSt4__lgi
	leal	(%eax,%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt22__final_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
L37:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8375:
	.section	.text$_ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_
	.def	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_:
LFB8421:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8421:
	.section	.text$_ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEC1ES5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEC1ES5_
	.def	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEC1ES5_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEC1ES5_:
LFB8424:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE8424:
	.section	.text$_ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_,"x"
	.linkonce discard
	.globl	__ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_
	.def	__ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_;	.scl	2;	.type	32;	.endef
__ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_:
LFB8425:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
L44:
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	cmpl	$64, %eax
	jle	L41
	cmpl	$0, 16(%ebp)
	jne	L43
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt14__partial_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_
	jmp	L41
L43:
	subl	$1, 16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt27__unguarded_partition_pivotIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_T0_
	movl	%eax, -12(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt16__introsort_loopIPP6vertexiN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_T1_
	movl	-12(%ebp), %eax
	movl	%eax, 12(%ebp)
	jmp	L44
L41:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8425:
	.section	.text$_ZSt22__final_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt22__final_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	.def	__ZSt22__final_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt22__final_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_:
LFB8426:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	cmpl	$64, %eax
	jle	L46
	movl	8(%ebp), %eax
	leal	64(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	movl	8(%ebp), %eax
	leal	64(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt26__unguarded_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	jmp	L48
L46:
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
L48:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8426:
	.section	.text$_ZSt14__partial_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt14__partial_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_
	.def	__ZSt14__partial_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt14__partial_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_:
LFB8463:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__heap_selectIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_
	leal	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__sort_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8463:
	.section	.text$_ZSt27__unguarded_partition_pivotIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt27__unguarded_partition_pivotIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_T0_
	.def	__ZSt27__unguarded_partition_pivotIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt27__unguarded_partition_pivotIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_T0_:
LFB8464:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	leal	-4(%eax), %ecx
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt22__move_median_to_firstIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_S9_T0_
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt21__unguarded_partitionIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_S9_T0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8464:
	.section	.text$_ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	.def	__ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt16__insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_:
LFB8465:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L58
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -12(%ebp)
L57:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L52
	leal	16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L55
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13move_backwardIPP6vertexS2_ET0_T_S4_S3_
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L56
L55:
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_
L56:
	addl	$4, -12(%ebp)
	jmp	L57
L58:
	nop
L52:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8465:
	.section	.text$_ZSt26__unguarded_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt26__unguarded_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_
	.def	__ZSt26__unguarded_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt26__unguarded_insertion_sortIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_T0_:
LFB8466:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
L61:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L62
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_
	addl	$4, -12(%ebp)
	jmp	L61
L62:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8466:
	.section	.text$_ZSt13__heap_selectIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt13__heap_selectIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_
	.def	__ZSt13__heap_selectIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt13__heap_selectIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_T0_:
LFB8495:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__make_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
L66:
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jnb	L67
	leal	20(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L65
	leal	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_
L65:
	addl	$4, -12(%ebp)
	jmp	L66
L67:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8495:
	.section	.text$_ZSt11__sort_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_,"x"
	.linkonce discard
	.globl	__ZSt11__sort_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_
	.def	__ZSt11__sort_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_;	.scl	2;	.type	32;	.endef
__ZSt11__sort_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_:
LFB8496:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
L70:
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	cmpl	$4, %eax
	jle	L71
	subl	$4, 12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_
	jmp	L70
L71:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8496:
	.section	.text$_ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	.def	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_:
LFB8498:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %ecx
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE8498:
	.section	.text$_ZSt22__move_median_to_firstIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt22__move_median_to_firstIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_S9_T0_
	.def	__ZSt22__move_median_to_firstIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt22__move_median_to_firstIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_S9_T0_:
LFB8497:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	leal	24(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L75
	leal	24(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L76
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	jmp	L81
L76:
	leal	24(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L78
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	jmp	L81
L78:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	jmp	L81
L75:
	leal	24(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L79
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	jmp	L81
L79:
	leal	24(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L80
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	jmp	L81
L80:
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
L81:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8497:
	.section	.text$_ZSt21__unguarded_partitionIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_S9_T0_,"x"
	.linkonce discard
	.globl	__ZSt21__unguarded_partitionIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_S9_T0_
	.def	__ZSt21__unguarded_partitionIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_S9_T0_;	.scl	2;	.type	32;	.endef
__ZSt21__unguarded_partitionIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEET_S9_S9_S9_T0_:
LFB8499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
L84:
	leal	20(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L83
	addl	$4, 8(%ebp)
	jmp	L84
L83:
	subl	$4, 12(%ebp)
L86:
	leal	20(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L85
	subl	$4, 12(%ebp)
	jmp	L86
L85:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jb	L87
	movl	8(%ebp), %eax
	jmp	L89
L87:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	addl	$4, 8(%ebp)
	jmp	L84
L89:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8499:
	.section	.text$_ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_:
LFB8500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8500:
	.section	.text$_ZSt13move_backwardIPP6vertexS2_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt13move_backwardIPP6vertexS2_ET0_T_S4_S3_
	.def	__ZSt13move_backwardIPP6vertexS2_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt13move_backwardIPP6vertexS2_ET0_T_S4_S3_:
LFB8501:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP6vertexET_S3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP6vertexET_S3_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt23__copy_move_backward_a2ILb1EPP6vertexS2_ET1_T0_S4_S3_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8501:
	.section	.text$_ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE
	.def	__ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops15__val_comp_iterIPFbP6vertexS3_EEENS0_14_Val_comp_iterIT_EENS0_15_Iter_comp_iterIS7_EE:
LFB8502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_
	movl	%eax, %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8502:
	.section	.text$_ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_,"x"
	.linkonce discard
	.globl	__ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_
	.def	__ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_;	.scl	2;	.type	32;	.endef
__ZSt25__unguarded_linear_insertIPP6vertexN9__gnu_cxx5__ops14_Val_comp_iterIPFbS1_S1_EEEEvT_T0_:
LFB8503:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	subl	$4, -12(%ebp)
L98:
	leal	12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEclIS3_PS3_EEbRT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L97
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%ebp)
	subl	$4, -12(%ebp)
	jmp	L98
L97:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8503:
	.section	.text$_ZSt11__make_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_,"x"
	.linkonce discard
	.globl	__ZSt11__make_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_
	.def	__ZSt11__make_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_;	.scl	2;	.type	32;	.endef
__ZSt11__make_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_RT0_:
LFB8528:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	cmpl	$4, %eax
	jle	L104
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
L103:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_
	cmpl	$0, -12(%ebp)
	je	L105
	subl	$1, -12(%ebp)
	jmp	L103
L104:
	nop
	jmp	L99
L105:
	nop
L99:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8528:
	.section	.text$_ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_,"x"
	.linkonce discard
	.globl	__ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_
	.def	__ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_;	.scl	2;	.type	32;	.endef
__ZSt10__pop_heapIPP6vertexN9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_S9_S9_RT0_:
LFB8529:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	subl	8(%ebp), %edx
	sarl	$2, %edx
	movl	%edx, %ecx
	movl	20(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8529:
	.section	.text$_ZSt9iter_swapIPP6vertexS2_EvT_T0_,"x"
	.linkonce discard
	.globl	__ZSt9iter_swapIPP6vertexS2_EvT_T0_
	.def	__ZSt9iter_swapIPP6vertexS2_EvT_T0_;	.scl	2;	.type	32;	.endef
__ZSt9iter_swapIPP6vertexS2_EvT_T0_:
LFB8530:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4swapIP6vertexENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS6_ESt18is_move_assignableIS6_EEE5valueEvE4typeERS6_SG_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8530:
	.section	.text$_ZSt12__miter_baseIPP6vertexET_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPP6vertexET_S3_
	.def	__ZSt12__miter_baseIPP6vertexET_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPP6vertexET_S3_:
LFB8531:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8531:
	.section	.text$_ZSt23__copy_move_backward_a2ILb1EPP6vertexS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt23__copy_move_backward_a2ILb1EPP6vertexS2_ET1_T0_S4_S3_
	.def	__ZSt23__copy_move_backward_a2ILb1EPP6vertexS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt23__copy_move_backward_a2ILb1EPP6vertexS2_ET1_T0_S4_S3_:
LFB8532:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP6vertexET_S3_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP6vertexET_S3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP6vertexET_S3_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__copy_move_backward_aILb1EPP6vertexS2_ET1_T0_S4_S3_
	movl	%eax, 4(%esp)
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_wrapIPP6vertexET_RKS3_S3_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8532:
	.section	.text$_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_
	.def	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_:
LFB8533:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8533:
	.section	.text$_ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE
	.def	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE:
LFB8536:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE8536:
	.section	.text$_ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEclIS3_PS3_EEbRT_T0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEclIS3_PS3_EEbRT_T0_
	.def	__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEclIS3_PS3_EEbRT_T0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Val_comp_iterIPFbP6vertexS3_EEclIS3_PS3_EEbRT_T0_:
LFB8537:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %ecx
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE8537:
	.section	.text$_ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_,"x"
	.linkonce discard
	.globl	__ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_
	.def	__ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_;	.scl	2;	.type	32;	.endef
__ZSt13__adjust_heapIPP6vertexiS1_N9__gnu_cxx5__ops15_Iter_comp_iterIPFbS1_S1_EEEEvT_T0_SA_T1_T2_:
LFB8546:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
L120:
	movl	16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -12(%ebp)
	jge	L118
	movl	-12(%ebp), %eax
	addl	$1, %eax
	addl	%eax, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	leal	24(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS3_EEclIPS3_S8_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L119
	subl	$1, -12(%ebp)
L119:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%ebp)
	jmp	L120
L118:
	movl	16(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	L121
	movl	16(%ebp), %eax
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -12(%ebp)
	jne	L121
	movl	-12(%ebp), %eax
	addl	$1, %eax
	addl	%eax, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%ebp)
L121:
	leal	24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterIPFbP6vertexS4_EEEEONSt16remove_referenceIT_E4typeEOSA_
	movl	%eax, %edx
	leal	-20(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE
	subl	$4, %esp
	leal	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	leal	-20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__push_heapIPP6vertexiS1_N9__gnu_cxx5__ops14_Iter_comp_valIPFbS1_S1_EEEEvT_T0_SA_T1_RT2_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8546:
	.section	.text$_ZSt4swapIP6vertexENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS6_ESt18is_move_assignableIS6_EEE5valueEvE4typeERS6_SG_,"x"
	.linkonce discard
	.globl	__ZSt4swapIP6vertexENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS6_ESt18is_move_assignableIS6_EEE5valueEvE4typeERS6_SG_
	.def	__ZSt4swapIP6vertexENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS6_ESt18is_move_assignableIS6_EEE5valueEvE4typeERS6_SG_;	.scl	2;	.type	32;	.endef
__ZSt4swapIP6vertexENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS6_ESt18is_move_assignableIS6_EEE5valueEvE4typeERS6_SG_:
LFB8547:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8547:
	.section	.text$_ZSt12__niter_baseIPP6vertexET_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIPP6vertexET_S3_
	.def	__ZSt12__niter_baseIPP6vertexET_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIPP6vertexET_S3_:
LFB8548:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8548:
	.section	.text$_ZSt22__copy_move_backward_aILb1EPP6vertexS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt22__copy_move_backward_aILb1EPP6vertexS2_ET1_T0_S4_S3_
	.def	__ZSt22__copy_move_backward_aILb1EPP6vertexS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt22__copy_move_backward_aILb1EPP6vertexS2_ET1_T0_S4_S3_:
LFB8549:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIP6vertexEEPT_PKS5_S8_S6_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8549:
	.section	.text$_ZSt12__niter_wrapIPP6vertexET_RKS3_S3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_wrapIPP6vertexET_RKS3_S3_
	.def	__ZSt12__niter_wrapIPP6vertexET_RKS3_S3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_wrapIPP6vertexET_RKS3_S3_:
LFB8550:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8550:
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE
	.def	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEC1EONS0_15_Iter_comp_iterIS5_EE:
LFB8555:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRPFbP6vertexS1_EEONSt16remove_referenceIT_E4typeEOS6_
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE8555:
	.section	.text$_ZSt11__push_heapIPP6vertexiS1_N9__gnu_cxx5__ops14_Iter_comp_valIPFbS1_S1_EEEEvT_T0_SA_T1_RT2_,"x"
	.linkonce discard
	.globl	__ZSt11__push_heapIPP6vertexiS1_N9__gnu_cxx5__ops14_Iter_comp_valIPFbS1_S1_EEEEvT_T0_SA_T1_RT2_
	.def	__ZSt11__push_heapIPP6vertexiS1_N9__gnu_cxx5__ops14_Iter_comp_valIPFbS1_S1_EEEEvT_T0_SA_T1_RT2_;	.scl	2;	.type	32;	.endef
__ZSt11__push_heapIPP6vertexiS1_N9__gnu_cxx5__ops14_Iter_comp_valIPFbS1_S1_EEEEvT_T0_SA_T1_RT2_:
LFB8556:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
L134:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jle	L131
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	24(%ebp), %eax
	leal	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEclIPS3_S3_EEbT_RT0_
	subl	$8, %esp
	testb	%al, %al
	je	L131
	movl	$1, %eax
	jmp	L132
L131:
	movl	$0, %eax
L132:
	testb	%al, %al
	je	L133
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
	jmp	L134
L133:
	leal	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRP6vertexEONSt16remove_referenceIT_E4typeEOS4_
	movl	12(%ebp), %edx
	leal	0(,%edx,4), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8556:
	.section	.text$_ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIP6vertexEEPT_PKS5_S8_S6_,"x"
	.linkonce discard
	.globl	__ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIP6vertexEEPT_PKS5_S8_S6_
	.def	__ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIP6vertexEEPT_PKS5_S8_S6_;	.scl	2;	.type	32;	.endef
__ZNSt20__copy_move_backwardILb1ELb1ESt26random_access_iterator_tagE13__copy_move_bIP6vertexEEPT_PKS5_S8_S6_:
LFB8557:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L136
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	movl	%edx, %ecx
	negl	%ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_memmove
L136:
	movl	-12(%ebp), %eax
	sall	$2, %eax
	negl	%eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8557:
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEclIPS3_S3_EEbT_RT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEclIPS3_S3_EEbT_RT0_
	.def	__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEclIPS3_S3_EEbT_RT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Iter_comp_valIPFbP6vertexS3_EEclIPS3_S3_EEbT_RT0_:
LFB8558:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %ecx
	movl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	*%eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE8558:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB8568:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8568:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB8567:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L143
	cmpl	$65535, 12(%ebp)
	jne	L143
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L143:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8567:
	.def	__GLOBAL__sub_I__Z10comparatorP6vertexS0_;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z10comparatorP6vertexS0_:
LFB8569:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE8569:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z10comparatorP6vertexS0_
	.ident	"GCC: (MinGW.org GCC Build-2) 9.2.0"
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	___cxa_throw_bad_array_new_length;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
