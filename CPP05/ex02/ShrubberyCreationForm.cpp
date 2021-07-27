#include "ShrubberyCreationForm.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const name) : Form(name, 145, 137)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::action(std::string target) const
{
	std::ofstream	ofs(target + "_shrubbery");
	
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