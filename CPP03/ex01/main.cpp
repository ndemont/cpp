#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	sophie("Sophie");
	std::string	student = "student";

	sophie.attack(student);
	sophie.guardGate();
	return 0;
}