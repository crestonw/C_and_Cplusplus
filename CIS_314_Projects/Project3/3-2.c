// Author: Creston Wilson
// References: CIS314 Lecture Slides, stackoverflow.com

#include <stdio.h>
#include <stdlib.h>


int decode(int x, int y, int z)
{
	// Initialize variables
	int res, sub;
	
	// movl 12(%ebp) which is y and put into %edx
	sub = y; 
	// subl 16(%ebp) which is z by %edx and store in %edx
	sub -= z;
	// movl %edx into %eax
	res = sub;
	// imull 8(%ebp) which is x by %edx and store in %edx 
	sub *= x;
	// sall by $31 and store at %eax
	res <<= 31;
	// sall by $31 and store at %eax
	res >>= 31;
	// xorl with what's in %edx and store at %eax
	res ^= sub;

	return res;
}

int main()
{
	printf("%d\n", decode(1, 2, 4));
	printf("%d\n", decode(-4, -8, -12));
	return 0;
}