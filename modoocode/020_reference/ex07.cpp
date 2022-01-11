#include <iostream>

int& function(int& a)
{
	a = 42;
	return (a);
}

int	main()
{
	int	b = 2;
	int	c = function(b);
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	return (0);
}
