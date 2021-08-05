#include "span.hpp"

	Span::Span(void) : _size(0), _shortest(4294967295), _longest(0), _error(false)
	{
	}

	Span::Span(unsigned int N) : _size(N), _shortest(4294967295), _longest(0), _error(false)
	{
	}

	Span::Span(std::list<int>::iterator begin, std::list<int>::iterator end) : _shortest(4294967295), _longest(0), _error(false)
	{
		while (begin != end)
		{
			_storage.push_back(*begin);
			begin++;
		}
		_size = _storage.size();
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
		try 
		{
			if (_storage.size() == _size)
			{
				throw SpanError();
			}
			else
			{
				_storage.push_back(nb);
			}
		} 
		catch(const std::exception & e) 
		{
			std::cerr << e.what() << std::endl;
			_error = true;
		}
	}

	void	Span::addRange(std::list<int>::iterator begin, std::list<int>::iterator end)
	{
		while (begin != end)
		{
				addNumber(*begin);
				if (_error)
					break ;
				begin++;
		}
	}

	int	Span::longestSpan(void)
	{
		if (_storage.size() <= 1)
			throw SpanError();
		_storage.sort();
		if (static_cast<unsigned long>(_storage.back() - _storage.front()) > _longest)
		{
			_longest = (_storage.back()) - _storage.front();
		}
		return _longest;
	}

	int	Span::shortestSpan(void)
	{
		if (_storage.size() <= 1)
			throw SpanError();
		
		_storage.sort();

		std::list<int>::iterator begin = _storage.begin();
		std::list<int>::iterator next = _storage.begin();
		std::list<int>::iterator end = _storage.end();
	
		if (begin != end)
			next++;
		while (next != end)
		{
			if (static_cast<unsigned long>(*next - *begin) < _shortest)
				_shortest = *next - *begin;
			begin = next;
			next++;
		}
		return _shortest;
	}
