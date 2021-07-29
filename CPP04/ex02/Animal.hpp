#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class AAnimal
{
	public:
		virtual ~AAnimal(void);

		virtual void		makeSound(void) const = 0;

	protected:
		std::string			_type;

	private:
};

#endif