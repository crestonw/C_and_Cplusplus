#include <source.h>
#include <stdio.h>
#include <stdlib.h>

// The getter for the Image object that returns a pointer.
Image*
Source::GetOutput()
{
	return &(this->img);
}

// The default constructor, it calls the Image object's SetSource method to
// let the Image know what type of Source it's dealing with.
Source::Source()
{
	img.SetSource(this);
}

// The update method for all Source objects, this simply calls the current
// objects Execute method.
void
Source::Update()
{
	this->Execute();
}
