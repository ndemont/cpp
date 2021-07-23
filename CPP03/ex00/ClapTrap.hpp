#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);

		std::string	getName(void) const;
		int			getDamage(void) const;
		void		attack(std::string const & target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

#endif