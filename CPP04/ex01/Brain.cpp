#include "Brain.hpp"

/* CONSTRUCTORS */
Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

/* OPERATORS */
Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}