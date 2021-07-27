#include "DiamondTrap.hpp"

//CONSTRUCTOR
DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "My Diamond name is "<< DiamondTrap::getName() << std::endl;
	std::cout << "My Clap name is " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return this->_name;
}