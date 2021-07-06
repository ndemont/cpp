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
	void search_contact();

	private:

	Contact				m_Phonebook[8];
	int					m_nb_of_contacts;
}; 

#endif