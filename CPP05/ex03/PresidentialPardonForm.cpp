#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("Unknown")
{
	std::cout << "Default PresidentialPardonForm constructor called with target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Default PresidentialPardonForm constructor called with target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : _target(src.getTarget())
{
	std::cout << "Copy PresidentialPardonForm constructor called with target: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called with target: " << _target << std::endl;
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
	std::cout << _target << " has been forgiven by Zafod Beeblebrox" << std::endl;
}
