#include "stdio.h"

unsigned int combine(unsigned int x, unsigned int y) {
	unsigned int z;
	x = x & 0xFF000000;
	y = y & 0x00FFFFFF;
	z = x | y;
	return z;	
}

int main() {
	printf("0x%x\n", combine(0x12345678, 0xABCDEF00));
	printf("0x%x\n", combine(0xABCDEF00, 0x12345678));
	return 0;
}


