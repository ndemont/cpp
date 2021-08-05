#include "span.hpp"

int main()
{
	Span sp = Span(2);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	Span err(5);
    err.addNumber(1);
    err.addNumber(142);
    err.addNumber(100);
    err.addNumber(121);
    err.addNumber(122);
    std::cout << err.shortestSpan() << std::endl;
    std::cout << err.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}