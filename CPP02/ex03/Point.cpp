#include "Point.hpp"

//CONSTRUCTORS

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed const p1, Fixed const p2) : _x(p1), _y(p2)
{
}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
	std::cout << "Copy constructor called" << std::endl;
}

//DESTRUCTORS

Point::~Point(void)
{
	std::cout << "Destructor called" << std::endl;
}

//OPERATORS

Point & Point::operator=(Point const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Point const & i)
{
	o << (i.getX()).toFloat() << (i.getY()).toFloat() << std::endl;
	return o;
}

//GET

Fixed	const Point::getX(void) const
{
	return _x;
}

Fixed	const Point::getY(void) const
{
	return _y;
}