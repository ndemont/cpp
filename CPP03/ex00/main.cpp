#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	sophie("Sophie");
	ClapTrap	xavier("Xavier");
	ClapTrap	norminet("Norminet");
	std::string	student = "student";

	sophie.attack(student);
	xavier.takeDamage(15);
	norminet.beRepaired(10);
	return 0;
}