#include <stdio.h>
#include <stdlib.h>
#include <sink.h>

// The default constructor for the Sink class. The two Image objects are initialized
// to NULL.
Sink::Sink()
{
	img1 = 0;
	img2 = 0;
}

// The SetInput method takes an Image pointer and sets the img1 data member
// to point to the given Image pointer.
void
Sink::SetInput(Image *image)
{
	this->img1 = image;
}

// The SetInput2 method takes an Image pointer and sets the img2 data member
// to point to the given Image pointer.
void
Sink::SetInput2(Image *image)
{
	this->img2 = image;
}
