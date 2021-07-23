#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) 
{
	bool	point1 = bsp(Point(1,1), Point(1,5), Point(5,1), Point(2,2));
	bool	point2 = bsp(Point(1,1), Point(1,5), Point(5,1), Point(-1,-1));
	bool	point3 = bsp(Point(1,1), Point(1,5), Point(5,1), Point(1,1));

	std::cout << "Is the point 1 in triangle? " << point1 << std::endl;
	std::cout << "Is the point 2 in triangle? " << point2 << std::endl;
	std::cout << "Is the point 3 in triangle? " << point3 << std::endl;
	return 0;
}