#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "Wrong Cat";
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

void		WrongCat::makeSound(void) const
{
	std::cout << "Miaaaaaouuuuuuuuuuu!" << std::endl;
}