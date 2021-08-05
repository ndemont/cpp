#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template< typename T >
class	Array
{
	public:
		Array<T>(void) : _array(new T[1]), _size(0) 
		{
			_array[0] = 0;
		}
		Array<T>(unsigned int size) : _array(new T[size]), _size(size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = 0;
		}
		Array<T>(Array<T> const & src) : _array(new T[0])
		{
			*this = src;
		}
		virtual ~Array<T>(void)
		{
			delete [] _array;
		}

		class IndexOutsideArrayException : public std::exception
    	{
        	public:
            	IndexOutsideArrayException(void) {};
            	virtual ~IndexOutsideArrayException(void) throw() {};
            	virtual const char* what() const throw()
				{
					return "This index does not correspond to an element of the array";
				};
    	};

		Array<T> & operator=(Array<T> const & rhs)
		{
			delete [] _array;
			_array = new T[rhs.size()];
			T * rhsArray = rhs.getArray();
			for (unsigned int i = 0; i < rhs.size(); i++)
				_array[i] = rhsArray[i];
			_size = rhs.size();
			return *this;
		}

		T	& operator[](unsigned int idx)
		{
			try
			{
				if (idx >= this->size() || idx < 0)
					throw Array<T>::IndexOutsideArrayException();
				else 
					return _array[idx];
			}
			catch(const std::exception & e)
			{
				std::cerr << e.what() << std::endl;
			}
			return _array[this->size() -1];
		}
		

		unsigned int	size(void) const
		{
			return _size;
		}
		
		T	*getArray(void) const
		{
			return _array;
		}

	private:
		T 				*_array;
		unsigned int	_size;
};

#endif
