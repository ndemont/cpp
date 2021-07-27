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
		RobotomyRequestForm(std::string const target);
		//RobotomyRequestForm(Form const & src);
		~RobotomyRequestForm(void);

	virtual	void	action(void) const;
	
	private:
		std::string 	_target;

};

#endif