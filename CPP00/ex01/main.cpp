/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:58 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/05 18:17:05 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deathnote.h"

using namespace std;

int main(int ac, char **av)
{
	string			command("INIT");
	list<Contact>	deathnote;
	int				nb_of_people(0);

	getline(cin, command);
	while ((command != "EXIT"))
	{
		if (command == "ADD")
			add(&deathnote, &nb_of_people);
		if (command == "SEARCH")
			search(&deathnote, &nb_of_people);
		getline(cin, command);
	}
	return 0;
}
