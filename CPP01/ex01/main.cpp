#include "Zombie.hpp"

int main()
{
	Zombie *Horde;
	int		ZombieNbr = 7;

	Horde = zombieHorde(ZombieNbr, "Macron");
	for (int i = 0; i < ZombieNbr; i++)
		Horde[i].announce();
	delete [] Horde;
	return 0;
}