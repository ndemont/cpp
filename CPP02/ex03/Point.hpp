#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class	Point
{
public:

	Point(void);
	Point(Point const & src);
	Point(Fixed const p1, Fixed const p2);
	~Point(void);

	Point &	operator=(Point const & rhs);
	Fixed	const getX(void) const;
	Fixed	const getY(void) const;

private:

	Fixed const	_x;
	Fixed const	_y;
};

std::ostream &	operator<<(std::ostream & o, Point const & i);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif