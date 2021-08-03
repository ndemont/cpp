#include "Scalar.hpp"

bool	isNumeric(char c);

Scalar::Scalar(void) : _c(0), _i(0), _f(0), _d(0)
{
	_precision = "";
	_charError = "Non displayable";
	_floatError = "";
	_doubleError = "";
	std::cout << "Default Scalar constructor called" << std::endl;
}

Scalar::Scalar(std::string input) : _c(0), _i(0), _f(0), _d(0)
{
	_precision = "";
	_charError = "Non displayable";
	_intError = "";
	_floatError = "";
	_doubleError = "";
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

void	Scalar::findType(std::string input)
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

std::string	Scalar::getPrecision(void) const
{
	return _precision;
}

std::string	Scalar::getCharError(void) const
{
	return _charError;
}

std::string	Scalar::getIntError(void) const
{
	return _intError;
}

std::string	Scalar::getFloatError(void) const
{
	return _floatError;
}

std::string	Scalar::getDoubleError(void) const
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
		_charError = "";
		_c	= static_cast<char>(_i);
	}
	else if (_i < 0 || _i > 127)
		_charError = "impossible";
}
		
void	Scalar::setFromFloat(void)
{
	_d	= static_cast<double>(_f);
	_i	= static_cast<int>(_f);	
	_c	= static_cast<char>(_f);
	if (_f >= 32.0 && _f <= 126.0)
	{
		_charError = "";
		_c	= static_cast<char>(_i);
	}
	else if (_f < 0.0 || _f > 127.0)
		_charError = "impossible";
}

void	Scalar::setFromDouble(void)
{
	_f	= static_cast<float>(_d);
	_i	= static_cast<int>(_d);	
	if (_d >= 32 && _d <= 126)
	{
		_charError = "";
		_c	= static_cast<char>(_i);
	}
	else if (_d < 0.0 || _d > 127.0)
		_charError = "impossible";
}

void	Scalar::setPrecision(void)
{
	double modulo = modf(_f, &modulo);
	if (!modulo && _f != INFINITY && _f != -INFINITY)
		_precision = ".0";
}

bool	Scalar::isChar(std::string str)
{
	if (isNumeric(str[0]) || str[1])
		return false;
	_charError = "";
	_c	= str[0];
	return true;
}

bool	Scalar::isInt(std::string str)
{
	int i = 0;

	try {
		_i = std::stoi(str);
	} catch(const std::exception& e) {
		_intError = "impossible";
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

bool	Scalar::isFloat(std::string str)
{
	try {
		_f = std::stof(str);
	} catch(const std::exception& e) {
		_floatError = "impossible";
		return false;
	}
	return true;

}

bool	Scalar::isDouble(std::string str)
{
	try {
		_d = std::stod(str);
	} catch(const std::exception& e) {
		_doubleError = "impossible";
		_charError = "impossible";
		return false;
	}
	float	mod = modf(_d, &mod);
	if (mod)
		_precision = ".0";
	return true;
}

std::ostream &	operator<<(std::ostream & o, Scalar const & i)
{
	o << "char:   ";
	if (i.getCharError() != "")
		o << i.getCharError() << std::endl;
	else
		o << "'" << i.getChar() << "'" << std::endl;
	o << "int:    ";
	if (i.getIntError() != "")
		o << i.getIntError() << std::endl;
	else
		o << i.getInt() << std::endl;
	o << "float:  ";
	if (i.getFloatError() != "")
		o << i.getFloatError() << std::endl;
	else
		o << i.getFloat() << i.getPrecision() << "f" << std::endl;
	o << "double: ";
	if (i.getDoubleError() != "")
		o << i.getDoubleError() << std::endl;
	else
		o << i.getDouble() << i.getPrecision() << std::endl;
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