#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("Unknown")
{
	std::cout << "Default RobotomyRequestForm constructor called with target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called with target: "<< _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : _target(src.getTarget())
{
	std::cout << "Copy RobotomyRequestForm constructor called with target: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called with target: " << _target << std::endl;
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSignedStatus())
		return ;
	try
	{
		if (executor.getGrade() > getGradeToExec())
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e) 
	{
		std::cerr << "YOU DO NOT HAVE THE GRADE TO EXECUTE THIS" << std::endl;
		return ;
	}

	int idx = rand() % 2;
	if (idx)
		std::cout << "Robotomization of " << _target << " failed" << std::endl;
	else
	{
		std::cout << "* loud drill sounds *" << std::endl;
		std::cout << _target << " has been robotomized" << std::endl;

	}
}
