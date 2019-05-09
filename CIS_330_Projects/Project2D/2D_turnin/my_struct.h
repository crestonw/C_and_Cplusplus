#include <stdio.h>
#include <stdlib.h>

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

typedef union
{
        Rectangle *r;
        Circle    *c;
        Triangle  *t;

} ShapeUnion;

typedef enum
{ 
        RECT,
        CIRC,
        TRI,
} ShapeType;

struct Shape;

typedef struct
{
        double (*GetArea)(struct Shape *);
        void   (*GetBoundingBox)(struct Shape *, double *);

} FunctionTable;

struct Shape
{
        ShapeUnion *u;
        ShapeType *s;
        FunctionTable ft;

};
   
