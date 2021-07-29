#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default Wrong Cat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "Copy Wrong Cat constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}

void		WrongCat::makeSound(void) const
{
	std::cout << "Miaaaaaouuuuuuuuuuu!" << std::endl;
}