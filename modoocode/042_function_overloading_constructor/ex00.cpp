#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main()
{
	int i = 42;
	char c = '*';
	double f = 4.2f;

	print(i);
	print(c);
	print(f);

	return (0);
}
