#include "iter.hpp"
#include <iostream>

int		mult2(int nb)
{
	return (nb * 2);
}

float		mult10(float nb)
{
	return (nb * 10);
}

int		main(void)
{
	int		len =  10;
	int		tab[10] = {0,1,2,3,4,5,6,7,8,9};
	float	tab2[10] = {0,1,2,3,4,5,6,7,8,9};

	iter<int>(tab, len, &mult2);
	std::cout << "Function multiple of 2" << std::endl;
	std::cout << "tab[0] (0 * 2) = " << tab[0] << std::endl;
	std::cout << "tab[5] (5 * 2) = " << tab[5] << std::endl;

	iter<float>(tab2, len, &mult10);
	std::cout << "Function multiple of 10" << std::endl;
	std::cout << "tab2[0] (0 * 10) = " << tab2[0] << std::endl;
	std::cout << "tab2[5] (5 * 10) = " << tab2[5] << std::endl;

	return 0;
}