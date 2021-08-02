#include "Bureaucrat.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called: " << getName() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called: " << getName() << std::endl;
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
	std::cout << "Copy Bureaucrat constructor called: " << getName() << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called: " << getName() << std::endl;

}

/* OPERATORS */

Bureaucrat const &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_grade = rhs.getGrade();
	return *this;
}


Bureaucrat &	Bureaucrat::operator++(void)
{
	try
	{
		checkGrade(_grade - 1);
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
		checkGrade(_grade + 1);
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

/* GETTERS & SETTERS*/
std::string	const	Bureaucrat::getName(void) const
{
	return _name;
}

int			Bureaucrat::getGrade(void) const
{
	return _grade;
}

/* METHODS */
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