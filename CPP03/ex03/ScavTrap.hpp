#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);
	
		ScavTrap const & operator=(ScavTrap const & rhs);

		void	guardGate(void);
};

#endif