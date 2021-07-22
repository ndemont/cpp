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

Fixed Fixed::operator+(Fixed const & rhs) const
{
	float	left;
	float	right;
	float	plus;

	left = this->toFloat();
	right = rhs.toFloat();
	plus = left + right;
	
	Fixed rslt(plus);

	return rslt;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	float	left;
	float	right;
	float	minus;

	left = this->toFloat();
	right = rhs.toFloat();
	minus = left - right;
	
	Fixed rslt(minus);

	return rslt;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	float	left;
	float	right;
	float	mult;

	left = this->toFloat();
	right = rhs.toFloat();
	mult = left * right;
	
	Fixed rslt(mult);

	return rslt;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	float	left;
	float	right;
	float	div;

	left = this->toFloat();
	right = rhs.toFloat();
	div = left / right;
	
	Fixed rslt(div);

	return rslt;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

//INCREMENTS & DECREMENT

Fixed &	Fixed::operator++(void)
{
	float	plus;

	plus = this->toFloat();
	plus += 0.005f;
	*this = Fixed(plus);

	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;

	return tmp;
}

Fixed &	Fixed::operator--(void)
{
	float	minus;

	minus = this->toFloat();
	minus -= 0.005f;
	*this = Fixed(minus);

	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;

	return tmp;
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

int			Fixed::setRawBits(int const raw)
{
	_RawBits = raw;
	return _RawBits;
}

float		Fixed::toFloat(void) const
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

//COMPARISOM

bool Fixed::operator>(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 > f2)
		return 1;
	else
		return 0;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 < f2)
		return 1;
	else
		return 0;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 >= f2)
		return 1;
	else
		return 0;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 <= f2)
		return 1;
	else
		return 0;
}

bool Fixed::operator==(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 == f2)
		return 1;
	else
		return 0;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	float	f1 = this->toFloat();
	float	f2 = rhs.toFloat();
	
	if (f1 != f2)
		return 1;
	else
		return 0;
}

//MAX & MIN

Fixed & Fixed::min(Fixed const & rhs)
{
	Fixed static min;

	if ((fix1.operator<=)(fix2))
		min = Fixed(fix1);
	else
		min = Fixed(fix2);
	return	min;
}

Fixed & Fixed::max(Fixed const & rhs)
{
	Fixed static max;

	if ((fix1.operator>=)(fix2))
		max = Fixed(fix1);
	else
		max = Fixed(fix2);
	return	max;
}

float Fixed::min(Fixed const & fix1, Fixed const & fix2)
{
	if ((fix1.operator<=)(fix2))
		return fix1.toFloat();
	else
		return fix2.toFloat();
}

float Fixed::max(Fixed const & fix1, Fixed const & fix2)
{
	if ((fix1.operator>=)(fix2))
		return fix1.toFloat();
	else
		return fix2.toFloat();
}

