#include <source.h>
#include <sink.h>

/*
The class Filter is a Source and a Sink. It has a default constructor and
implements its own vitual Update method.
*/
class Filter : public Source, public Sink
{
	public:
		Filter() {};
		virtual void Update();
};

/*
The class Shrinker is a Filter and has a default constructor. It also
implements its own virtual Execute method.
*/
class Shrinker : public Filter
{
	public:
		Shrinker() {};
		virtual void Execute();
};

/*
The class LRCombine is a Filter and has a default constructor. It also
implements its own virtual Execute method.
*/
class LRCombine : public Filter
{
	public:
		LRCombine() {};
		virtual void Execute();
};

/*
The class TBCombine is a Filter and has a default constructor. It also
implements its own virtual Execute method.
*/
class TBCombine : public Filter
{
	public:
		TBCombine() {};
		virtual void Execute();
};

/*
The class Blender is a Filter and has a default constructor that sets the data
member factor to 0. It also implements its own virtual Execute method. The
one data member this class has also gets getter and setter methods.
*/
class Blender : public Filter
{
	private:
		double factor;

	public:
		Blender() { factor=0; };
		virtual void Execute();
		double GetFactor() { return factor; };
		void SetFactor(double f) { factor = f; };
};
