#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct
{
	int width;
	int height;
	Pixel *pixels;
} Image;

Image * ReadImage(char *filename)
{
/* These lines are useful:
 * char magicNum[128];
 * int width, height, maxval;
 * fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
 * where f_in is the name of the input FILE.
 */

	// Initialize local variables
	char magicNum[128];
	int width, height, maxval;
	FILE *f_in = fopen(filename, "r");

	// Get the header from the file
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	
	// Initialize values of img
	Image *img;
	img = malloc(sizeof(Image));
	img->width = width;
	img->height = height;
	img->pixels = malloc((img->width) * (img->height) * sizeof(Pixel));

	fread(img->pixels, (sizeof(Pixel)*width*height), 1, f_in);

	fclose(f_in);
	return img;
}

void WriteImage(Image *img, char *filename)
{
	int i;
	FILE *f_out;
	
	f_out = fopen(filename, "w");
	fprintf(f_out, "%s\n%d %d\n%d\n", "P6", img->width, img->height, 255);

	fwrite(img->pixels, sizeof(Pixel), (img->width * img->height), f_out);
	
	free(img->pixels);
	free(img);
	fclose(f_out);
}

Image * YellowDiagonal(Image *input)
{
	int i,j;
	Image *img;
	img = malloc(sizeof(Image));
	img->width = input->width;
	img->height = input->height;
	img->pixels = malloc(sizeof(Pixel) * input->height * input->width);

	for (i = 0; i < (input->height * input->width); i++)
	{
		img->pixels[i] = input->pixels[i];
	}

	free(input->pixels);
	free(input);

	for (i = 0; i < (img->height); i++)
	{
		for (j = 0; j < (img->width); j++)
		{	
			if (i == j) {
				img->pixels[i*(img->width)+j].r = 0xFF;
				img->pixels[i*(img->width)+j].g = 0xFF;
				img->pixels[i*(img->width)+j].b = 0x00;
			}
		}
	}
	
	return img;	
}

void main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */

	Image *img;
	img = malloc(sizeof(Image));
	img = ReadImage(argv[1]);
	img = YellowDiagonal(img);
	WriteImage(img, argv[2]);
}
