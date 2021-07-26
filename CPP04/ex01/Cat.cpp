#include "Cat.hpp"

Cat::Cat(void) : type("Cat"), _brain(new Brain())
{
	std::cout << "Default Cat constructor called & brain allocated" << std::endl;
}

Cat::Cat(Cat const & src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called & brain deleted" << std::endl;
}

Cat &	Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain();
		std::cout << "Old brain deleted, new brain allocated" << std::endl;
		*_brain = *(rhs._brain);
		type = rhs.type;
	}
	return *this;
}

std::string	Cat::getType(void) const
{
	return type;
}

void		Cat::makeSound(void) const
{
	std::cout << "Miaaaaaouuuuuuuuuuu!" << std::endl;
}