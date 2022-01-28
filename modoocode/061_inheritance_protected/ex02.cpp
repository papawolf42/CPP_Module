//protected
#include <iostream>

class Base {
	// std::string s;
	protected:// 현관문 비밀번호!
	std::string parent_string;

	public:
	// Base() : s("기반") {
	Base() : parent_string("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	// void what() { std::cout << s << std::endl; }
	void what() { std::cout << parent_string << std::endl; }
};

class Derived : public Base {
	// std::string s;
	std::string child_string;

	public:
	// Derived() : Base(), s("파생") {
	Derived() : Base(), child_string("파생") {
		std::cout << "파생 클래스" << std::endl;
		// what();
		parent_string = "바꾸기";
	}
};

int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return (0); 
}
