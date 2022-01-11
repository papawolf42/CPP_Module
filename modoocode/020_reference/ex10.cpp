#include <iostream>
#include <stdio.h>

int function()
{
	int	b;
	// int &a = b;

	b = 3;
	printf("%p\n", &b);
	// printf("%p\n", &a);
	return (b);
}

int main()
{
	const int& a = function();
	std::cout << a << std::endl;
	printf("%p\n", &a);
	return (0);
}
