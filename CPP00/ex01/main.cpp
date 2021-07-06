/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:58 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/06 17:51:13 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

using namespace std;

int main()
{
	string			command("INIT");
	PhoneBook		deathnote;

	cout << endl;
	cout << "Welcome to the Death Note. You can use the following commands:" << endl << endl;
	cout << "ADD:    to add a new contact." << endl;
	cout << "SEARCH: to preview contacts and choose the one you want more details about." << endl;
	cout << "EXIT:   to exit the Death Note." << endl << endl;
	cout << "Type your command: ";
	getline(cin, command);
	cout << endl;
	while ((command != "EXIT"))
	{
		if (command == "ADD")
			deathnote.add_contact();
		if (command == "SEARCH")
			deathnote.search_contact();
		cout << endl;
		cout << "Type your command: ";
		getline(cin, command);
		cout << endl;
	}
	return 0;
}
