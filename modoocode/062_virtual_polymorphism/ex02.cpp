// try down-casting, cannot be compiled
#include <iostream>

class Base {
	std::string s;

	public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

	public:
	Derived() : Base(), s("파생") { std::cout << "파생 클래스" << std::endl; }
	void what() { std::cout << s << std::endl; }
};

int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 ===" << std::endl;
	Derived* p_p = &p;
	p_p->what();

	return (0); 
}
