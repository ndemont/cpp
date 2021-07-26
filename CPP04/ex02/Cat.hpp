#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		virtual	Cat &		operator=(Cat const & rhs);
		virtual void		makeSound(void) const;

	private:
		Brain		*_brain;
};

#endif