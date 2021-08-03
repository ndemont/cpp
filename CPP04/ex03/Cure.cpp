#include "Cure.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
Cure::Cure(void)
{
	_type = "cure";
	std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(Cure const & src)
{
	_type = "cure";
	std::cout << "Copy Cure constructor called" << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure const & Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure assignation operator called" << std::endl;
	(void)rhs;
	return *this;
}

AMateria*	Cure::clone(void) const
{
	AMateria *newCure = new Cure();

	newCure->setType(getType());
	return newCure;
}

void		Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
