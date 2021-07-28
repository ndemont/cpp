#include "Scalar.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "This program needs precisely one argument." << std::endl;
		return 1;
	}
	Scalar conversion(av[1]);
	std::cout << std::endl << conversion << std::endl;
	return 0;
}