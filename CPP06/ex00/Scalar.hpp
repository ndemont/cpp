#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

class Scalar
{
	public:
		Scalar(void);
		Scalar(std::string);
		Scalar(Scalar const & src);
		~Scalar(void);

		Scalar const &	operator=(Scalar const & rhs);

		void	findType(std::string input);

		bool	isChar(std::string str);
		bool	isInt(std::string str);
		bool	isFloat(std::string str);
		bool	isDouble(std::string str);

		void	setFromChar(std::string input);
		void	setFromInt(std::string input);
		void	setFromFloat(std::string input);
		void	setFromDouble(std::string input);

		char	getChar(void) const;
		int		getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;
		bool	getImpossible(void) const;
		bool	getNonDisplayable(void) const;
	
	private:
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		bool		_impossible;
		bool		_nonDisplayable;
};

std::ostream &	operator<<(std::ostream & o, Scalar const & i);

#endif