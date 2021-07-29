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
	std::cout << "tab[0] = " << tab[0] << std::endl;
	std::cout << "tab[1] = " << tab[1] << std::endl;

	iter<float>(tab2, len, &mult10);
	std::cout << "tab2[0] = " << tab2[0] << std::endl;
	std::cout << "tab2[1] = " << tab2[1] << std::endl;

	return 0;
}