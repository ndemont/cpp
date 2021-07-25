#include "ScavTrap.hpp"


//CONSTRUCTORS

ScavTrap::ScavTrap(void)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << getName() << " guards the gate." << std::endl;
}
