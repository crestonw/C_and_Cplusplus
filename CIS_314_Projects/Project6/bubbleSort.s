	.file	"bubbleSort.c"
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
	.globl	sortIntArray
	.type	sortIntArray, @function
sortIntArray:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	8(%ebp), %edi
	movl	12(%ebp), %eax
	leal	-1(%eax), %esi
	testl	%esi, %esi
	jle	.L3
	leal	-4(%edi,%eax,4), %ebx
	jmp	.L5
.L7:
	movl	(%eax), %edx
	movl	4(%eax), %ecx
	cmpl	%ecx, %edx
	jle	.L6
	movl	%ecx, (%eax)
	movl	%edx, 4(%eax)
.L6:
	addl	$4, %eax
	cmpl	%ebx, %eax
	jne	.L7
.L8:
	subl	$4, %ebx
	subl	$1, %esi
	je	.L3
.L5:
	testl	%esi, %esi
	jle	.L8
	movl	%edi, %eax
	jmp	.L7
.L3:
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	sortIntArray, .-sortIntArray
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%i"
	.text
	.globl	printArray
	.type	printArray, @function
printArray:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	movl	8(%ebp), %esi
	movl	%esi, %ebx
	addl	$40, %esi
.L12:
	subl	$4, %esp
	pushl	(%ebx)
	pushl	$.LC0
	pushl	$1
	call	__printf_chk
	addl	$4, %ebx
	addl	$16, %esp
	cmpl	%esi, %ebx
	jne	.L12
	subl	$12, %esp
	pushl	$10
	call	putchar
	addl	$16, %esp
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.size	printArray, .-printArray
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
	movl	$9, -52(%ebp)
	movl	$8, -48(%ebp)
	movl	$7, -44(%ebp)
	movl	$6, -40(%ebp)
	movl	$5, -36(%ebp)
	movl	$4, -32(%ebp)
	movl	$3, -28(%ebp)
	movl	$2, -24(%ebp)
	movl	$1, -20(%ebp)
	movl	$0, -16(%ebp)
	pushl	$10
	leal	-52(%ebp), %eax
	pushl	%eax
	call	sortIntArray
	addl	$8, %esp
	movl	-12(%ebp), %eax
	xorl	%gs:20, %eax
	je	.L16
	call	__stack_chk_fail
.L16:
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
