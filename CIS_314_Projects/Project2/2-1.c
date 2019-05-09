#include <stdio.h>

int mask(int n)
{
	// Initialize mask variable and position the mask by shifting
	unsigned int mask = 0xFFFFFFFF;
	mask = mask >> (32-n);

	return mask;				
}

int main()
{
	// Test Cases
	printf("0x%x\n", mask(1));
	printf("0x%x\n", mask(2));
	printf("0x%x\n", mask(3));
	printf("0x%x\n", mask(5));
	printf("0x%x\n", mask(8));
	printf("0x%x\n", mask(16));
	printf("0x%x\n", mask(32));
	return 0;
}

