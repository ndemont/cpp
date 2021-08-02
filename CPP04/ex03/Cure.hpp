#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		virtual ~Cure(void);

		virtual Cure const & operator=(Cure const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter & target);

};

#endif