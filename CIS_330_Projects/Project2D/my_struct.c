/* This file should contaiin the 9 functions defined in prototypes.h */
#include <prototypes.h>

void InitializeCircle(struct Shape *circ, double radius, double originX, double originY)
{
	circ->u.c->radius  = radius;
	circ->u.c->originX = originX;
	circ->u.c->originY = originY;

	circ->s = Circ;
	circ->ft.GetArea = GetCircleArea;
	circ->ft.GetBoundingBox = GetCircleBoundingBox;	
}

void InitializeRectangle(struct Shape *rect, double minX, double maxX, double minY, double maxY)
{
	rect->u.r->minX = minX;
	rect->u.r->maxX = maxX;
	rect->u.r->minY = minY;
	rect->u.r->maxY = maxY;

	rect->s = Rect;
	rect->ft.GetArea = GetRectangleArea;
	rect->ft.GetBoundingBox = GetRectangleBoundingBox;
}

void InitializeTriangle(struct Shape *tri, double pt1X, double pt2X, double minY, double maxY)
{
	tri->u.t->pt1X = pt1X;
	tri->u.t->pt2X = pt2X;
	tri->u.t->minY = minY;
	tri->u.t->maxY = maxY;

	tri->s = Tri;
	tri->ft.GetArea = GetTriangleArea;
	tri->ft.GetBoundingBox = GetTriangleBoundingBox;
}

double GetCircleArea(struct Shape *circ)
{
	double area;
	area = 3.14159 * circ->u.c->radius * circ->u.c->radius;
	return area;
}

double GetRectangleArea(struct Shape *rect)
{
	double area;
	area = (rect->u.r->maxX - rect->u.r->minX)*(rect->u.r->maxY - rect->u.r->minY);
	return area;
}

double GetTriangleArea(struct Shape *tri)
{
	double area;
	area = (tri->u.t->pt2X - tri->u.t->pt1X)*(tri->u.t->maxY - tri->u.t->minY)/2;
	return area;
}

void GetCircleBoundingBox(struct Shape *circ, double *bbox)
{
	bbox[0] = (circ->u.c->originX - circ->u.c->radius);
	bbox[1] = (circ->u.c->originX + circ->u.c->radius);
	bbox[2] = (circ->u.c->originY - circ->u.c->radius);
	bbox[3] = (circ->u.c->originY + circ->u.c->radius);
}

void GetRectangleBoundingBox(struct Shape *rect, double *bbox)
{
	bbox[0] = rect->u.r->minX;
	bbox[1] = rect->u.r->maxX;
	bbox[2] = rect->u.r->minY;
	bbox[3] = rect->u.r->maxY;
}

void GetTriangleBoundingBox(struct Shape *tri, double *bbox)
{
	bbox[0] = tri->u.t->pt1X;
	bbox[1] = tri->u.t->pt2X;
	bbox[2] = tri->u.t->minY;
	bbox[3] = tri->u.t->maxY;
}


