#include "Intern.hpp"

Intern::Intern(void)
{
	formNames[0] = "robotomy request";
	formNames[1] = "presidential pardon";
	formNames[2] = "shrubbery creation";
	formClasses[0] = &Intern::_robotomy;
	formClasses[1] = &Intern::_presidential;
	formClasses[2] = &Intern::_shrubbery;
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	formNames[0] = "robotomy request";
	formNames[1] = "presidential pardon";
	formNames[2] = "shrubbery creation";
	formClasses[0] = &Intern::_robotomy;
	formClasses[1] = &Intern::_presidential;
	formClasses[2] = &Intern::_shrubbery;
	std::cout << "Copy Intern constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor created" << std::endl;
}

Intern const & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form	*Intern::checkFormName(std::string formName, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			ptr form = formClasses[i];
			return (this->*form)(target);

		}
	}
	throw Intern::FormNotFound();
	return 0;
}


Form	*Intern::makeForm(std::string name, std::string target)
{
	Form 	*BrandNewForm;

	try
	{
		BrandNewForm = checkFormName(name, target);
	}
	catch(const std::exception& e) 
	{
       std::cerr << e.what() << std::endl;
	}
	return BrandNewForm;
}

Form* 	Intern::_robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form* 	Intern::_presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form* 	Intern::_shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}