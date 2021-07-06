/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathnote.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:46:08 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/06 11:55:53 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deathnote.h"

using namespace std;

Contact::Contact()
{
	m_firstname = "no first name";
	m_lastname = "no last name";
	m_nickname = "no nick name";
	m_phonenumber = "no phone number"; 
	m_darkestsecret = "no secret";
}
Contact::Contact(string firstname, string lastname, string nickname, string phonenumber, string secret)
{
	m_phonenumber = phonenumber;
	m_firstname = firstname;
	m_lastname = lastname;
	m_nickname = nickname;
	m_darkestsecret = secret;
}

Contact::~Contact()
{
}

void add(PhoneBook deathnote, int *nb_of_contacts)
{
	string	firstname;
	string	lastname;
	string	nickname;
	string	age;
	string	secret;

	cout << "Enter your first name:" << endl;
	getline(cin, firstname);
	cout << "Enter your last name:" << endl;
	getline(cin, lastname);
	cout << "Enter your nickname:" << endl;
	getline(cin, nickname);
	cout << "Enter your phone nucmber:" << endl;
	getline(cin, age);
	cout << "Enter your darkest secret:" << endl;
	getline(cin, secret);
	cout << "New contact registered." << endl;
	Contact new_person(firstname, lastname, nickname, age, secret);
	deathnote.m_phonebook.push_back(new_person);
	if (*nb_of_contacts == 8)
		deathnote.m_phonebook.pop_front();
	else
		*nb_of_contacts = *nb_of_contacts + 1;
}

void	display_string(string str)
{
	size_t	length;

	cout << "|";
	length = str.size();
	if (length <= 10)
	{
		while (10 - length > 0)
		{
			cout << " ";
			length++;
		}
		cout << str;
	}
	else
	{
		cout << str.substr(0, 9);
		cout << ".";
	}
}

void	search(PhoneBook deathnote, int *nb_of_contacts)
{
	list<Contact>::iterator	contact;
	int						i;
	int						index;

	cout << "|     index|first name| last name|  nickname|" << endl;
	i = 0;
	for (contact = deathnote.m_phonebook.begin(); contact != deathnote.m_phonebook.end(); contact++)
	{
		printf("| %9i", i); 
		display_string(contact->m_firstname);
		display_string(contact->m_lastname);
		display_string(contact->m_nickname);
		cout << "|" << endl;
		i++;
	}
	cout << "Enter the index of the contact from which you want more informations:" << endl;
	cin >> index;
	cin.ignore();
	if (index < 0 || index > i)
		cout << "Wrong index." << endl;
	else
	{
		while (index < *nb_of_contacts)
		{
			contact--;
			index++;
		}
		cout << contact->m_firstname << endl;
		cout << contact->m_lastname << endl;
		cout << contact->m_nickname << endl;
		cout << contact->m_phonenumber << endl;
		cout << contact->m_darkestsecret << endl;
	}
}

void exit(void)
{
}

