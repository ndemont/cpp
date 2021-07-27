#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
PresidentialPardonForm::PresidentialPardonForm(std::string const name) : Form(name, 25, 5)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::action(std::string target) const
{
	std::cout << target << " has been forgiven by Zafod Beeblebrox" << std::endl;
}
