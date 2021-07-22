#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
public:

	Fixed(void);
	Fixed(int const i);
	Fixed(float const f);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	Fixed &	operator++(void);
	Fixed	operator++(int);
	Fixed &	operator--(void);
	Fixed	operator--(int);

	Fixed &	operator=(Fixed const & rhs);
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	Fixed static &	min(Fixed & fix1, Fixed & fix2);
	float static	min(Fixed const & fix1, Fixed const & fix2);
	Fixed static &	max(Fixed const & fix2);
	float static	max(Fixed & fix1, Fixed & fix2);

	int		getRawBits(void) const;
	int		getFractBits(void) const;
	int		setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int			_RawBits;
	int			_FractBits;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);
float	power(int n, int power);

#endif