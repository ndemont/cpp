#include "Dog.hpp"

Dog::Dog(void) : type("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return *this;
}

std::string	Dog::getType(void) const
{
	return type;
}

void		Dog::makeSound(void) const
{
	std::cout << "Wouaf! Wouaaaaaf! Wouaf wouaf wouaf!" << std::endl;
}


std::ostream &	operator<<(std::ostream & o, Dog const & i)
{
	(void)i;
	return o;
}