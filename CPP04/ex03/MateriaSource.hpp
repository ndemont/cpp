#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
	
	private:
		AMateria	*_inventory[4];
};

#endif