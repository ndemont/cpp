#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat &		operator++(void);
		Bureaucrat			operator++(int);
		Bureaucrat &		operator--(void);
		Bureaucrat			operator--(int);

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

		std::string		getName(void) const;
		int				getGrade(void) const;
		void 			checkGrade(int grade);
	
	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif