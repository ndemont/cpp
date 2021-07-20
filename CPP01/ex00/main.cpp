#include "Zombie.hpp"

int main()
{
	Zombie *zombieOne = NULL;

	zombieOne = newZombie("Bub");
	zombieOne->announce();
	randomChump("Billy Butcherson");
	delete zombieOne;
}