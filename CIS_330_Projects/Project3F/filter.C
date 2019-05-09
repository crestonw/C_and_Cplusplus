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
	if (input1 != NULL)
	{
		char msg[1024];
		sprintf(msg, "%s: about to update input1", SinkName());
		Logger::LogEvent(msg);
		input1->Update();
		sprintf(msg, "%s: done updating input1", SinkName());
		Logger::LogEvent(msg);
	}

	if (input2 != NULL)
	{	
		char msg[1024];
		sprintf(msg, "%s: about to update input2", SinkName());
		Logger::LogEvent(msg);
		input2->Update();
		sprintf(msg, "%s: done updating input2", SinkName());
		Logger::LogEvent(msg);
	}

	char msg[1024];
	sprintf(msg, "%s: about to execute", SinkName());
	Logger::LogEvent(msg);
	this->Execute();
	sprintf(msg, "%s: done executing", SinkName());
	Logger::LogEvent(msg);
}

/*
The Shrinker Execute method takes its Image object and shrinks it to half the
width and half the height and saves the shrunk Image where it found it.
*/
void
Shrinker::Execute()
{
	if (this->GetInput1() == NULL)
	{
		DataFlowException e(SinkName(), "Shrinker: no input1");
		throw e;
	}

	this->GetOutput()->SetWidth((this->GetInput1()->GetWidth())/2);
	this->GetOutput()->SetHeight((this->GetInput1()->GetHeight())/2);

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight()); i++)
	{
		for (int j = 0; j < (this->GetOutput()->GetWidth()); j++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+j] = this->GetInput1()->GetPixels()[(i*2) * (this->GetInput1()->GetWidth()) + (j*2)];
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

	if (this->GetInput1() == NULL)
	{
		DataFlowException e(SinkName(), "LRCombine: no input1");
		throw e;
	}

	if (this->GetInput2() == NULL)
	{
		DataFlowException e(SinkName(), "LRCombine: no input2");
		throw e;
	}

	if (this->GetInput1()->GetHeight() != this->GetInput2()->GetHeight())
	{
		char msg[1024];
		sprintf(msg, "%s: heights must match: %d, %d", SinkName(), this->GetInput1()->GetHeight(), this->GetInput2()->GetHeight());
		DataFlowException e(SinkName(), msg);
		throw e;
	}	 

	this->GetOutput()->SetWidth((this->GetInput1()->GetWidth())+(this->GetInput2()->GetWidth()));
	this->GetOutput()->SetHeight(this->GetInput1()->GetHeight());

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight()); i++)
	{
		for (int j = 0; j < (this->GetInput1()->GetWidth()); j++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+j] = this->GetInput1()->GetPixels()[i*(this->GetInput1()->GetWidth())+j];
		}

		for (int k = 0; k < (this->GetInput2()->GetWidth()); k++)
		{
			this->GetOutput()->GetPixels()[i*(this->GetOutput()->GetWidth())+(this->GetInput1()->GetWidth() + k)] = this->GetInput2()->GetPixels()[i*(this->GetInput2()->GetWidth())+k];
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

	if (this->GetInput1() == NULL)
	{
		DataFlowException e(SinkName(), "TBCombine: no input1");
		throw e;
	}

	if (this->GetInput2() == NULL)
	{
		DataFlowException e(SinkName(), "TBCombine: no input2");
		throw e;
	}
	
	this->GetOutput()->SetWidth(this->GetInput1()->GetWidth());
	this->GetOutput()->SetHeight(this->GetInput1()->GetHeight() + this->GetInput2()->GetHeight());

	if (this->GetInput2()->GetWidth() != this->GetInput1()->GetWidth())
	{
		char msg[1024];
		sprintf(msg, "%s: widths must match: %d, %d", SinkName(), this->GetInput1()->GetWidth(), this->GetInput2()->GetWidth());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight() * this->GetOutput()->GetWidth()); i++)
	{
		if (i < (this->GetInput1()->GetWidth() * this->GetInput1()->GetHeight()))
		{
			this->GetOutput()->GetPixels()[i] = this->GetInput1()->GetPixels()[i];
		}

		else
		{
			this->GetOutput()->GetPixels()[i] = this->GetInput2()->GetPixels()[i-(this->GetInput2()->GetWidth() * this->GetInput2()->GetHeight())];
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
	if (this->GetInput1() == NULL)
	{
		DataFlowException e(SinkName(), "Blender: no input1");
		throw e;
	}

	if (this->GetInput2() == NULL)
	{
		DataFlowException e(SinkName(), "Blender: no input2");
		throw e;
	}

	if ((this->GetFactor() > 1) || (this->GetFactor() < 0))
	{
		char msg[1024];
		sprintf(msg, "Invalid factor for Blender: %f",this->GetFactor());
		DataFlowException e(SinkName(), msg);
		throw e;
	} 	
	
	this->GetOutput()->SetWidth(this->GetInput1()->GetWidth());
	this->GetOutput()->SetHeight(this->GetInput1()->GetHeight());

	Pixel *p = (Pixel *) malloc(sizeof(Pixel) * this->GetOutput()->GetWidth() * this->GetOutput()->GetHeight());

	this->GetOutput()->SetPixels(p);

	for (int i = 0; i < (this->GetOutput()->GetHeight() * this->GetOutput()->GetWidth()); i++)
	{
		this->GetOutput()->GetPixels()[i].r = this->GetFactor() * this->GetInput1()->GetPixels()[i].r + (1 - this->GetFactor()) * this->GetInput2()->GetPixels()[i].r;
		this->GetOutput()->GetPixels()[i].g = this->GetFactor() * this->GetInput1()->GetPixels()[i].g + (1 - this->GetFactor()) * this->GetInput2()->GetPixels()[i].g;
		this->GetOutput()->GetPixels()[i].b = this->GetFactor() * this->GetInput1()->GetPixels()[i].b + (1 - this->GetFactor()) * this->GetInput2()->GetPixels()[i].b;
	}
}
