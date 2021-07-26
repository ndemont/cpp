#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &	Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
		type = rhs.type;
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


std::ostream &	operator<<(std::ostream & o, Cat const & i)
{
	(void) i;
	return o;
}