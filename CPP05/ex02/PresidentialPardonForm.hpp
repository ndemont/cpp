#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class	PresidentialPardonForm : virtual public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm const & operator=(PresidentialPardonForm const &rhs);

		std::string		getTarget(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
	
	private:
		std::string		_target;
};

#endif