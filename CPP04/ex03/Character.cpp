#include "Character.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
Character::Character(void) : _name("No name")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(Character const & src)
{
	std::cout << "Copy Character constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character detructor called" << std::endl;
}

/* OPERATORS */
Character const & Character::operator=(Character const & rhs)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &rhs)
		_name = rhs.getName();
	return *this;
}

/* METHODS */
std::string const &	Character::getName(void) const
{
	return _name;
}

void				Character::equip(AMateria* m)
{
	int i = 0;

	if (_inventory[3])
		std::cout << "Inventory of Materias is full" << std::endl;
	else
	{
		while (i < 4)
		{
			if (!_inventory[i])
				break ;
		}
		_inventory[i] = m;
	}
}

void				Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void 				Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}