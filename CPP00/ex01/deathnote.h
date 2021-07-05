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

void add(std::list<Contact> *deathnote, int *nb_of_people);
void search(std::list<Contact> *deathnote, int *nb_of_people);
void exit(void);

#endif