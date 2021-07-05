/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathnote.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:46:08 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/05 22:44:32 by ndemont          ###   ########.fr       */
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

void add(list<Contact> *deathnote, int *nb_of_people)
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
	cout << "Enter your phone number:" << endl;
	getline(cin, age);
	cout << "Enter your darkest secret:" << endl;
	getline(cin, secret);
	cout << "New contact registered." << endl;
	Contact new_person(firstname, lastname, nickname, age, secret);
	deathnote->push_back(new_person);
	if (*nb_of_people == 8)
		deathnote->pop_front();
	else
		*nb_of_people = *nb_of_people + 1;
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

//void	display_contact()

void	search(list<Contact> *deathnote, int *nb_of_people)
{
	list<Contact>::iterator	contact;
	int						i;
	int						index;
	char					*buffer;

	cout << "|     index|first name| last name|  nickname|" << endl;
	i = 0;
	for (contact = deathnote->begin(); contact != deathnote->end(); contact++)
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
		while (index < *nb_of_people)
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

