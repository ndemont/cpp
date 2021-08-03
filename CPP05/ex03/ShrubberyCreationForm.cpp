#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("Unkown target")
{
	std::cout << "Default ShrubberyCreationForm constructor called with target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Default ShrubberyCreationForm constructor called with target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : _target(src.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm constructor called with target: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called with target: " << _target << std::endl;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
	
 	std::string fileName = _target + "_shrubbery";
	char* c = const_cast<char*>(fileName.c_str());
	std::ofstream	ofs(c);
	
	ofs << "	               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;	
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "	\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	ofs.close();
}