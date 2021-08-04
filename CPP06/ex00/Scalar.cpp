#include "Scalar.hpp"

bool	isNumeric(char c);

Scalar::Scalar(void)
{
}

Scalar::Scalar(char * input) : _c(0), _i(0), _f(0), _d(0)
{
	_displayable = true;
	_precision = false;
	_charError = false;
	_intError = false;
	_floatError = false;
	_doubleError = false;
	findType(input);
	std::cout << "Scalar constructor called with input: '" << input << "'" << std::endl;
}

Scalar::Scalar(Scalar const & src)
{
	*this = src;
	std::cout << "Copy Scalar constructor called" << std::endl;
}

Scalar::~Scalar(void)
{
	std::cout << "Scalar destructor called" << std::endl;
}

Scalar const &	Scalar::operator=(Scalar const & rhs)
{
	if (this != &rhs)
	{
		_c = rhs.getChar();
		_i = rhs.getInt();
		_f = rhs.getFloat();
		_d = rhs.getDouble();
		_precision = rhs.getPrecision();
		_charError = rhs.getCharError();
		_intError = rhs.getIntError();
		_floatError = rhs.getFloatError();
		_doubleError = rhs.getDoubleError();
	}
	return *this;
}

void	Scalar::findType(char * input)
{
	if (isChar(input))
		setFromChar();
	else if (isInt(input))
		setFromInt();
	else if (isFloat(input))
		setFromFloat();
	else if (isDouble(input))
		setFromDouble();
	setPrecision();
}

char	Scalar::getChar(void) const
{
	return _c;
}

int		Scalar::getInt(void) const
{
	return _i;
}

float	Scalar::getFloat(void) const
{
	return _f;
}

double	Scalar::getDouble(void) const
{
	return _d;
}

bool	Scalar::getDisplayable(void) const
{
	return _displayable;
}

bool	Scalar::getPrecision(void) const
{
	return _precision;
}

bool	Scalar::getCharError(void) const
{
	return _charError;
}

bool	Scalar::getIntError(void) const
{
	return _intError;
}

bool	Scalar::getFloatError(void) const
{
	return _floatError;
}

bool	Scalar::getDoubleError(void) const
{
	return _doubleError;
}

void	Scalar::setFromChar(void)
{
	_i	= static_cast<int>(_c - 48);
	_f	= static_cast<float>(_c - 48);
	_d	= static_cast<double>(_c - 48);
}

void	Scalar::setFromInt(void)
{
	_f = static_cast<float>(_i);
	_d	= static_cast<double>(_i);
	if (_i >= 32 && _i <= 126)
	{
		_charError = false;
		_c	= static_cast<char>(_i);
	}
	else if (_i < 0 || _i > 127)
		_charError = true;
	else
		_displayable = false;
}
		
void	Scalar::setFromFloat(void)
{
	_d	= static_cast<double>(_f);
	_i	= static_cast<int>(_f);	
	_c	= static_cast<char>(_f);
	if (_f >= 32.0 && _f <= 126.0)
	{
		_charError = false;
		_c	= static_cast<char>(_i);
	}
	else if (_f < 0.0 || _f > 127.0)
		_charError = true;
	else
		_displayable = false;
}

void	Scalar::setFromDouble(void)
{
	_f	= static_cast<float>(_d);
	_i	= static_cast<int>(_d);	
	if (_d >= 32 && _d <= 126)
	{
		_charError = false;
		_c	= static_cast<char>(_i);
	}
	else if (_d < 0.0 || _d > 127.0)
		_charError = true;
	else
	{
		std::cout << "NAAAANI" << std::endl;
		_displayable = false;
	}
}

void	Scalar::setPrecision(void)
{
	double modulo = modf(_f, &modulo);
	if (!modulo && _f != INFINITY && _f != -INFINITY)
		_precision = true;
}

bool	Scalar::isChar(char * str)
{
	if (isNumeric(str[0]) || str[1])
		return false;
	_charError = false;
	_c	= str[0];
	return true;
}

bool	Scalar::isInt(char * str)
{
	int i = 0;

	try {
		_i = std::stoi(str);
	} catch(const std::exception& e) {
		_intError = true;
		return false;
	}
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (isNumeric(str[i]))
		i++;
	if (str[i])
		return false;
	return true;
}

bool	Scalar::isFloat(char * str)
{
	try {
		_f = std::stof(str);
	} catch(const std::exception& e) {
		_floatError = true;
		return false;
	}
	return true;

}

bool	Scalar::isDouble(char * str)
{
	try {
		_d = std::stod(str);
	} catch(const std::exception& e) {
		_doubleError = true;
		_charError = true;
		return false;
	}
	float	mod = modf(_d, &mod);
	if (mod)
		_precision = true;
	return true;
}

std::ostream &	operator<<(std::ostream & o, Scalar const & i)
{
	o << "char:   ";
	if (!i.getDisplayable() && !i.getIntError())
		o << "Non Displayable" << std::endl;
	else if (i.getCharError() || !i.getDisplayable())
		o << "impossible" << std::endl;
	else
		o << "'" << i.getChar() << "'" << std::endl;
	o << "int:    ";
	if (i.getIntError())
		o << "impossible" << std::endl;
	else
		o << i.getInt() << std::endl;
	o << "float:  ";
	if (i.getFloatError())
		o << "impossible" << std::endl;
	else
	{
		o << i.getFloat();
		if (i.getPrecision()) 
			o << ".0";
		o << "f" << std::endl;
	}
	o << "double: ";
	if (i.getDoubleError())
		o << "impossible" << std::endl;
	else
	{
		o << i.getDouble();
		if (i.getPrecision()) 
			o << ".0";
		o << std::endl;
	}
	o << std::endl;
	return o;
}

bool	isNumeric(char c)
{
	if (c < '0' || c > '9')
		return  false;
	else
		return true;
}
