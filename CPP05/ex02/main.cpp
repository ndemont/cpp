#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Bureaucrat Macron("Macron", 160);
	Bureaucrat Nastasia("Nastasia", 1);
	std::cout << Macron;
	std::cout << Nastasia;
	Nastasia++;
	std::cout << Nastasia;
	std::cout << std::endl;
	RobotomyRequestForm form("nboisde");
	Macron.signForm(form);
	Nastasia.signForm(form);
	form.execute(Nastasia);
	std::cout << form;
	return 0;
}