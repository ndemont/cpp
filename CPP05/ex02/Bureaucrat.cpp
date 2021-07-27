#include "Bureaucrat.hpp"

void	Bureaucrat::checkGrade(int grade)
{
	if (grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else
		_grade = grade;
}

/* CONSTRUCTORS & DESTRUCTORS */
Bureaucrat::Bureaucrat(void) : _grade(150)
{
	std::cout << "Default Bureaucrat constructor called: Unknown" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Default Bureaucrat constructor called: " << getName() << std::endl;
	try
	{
		checkGrade(grade);
	}
	catch(const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
	} 
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade()) 
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/* OPERATORS */

Bureaucrat &	Bureaucrat::operator++(void)
{
	try
	{
		checkGrade(getGrade() - 1);
	}
	catch(const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
	}
	return *this;
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat tmp = *this;
	++*this;

	return tmp;
}

Bureaucrat &	Bureaucrat::operator--(void)
{
	try
	{
		checkGrade(getGrade() + 1);
	}
	catch(const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
	}
	return *this;
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat tmp = *this;
	--*this;

	return tmp;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i)
{
	std::cout << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}

/* GETTERS */
std::string		Bureaucrat::getName(void) const
{
	return _name;
}

int			Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::signForm(Form & form)
{
	form.beSigned(*this);
	if (form.getSignedStatus())
		std::cout << getName() << " signs " << form.getName() <<std::endl;
	else
		std::cout << getName() << " cannot sign because his grade is to low" <<std::endl;
}
