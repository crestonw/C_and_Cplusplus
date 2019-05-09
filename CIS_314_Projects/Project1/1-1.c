#include "stdio.h"

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}	
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}
	
void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

// The main function had to be added in order to compile the file. 
int main() {
        int i = 12345;
        printInt(i);
        printFloat(i);
        printShort(i);
        printLong(i); 
        printDouble(i);
        return 0;
       	// The double function prints 8 hexadecimal represented bytes for this 64-bit system. Whats interesting is that the bytes
        // don't appear to be similarly represented in hex as the printInt function represents the value. I learned that this is
        // because of floats and doubles use different encoding schemes than ints, shorts, and longs. 
}
