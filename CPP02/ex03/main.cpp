#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) 
{
	Fixed const f1 = 1;
	Fixed const f5 = 5;
	Fixed const f0 = 0;
	Fixed const f2 = 2;
	
	Point const A1(f1, f1);
	Point const A2(f1, f5);
	Point const A3(f5, f1);
	Point const P(2, 2);

	bool	result = bsp(A1, A2, A3, P);
	bool	result2 = bsp(Point(1,1), Point(1,5), Point(5,1), Point(1,1));

	std::cout << "The point 1 is in triangle? " << result << std::endl;
	std::cout << "The point 2 is in triangle? " << result2 << std::endl;
	return 0;
}