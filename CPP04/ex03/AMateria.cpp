#include "AMateria.hpp"

/* CONSTRUCTORS & DESTRUCTORS */
AMateria::AMateria(void) : _type("Generic Materia")
{
	std::cout << "Default Materia constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Default Materia constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "Copy Materia constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "Materia destructor called" << std::endl;
}

/* OPERATORS */
AMateria const & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "Materia assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

/* METHODS */
std::string const &	AMateria::getType() const
{
	return _type;
}

void				AMateria::setType(std::string const & type)
{
	_type = type;
}

void				AMateria::use(ICharacter& target)
{
	(void)target;
}
