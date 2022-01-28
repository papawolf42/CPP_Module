// which access keyword inherited
#include <iostream>

class Base {
	public:
	std::string parent_string;
	Base() : parent_string("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	void what() { std::cout << parent_string << std::endl; }
};

// class Derived : public Base {
class Derived : private Base {
	std::string child_string;

	public:
	Derived() : Base(), child_string("파생") {
		std::cout << "파생 클래스" << std::endl;

		parent_string = "바꾸기";
	}
};

int main() {
	// std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;
	// parent_string이 public 이므로
	// 외부에서 접근이 가능함!
	std::cout << p.parent_string << std::endl;

	// std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;
	// 반면에 Derived에서는
	// Base를 private로 상속 받았기 때문에
	// private이 되어서 외부에서 접근이 불가능하다...
	std::cout << c.parent_string << std::endl;

	return (0); 
}
