#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "Character.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);

		virtual AMateria const & operator=(AMateria const & rhs);

		std::string const &	getType(void) const;
		void				setType(std::string const & type);
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter & target);

	protected:
		std::string		_type;
};

#endif