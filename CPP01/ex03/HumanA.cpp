#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _WeaponA(weapon), _name(name)
{
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with his " << _WeaponA.getType() << std::endl;
}