#include <stdio.h>

unsigned int extract(unsigned int x, int i)
{
	// Initialize a signed instance of variable x.
	signed int x2 = x;
	// Create a mask and shift in into place according to i.
	unsigned int mask = 0x000000FF;
	mask = mask << (i*8);
	// Preform the exchange between mask and signed variable.
	x2 = x2 & mask;
	x2 = x2 << (24 - (i*8));
	// Sign extension
	x2 = x2 >> 24;
	return x2;
}

int main()
{
	// Test Cases
	printf("0x%08X\n", extract(0x12345678, 0));
	printf("0x%08X\n", extract(0xABCDEF00, 2));
}
