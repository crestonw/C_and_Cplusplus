
#include <my_struct.h>

void InitializeCircle(struct Shape *, double, double, double);
void InitializeRectangle(struct Shape *, double, double, double, double);
void InitializeTriangle(struct Shape *, double, double, double, double);

double GetRectangleArea(struct Shape *);
double GetCircleArea(struct Shape *);
double GetTriangleArea(struct Shape *);

void GetRectangleBoundingBox(struct Shape *, double *);
void GetCircleBoundingBox(struct Shape *, double *);
void GetTriangleBoundingBox(struct Shape *, double *);



