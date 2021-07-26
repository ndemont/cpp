#include "Ice.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
Ice::Ice(void)
{
	_type = "Ice";
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & src)
{
	std::cout << "Copy Ice constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

/* OPERATORS */
Ice const & Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

/* METHODS */
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