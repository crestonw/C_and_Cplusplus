#include <stdio.h>
#include <stdlib.h>
#include <image.h>
#ifndef SINK_330
#define SINK_330

class Sink
{
	private:
		Image *img1;
		Image *img2;	

	public:
		Sink(void);
		void SetInput(Image *image);
		void SetInput2(Image *image);

		Image * GetImg1() { return img1; };
		Image * GetImg2() { return img2; };
};

#endif
