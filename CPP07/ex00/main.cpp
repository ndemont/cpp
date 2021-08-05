#include "whatever.hpp"

int		main(void)
{
	int		i1 = 23;
	int		i2 = 51;
	float	f1 = 7478.13;
	float	f2 = 7478.12;
	char	c1 = 'z';
	char	c2 = 'o';

	std::cout << "Max of " << i1 << " and " << i2 << ": " << max<int>(i1, i2) << std::endl;
	std::cout << "Min of " << f1 << " and " << f2 << ": " << min<float>(f1, f2) << std::endl;
	std::cout << "Value of c1 is " << c1 << std::endl;
	std::cout << "Value of c2 is " << c2 << std::endl;
	swap<char>(c1,c2);
	std::cout << "New value of c1 is " << c1 << std::endl;
	std::cout << "New value of c2 is " << c2 << std::endl << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return (0);
}