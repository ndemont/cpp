#include "Form.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExec) : _name(name), _signed(false), _gradeToSign(getGrade(gradeToSign)), _gradeToExec(getGrade(gradeToExec))
{
	std::cout << "Default Form constructor called: " << getName() << std::endl;
	try
	{
		checkGrade(gradeToSign);
	}
	catch(const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
	}
	try
	{
		checkGrade(gradeToExec);
	}
	catch(const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
	}
}

Form::Form(Form const & src) : _name(src.getName()), _signed(src.getSignedStatus()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) 
{
	std::cout << "Copy Form constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form const &	Form::operator=(Form const & rhs)
{
	_signed = rhs.getSignedStatus();
	return *this;
}

std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getSignedStatus(void) const
{
	return _signed;	
}

int	Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	Form::getGradeToExec(void) const
{
	return _gradeToExec;
}

int		 Form::getGrade(int const grade)
{
	if (grade > 150)
		return 150;
	else if (grade < 1)
		return 1;
	else
		return grade;
}

void	Form::checkGrade(int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
}

void	Form::checkSignature(int grade, int gradeToSign)
{
	if (grade <= gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		checkSignature(bureaucrat.getGrade(), _gradeToSign);
	}
	catch(const std::exception& e) 
	{
       std::cerr << e.what() << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, Form const & i)
{
	std::cout << i.getName() << std::endl;
	std::cout << "Form signed status: " << i.getSignedStatus() << std::endl;
	std::cout << "Required grade to sign: " << i.getGradeToSign() << std::endl;
	std::cout << "Required grade to exec: " << i.getGradeToExec() << std::endl << std::endl;
	return o;
}