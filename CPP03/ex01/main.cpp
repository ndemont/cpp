#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	sophie("Sophie");
	ClapTrap	xavier("Xavier");
	ScavTrap	norminet("Norminet");
	std::string	student = "student";

	sophie.attack(student);
	xavier.takeDamage(15);
	norminet.beRepaired(10);
	sophie.guardGate();
	norminet.guardGate();
	return 0;
}