#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>
# include "Form.hpp"

class	RobotomyRequestForm : virtual public Form
{
	public:
		RobotomyRequestForm(std::string const name);
		//RobotomyRequestForm(Form const & src);
		~RobotomyRequestForm(void);

		void	action(std::string target) const;
};

#endif