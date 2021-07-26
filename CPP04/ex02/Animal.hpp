#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);

		virtual AAnimal & 	operator=(AAnimal const & rhs);
		
		std::string			getType(void) const;
		void				setType(std::string newType);
		virtual void		makeSound(void) const = 0;

	protected:
		std::string	type;

	private:
};

#endif