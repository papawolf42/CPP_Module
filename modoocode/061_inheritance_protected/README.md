# 사원 관리 프로그램

- 프로그램의 목적
    - 회사 사원들의 월급을 계산
    - 한달에 총 얼마나 되는 돈을 월급으로 지출해야하는지 알려주는

- Manager를 추가했을 때, Employee와 엄청나게 비슷한
- 코드 몇줄만 다르지만 다시 선언해야하는 점을 굉장히 비효율적임을 보여줌
- **상속**의 필요성을 빌드업



# 상속(inheritance)

- 상속은 보통 부모-자식 클래스라고 이야기함
    - 하지만 C++에서는 여러명의 부모를 가질 수 있어, 
    - 기반-파생 클래스라고 부르는 게 낫다고 생각

```c++
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
	Derived() : Base(), s("파생") {
		std::cout << "파생 클래스" << std::endl;
		what();
	}
};
```

- `Derived`가 `Base`를 `Public` 형식으로 상속받겠다는 의미.
- public은 나주엥 다룸.

- 상속 뒤 아래와 같은 모습이 됨.

![이미지](https://modoocode.com/img/cpp/6.1.1.png)

- Derived 클래스는 Base 클래스의 what 함수를 호출할 수 있게됨.
- 초기화 리스트로 기반의 생성자를 먼저 호출
- 초기화 리스트로 명시하지 않으면, 디폴트 생성자가 호출됨.



```c++
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return (0); 
}
```

```shell
 === 기반 클래스 생성 ===
기반 클래스
 === 파생 클래스 생성 ===
기반 클래스
파생 클래스
기반
```

- 파생의 초기화 리스트에서 기반의 기본 생성자를 호출해서, 
    - 기반 > 파생 순으로 생성자가 호출됩니다
- what() 은 파생에는 존재하지 않는 함수인데, Base의 모든 정보를 상속받아 호출 가능



- 이번엔 기반뿐 아니라 파생에도 `what()` 함수가 정의되면 어떻게 될까?
- 이를 가리켜 ***<u>오버라이딩(overriding)</u>*** 이라고 합니다
    - 오버로딩(overloading)과 혼동할 수 있는데, 
    - 오버로딩은 같은 이름의 함수에 인자를 달리 정의 하는 것.
    - 오벌라이딩은 상속에서 파생 클래스의 함수를 재정의 하는 것.



# 새로운 친구 protected

```c++
//protected
#include <iostream>

class Base {
	// std::string s;
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
```

```shell
➜  061_inheritance_protected git:(main) ✗ c++ ex02.cpp 
ex02.cpp:26:3: error: 'parent_string' is a private member of 'Base'
                parent_string = "바꾸기";
                ^
ex02.cpp:6:14: note: implicitly declared private here
        std::string parent_string;
                    ^
1 error generated.
```

- 수정 내용은
    - 파생클래스에서 기반클래스의 private 맴버 변수에 접근하여 값을 대입하려고 함
- 하지만, 컴파일 오류로, Derived에서 Base의 private에 접근할 수 없다고 뜹니다.



- 하지만, 파생에서 접근을 해야하는 경우의 필요성도 있겠죠?!
- 그래서 private과 public 중간 정도의 접근지원자를 지원합니다
- 비유하면
    - private: (부모님 마저 모르는)자신만의 비밀번호
    - protected: 집 현관문 비밀번호 (가족들만 앎)
    - public: 집 주소 (가족 외에도 알 수 있음)
- protected로 바꾸 컴파일이 잘 됨



```c++
class Derived : public Base
```

- 이제 public의 비밀을 공개합니다
    - public, protected, private 모두 실제 상속받는 파생클래스에서의 작동에 영향을 줌.
    - public으로 상속되면, 기반 클래스의 접근 지시자?? 들에 영향 없이 그대로 동작.
        - 즉, 파생 클래스 입장에서
        - public은 그대로 public
        - protected는 그대로 protected
        - private은 그대로 private
    - `protected`로 상속되면, 파생 클래스 입장에서 public은 protected로 바뀌고 나머지는 그대로 유지됨
    - private으로 상속되면, 파생 클래스 입장에서 모든 접근 지시자들이 private이 됨.



```c++
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
```

```shell
➜  061_inheritance_protected git:(main) ✗ c++ ex03.cpp
ex03.cpp:32:15: error: cannot cast 'Derived' to its private base class 'Base'
        std::cout << c.parent_string << std::endl;
                     ^
ex03.cpp:14:17: note: declared private here
class Derived : private Base {
                ^~~~~~~~~~~~
ex03.cpp:32:17: error: 'parent_string' is a private member of 'Base'
        std::cout << c.parent_string << std::endl;
                       ^
ex03.cpp:14:17: note: constrained by private inheritance here
class Derived : private Base {
                ^~~~~~~~~~~~
ex03.cpp:6:14: note: member is declared here
        std::string parent_string;
                    ^
2 errors generated.
➜  061_inheritance_prot
```



