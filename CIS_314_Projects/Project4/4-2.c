
//  Created by Creston Wilson on 2/8/18.
//  References: CIS314 Lecture Slides and Piazza

#include <stdio.h>
#include <stdlib.h>

/*
 .L3:                       // Marks the inner loop of transpose.
 movl (%edx), %esi          // Moves the value that's in the memory location of a[j][i] into the %esi register which.
 movl (%eax), %ecx          // Moves the value that's in the memory location of a[i][j] into the %ecx register which is t.
 addl $4, %eax              // Increments the register that holds i by 4.
 addl $40, %edx             // Increments the register that holds j by 40.
 movl %esi, -4(%eax)        // Moves a[j][i] into -4 offset of the memory location of i.
 movl %ecx, -40(%edx)       // Moves a[i][i] into -40 offset of the memory location of j.
 cmpl %ebx, %eax           // Compares the values of the registers %ebx and %eax which respectively N and i.
 jne .L3                   // If i is not equal to N we jump back into the inner loop.
 
 */

// Helper function that uses pointers to swap integers.
void swap(int *xp, int *yp)
{
    int t0 = *xp;
    int t1 = *yp;
    *xp = t1;
    *yp = t0;
}

#define N 4
typedef int array_t[N][N];
void transpose(array_t a)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // Uses pointers and a helper method instead of look ups.
            int *rp = &a[i][j];
            int *cp = &a[j][i];
            swap(rp, cp);
        }
    }
}

int main()
{
    // Initialize and declare 2D array of ints.
    array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    
    // Call transpose method.
    transpose(a);
    
    // Loop through transposed array and print the contents of the array.
    printf("{");
    for (int i = 0; i < N; ++i)
    {
        printf("{");
        for (int j = 0; j < 4; ++j)
        {
            printf("%i ", a[i][j]);
        }
        printf("}");
    }
    printf("}");
}



