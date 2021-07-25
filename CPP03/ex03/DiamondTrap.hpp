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

		void		whoAmI(void) const;
		std::string	getName(void) const;

		using FragTrap::_hitPoints;
		using ScavTrap::_energyPoints;
		using FragTrap::_attackDamage;
		using ScavTrap::attack;

	private:

		std::string _name;
};

#endif