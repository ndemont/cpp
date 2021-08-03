#include "Dog.hpp"

Dog::Dog(void) : _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Default Dog constructor called & brin allocated" << std::endl;
}

Dog::Dog(Dog const & src) : _brain(new Brain())
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called & brain deleted" << std::endl;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain();
		std::cout << "Old brain deleted, new brain allocated" << std::endl;
		*_brain = *(rhs._brain);
	}
	return *this;
}

void		Dog::makeSound(void) const
{
	std::cout << "Wouaf! Wouaaaaaf! Wouaf wouaf wouaf!" << std::endl;
}