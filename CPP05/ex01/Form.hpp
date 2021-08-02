#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(Form const & src);
		~Form(void);

		std::string		getName(void) const;
		bool			getSignedStatus(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExec(void) const;
		void 			checkGrade(int grade);
		void 			checkSignature(int grade, int gradeToSign);
		int				getGrade(int const grade);

		void			beSigned(Bureaucrat bureaucrat);

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
		std::string	const	_name;
		bool				_signed;
		int	const			_gradeToSign;
		int	const			_gradeToExec;
};

std::ostream &	operator<<(std::ostream & o, Form const & i);

#endif