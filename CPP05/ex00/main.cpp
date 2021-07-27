#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat Macron("Macron", 160);
	Bureaucrat Nicolas("Nicolas", 1);
	std::cout << Macron;
	std::cout << Nicolas;
	Nicolas++;
	std::cout << Nicolas;
	return 0;
}