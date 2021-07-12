#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	
public:

	Zombie( void );
	Zombie(std::string name);
	~Zombie( void );

	void		announce( void ) const;
	std::string	randomName( void ) const;
	std::string	getName( void ) const;

private:

	std::string	_name;

};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif