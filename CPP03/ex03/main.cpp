#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap	sophie("Sophie");
	DiamondTrap	xavier("Xavier");
	DiamondTrap	norminet("Norminet");
	std::string	student = "student";

	std::cout << std::endl;

	sophie.attack(student);
	xavier.takeDamage(67);
	norminet.beRepaired(10000);
	norminet.whoAmI();
	sophie.guardGate();
	xavier.highFivesGuys();

	std::cout << std::endl;

	return 0;
}