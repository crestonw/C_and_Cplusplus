#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_330
#define STRUCT_330

struct Pixel
{
	unsigned char r, g, b;
	
	Pixel(void);
	Pixel(unsigned char r, unsigned char g, unsigned char b);
};

struct Image
{
	int width, height;
	Pixel *pixels;

	Image(void);
	Image(int width, int height);
	Image(int width, int height, Pixel *pixels);
	Image(Image &img);
	
	void ResetSize(int width, int height);
};

#endif
