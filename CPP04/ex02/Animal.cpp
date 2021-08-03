#include "Animal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called with type: " << getType() << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

/* OPERATORS */
AAnimal &	AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "AAnimal assignation operator called" << std::endl;

	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return _type;
}
