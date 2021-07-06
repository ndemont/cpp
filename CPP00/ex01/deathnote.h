#ifndef DEATHNOTE_H
# define DEATHNOTE_H

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
	Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string secret);
	~Contact();

	std::string	m_firstname;
	std::string	m_lastname;
	std::string	m_nickname;
	std::string	m_phonenumber;
	std::string	m_darkestsecret;
};

class	PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();

	std::list<Contact>	m_phonebook;
};

void add(PhoneBook phonebook, int *nb_of_contacts);
void search(PhoneBook phonebook, int *nb_of_contacts);
void exit(void);

#endif