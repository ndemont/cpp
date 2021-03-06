#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
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

Animal &	Animal::operator=(Animal const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return _type;
}

void		Animal::makeSound(void) const 
{
	std::cout << "* Weird animal sound resonating in the wind *" << std::endl;
}


std::ostream &	operator<<(std::ostream & o, Animal const & i)
{
	o << i.getType();
	return o;
}