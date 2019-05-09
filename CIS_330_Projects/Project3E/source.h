#ifndef SOURCE
#define SOURCE
#include <image.h>

/*
The class Source has one Image object as a data member. It has a default constructor,
a pure virtual function, a getter, and a virtual method to update its Image.
*/
class Source
{

	protected:
		Source();
		virtual void Execute(void) = 0;
		Image img;

	public:
		virtual void Update();
		Image * GetOutput();
};

#endif
