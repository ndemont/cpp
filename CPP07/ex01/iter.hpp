#ifndef ITER_HPP
# define ITER_HPP

template < typename T >
void	iter(T *array, int length, T (*f)(T))
{
	for (int i = 0; i < length; i++)
	{
		array[i] = f(array[i]);
	}
}

#endif