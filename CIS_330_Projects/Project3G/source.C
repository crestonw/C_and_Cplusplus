#include <source.h>
#include <stdio.h>
#include <stdlib.h>

// The getter for the Image object that returns a pointer.
Image*
Source::GetOutput()
{
	return &output;
}

// The default constructor, it calls the Image object's SetSource method to
// let the Image know what type of Source it's dealing with.
Source::Source()
{
	output.SetSource(this);
}

// The update method for all Source objects, this simply calls the current
// objects Execute method.
void
Source::Update()
{
	char msg[128];
	sprintf(msg, "%s: about to execute", SourceName());
	Logger::LogEvent(msg);
	Execute();
	sprintf(msg, "%s: done executing", SourceName());
	Logger::LogEvent(msg);
}
