#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class	PresidentialPardonForm : virtual public Form
{
	public:
		PresidentialPardonForm(std::string const target);
		//PresidentialPardonForm(Form const & src);
		~PresidentialPardonForm(void);

		virtual void	action(void) const;
	
	private:
		std::string		_target;
};

#endif