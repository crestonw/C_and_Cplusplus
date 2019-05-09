#include <stdio.h>

int ge(float x, float y)
{
	// Provided Code by Instructor
	unsigned ux = * ((unsigned *) &x); // convert x raw bits
	unsigned uy = * ((unsigned *) &y); // convert y raw bits
	unsigned sx = ux >> 31; // extract sign bit of ux
	unsigned sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	// Boolean Expression that returns 1 for x >= y and 0 otherwise.
	return ((sy > sx) || (ux == uy) || ((sx == sy) && (ux >= uy))); 
}

int main()
{
	// Test Cases
	printf("%i\n", ge(0.0f, 0.0f));
	printf("%i\n", ge(-0.0f, 0.0f));
	printf("%i\n", ge(-1.0f, 0.0f));
	printf("%i\n", ge(0.0f, 1.0f));
	printf("%i\n", ge(1.0f, 0.0f));
	printf("%i\n", ge(0.0f, -1.0f));
}
