/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:58 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/06 11:57:38 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deathnote.h"

using namespace std;

int main()
{
	string			command("INIT");
	PhoneBook		deathnote;
	int				nb_of_contacts(0);

	getline(cin, command);
	while ((command != "EXIT"))
	{
		if (command == "ADD")
			add(deathnote, &nb_of_contacts);
		if (command == "SEARCH")
			search(deathnote, &nb_of_contacts);
		getline(cin, command);
	}
	return 0;
}
