#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int		main(void)
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << std::endl << std::endl;

	std::cout << "The " << *meta << " makes a sound: ";
	meta->makeSound();
	std::cout << "The " << *i << " makes a sound: ";
	i->makeSound();
	std::cout << "The " << *j << " makes a sound: ";
	j->makeSound();

	std::cout << std::endl << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << std::endl << std::endl;

	std::cout << "The " << *meta2 << " makes a sound: ";
	meta2->makeSound();
	std::cout << "The " << *i2 << " makes a sound: ";
	i2->makeSound();

	return 0;
}