#include "Animal.hpp"

/* CONSTRUCTORS */
Animal::Animal(void) : type("Generic Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/* OPERATORS */
Animal &	Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;

	if (this != &rhs)
		type = rhs.type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return type;
}

void		Animal::makeSound(void) const 
{
	std::cout << "*Weird animal sound resonating in the wind*" << std::endl;
}