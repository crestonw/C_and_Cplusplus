#include <source.h>
#include <sink.h>

class Filter : public Source, public Sink
{
	public:
		Filter(void) {};
};

class Shrinker : public Filter
{
	public:
		Shrinker(void) {};
		virtual void Execute();		
};

class LRCombine : public Filter
{
	public:
		LRCombine(void) {};
		virtual void Execute();
};

class TBCombine : public Filter
{
	public:
		TBCombine(void) {};
		virtual void Execute();
};

class Blender : public Filter
{
	private: 
		double factor;

	public:
		Blender(void) { factor=0; };
		virtual void Execute();
		double GetFactor() { return factor; };
		void SetFactor(double f) { factor = f; };
};

