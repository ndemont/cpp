#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const & src);
		~Animal(void);

		Animal &		operator=(Animal const & rhs);
		
		std::string	virtual	getType(void) const;
		void virtual		makeSound(void) const;

	protected:
		std::string	type;

	private:
};

std::ostream &		operator<<(std::ostream & o, Animal const & i);

#endif