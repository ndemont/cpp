#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <cmath> 
# include <ctgmath>
# include <sstream>

class Scalar
{
	public:
		Scalar(void);
		Scalar(std::string);
		Scalar(Scalar const & src);
		~Scalar(void);

		Scalar const &	operator=(Scalar const & rhs);

		void		findType(std::string input);

		bool		isChar(std::string str);
		bool		isInt(std::string str);
		bool		isFloat(std::string str);
		bool		isDouble(std::string str);

		void		setFromChar(void);
		void		setFromInt(void);
		void		setFromFloat(void);
		void		setFromDouble(void);
		void		setPrecision(void);

		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;
		std::string	getPrecision(void) const;
		std::string	getCharError(void) const;
		std::string	getIntError(void) const;
		std::string	getFloatError(void) const;
		std::string	getDoubleError(void) const;
	
	private:
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		std::string	_precision;
		std::string	_charError;
		std::string	_intError;
		std::string	_floatError;
		std::string	_doubleError;
};

std::ostream &	operator<<(std::ostream & o, Scalar const & i);

#endif