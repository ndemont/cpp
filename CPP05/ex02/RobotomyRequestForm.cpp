#include "RobotomyRequestForm.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
RobotomyRequestForm::RobotomyRequestForm(std::string const name) : Form(name, 72, 45)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::action(std::string target) const
{
	int idx = rand() % 2;

	if (idx)
		std::cout << "Robotomization of " << target << " failed" << std::endl;
	else
	{
		std::cout << "* loud drill sounds *" << std::endl;
		std::cout << target << " has been robotomized" << std::endl;

	}
}
