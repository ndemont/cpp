#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ScavTrap	sophie("Sophie");
	FragTrap	xavier("Xavier");
	std::string	student = "student";

	sophie.attack(student);
	xavier.attack(student);
	sophie.guardGate();
	xavier.highFivesGuys();
	return 0;
}