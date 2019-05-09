	.file	"doBubble.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movl	(%edx), %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	%ecx, (%eax)
	popl	%ebx
	popl	%ebp
	ret
	.size	swap, .-swap
	.globl	bubble
	.type	bubble, @function
bubble:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	12(%ebp), %eax
	leal	-1(%eax), %edi
	movl	8(%ebp), %esi
	leal	(%esi,%eax,4), %ebx
.L7:
	testl	%edi, %edi
	jle	.L3
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	$0, %esi
.L6:
	movl	(%eax), %ecx
	movl	-4(%eax), %edx
	cmpl	%edx, %ecx
	jge	.L5
	movl	%ecx, -4(%eax)
	movl	%edx, (%eax)
	movl	$1, %esi
.L5:
	addl	$4, %eax
	cmpl	%eax, %ebx
	jne	.L6
	subl	$1, %edi
	subl	$4, %ebx
	testl	%esi, %esi
	jne	.L7
.L3:
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	bubble, .-bubble
	.globl	main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$52, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$5, -52(%ebp)
	movl	$1, -48(%ebp)
	movl	$4, -44(%ebp)
	movl	$2, -40(%ebp)
	movl	$8, -36(%ebp)
	movl	$0, -32(%ebp)
	movl	$-11, -28(%ebp)
	movl	$3, -24(%ebp)
	movl	$8, -20(%ebp)
	movl	$9, -16(%ebp)
	pushl	$10
	leal	-52(%ebp), %eax
	pushl	%eax
	call	bubble
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L12
	call	__stack_chk_fail
.L12:
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
