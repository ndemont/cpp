#include "Zombie.hpp"

int main()
{
	Zombie *zombieOne = NULL;

	zombieOne = newZombie("Bub");
	randomChump("Billy Butcherson");
	delete zombieOne;
}