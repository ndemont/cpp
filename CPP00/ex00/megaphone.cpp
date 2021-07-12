#include <iostream>

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
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			letter = megaphone(av[i][j]);
			std::cout << letter;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}