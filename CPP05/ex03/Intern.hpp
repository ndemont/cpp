#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern const & operator=(Intern const & src);

		Form			*checkFormName(std::string formName, std::string target);
		typedef Form*	(Intern::*ptr)(std::string target);
		ptr				formClasses[3];
		std::string		formNames[3];

		Form			*makeForm(std::string name, std::string target);

		class FormNotFound : public std::exception
		{
			public:
				FormNotFound(void) {};
				virtual ~FormNotFound(void) throw() {};
				virtual const char* what() const throw()
				{
					return "This form does not exist";
				};
    	};

	private:
		Form*	_robotomy(std::string target);
		Form*	_presidential(std::string target);
		Form*	_shrubbery(std::string target);

};

#endif