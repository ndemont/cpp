#include "Weapon.hpp"

Weapon::Weapon( std::string weapon) : _type(weapon)
{
}

Weapon::~Weapon(void)
{
}

void			Weapon::setType(std::string type)
{
	_type = type;
}

std::string const &	Weapon::getType(void) const
{
	std::string	const &ref = _type;
	return ref;
}
