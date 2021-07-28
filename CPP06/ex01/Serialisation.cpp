#include "Serialisation.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
	return i;
}

Data*			deserialize(uintptr_t raw)
{
	Data	*data = new Data;

	data = reinterpret_cast<Data *>(raw);
	return data;
}
