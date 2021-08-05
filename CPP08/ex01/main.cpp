#include "span.hpp"

int main()
{
	Span sp = Span(10000000);
	std::list<int>	list;
	int j;

	for (int i = 0; i < 10000000; i++)
	{
		j = rand() % 1000;
		list.push_back(j);
	}
	sp.addRange(list.begin(), list.end());
	sp.addRange(list.begin(), list.end());
	std::cout << sp.longestSpan() << std::endl;
	
}