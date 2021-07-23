#include "Fixed.hpp"


//CONSTRUCTORS

Fixed::Fixed(void) : _RawBits(0), _FractBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i) : _RawBits(i), _FractBits(0)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _RawBits(f)
{
	std::cout << "Float constructor called" << std::endl;
	_FractBits = roundf((f - _RawBits) * power(2, 8));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

//DESTRUCTOR
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//OVERLOAD
Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
	{
		this->_RawBits = rhs.getRawBits();
		this->_FractBits = rhs.getFractBits();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

//MEMBER FUNCTIONS
int		Fixed::getRawBits(void) const
{
	return _RawBits;
}

int		Fixed::getFractBits(void) const
{
	return _FractBits;
}

void	Fixed::setRawBits(int const raw)
{
	_RawBits = raw;
}

float	Fixed::toFloat(void) const
{
	float	f = _RawBits + (_FractBits * (power(2, -8)));
	return f;
}

int		Fixed::toInt(void) const
{
	return _RawBits;
}

float	power(int n, int power)
{
	float rslt = 2;
	
	if (power > 0)
	{
		for (int i = 1; i < power; i++)
			rslt = rslt * n;
	}
	else if (power < 0)
	{
		for (int i = 1; i > power; i--)
			rslt = rslt / n;
	}
	return rslt;
}