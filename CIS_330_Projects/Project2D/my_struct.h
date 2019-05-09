/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */
#include <stdio.h>
#include <stdlib.h>
#ifndef SHAPE_330
#define SHAPE_330

typedef struct
{ 
	double minX;
	double maxX;
	double minY;
	double maxY;
} Rectangle;

typedef struct
{
	double radius;
	double originX;
	double originY;
} Circle;

typedef struct
{
	double pt1X;
	double pt2X;
	double minY;
	double maxY;
} Triangle;

#endif

typedef union
{
        Rectangle *r;
        Circle    *c;
        Triangle  *t;

} ShapeUnion;

enum ShapeType
{
        Rect,
        Circ,
        Tri,
};

struct Shape;

typedef struct
{
        double (*GetArea) (struct Shape *);
        void   (*GetBoundingBox) (struct Shape *, double *);

} FunctionTable;

struct Shape
{
        ShapeUnion u;
        enum   ShapeType s;
        FunctionTable ft;

};
   
