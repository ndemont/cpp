#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base	*generate(void)
{
	srand (time(NULL));
	int random = rand() % 3;
	if (random == 1)
	{
		A *newBase = new A;
		*newBase = A();
		std::cout << "Generating A Base" << std::endl;
		return newBase;
	}
	else if (random == 2)
	{
		B *newBase = new B;
		*newBase = B();
		std::cout << "Generating B Base" << std::endl;
		return newBase;
	}
	else
	{
		C *newBase = new C;
		*newBase = C();
		std::cout << "Generating C Base" << std::endl;
		return newBase;
	}
}

void	identify_from_pointer(Base * p)
{
	try
	{
		A base = dynamic_cast<A &>(*p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B base = dynamic_cast<B &>(*p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C base = dynamic_cast<C &>(*p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	

}

void	identify_from_reference(Base & p)
{
	try
	{
		//Base P = dynamic_cast<Base>(p);
		A base = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
		try
	{
		B base = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
		try
	{
		C base = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
}