#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
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

void		Dog::makeSound(void) const
{
	std::cout << "Wouaf! Wouaaaaaf! Wouaf wouaf wouaf!" << std::endl;
}
