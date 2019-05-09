
#include <my_struct.h>

void InitializeCircle(struct Shape *, double radius, double originX, double originY);
void InitializeRectangle(struct Shape *, double minX, double maxX, double minY, double maxY);
void InitializeTriangle(struct Shape *, double pt1X, double pt2X, double minY, double maxY);

double GetRectangleArea(struct Shape *);
double GetCircleArea(struct Shape *);
double GetTriangleArea(struct Shape *);

void GetRectangleBoundingBox(struct Shape *, double *);
void GetCircleBoundingBox(struct Shape *, double *);
void GetTriangleBoundingBox(struct Shape *, double *);

