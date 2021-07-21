#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name)
{
}

HumanB::~HumanB( void )
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_WeaponB = &weapon;
}


void	HumanB::attack( void )
{
	std::cout << _name << " attacks with his " << _WeaponB->getType() << std::endl;
}