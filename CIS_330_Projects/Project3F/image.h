#ifndef CLASS_330
#define CLASS_330

// Forward declaration of the Source class.
class Source;

// The Pixel struct that contains three unsigned char values for red, green, and blue.
struct Pixel
{
	unsigned char r, g, b;

	Pixel();
	Pixel(unsigned char r, unsigned char g, unsigned char b);
};

/*
The Image class that has four data members, along with getters and setters for
each of the members. The class implements a default, parameter, and copy constructor.
The class has a Update method that will be used to update the objects source.
Finally, a ResetSize method that allows the width and height to be set simultaneously.
*/
class Image
{
	private:
		int width, height;
		Pixel *pixels;
		Source *src;

	public:
		void Update();

		Image();
		Image(int width, int height);
		Image(int width, int height, Pixel *pixels);
		Image(Image *img);

		void ResetSize(int width, int height);

		int GetWidth() { return width; };
		int GetHeight() { return height; };
		Pixel * GetPixels() { return pixels; };
		Source * GetSource() { return src; };

		void SetWidth(int w) { width = w; };
		void SetHeight(int h) { height = h; };
		void SetPixels(Pixel *p);
		void SetSource(Source *s) { src = s; };
};

#endif
