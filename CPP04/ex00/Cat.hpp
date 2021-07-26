#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &		operator=(Cat const & rhs);

		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	type;

	private:
};

std::ostream &		operator<<(std::ostream & o, Cat const & i);

#endif