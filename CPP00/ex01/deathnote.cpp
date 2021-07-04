/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathnote.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:46:08 by ndemont           #+#    #+#             */
/*   Updated: 2021/07/05 00:16:48 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deathnote.h"

using namespace std;

void add(vector<string> notebook, int *name_nb)
{
	int		age;
	int		i;
	string	name("no name");

	cout << "Enter your name:" << endl;
	getline(cin, name);
	cout << "Enter your age:" << endl;
	cin >> age;
	cin.ignore();
	notebook.push_back(name);
	*name_nb = *name_nb + 1;
	if (*name_nb > 8)
		notebook.pop_front();
}

void search(vector<string> notebook, int *name_nb)
{
	(void)notebook;
	(void)name_nb;
}

void exit(void)
{

}

int main(int ac, char **av)
{
	string			command("INIT");
	vector<string>	deathnote;
	int				name_nb(0);

	getline(cin, command);
	while ((command.compare("EXIT")))
	{
		if (!(command.compare("ADD")))
			add(deathnote, &name_nb);
		if (!(command.compare("SEARCH")))
			search(deathnote, &name_nb);
		getline(cin, command);
	}
	return 0;
}