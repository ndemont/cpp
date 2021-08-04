
#include "Serialisation.hpp"

int		main(void)
{
	Data		*data1;
	Data		*data2;
	uintptr_t	i;
	float		f1 = 4.9384;
	float		*f2;

	data1 = new Data;
	data1->ptr = reinterpret_cast<void *>(&f1);
	i = serialize(data1);
	std::cout << "Initial adress of parameter: " << data1 << std::endl;
	std::cout << "Initial value of content:    " << f1 << std::endl;
	std::cout << std::endl;
	
	data2 = deserialize(i);
	f2 = reinterpret_cast<float *>(data2->ptr);
	std::cout << "Final adress of parameter:   " << data2 << std::endl;
	std::cout << "Final value of content:      " << *f2 << std::endl;
	
	delete data1;
	return 0;
}