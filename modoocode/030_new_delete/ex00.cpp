#include <iostream>

int	main()
{
	int* p = new int;
	*p = 42;

	std::cout << *p << std::endl;

	delete p;
	return (0);
}
