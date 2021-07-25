#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	//ScavTrap	sophie("Sophie");
	//FragTrap	xavier("Xavier");
	DiamondTrap	norminet("Norminet");
	std::string	student = "student";

	//sophie.attack(student);
	//xavier.attack(student);
	norminet.attack(student);
	norminet.whoAmI();
	//sophie.guardGate();
	//xavier.highFivesGuys();
	return 0;
}