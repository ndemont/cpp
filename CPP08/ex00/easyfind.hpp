#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <deque>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include <stdexcept>

class ValueNotFoundException : public std::exception
{
	public:
		ValueNotFoundException(void) {};
		virtual ~ValueNotFoundException(void) throw() {};
		virtual const char* what() const throw()
		{				
			return "has no occurence in this container.";
		}
};

template < typename T >
typename T::iterator	easyfind(T & container, int nb)
{
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();
	typename T::iterator find = std::find(begin, end, nb);

	try
	{
		if (end == find)
			throw ValueNotFoundException();
		else
			std::cout << "The value '" << nb << "' has at least one occurence in this container." << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << "The value '" << nb << "' " << e.what() << std::endl;
	}
	return find;
}

#endif