#include "Animal.hpp"

AAnimal::AAnimal(void) : type("Generic AAnimal")
{
	std::cout << "Default AAnimal constructor called" << std::endl;
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
		type = rhs.type;
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return type;
}

void	AAnimal::setType(std::string newType)
{
	type = newType;
}

void		AAnimal::makeSound(void) const 
{
	std::cout << "*Weird Aanimal sound resonating in the wind*" << std::endl;
}