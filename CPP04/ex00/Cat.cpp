#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
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

void		Cat::makeSound(void) const
{
	std::cout << "Miaaaaaouuuuuuuuuuu!" << std::endl;
}