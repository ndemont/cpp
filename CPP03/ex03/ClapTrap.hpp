#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap const & operator=(ClapTrap const & rhs);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getDamage(void) const;
		void		setHitPoints(int amount);
		void		setEnergyPoints(int amount);
		void		setAttackDammage(int amount);

		void		attack(std::string const & target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

#endif