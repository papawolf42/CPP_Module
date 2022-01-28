// pure virtual function and abstract class
#include <iostream>

class Animal {
	public:
	Animal() {}
	~Animal() {}
	// virtual void speak() {}
	virtual void speak() = 0;
	// both form can work!
};

class Dog : public Animal {
	public:
	Dog() : Animal() {}
	void speak() { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
	public:
	Cat() : Animal() {}
	void speak() { std::cout << "야옹 야옹" << std::endl; }
};

int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	Animal test;

	dog->speak();
	cat->speak();
}
