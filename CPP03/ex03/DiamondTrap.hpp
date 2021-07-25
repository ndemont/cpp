#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap	(DiamondTrap const & src);
		~DiamondTrap(void);

		void	whoAmI(void);

		FragTrap::_hitPoints;
		ScavTrap::_energyPoints;
		FragTrap::_attackDamage;
		ScavTrap::attack;
};

#endif