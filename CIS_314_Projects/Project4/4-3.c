//  Created by Creston Wilson on 2/8/18.
//  References: CIS314 Lecture Slides and Piazza

#include <stdio.h>

/*
int sum(int from, int to) {
    int result = 0;
    do {
        result += from;
        ++from;
    } while (from <= to);
    return result;
}
*/

int sum(int from, int to) {
    
    int result = 0;
    
    // Ensure that argument *from* is in %ecx,
    // argument *to* is in %edx, *result* is in %eax - do not modify.
    __asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
    __asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));
    __asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));
    
    // Your IA32 code goes below - comment each instruction...
    // Label the loop that marks the do loop in the C code.
    __asm__(".LOOP:");
    
    // Add from to result and save the value in the location of result.
    __asm__("addl %ecx, %eax");
    
    // Increment from by 1.
    __asm__("addl $1, %ecx");
    
    // Compare from and to.
    __asm__("cmpl %ecx, %edx");
    
    // If the value of from is greater than or equal to to, then jump back to .LOOP
    __asm__("jge .LOOP");
    
    // Ensure that *result* is in %eax for return - do not modify.
    __asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
    return result;
}

// Test cases
int main()
{
    printf("%i\n", sum(1, 6));
    printf("%i\n", sum(3, 5));
    return 0;
}
