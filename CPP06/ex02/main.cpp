#include "Base.hpp"

int		main(void)
{
	Base *base = new Base;

	base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}