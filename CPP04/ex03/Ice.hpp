#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		virtual ~Ice(void);

		virtual Ice const & operator=(Ice const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter & target);

	protected:
	
	private:

};

#endif