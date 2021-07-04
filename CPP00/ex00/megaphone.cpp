#include <iostream>

using namespace std;

char	megaphone(char letter)
{
	char megaphone;

	if (letter >= 97 && letter <= 122)
		megaphone = letter - 32;
	else
		megaphone = letter;
	return (megaphone);
}

int	main(int ac, char **av)
{
	int i;
	int j;
	char letter;

	if (ac < 2)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			letter = megaphone(av[i][j]);
			cout << letter;
			j++;
		}
		i++;
	}
	cout << endl;
	return 0;
}