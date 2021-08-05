#include "span.hpp"

	Span::Span(void) : _size(0), _shortest(4294967295), _longest(0)
	{
	}

	Span::Span(unsigned int N) : _size(N), _shortest(4294967295), _longest(0)
	{
	}

	Span::Span(Span const & src)
	{
		if (this != &src)
			*this = src;
	}
		
	Span::~Span(void)
	{
	}

	Span const & Span::operator=(Span const & rhs)
	{
		_size = rhs._size;
		_storage = rhs._storage;
		_longest = rhs._longest;
		_shortest = rhs._shortest;
		return *this;
	}

	void	Span::addNumber(int nb)
	{
		std::list<int>::iterator begin;
		std::list<int>::iterator end;

		try 
		{
			if (_storage.size() == _size)
			{
				throw SpanIsFullException();
			}
			else 
			{
				begin = _storage.begin();
				end = _storage.end();
				if (static_cast<unsigned long>(nb - *begin) < _shortest)
						_shortest = static_cast<unsigned long>(nb - *begin);
				if (begin != end)
					begin++;
				while (begin != end)
				{
					if (static_cast<unsigned long>(nb - *begin) < _shortest)
						_shortest = nb - *begin;
					begin++;
				}
				_storage.push_front(nb);
				_storage.sort();
				if (static_cast<unsigned long>(_storage.back() - _storage.front()) > _longest)
					_longest = (_storage.back()) - _storage.front();
			}
		} 
		catch(const std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}

	int	Span::longestSpan(void)
	{
		return _longest;
	}

	int	Span::shortestSpan(void)
	{
		return _shortest;
	}
