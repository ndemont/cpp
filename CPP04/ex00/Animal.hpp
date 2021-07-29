#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &			operator=(Animal const & rhs);
		
		std::string			getType(void) const;
		void virtual		makeSound(void) const;

	protected:
		std::string			_type;
};

std::ostream &				operator<<(std::ostream & o, Animal const & i);

#endif