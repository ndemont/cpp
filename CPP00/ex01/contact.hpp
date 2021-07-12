#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <vector>
# include <iostream>
# include <cstdlib>
# include <list>

class	Contact
{
	public:

	Contact();
	~Contact();

	void	create_contact(int index);
	void	display_preview(void) const;
	void	display_all(void) const;
	int		get_index(void) const;

	private:

	int			_index;
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darkestsecret;
};

#endif