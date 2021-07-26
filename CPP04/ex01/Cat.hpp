#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		virtual	Cat &		operator=(Cat const & rhs);

		virtual std::string	getType(void) const;
		virtual void		makeSound(void) const;

	protected:
		std::string	type;

	private:
		Brain		*_brain;
};

#endif