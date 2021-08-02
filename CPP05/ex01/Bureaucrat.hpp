#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat const &	operator=(Bureaucrat const & rhs);
		Bureaucrat &		operator++(void);
		Bureaucrat			operator++(int);
		Bureaucrat &		operator--(void);
		Bureaucrat			operator--(int);

		std::string	const	getName(void) const;
		int					getGrade(void) const;
		void 				checkGrade(int grade);
		void				signForm(Form & form);

		class GradeTooHighException : public std::exception
    	{
        	public:
            	GradeTooHighException(void) {};
            	virtual ~GradeTooHighException(void) throw() {};
            	virtual const char* what() const throw()
				{
					return "This grade is too high, it will be set at 1";
				};
    	};

		class GradeTooLowException : public std::exception
    	{
        	public:
            	GradeTooLowException(void) {};
            	virtual ~GradeTooLowException(void) throw() {};
            	virtual const char* what() const throw()
				{
					return "This grade is too low, it will be set at 150";
				};
    	};
	
	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif