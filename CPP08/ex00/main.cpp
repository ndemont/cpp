#include "easyfind.hpp"

int		main(void)
{
	std::list<int>		mylist(4, 15);
	std::array<int, 5>	myarray = {0, 2, 4, 6, 8};

	easyfind(myarray, 6);
	easyfind(mylist, 16);
	return 0;
}