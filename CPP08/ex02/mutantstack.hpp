#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <iterator>

template < typename T >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void) {};
		MutantStack<T>(MutantStack<T> const & src)
		{
			if (this != &src)
			*this = src;
		}
		~MutantStack<T>() {};

		MutantStack<T> const &	operator=(MutantStack<T> const & rhs)
		{
			_list = rhs._list;
			return *this;
		}

		void	push(T elem)
		{
			this->std::stack<T>::push(elem);
			_list.push_front(elem);
		}

		void	pop(void)
		{
			this->std::stack<T>::pop();
			_list.pop_front();
		}

		class iterator
		{
			public:
				iterator(void) {};
				iterator(typename std::list<T>::iterator it) 
				{
					_it = it;
				}
				iterator(iterator const & src)
				{
					_it = src._it;
				}
				~iterator(void) {};
				iterator const & operator=(iterator const & rhs)
				{
					_it = rhs._it;
					return *this;
				}
				iterator &	operator++(void)
				{
					_it++;
					return *this;
				}
				iterator	operator++(int)
				{
					++_it;
					return this;
				}
				iterator &	operator--(void)
				{
					_it--;
					return *this;
				}
				iterator	operator--(int)
				{
					--_it;
					return this;
				}
				T	operator*(void)
				{
					return *_it;
				}

				bool	operator!=(iterator const & rhs)
				{
					return (_it != rhs._it);
				}

			private:
				typename std::list<T>::iterator	_it;
		};

		iterator	begin(void)
		{
			return (iterator(_list.begin()));
		}

		iterator	end(void)
		{
			return (iterator(_list.end()));
		}
	

	private:
		std::list<T>	_list;
};

#endif