#include <image.h>
#include <source.h>
#include <stdio.h>
#include <stdlib.h>

// The default constructor for Pixel struct initializes its three unsigned chars to be 0.
Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}

// The parameter constructor initializes its three unsigned chars to be the given
// parameter unsigned chars.
Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

// The default constructor for the Image class. This initializes its four data
// members to be 0.
Image::Image()
{
	width = 0;
	height = 0;
	pixels = 0;
	src = 0;

}

/*
The parameter constructor for the Image class. It sets the given width and height
and then allocates memory for its pixel buffer.
*/
Image::Image(int width, int height)
{
	this->width = width;
	this->height = height;
	pixels = (Pixel *) malloc(sizeof(char) * height * width);
}

/*
The second parameter constructor for the Image class. It sets the width, height,
and array of Pixels.
*/
Image::Image(int width, int height, Pixel *pixels)
{
	this->width = width;
	this->height = height;

	SetPixels(pixels);
}

/*
The copy constructor for the Image class. It takes another pointer to an Image
object and copys the contents into a new Image object.
*/
Image::Image(Image *img)
{
	this->width = img->GetWidth();
	this->height = img->GetHeight();

	SetPixels(img->GetPixels());
}

/*
The ResetSize method for the Image class resets the width and height of the
Image to be the given parameters.
*/
void
Image::ResetSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

/*
The setter method for the array of Pixels in the Image class. This method
takes a Pixel array as a parameter and allocates new memory for the array
then copys over all the contents of the given array into the new memory location.
*/
void
Image::SetPixels(Pixel *p)
{
	this->pixels = (Pixel *) malloc(sizeof(Pixel) * this->width * this->height);

	for (int i = 0; i < (this->width * this->height); i++)
	{
		this->pixels[i].r = p[i].r;
		this->pixels[i].g = p[i].g;
		this->pixels[i].b = p[i].b;
	}
}

/*
This is the Update method for all Image objects. It simply calls the current
Update method of its Source data member.
*/
void
Image::Update()
{
	src->Update();
}
