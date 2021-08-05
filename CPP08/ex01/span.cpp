#include "span.hpp"

	Span::Span(void) : _storage(new unsigned int[0]) , _size(0), _stored(0)
	{
		std::cout << "Default Span constructor called" << std::endl;
	}

	Span::Span(unsigned int N) : _storage(new unsigned int[N]), _size(N), _stored(0)
	{
		std::cout << "Span constructor called for " << N << " elements" << std::endl;
	}

	Span::Span(Span const & src)
	{
		if (this != &src)
			*this = src;
	}
		
	Span::~Span(void)
	{
		delete [] _storage;
		std::cout << "Span destructor called" << std::endl;
	}

	Span const & Span::operator=(Span const & rhs)
	{
		delete [] _storage;

		_storage = new unsigned int[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); i++)
			_storage[i] = rhs._storage[i];
		
		return *this;
	}

	void	Span::addNumber(unsigned int nb)
	{
		try {
			if (_stored > _size)
				throw SpanIsFullException();
			else {
				_storage[_stored] = nb;
				_stored++;
			}
		} catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	unsigned int	Span::size(void) const
	{
		return _size;
	}

	Span const & Span::longestSpan(void)
	{
		return *this;
	}

	Span const & Span::shortestSpan(void)
	{
		return *this;
	}
