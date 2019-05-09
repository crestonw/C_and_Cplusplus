#include <source.h>
#include <sink.h>

class Color : public Source
{
	public:
		const char *SourceName() { return "Color"; };
		Color(int width, int height, unsigned char r, unsigned char g, unsigned char b);
		virtual void Execute() {};
};

class CheckSum : public Sink
{
	public:
		const char *SinkName() { return "CheckSum"; };
		void OutputCheckSum(const char *filename);
};

/*
The class Filter is a Source and a Sink. It has a default constructor and
implements its own vitual Update method.
*/
class Filter : public Source, public Sink
{
	protected:
		virtual const char *FilterName() = 0;
	public:
		const char *SourceName() { return FilterName(); };
		const char *SinkName() { return FilterName(); };
		Filter() {};
		virtual void Update();
};

class Mirror : public Filter
{
	public:
		virtual const char *FilterName() { return "Mirror"; };
		Mirror() {};
		virtual void Execute();
};

class Rotate : public Filter
{
	public:
		virtual const char *FilterName() { return "Rotate"; };
		Rotate() {};
		virtual void Execute();
};

class Subtract : public Filter
{
	public:
		virtual const char *FilterName() { return "Subtract"; };
		Subtract() {};
		virtual void Execute();
};

class Grayscale : public Filter
{
	public:
		virtual const char *FilterName() { return "Grayscale"; };
		Grayscale() {};
		virtual void Execute();
};

class Blur : public Filter
{
	public:
		virtual const char *FilterName() { return "Blur"; };
		Blur() {};
		virtual void Execute();
};

/*
The class Shrinker is a Filter and has a default constructor. It also
implements its own virtual Execute method.
*/
class Shrinker : public Filter
{
	public:
		virtual const char *FilterName() { return "Shrinker"; };
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
		virtual const char *FilterName() { return "LRCombine"; };
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
		virtual const char *FilterName() { return "TBCombine"; };
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
		virtual const char *FilterName() { return "Blender"; };
		Blender() { factor=0; };
		virtual void Execute();
		double GetFactor() { return factor; };
		void SetFactor(double f) { factor = f; };
};
