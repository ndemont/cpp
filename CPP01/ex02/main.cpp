#include <iostream>

int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*ptr = &str;
	std::string		&ref = str;

	std::cout << "The string through pointer: " << *ptr << std::endl;
	std::cout << "The string through reference: " << ref << std::endl;
	return 0;
}