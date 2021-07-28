#include "Serialisation.hpp"

int		main(void)
{
	Data		data1;
	Data		*data2;
	uintptr_t	i;
	float		f1 = 4.9384;
	float		*f2;

	data1.ptr = reinterpret_cast<void *>(&f1);
	i = serialize(&data1);
	std::cout << i << std::endl;
	data2 = deserialize(i);
	f2 = reinterpret_cast<float *>(data2->ptr);
	std::cout << *f2 << std::endl;
	return 0;
}