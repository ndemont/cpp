#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>

# define MAX_INT_SPAN 4294967295

class Span 
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(std::list<int>::iterator begin, std::list<int>::iterator end);
		Span(Span const & src);
		virtual ~Span(void);

		Span const & 	operator=(Span const & rhs);
	
		void		addNumber(int nb);
		void		addRange(std::list<int>::iterator begin, std::list<int>::iterator end);


		int	shortestSpan(void);
		int	longestSpan(void);

		class SpanError: public std::exception{
			public:
				SpanError(void) {};
				virtual ~SpanError(void) throw() {};
				virtual const char* what() const throw()
				{				
					return "Span error.";
				}
		};

	private:
		std::list<int>	_storage;
		unsigned long 	_shortest;
		unsigned long 	_longest;
		unsigned int 	_size;
		bool			_error;
};



#endif