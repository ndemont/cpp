#include "Fixed.hpp"
#include "Point.hpp"

float	absolut(float f)
{
	if (f < 0)
		return -f;
	else
		return f;
}

float area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	Fixed	area;

	area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	return (absolut(area.toFloat() / 2.0));
}

bool		bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	A, A1, A2, A3;
	float	rslt;

	A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	A1 = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	A2 = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());

	rslt = A1 + A2 + A3;
	return ((A == A1 + A2 + A3) && A1 && A2 && A3);
}