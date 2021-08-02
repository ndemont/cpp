#include "Ice.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
Ice::Ice(void)
{
	_type = "ice";
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & src)
{
	_type = "ice";
	std::cout << "Copy Ice constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice const & Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice assignation operator called" << std::endl;
	(void)rhs;
	return *this;
}

AMateria*	Ice::clone(void) const
{
	AMateria *newIce = new Ice();

	newIce->setType(getType());
	return newIce;
}

void		Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}