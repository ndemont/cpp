#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include <string>
#include <fstream>
#include <sstream>
#include <cstring>

# include "Form.hpp"

class	ShrubberyCreationForm : virtual public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm const & operator=(ShrubberyCreationForm const &rhs);

		std::string		getTarget(void) const;
		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string 	_target;
};

#endif