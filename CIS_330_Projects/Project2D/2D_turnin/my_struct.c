/* This file should contaiin the 9 functions defined in prototypes.h */
#include <prototypes.h>

void InitializeCircle(struct Shape *circ, double radius, double originX, double originY)
{
	struct Shape *circle;
	circle = circ;
	circle->u = (union ShapeUnion *) malloc(sizeof(ShapeUnion));
	circle->s = (enum ShapeType *) malloc(sizeof(ShapeType));
	circle->u->c = (struct Circle *) malloc(sizeof(Circle));	

	circle->u->c->radius  = radius;
	circle->u->c->originX = originX;
	circle->u->c->originY = originY;

	circle->s = CIRC;
	circle->ft.GetArea = GetCircleArea;
	circle->ft.GetBoundingBox = GetCircleBoundingBox;	
}

void InitializeRectangle(struct Shape *rect, double minX, double maxX, double minY, double maxY)
{
	struct Shape *rectangle; 
	rectangle = rect;
	rectangle->u = (union ShapeUnion *) malloc(sizeof(ShapeUnion));
	rectangle->s = (enum ShapeType *) malloc(sizeof(ShapeType));
	rectangle->u->c = (struct Rectangle *) malloc(sizeof(Rectangle));

	rectangle->u->r->minX = minX;
	rectangle->u->r->maxX = maxX;
	rectangle->u->r->minY = minY;
	rectangle->u->r->maxY = maxY;

	rectangle->s = RECT;
	rectangle->ft.GetArea = GetRectangleArea;
	rectangle->ft.GetBoundingBox = GetRectangleBoundingBox;
}

void InitializeTriangle(struct Shape *tri, double pt1X, double pt2X, double minY, double maxY)
{
	struct Shape *triangle;
	triangle = tri;
	triangle->u = (union ShapeUnion *) malloc(sizeof(ShapeUnion));
	triangle->s = (enum ShapeType *) malloc(sizeof(ShapeType));
	triangle->u->c = (struct Triangle *) malloc(sizeof(Triangle));

	triangle->u->t->pt1X = pt1X;
	triangle->u->t->pt2X = pt2X;
	triangle->u->t->minY = minY;
	triangle->u->t->maxY = maxY;

	triangle->s = TRI;
	triangle->ft.GetArea = GetTriangleArea;
	triangle->ft.GetBoundingBox = GetTriangleBoundingBox;
}

double GetCircleArea(struct Shape *circ)
{
	double area;
	area = 3.14159 * circ->u->c->radius * circ->u->c->radius;
	return area;
}

double GetRectangleArea(struct Shape *rect)
{
	double area;
	area = (rect->u->r->maxX - rect->u->r->minX)*(rect->u->r->maxY - rect->u->r->minY);
	return area;
}

double GetTriangleArea(struct Shape *tri)
{
	double area;
	area = (tri->u->t->pt2X - tri->u->t->pt1X)*(tri->u->t->maxY - tri->u->t->minY)/2;
	return area;
}

void GetCircleBoundingBox(struct Shape *circ, double *bbox)
{
	bbox[0] = (circ->u->c->originX - circ->u->c->radius);
	bbox[1] = (circ->u->c->originX + circ->u->c->radius);
	bbox[2] = (circ->u->c->originY - circ->u->c->radius);
	bbox[3] = (circ->u->c->originY + circ->u->c->radius);
}

void GetRectangleBoundingBox(struct Shape *rect, double *bbox)
{
	bbox[0] = rect->u->r->minX;
	bbox[1] = rect->u->r->maxX;
	bbox[2] = rect->u->r->minY;
	bbox[3] = rect->u->r->maxY;
}

void GetTriangleBoundingBox(struct Shape *tri, double *bbox)
{
	bbox[0] = tri->u->t->pt1X;
	bbox[1] = tri->u->t->pt2X;
	bbox[2] = tri->u->t->minY;
	bbox[3] = tri->u->t->maxY;
}


