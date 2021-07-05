/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathnote.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:46:08 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/05 18:18:27 by ndemont          ###   ########.fr       */
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
	getline(std::cin, firstname);
	cout << "Enter your last name:" << endl;
	getline(std::cin, lastname);
	cout << "Enter your last name:" << endl;
	getline(cin, nickname);
	cout << "Enter your age:" << endl;
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

void search(list<Contact> *deathnote, int *nb_of_people)
{
	list<Contact>::iterator	contact;

	cout << "|     index|first name| last name|  nickname|" << endl;
	for (contact = deathnote->begin(); contact != deathnote->end(); contact++)
	{
		cout << "|" << contact->m_firstname << "|";
		cout << "|" << contact->m_lastname << "|";
		cout << "|" << contact->m_nickname << "|";
		cout << "|" << contact->m_phonenumber << "|";
		cout << "|" << contact->m_darkestsecret << "|";
	}
}

void exit(void)
{
}

