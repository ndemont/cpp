#include "MateriaSource.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Materia Source constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Copy Materia Source constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "Materia Source destructor called" << std::endl;
}

/* OPERATORS */
MateriaSource const &	MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "Materia assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			_inventory[i] = rhs.getMateria(i);
	}
	return *this;
}

/* METHODS */
AMateria		*MateriaSource::getMateria(int idx) const
{
	return _inventory[idx];
}

void	MateriaSource::learnMateria(AMateria* const m)
{
	int i = 0;

	if (_inventory[3])
		std::cout << "Inventory of Materias is full" << std::endl;
	else
	{
		std::cout << "Learning new Materia of type: " << m->getType() << std::endl;
		while (i < 4)
		{
			if (!_inventory[i])
				break ;
			i++;
		}
		_inventory[i] = m;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (i < 4)
	{
		if (type == _inventory[i]->getType())
			return (_inventory[i]);
		i++;
	}
	std::cout << "Unknown type of Materia"<< std::endl;
	return 0;
}