#include "Karen.hpp"

Karen::Karen(void)
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Karen::~Karen(void)
{
}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << " I’ve been coming here for years and you just started working here last month" << std::endl;
	std::cout << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Karen::other(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Karen::complain(std::string level)
{
	int complaint = 0;

	while (complaint < 4)
	{
		if (level == levels[complaint])
			break;
		complaint++;
	}
	switch(complaint)
	{
		default: 
			other();
			break ;
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
	}
}