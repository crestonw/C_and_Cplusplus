#include <stdio.h>
#include <stdlib.h>
#include <sink.h>

Sink::Sink()
{
	img1 = new Image();
	img2 = new Image();
}

void
Sink::SetInput(Image *image)
{
	this->img1 = image;
}


void
Sink::SetInput2(Image *image)
{
	this->img2 = image;
}
