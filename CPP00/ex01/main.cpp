/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:58 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/12 13:03:16 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string	command("INIT");
	PhoneBook	deathnote;

	std::cout << std::endl;
	std::cout << "Welcome to the Death Note. You can use the following commands:" << std::endl << std::endl;
	std::cout << "ADD:    to add a new contact." << std::endl;
	std::cout << "SEARCH: to preview contacts and choose the one you want more details about." << std::endl;
	std::cout << "EXIT:   to exit the Death Note." << std::endl << std::endl;
	std::cout << "Type your command: ";
	getline(std::cin, command);
	std::cout << std::endl;
	while ((command != "EXIT"))
	{
		if (command == "ADD")
			deathnote.add_contact();
		if (command == "SEARCH")
			deathnote.search_contact();
		std::cout << std::endl;
		std::cout << "Type your command: ";
		getline(std::cin, command);
		std::cout << std::endl;
	}
	return 0;
}
