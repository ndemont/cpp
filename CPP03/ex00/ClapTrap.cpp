#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::~ClapTrap(void)
{
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int			 ClapTrap::getDamage(void) const
{
	return _attackDamage;
}


void	ClapTrap::attack(std::string const & target) const
{
	std::cout << getName() << " attacks " << target << " causing " << getDamage() << " points of dammage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	(void)_hitPoints;
	std::cout << getName() << " takes " << amount << " points of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	(void)_energyPoints;
	std::cout << getName() << " is repaired from" << amount << " points." << std::endl;
}
