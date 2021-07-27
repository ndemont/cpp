#include "PresidentialPardonForm.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << _target << " has been forgiven by Zafod Beeblebrox" << std::endl;
}
