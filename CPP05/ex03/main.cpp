#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Form		*Law1;
	Form		*Law2;
	Form		*Law3;
	Bureaucrat	Xavier("Xavier", 1);
	Bureaucrat	Nicolas("Nicolas", 150);
	Intern		nboisde;

	std::cout << std::endl;

	Law1 = nboisde.makeForm("presidential pardon", "Nastasia");
	Law2 = nboisde.makeForm("robotomy request", "Lou");
	Law3 = nboisde.makeForm("shrubbery creation", "Tom");

	std::cout << std::endl;

	Xavier.signForm(*Law1);
	Xavier.signForm(*Law2);
	Xavier.signForm(*Law3);
	
	std::cout << std::endl;

	Law1->execute(Xavier);
	Law2->execute(Nicolas);
	Law3->execute(Xavier);

	std::cout << std::endl;

	delete	Law1;
	delete	Law2;
	delete	Law3;

	return 0;
}