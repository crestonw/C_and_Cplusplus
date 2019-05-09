#include "stdio.h"

unsigned int replace(unsigned int x, int i, unsigned char b) {
	unsigned int mask = 0x000000FF;
	mask <<= (i * 8);
	x = x & (~mask);
	unsigned int hex = b;
	x = (hex << i * 8) | x;
	return x;
}

int main() {
	printf("0x%X\n", replace(0x12345678, 2, 0xAB));
	printf("0x%X\n", replace(0x12345678, 0, 0xAB));
	return 0;
}
