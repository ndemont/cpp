#include "phonebook.hpp"

using namespace std;

PhoneBook::PhoneBook()
{
	m_nb_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact(void)
{
	if (m_nb_of_contacts < 8)
	{
		m_Phonebook[m_nb_of_contacts].create_contact(m_nb_of_contacts + 1);
		m_nb_of_contacts++;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (m_Phonebook[i].get_index() == 1)
				m_Phonebook[i].create_contact(m_nb_of_contacts + 1);
			m_Phonebook[i].lower_index();
		}
	}
}

void	PhoneBook::search_contact(void)
{
	string				index_str;
	int					index_int;
	stringstream		ss;

	cout << "---------------------------------------------" << endl;
	cout << "|     index|first name| last name|  nickname|" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < m_nb_of_contacts; i++)
		m_Phonebook[i].display_preview();
	cout << "---------------------------------------------" << endl;
	cout << endl << "Enter the index you are interested in: ";
	getline(cin, index_str);
	cout << endl;
	ss << index_str;
	ss >> index_int;
	if (index_int < 1 || index_int > m_nb_of_contacts)
		cout << "This index does not exists. Sorry" << endl;
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (m_Phonebook[i].get_index() == index_int)
				m_Phonebook[index_int - 1].display_all();
		}
	}
}
