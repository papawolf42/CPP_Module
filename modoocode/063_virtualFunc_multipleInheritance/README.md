- 이번 강좌에서는
    - virtual 소멸자 (가상 소멸자)
    - 가상 함수 테이블(virtual function table)
    - 다중 상속
    - 가상 상속



- virtual에 놀라셨습니까?
    - 동적 바인딩 이란 것!!!
    - 정리해보겠숩니다
        - Parent 클래스와 Child 클래스에 모두 f라는 가상함수가 정의되어 있고,
        - Child 클래스가 Parent 를 상속받는다고 해봅니다.
        - 그럼 다음 Parent 클래스 타입 포인터에 각각 하나씩 할당한뒤
        - 오버라이딩 한 Parent 클래스의 맴버 함수에 virtual을 붙이면
        - Parent 포인터 타입이지만, Child의 맴버함수를 호출할 수 있습니다!
        - 이게 가능한 이유는 f를 가상함수로 만들었기 때문!!!



# virtual 소멸자

- 클래스를 상속할때 중요하게 처리해야하는 부분. 
    - **<u>*상속 시에 소멸자를 가상함수로 만들어야함!!!*</u>**

```c++
#include <iostream>

class Parent {
	public:
	Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
	~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};

class Child : public Parent {
	public:
	Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
	~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main() {
	std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
	{ Child c; }
	std::cout << "--- Parent 포인터로 Child 만들었을 때 ---" << std::endl;
	{
		Parent *p = new Child();
		delete p;
	}
}
```

```shell
➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex00.cpp 
➜  063_virtualFunc_multipleInheritance git:(main) ✗ ./a.out 
--- 평범한 Child 만들었을 때 ---
Parent 생성자 호출
Child 생성자 호출
Child 소멸자 호출
Parent 소멸자 호출
--- Parent 포인터로 Child 만들었을 때 ---
Parent 생성자 호출
Child 생성자 호출
Parent 소멸자 호출
```

- 평범한 친구는 생성2번 소멸 2번 자연스럽게 일어남
    - 이는 집을 짓고 철거하는 비유로 설명 가능
- 반면, 포인터로 동적할당할때가 문제
    - <u>Child 소멸자를 호출하지 않음!</u>
    - 만약에 Child 클래스 내에서 동적할당이 일어나고, 소멸자가 호출되지 않는다면, 메모리 누수(leak) 발생
- 소멸자에 virtual을 써준다면, 소멸자를 성공적으로 호출



## 다시 정리해보자

- virtual은 상속을 구현하다가 고안되었음
- virtual은 2가지 곳에 사용된다
    - **상속된 객체가 업-케스팅 되었을 경우, 기반 클래스의 메쏘드를 오버라이딩 하기 위해**
    - **마찬가지로 업-케스팅된 객체가 소멸할 때, 파생 클래스의 소멸자를 호출하지 않는데, 이를 방지함.**
- 이렇게 컴파일시가 아닌 런타임시에 정해지는 일을 가리켜 **<u>*동적 바인딩(dynamic binding)*</u>**이라고 함.
- 하나의 메소드를 호출했음에도 여러가지 다른 작업들을 할 수 있는 것을 **<u>*다형성(polymorphism)*</u>**이라고 함.



# 레퍼런스도 된다

```c++
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
```

```shell
➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex01.cpp; ./a.out 
I'm Parent !
I'm Parent !
➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex01.cpp; ./a.out 
I'm Parent !
I'm Child !
```

- 아까는 포인터에 받아서 했고, 이번엔 기반 클래스로 레퍼런스로 지역변수 초기화했을때의 상황에도 똑같이 적용된다.



# 가상 함수의 구현 원리

- **그럼 모든 함수를 virtual로 만들면 되지 않는가???**
    - 사실상 문제될 것이 없음. <u>*(이거랑 비슷한 생각이, private과 protected도 이런 질문을 던져봤었음)*</u>
    - 가상 함수 어감이 그런데, `virtual` 키워드를 붙여도 실존하는 함수임
- 실제로 자바의 경우 모든 함수가 virtual 함수로 선언됨
- 그렇다면 왜 C++은 사용자가 직접 선언하게 만들었을까? **<u>*오버헤드(overhead)*</u>**가 존재하기 때문



- C++ 컴파일러는 virtual이 붙은 함수 즉 가상함수가 단 하나라도 존재한다면
    - 가상 함수 테이블(virtual function table; vtable)을 만들게 됨.
    - 전화번호부 라고 생각해도 좋음.

```c++
class Parent {
 public:
  virtual void func1();
  virtual void func2();
};
class Child : public Parent {
 public:
  virtual void func1();
  void func3();
};
```

- Parent와 Child 맴버함수 모두 virtual이 붙어있음.



![img](https://modoocode.com/img/2113164253DB01CF09ACCF.webp)

- 위와 같이 구성됨.
- `func3`는 가상함수가 아니라 직접 실행됨
- 하지만 가상함수를 호출하면, 가상 함수 테이블을 걸쳐 **<u>*어떤 함수를 고를지*</u>** 결정하게됨.

```c++
Parent* p = Parent();
p->func1();
```

1. p가 Parent를 가리키는 포인터니까 func1을 Parent에서 찾아보자.
2. func1이 가상함수네? 그럼 바로 실행하지 말고, 가상 함수 테이블에서 func1에 해당하는 함수를 실행해야겠음



```c++
Parent* c = Child();
c->func1();
```

- 업 케스팅된 경우
- func1을 호출하면 p가 실제로는 Child 객체를 가리키고 있어, 



# 순수 가상 함수(pure virtual function)와 추상 클래스(abstract class)

```c++

#include <iostream>

class Animal {
	public:
	Animal() {}
	~Animal() {}
	virtual void speak() = 0;
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

	dog->speak();
	cat->speak();
}
```

```shell
➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex02.cpp
➜  063_virtualFunc_multipleInheritance git:(main) ✗ ./a.out 
왈왈
야옹 야옹
```

- Animal의 speak는 몸통이 정의되어있지 않ㅇ므

- `=0;` 이라고 처리되어있는 가상함수

    - (추가) 심지어 =0; 을 빼면 컴파일이 안됨

    - ```shell
        ➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex02.cpp
        Undefined symbols for architecture arm64:
          "typeinfo for Animal", referenced from:
              typeinfo for Dog in ex02-e2f70c.o
              typeinfo for Cat in ex02-e2f70c.o
          "vtable for Animal", referenced from:
              Animal::Animal() in ex02-e2f70c.o
          NOTE: a missing vtable usually means the first non-inline virtual member function has no definition.
        ld: symbol(s) not found for architecture arm64
        clang: error: linker command failed with exit code 1 (use -v to see invocation)
        ```

- 이를 **순수 가상 함수(pure virtual function)**이라고 하고

- 본체에서 이를 호출하는 것은 불가능. 즉 Animal은 speak 불가

    - C++에서는 호출을 막기보다는, Animal 객체, 즉 인스턴스의 생성을 막는식으로 동작함.

    - ```shell
        error C2259: 'Animal' : cannot instantiate abstract class
        1>          due to following members:
        1>          'void Animal::speak(void)' : is abstract
        ```

        ```shell
        ➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex02.cpp; ./a.out
        ex02.cpp:28:9: error: variable type 'Animal' is an abstract class
                Animal test;
                       ^
        ex02.cpp:9:15: note: unimplemented pure virtual method 'speak' in 'Animal'
                virtual void speak() = 0;
                             ^
        ```

- **즉 순수 가상 함수를 하나라도 포함하는 클래스는 객체를 생성할 수 없음**

- 이 클래스를 상속 받는 클래스를 만들어 모든 순수 가상함수를 오버라이딩 해주어야만 하는데



- *<u>**이런 순수 가상 함수를 최소 하개 포함하고 있는,**</u>*
- *<u>**동시에 반드시 상속되어야 하는 클래스를**</u>*
- *<u>**추상 클래스(abstract class)라고 부름.**</u>*



- 그럼 인스턴스로 생성 못하는 추상 클래스는 왜 쓰는 걸까요?
- 오직 상속만 받아서 사용할 수 있기 때문에, **<u>*설계도*</u>** 라고 생각하면 좋습니다.



- 추상 클래스의 또 한가지 특징은,
- 비록 객체는 생성 불가능하지만
- 추상 클래스를 가리키는 포인터는 문제없이 만들 수 있습니다. `like Animal*`



# 다중 상속(multiple inheritance)

한 클래스에 여러개의 클래스를 상속받는 것을 다중 상속이라고 합니다.

```c++
class A {
 public:
  int a;
};

class B {
 public:
  int b;
};

class C : public A, public B {
 public:
  int c;
};
```

![img](https://modoocode.com/img/274F493853DD288E298103.webp)

```c++
class C : public A, public B
A 생성자 호출
B 생성자 호출
C 생성자 호출
    
class C : public B, public A
B 생성자 호출
A 생성자 호출
C 생성자 호출
```

- 생성자 호출 순서는 상속 순서



# 다중 상속 시 주의할 점

```c++
class A {
 public:
  int a;
};

class B {
 public:
  int a;
};

class C : public B, public A {
 public:
  int c;
};

int main() {
	C c;
	c.a = 3;
}
```

```shell
➜  063_virtualFunc_multipleInheritance git:(main) ✗ c++ ex04.cpp 
ex04.cpp:18:4: error: member 'a' found in multiple base classes of different types
        c.a = 3;
          ^
ex04.cpp:8:7: note: member found by ambiguous name lookup
  int a;
      ^
ex04.cpp:3:7: note: member found by ambiguous name lookup
  int a;
      ^
1 error generated.
```

- 기반과 파생 클래스 모두 같은 이름의 맴버를 가지고 있다면 에러가 남



- 또 다중 상속시 조심해야 하는 것, **<u>*다이아몬드 상속(diamon inheritance)*</u>**

```c++
class Human {
  // ...
};
class HandsomeHuman : public Human {
  // ...
};
class SmartHuman : public Human {
  // ...
};
class Me : public HandsomeHuman, public SmartHuman {
  // ...
};
```

![img](https://modoocode.com/img/27033F4653DD3A87338E99.webp)

- 상속 되는 두개의 클래스가 공통의 Base 클래스를 포함하고 있는 형태를 다이아몬드 상속이라고 함
- Human에 name 멤버 변수가 있다면
    - HandsomeHuman, smartHuman 모두 name이라는 변수를 가짐
    - Me는 2개의 클래스를 상속 받으니 결국 name이 겹치는 문제가 발생!
- 이를 해결할 수 있는 방법

```c++
class Human {
 public:
  // ...
};
class HandsomeHuman : public virtual Human {
  // ...
};
class SmartHuman : public virtual Human {
  // ...
};
class Me : public HandsomeHuman, public SmartHuman {
  // ...
};
```

- 이런식으로 상속을 가상으로 받는 것! 가상 상속!
- virtual로 받으면 컴파일러가 Human을 한번만 상속받음.



# 다중 상속은 언제 사용해야 할까?

- [c++ 공식 웹사이트 FAQ](https://isocpp.org/wiki/faq/multiple-inheritance#virtual-inheritance-where)에서는 그 가이드라인을 제시함
    - 절대적이지는 않음



- 차량(Vehicle)을 만든다고 해봅시다.

    - 땅에서 다니는 차
    - 물에서 다니는 차
    - 하늘에서 다니는 차
    - 우주에서 다니는 차

    - 정확히는 운송수단이라고 해석하는게 좋겠네요

- 이들의 동력원은

    - 휘발유
    - 풍력
    - 원자력
    - 페달

- 여러가지가 될 수 있을 겁니다

- 그럼 다중상속을 활용하기 전에 이런 질문을 해봅시다



- 질문
    - attribute에 따라 클래스를 만드는데
    - 브릿지 패턴, 중첩된 일반화, 다중 상속을 소개한다.
    - 아무래도 다중상속이 가장 편해보인다...