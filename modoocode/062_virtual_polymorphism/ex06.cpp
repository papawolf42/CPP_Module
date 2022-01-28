// dynamic_cast<>(), not compiled
#include <iostream>

class Base {
	std::string s;

	public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	virtual void what() { std::cout << s << std::endl; }
	// void what() { std::cout << s << std::endl; }
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

	Base* p_p = &p;
	Base* p_c = &c;
	
	std::cout << " === 기반 -> 기반 포인터 ===" << std::endl;
	p_p->what();

	std::cout << " === 파생 -> 기반 포인터 ===" << std::endl;
	p_c->what();

	return (0);
}
