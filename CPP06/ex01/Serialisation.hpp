#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <cstdint>
# include <iostream>

typedef struct	s_Data
{
	void	*ptr;
}				Data;

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);

#endif