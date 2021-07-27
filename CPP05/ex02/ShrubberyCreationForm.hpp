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
		ShrubberyCreationForm(std::string const target);
		//ShrubberyCreationForm(Form const & src);
		~ShrubberyCreationForm(void);

		virtual void	action(void) const;

	private:
		std::string 	_target;
};

#endif