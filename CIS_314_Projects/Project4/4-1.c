//  Created by Creston Wilson on 2/8/18.
//  for CIS314.
//  References include cs.virginia.edu and CIS314 Lecture Slides

#include <stdio.h>
#include <stdlib.h>

/*
 
 loop:
    pushl %ebp                  // Save the frame pointer.
    movl %esp, %ebp             // Create new frame pointer.
    pushl %esi                  // Since this is a callee-save register, it pushes the old value of
                                %esi onto the stack as part of the stack frame setup.
    pushl %ebx                  // Since this is a callee-save register, it pushes the old value of
                                %ebx onto the stack as part of the stack frame setup.
    movl 8(%ebp), %esi          // Moves the value of x into the %esi register
    movl 12(%ebp), %ecx         // Moves the value of y into the %ecx register
    movl $2, %edx               // Moves the value 2 into the %edx register as the value
                                of mask.
    movl $-1, %eax              // Moves the value -1 into the %eax register as the
                                value of result.
 .L2:
    movl %esi, %ebx             // Moves the value of value of x into the %ebx register.
    andl %edx, %ebx             // Ands the value of result with the value of x, the value is stored in x which is in %ebx.
    xorl %ebx, %eax             // Exclusive-Or of x and result and the value is saved in result which is in %eax.
    sall %cl, %edx              // An arithmetic shift left on result by the only using
                                the least significant bit of y in the %ecx register.
    cmpl $1, %edx               // Jumps into the loop if %edx which is mask is greater than 1.
    jg .L2
    popl %ebx                   // Pops the top element of the stack into the %ebx register.
    popl %esi                   // Pops the top element of the stack into the %esi register.
    popl %ebp                   // Pops the top element of the stack into the %ebp register.
    ret                         // Returns the value of what's in the %eax register, which is result.
 
*/

// Changed template
int loop(int x, int y)
{
    int result = -1;
    for (int mask = 2; mask > 1; mask <<= y)
    {
        result ^= (x & mask);
    }
    return result;
}

// Test Cases
int main()
{
    printf(loop(1, 5));     // Output: -1
    printf(loop(2, 4));     // Output: -3
    printf(loop(3, 3));     // Output: -3
    printf(loop(4, 2));     // Output: -1
    printf(loop(5, 1));     // Output: -5
    return 0;
}










