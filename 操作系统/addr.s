	.file	"addr.cpp"
	.text
	.globl	A
	.bss
	.align 4
	.type	A, @object
	.size	A, 4
A:
	.zero	4
	.globl	B
	.align 4
	.type	B, @object
	.size	B, 4
B:
	.zero	4
	.globl	C
	.data
	.align 4
	.type	C, @object
	.size	C, 4
C:
	.long	2
	.local	_ZL1D
	.comm	_ZL1D,4,4
	.local	_ZL1E
	.comm	_ZL1E,4,4
	.align 4
	.type	_ZL1F, @object
	.size	_ZL1F, 4
_ZL1F:
	.long	4
	.section	.rodata
	.align 4
	.type	_ZL1G, @object
	.size	_ZL1G, 4
_ZL1G:
	.long	5
	.type	_ZL1H, @object
	.size	_ZL1H, 1
_ZL1H:
	.byte	6
	.local	_ZZ4mainE1d
	.comm	_ZZ4mainE1d,4,4
	.local	_ZZ4mainE1e
	.comm	_ZZ4mainE1e,4,4
	.data
	.align 4
	.type	_ZZ4mainE1f, @object
	.size	_ZZ4mainE1f, 4
_ZZ4mainE1f:
	.long	4
	.section	.rodata
.LC0:
	.string	"123456"
.LC1:
	.string	"PID is : %d\n\n"
.LC2:
	.string	"int A   \t\tA_addr = %p\n"
.LC3:
	.string	"int B = 0      \t\tB_addr = %p\n"
.LC4:
	.string	"int C = 2 \t\tC_addr = %p\n"
.LC5:
	.string	"static int D \t\tD_addr = %p\n"
.LC6:
	.string	"static int E = 0\tE_addr = %p\n"
.LC7:
	.string	"static int F = 4\tF_addr = %p\n"
.LC8:
	.string	"const int G = 5\t\tG_addr = %p\n"
.LC9:
	.string	"const char H = 6\tH_addr = %p\n"
.LC10:
	.string	"int a   \t\t\ta_addr = %p\n"
.LC11:
	.string	"int b = 0      \t\tb_addr = %p\n"
.LC12:
	.string	"int c = 2 \t\t\tc_addr = %p\n"
.LC13:
	.string	"static int d \t\td_addr = %p\n"
.LC14:
	.string	"static int e = 0\te_addr = %p\n"
.LC15:
	.string	"static int f = 4\tf_addr = %p\n"
.LC16:
	.string	"const int g = 5\t\tg_addr = %p\n"
	.align 8
.LC17:
	.string	"char char1[] = 'abcde' \t\t\tchar1_addr = %p\n"
	.align 8
.LC18:
	.string	"char *cptr = '1' \t\t\t cptr_addr = %p\n"
	.align 8
.LC19:
	.string	"value of the cptr \t\t\t cptr_value = 0x%p\n"
	.align 8
.LC20:
	.string	"value of %p \t\t\t  value_0x %p = %d\n"
	.align 8
.LC21:
	.string	"int *heap = malloc(sizeof(int)*4)\t heapp_addr = %p\n"
	.align 8
.LC22:
	.string	"int *heap = malloc(sizeof(int)*4)\t &heapp_addr = %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -44(%rbp)
	movl	$2, -40(%rbp)
	movl	$5, -36(%rbp)
	movl	$1684234849, -14(%rbp)
	movw	$101, -10(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -32(%rbp)
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	A(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	B(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	C(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZL1D(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZL1E(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZL1F(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZL1G(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZL1H(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZZ4mainE1d(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZZ4mainE1e(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	_ZZ4mainE1f(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	leaq	-14(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-14(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movq	-24(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC21(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC22(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
