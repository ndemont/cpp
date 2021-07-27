#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class	PresidentialPardonForm : virtual public Form
{
	public:
		PresidentialPardonForm(std::string const name);
		//PresidentialPardonForm(Form const & src);
		~PresidentialPardonForm(void);

		void	action(std::string target) const;
};

#endif