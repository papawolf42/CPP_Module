// even reference work same!
#include <iostream>

class A {
	public:
	// virtual ~A() { std::cout << "Parent destructed !" << std::endl; }
	virtual void show() { std::cout << "I'm Parent !" << std::endl; }
};

class B : public A {
	public:
	// ~B() { std::cout << "Child destructed !" << std::endl; }
	void show() { std::cout << "I'm Child !" << std::endl; }
};

void test(A& a) { a.show(); }

int main() {
	A a;
	B b;
	test(a);
	test(b);

	return (0);
}
