#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	Animal	farm[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			farm[i] = Cat();
		else
			farm[i] = Dog();
		std::cout << std::endl;
	}

	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	Cat cat1 = Cat();
	std::cout << std::endl;
	Cat cat2 = cat1;
	std::cout << std::endl;

	delete j;
	delete i;
	return 0;
}