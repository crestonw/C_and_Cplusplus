#include "stdio.h"

int even(unsigned int x) {
	unsigned int mask = 0xAAAAAAAA;
	x = x & (~mask);
	return !!x;
}

unsigned int main() {
	printf("0x%X\n", even(0x0));
	printf("0x%X\n", even(0x1));
	printf("0x%X\n", even(0x2));
	printf("ox%X\n", even(0x3));
	printf("0x%X\n", even(0xFFFFFFFF));
	printf("0x%X\n", even(0xAAAAAAAA));
	return 0;
}
