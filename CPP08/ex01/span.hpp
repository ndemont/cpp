#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span 
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & src);
		virtual ~Span(void);

		Span const & 	operator=(Span const & rhs);
	
		void			addNumber(unsigned int nb);
		unsigned int	size(void) const;

		Span const & shortestSpan(void);
		Span const & longestSpan(void);

		class SpanIsFullException {
			public:
        		SpanIsFullException(void) {};
       			virtual ~SpanIsFullException(void) throw() {};
       			virtual const char* what() const throw()
				{				
					return "This Span is already full.";
				}
		};

	private:
		unsigned int 	*_storage;
		unsigned int 	_size;
		unsigned int 	_stored;
};



#endif