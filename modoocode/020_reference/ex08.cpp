#include <iostream>

int	function()
{
	return (42);
}

int	main()
{
	int& a = function();
	return (0);
}
