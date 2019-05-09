#include <stdio.h>
#include <stdlib.h>
#ifndef CLASS_330
#define CLASS_330

struct Pixel
{
	unsigned char r, g, b;
	
	Pixel(void);
	Pixel(unsigned char r, unsigned char g, unsigned char b);
};

class Image
{
	private:
		int width, height;
		Pixel *pixels;

	public:
		Image(void);
		Image(int width, int height);
		Image(int width, int height, Pixel *pixels);
		Image(Image *img);
	
		void ResetSize(int width, int height);

		int GetWidth() { return width; };
		int GetHeight() { return height; };
		Pixel * GetPixels() { return pixels; };

		void SetWidth(int w) { width = w; };
		void SetHeight(int h) { height = h; };
		void SetPixels(Pixel *p);  
};

#endif
