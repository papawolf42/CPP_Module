#include <iostream>

int& function()
{
	int	a = 2;
	return (a);
}

int	main()
{
	int	b = function();
	std::cout << b << std::endl;
	b = 3;
	std::cout << b << std::endl;
	return (0);
}
