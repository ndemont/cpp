#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	
public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void		announce(void) const;
	void		setName(std::string name);
	std::string	randomName(void) const;
	std::string	getName(void) const;

private:

	std::string	_name;

};

Zombie* zombieHorde(int N, std::string name);

#endif