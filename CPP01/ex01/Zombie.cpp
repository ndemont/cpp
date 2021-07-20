#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = randomName();
	return;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " has been destroyed" << std::endl;
}

void		Zombie::announce(void) const
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

std::string	Zombie::getName(void) const
{
	return _name;
}

std::string Zombie::randomName(void) const
{
	std::string	list[10];

	list[0] = "Walker";
	list[1] = "Geek";
	list[2] = "Lurker";
	list[3] = "Biter";
	list[4] = "Creeper";
	list[5] = "Roamer";
	list[6] = "The infected";
	list[7] = "Rotter";
	list[8] = "Lame-Brain";
	list[9] = "Stinker";
	return list[rand() % 9];
}