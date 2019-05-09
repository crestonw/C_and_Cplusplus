#include <stdio.h>
#include <stdlib.h>
#include <image.h>
#ifndef SINK_330
#define SINK_330

/*
The class Sink that has two pointers to Image objects for data members.
It has a default constructor and getters and setters for the data members.
*/
class Sink
{
	protected:
		Image *img1;
		Image *img2;

	public:
		Sink();
		void SetInput(Image *image);
		void SetInput2(Image *image);

		Image * GetImg1() { return img1; };
		Image * GetImg2() { return img2; };

};

#endif
