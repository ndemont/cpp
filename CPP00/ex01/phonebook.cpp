#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_nb_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact(void)
{
	if (_nb_of_contacts < 8)
	{
		_Phonebook[_nb_of_contacts].create_contact(_nb_of_contacts + 1);
		_nb_of_contacts++;
	}
	else
		std::cout << "Your Death Note is full. Sorry." << std::endl;
}

void	PhoneBook::search_contact(void) const
{
	std::stringstream	ss;
	std::string			index_str;
	int					index_int;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _nb_of_contacts; i++)
		_Phonebook[i].display_preview();
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl << "Enter the index you are interested in: ";
	getline(std::cin, index_str);
	std::cout << std::endl;
	ss << index_str;
	ss >> index_int;
	if (index_int < 1 || index_int > _nb_of_contacts)
		std::cout << "This index does not exists. Sorry." << std::endl;
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (_Phonebook[i].get_index() == index_int)
				_Phonebook[index_int - 1].display_all();
		}
	}
}
