#include <image.h>
#include <stdio.h>
#include <stdlib.h>

Pixel::Pixel(void)
{
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Image::Image(void)
{
	width = 0;
	height = 0;
	pixels = 0;
}

Image::Image(int width, int height)
{
	this->width = width;
	this->height = height;
	pixels = (Pixel *) malloc(sizeof(char) * height * width);
}

Image::Image(int width, int height, Pixel *pixels)
{
	this->width = width;
	this->height = height;
	this->pixels = (Pixel *) malloc(sizeof(char) * width * height);

	SetPixels(pixels);
}

Image::Image(Image &img)
{
	width = img.width;
	height = img.height;
	pixels = (Pixel *) malloc(sizeof(char) * img.width * img.height);

	SetPixels(pixels);
}

void
Image::ResetSize(int width, int height)
{
	width = 0;
	height = 0;
}

void
Image::SetPixels(Pixel *p)
{

		for (int i = 0; i < (this->width * this->height); i++)
		{
			this->pixels[i] = p[i];
		}
}
