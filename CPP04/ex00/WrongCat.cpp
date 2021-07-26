#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("WrongCat")
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
		type = rhs.type;
	return *this;
}

std::string	WrongCat::getType(void) const
{
	return type;
}

void		WrongCat::makeSound(void) const
{
	std::cout << "Miaaaaaouuuuuuuuuuu!" << std::endl;
}


std::ostream &	operator<<(std::ostream & o, WrongCat const & i)
{
	(void) i;
	return o;
}