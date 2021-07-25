#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int			 ClapTrap::getDamage(void) const
{
	return _attackDamage;
}

void		ClapTrap::setHitPoints(int amount)
{
	_hitPoints = amount;
}
void		ClapTrap::setEnergyPoints(int amount)
{
	_energyPoints = amount;
}

void		ClapTrap::setAttackDammage(int amount)
{
	_attackDamage = amount;
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
