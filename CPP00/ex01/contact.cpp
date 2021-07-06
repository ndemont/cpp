#include "phonebook.hpp"

using namespace std;

Contact::Contact()
{
	m_index = -1;
	m_firstname = "no first name";
	m_lastname = "no last name";
	m_nickname = "no nick name";
	m_phonenumber = "no phone number"; 
	m_darkestsecret = "no secret";
}

Contact::~Contact()
{
}

void Contact::create_contact(int index)
{
	cout << "Enter your first name: ";
	getline(cin, m_firstname);
	cout << "Enter your last name: ";
	getline(cin, m_lastname);
	cout << "Enter your nickname: ";
	getline(cin, m_nickname);
	cout << "Enter your phone number: ";
	getline(cin, m_phonenumber);
	cout << "Enter your darkest secret: ";
	getline(cin, m_darkestsecret);
	cout << "New contact registered." << endl;
	m_index = index;
}

void	display_str(string str)
{
	string	trunc;

	cout << "|";
	if (str.size() == 10)
		cout << str;
	else if (str.size() > 10)
	{
		trunc = str.substr(0, 9);
		cout << trunc;
		cout << ".";
	}
	else
	{
		for (unsigned long i = 0; i < 10 - str.size(); i++)
			cout << " ";
		cout << str;
	}
}

void Contact::display_preview(void)
{
	cout << "|         " << m_index;
	display_str(m_firstname);
	display_str(m_lastname);
	display_str(m_nickname);
	cout << "|" << endl;
}

void Contact::display_all(void)
{
	cout << m_firstname << endl;
	cout << m_lastname << endl;
	cout << m_nickname << endl;
	cout << m_phonenumber << endl;
	cout << m_darkestsecret << endl;
}

int Contact::get_index(void)
{
	return (m_index);
}

void Contact::lower_index(void)
{
	m_index--;
}