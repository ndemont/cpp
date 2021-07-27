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
		ShrubberyCreationForm(std::string const name);
		//ShrubberyCreationForm(Form const & src);
		~ShrubberyCreationForm(void);

		void	action(std::string target) const;
};

#endif