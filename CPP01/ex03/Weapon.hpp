#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
public:

	Weapon(std::string weapon);
	~Weapon(void);

	void				setType(std::string type);
	std::string const &	getType(void) const;
	
private:

	std::string	_type;
};

#endif