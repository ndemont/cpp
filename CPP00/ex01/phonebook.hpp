#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <vector>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <list>
# include "contact.hpp"

class	PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();

	void add_contact();
	void search_contact() const;

	private:

	Contact				_Phonebook[8];
	int					_nb_of_contacts;
}; 

#endif