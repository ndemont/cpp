#include "RobotomyRequestForm.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::action() const
{
	int idx = rand() % 2;

	if (idx)
		std::cout << "Robotomization of " << _target << " failed" << std::endl;
	else
	{
		std::cout << "* loud drill sounds *" << std::endl;
		std::cout << _target << " has been robotomized" << std::endl;

	}
}
