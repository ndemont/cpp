#include "WrongAnimal.hpp"

/* CONSTRUCTORS */
WrongAnimal::WrongAnimal(void) : type("Generic WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* OPERATORS */
WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		type = rhs.type;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return type;
}

void		WrongAnimal::makeSound(void) const 
{
	std::cout << "*Weird animal sound resonating in the wind*" << std::endl;
}


std::ostream &	operator<<(std::ostream & o, WrongAnimal const & i)
{
	(void)i;
	return o;
}