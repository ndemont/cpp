#include "phonebook.hpp"

Contact::Contact()
{
	_index = -1;
	_firstname = "no first name";
	_lastname = "no last name";
	_nickname = "no nick name";
	_phonenumber = "no phone number"; 
	_darkestsecret = "no secret";
}

Contact::~Contact()
{
}

void Contact::create_contact(int index)
{
	std::cout << "Enter your first name: ";
	getline(std::cin, _firstname);
	std::cout << "Enter your last name: ";
	getline(std::cin, _lastname);
	std::cout << "Enter your nickname: ";
	getline(std::cin, _nickname);
	std::cout << "Enter your phone number: ";
	getline(std::cin, _phonenumber);
	std::cout << "Enter your darkest secret: ";
	getline(std::cin, _darkestsecret);
	std::cout << "New contact registered." << std::endl;
	_index = index;
}

void	display_str(std::string str)
{
	std::string	trunc;

	std::cout << "|";
	if (str.size() == 10)
		std::cout << str;
	else if (str.size() > 10)
	{
		trunc = str.substr(0, 9);
		std::cout << trunc;
		std::cout << ".";
	}
	else
	{
		for (unsigned long i = 0; i < 10 - str.size(); i++)
			std::cout << " ";
		std::cout << str;
	}
}

void Contact::display_preview(void) const
{
	std::cout << "|         " << _index;
	display_str(_firstname);
	display_str(_lastname);
	display_str(_nickname);
	std::cout << "|" << std::endl;
}

void Contact::display_all(void) const
{
	std::cout << _firstname << std::endl;
	std::cout << _lastname << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _phonenumber << std::endl;
	std::cout << _darkestsecret << std::endl;
}

int Contact::get_index(void) const
{
	return (_index);
}
