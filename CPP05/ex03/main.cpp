#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Form *Prout;
	Bureaucrat caca("caca", 1);
	Intern	nboisde;

	Prout = nboisde.makeForm("presidential pardon", "Nastasia");
	caca.signForm(*Prout);
	Prout->execute(caca);
	return 0;
}