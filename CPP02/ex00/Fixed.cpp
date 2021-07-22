#include "Fixed.hpp"

int	const Fixed::_FractBits = 8;

Fixed::Fixed(void) : _RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _RawBits;
}

int			Fixed::setRawBits(int const raw)
{
	_RawBits = raw;
	return _RawBits;
}
