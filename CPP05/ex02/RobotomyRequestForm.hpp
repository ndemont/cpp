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
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm const & operator=(RobotomyRequestForm const &rhs);

		std::string		getTarget(void) const;
		void			execute(Bureaucrat const & executor) const;
	
	private:
		std::string 	_target;

};

#endif