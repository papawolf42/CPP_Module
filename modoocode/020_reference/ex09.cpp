#include <iostream>

int	function()
{
	return (42);
}

int	main()
{
	const int& a = function();
	std::cout << a << std::endl;
	return (0);
}
