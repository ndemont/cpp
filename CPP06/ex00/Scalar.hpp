#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <cmath> 
# include <ctgmath>
# include <sstream>

class Scalar
{
	public:
		Scalar(char *input);
		Scalar(Scalar const & src);
		~Scalar(void);

		Scalar const &	operator=(Scalar const & rhs);

		void		findType(char * input);

		bool		isChar(char * str);
		bool		isInt(char * str);
		bool		isFloat(char * str);
		bool		isDouble(char * str);

		void		setFromChar(void);
		void		setFromInt(void);
		void		setFromFloat(void);
		void		setFromDouble(void);
		void		setPrecision(void);

		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;
		bool		getDisplayable(void) const;
		bool		getPrecision(void) const;
		bool		getCharError(void) const;
		bool		getIntError(void) const;
		bool		getFloatError(void) const;
		bool		getDoubleError(void) const;
	
	private:
		Scalar(void);

		char	_c;
		int		_i;
		float	_f;
		double	_d;
		bool	_displayable;
		bool	_precision;
		bool	_charError;
		bool	_intError;
		bool	_floatError;
		bool	_doubleError;
};

std::ostream &	operator<<(std::ostream & o, Scalar const & i);

#endif