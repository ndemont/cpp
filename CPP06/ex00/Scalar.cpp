#include "Scalar.hpp"

bool	isNumeric(char c);

Scalar::Scalar(void) : _c(0), _i(0), _f(0), _d(0), _impossible(false), _nonDisplayable(false)
{
	std::cout << "Default Scalar constructor called" << std::endl;
}

Scalar::Scalar(std::string input) : _c(0), _i(0), _f(0), _d(0), _impossible(false), _nonDisplayable(false)
{
	findType(input);
	std::cout << "Default Scalar constructor called" << std::endl;
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
	}
	return *this;
}

void	Scalar::findType(std::string input)
{
	if (isChar(input))
		setFromChar(input);
	else if (isInt(input))
		setFromInt(input);
	else if (isFloat(input))
		setFromFloat(input);
	else if (isDouble(input))
		setFromDouble(input);
	else
		std::cout << "Invalid Argument: your input can not be converted." << std::endl;
}

void	Scalar::setFromChar(std::string input)
{
	_c	= input[0];
	_i	= static_cast<int>(_c - 48);
	_f	= static_cast<float>(_c - 48);
	_d	= static_cast<double>(_c - 48);
}

void	Scalar::setFromInt(std::string input)
{
	_i = std::stoi(input);
	_f = static_cast<float>(_i);
	_d	= static_cast<double>(_i);
	_c	= static_cast<char>(_i);
}
		
void	Scalar::setFromFloat(std::string input)
{
	_f = std::stof(input);
	_d	= static_cast<double>(_f);
	_i	= static_cast<int>(_f);	
	_c	= static_cast<char>(_f);
}

void	Scalar::setFromDouble(std::string input)
{
	_d = std::stod(input);
	_f	= static_cast<float>(_d);
	_i	= static_cast<int>(_d);	
	_c	= static_cast<char>(_i);
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

bool	Scalar::getImpossible(void) const
{
	return _impossible;
}

bool	Scalar::getNonDisplayable(void) const
{
	return _nonDisplayable;
}

std::ostream &	operator<<(std::ostream & o, Scalar const & i)
{
	if (i.getImpossible())
	{
		o << "char:   " << "impossbile" << std::endl;
		o << "int:    " << "impossbile" << std::endl;
	}
	else if (i.getNonDisplayable())
	{
		o << "char:   " << "Non displayable" << std::endl;
		o << "int:    " << i.getInt() << std::endl;
	}
	else
	{
		o << "char:   '" << i.getChar() << "'" << std::endl;
		o << "int:    " << i.getInt() << std::endl;
	}
	o << "float:  " << i.getFloat();
	if (!(i.getFloat() - static_cast<int>(i.getFloat())))
		o << ".0";
	o << "f" << std::endl;
	o << "double: " << i.getDouble();
	if (!(i.getDouble() - static_cast<int>(i.getDouble())))
		o << ".0";
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

bool	Scalar::isChar(std::string str)
{
	if (!str[0])
		return false;
	else if (str[1])
		return false;
	else if (str[0] < 20 || str[0] > 126 || isNumeric(str[0]))
	{
		_nonDisplayable = true;
		return false;
	}
	else
		return true;
}

bool	Scalar::isInt(std::string str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isNumeric(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	Scalar::isFloat(std::string str)
{
	int i 		= 0;
	int point 	= 0;
	int f 		= 0;

	if (str == "-inff" || str == "inff" || str == "nanf")
	{
		_impossible = true;
		return true;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isNumeric(str[i]))
		{
			if (!point && str[i] == '.' && i)
				point++;
			else if (!f && str[i] == 'f')
				f++;
			else 
				return false;
		}
		i++;
	}
	if (str[i - 1] != 'f')
		return false;
	else
		return true;
}

bool	Scalar::isDouble(std::string str)
{
	int i 		= 0;
	int point 	= 0;

	if (str == "-inf" || str == "inf" || str == "nan")
	{
		_impossible = true;
		return true;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isNumeric(str[i]))
		{
			if (!point && str[i] == '.' && i)
				point++;
			else 
				return false;
		}
		i++;
	}
	return true;
}