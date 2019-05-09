#include <filter.h>

/*
The Update method for all Filter objects. This checks to see if its
Sink Images are intialized to something other than NULL. If so,
each of the two Image objects are Updated via their Update method.
The Filter object's Execute methods is then called.
*/
void
Filter::Update()
{
	if (img1 != NULL) img1->Update();
	if (img2 != NULL) img2->Update();

	this->Execute();
}

/*
The Shrinker Execute method takes its Image object and shrinks it to half the
width and half the height and saves the shrunk Image where it found it.
*/
void
Shrinker::Execute()
{
	this->GetOutput()->SetWidth((this->GetImg1()->GetWidth())/2);
	this->GetOutput()->SetHeight((this->GetImg1()->GetHeight())/2);

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight()); i++)
	{
		for (int j = 0; j < (this->GetOutput()->GetWidth()); j++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+j] = this->GetImg1()->GetPixels()[(i*2) * (this->GetImg1()->GetWidth()) + (j*2)];
		}
	}

}

/*
The LRCombine Execute method takes two Image objects that are the same height
and combines them side by side. Then saves the combined Image where it found it.
*/
void
LRCombine::Execute()
{
	this->GetOutput()->SetWidth((this->GetImg1()->GetWidth())+(this->GetImg2()->GetWidth()));
	this->GetOutput()->SetHeight(this->GetImg1()->GetHeight());

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight()); i++)
	{
		for (int j = 0; j < (this->GetImg1()->GetWidth()); j++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+j] = this->GetImg1()->GetPixels()[i*(this->GetImg1()->GetWidth())+j];
		}

		for (int k = 0; k < (this->GetImg2()->GetWidth()); k++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+(this->GetImg1()->GetWidth() + k)] = this->GetImg2()->GetPixels()[i*(this->GetImg2()->GetWidth())+k];
		}
	}
}

/*
The TBCombine Execute method takes two Image objects that are the same width
and combines then one on top of the other. The combined Image is then saved where
it was found.
*/
void
TBCombine::Execute()
{
	this->GetOutput()->SetWidth(this->GetImg1()->GetWidth());
	this->GetOutput()->SetHeight(this->GetImg1()->GetHeight() + this->GetImg2()->GetHeight());

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight() * this->GetOutput()->GetWidth()); i++)
	{
		if (i < (this->GetImg1()->GetWidth() * this->GetImg1()->GetHeight()))
		{
			this->GetOutput()->GetPixels()[i] = this->GetImg1()->GetPixels()[i];
		}

		else
		{
			this->GetOutput()->GetPixels()[i] = this->GetImg2()->GetPixels()[i-(this->GetImg2()->GetWidth() * this->GetImg2()->GetHeight())];
		}
	}
}

/*
The Blender Execute method takes two Image objects and blends them by a
factor that is set within the Blender object. The blended Image is then saved
where it was found.
*/
void
Blender::Execute()
{
	this->GetOutput()->SetWidth(this->GetImg1()->GetWidth());
	this->GetOutput()->SetHeight(this->GetImg1()->GetHeight());

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight() * this->GetOutput()->GetWidth()); i++)
	{
		this->GetOutput()->GetPixels()[i].r = this->GetFactor() * this->GetImg1()->GetPixels()[i].r + (1 - this->GetFactor()) * this->GetImg2()->GetPixels()[i].r;
		this->GetOutput()->GetPixels()[i].g = this->GetFactor() * this->GetImg1()->GetPixels()[i].g + (1 - this->GetFactor()) * this->GetImg2()->GetPixels()[i].g;
		this->GetOutput()->GetPixels()[i].b = this->GetFactor() * this->GetImg1()->GetPixels()[i].b + (1 - this->GetFactor()) * this->GetImg2()->GetPixels()[i].b;
	}
}
