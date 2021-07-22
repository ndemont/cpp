#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class	Point
{
public:

	Point(void);
	Point(Fixed const p1, Fixed const p2);
	Point(Point const & src);
	~Point(void);

	Point &	operator=(Point const & rhs);

private:
	Fixed const	_x;
	Fixed const	_y;
}

std::ostream &	operator<<(std::ostream & o, Point const & i);

#endif