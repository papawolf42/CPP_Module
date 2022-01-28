# 가상(virtual) 함수와 다형성

이번 강좌에서는

1. is-a 와 has-a 관계
2. 오버라이딩(overriding)
3. virtual 키워드와 가상함수(virtual function)
4. 다형성(polymorphism)

에 대해서 배움



# is '-a'와 'has-a'

- 상속이 왜 필요할까요?

    - C++에서는 단순히 코드 중복을 막기 위해
    - ctrl+c, ctrl+v 방지용이 아닙니다!(이런 이유도 조금은 있습니다!)
    - ***<u>실제 이유는, 상속을 통해 객체지향 프로그래밍에서 추구하는 객체의 추상화를 좀 더 효과적으로 가능하게 하기 때문</u>***

- 무슨말이냐

    - C에서는 구조체 사이 관계를 표현할 수 없었음
    - C++에서는 상속을 도입, 클래스 사이 관계 표현 가능

- like `class Manager : public Employee`

    - 이것의 의미는
    - `Manager` 클래스는 `Employee` 의 모든 기능을 포함한다.
    - Manager 클래스는 Employee 의 기능을 모두 수행 가능, 고로 Manager를 Employee라고 말해도 무방
    - 즉, 모든 Manager는 Employee 이다.
    - **Manager is a Employee!!**

- 따라서, 모든 상속 관계는 is a 관계라고 볼 수 있음, 단 역은 성립하지 않음. *<u>Employee 는 Manager(x)</u>*

    ![img](https://modoocode.com/img/223ADD465337C5D02236C5.webp)

- 이런 클래스간 상속 관계를 도표로 나타내는 경우가 많은데

    - 이때 파생 클래스가 기반 클래스를 화살표로 가리키게 됨.

- 실제 `is a` 관계가 엄청 많음. 

    - 사람 클래스를 만들면
    - `프로그래머는 사람이다` 이므로
    - 프로그래머 클래스는 사람 클래스를 상속 받을 수 있도록 구성 가능합니다.

![img](https://modoocode.com/img/254A344D5337C6D52329FF.webp)

- 위는 또다른 `is a` 관계
- `은행계좌(BankAccount)`가 있고, `자유입출금계좌(CheckingAccount)`와 `적금계좌(SavingsAccount)`가 이를 상속
- 은행계좌는 두계좌에 비해 좀 더 ***<u>'일반적인'</u>*** 계좌
- 그리고 파생 클래스일수록 좀 더 **<u>*특수화(구체화; specialize)*</u>** 됨
- 그리고 기반 클래스로 올라갈 수록 좀 더 **<u>*일반화(generalize)*</u>** 된다고 말함



- 모든 클래스를 `is-a` 관계로만 표현할 수 있을까요? ***<u>No</u>***
- has-a 관계를 가지기도 합니다.
- 자동차 클래스를 생각해봅시다
    - 엔진 클래스, 브레이크 클래스, 오디오 클래스 등
    - 자동차는 엔진이다. 엔진은 자동차이다. 모두 성립할 수 없음
    - 자동차가 엔진을 가진다(O)
- EmployeeList를 생각해보면 Employee를 포함하므로 `has-a`관계



# (다시 보는) 오버라이딩

```c++
//overriding
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
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;
	p.what();

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;
	c.what();

	return (0); 
}

```

```shell
➜  062_virtual_polymorphism git:(main) ✗ c++ ex00.cpp 
➜  062_virtual_polymorphism git:(main) ✗ ./a.out 
 === 기반 클래스 생성 ===
기반 클래스
기반
 === 파생 클래스 생성 ===
기반 클래스
파생 클래스
파생
```

- 오버라이딩을 통해, 파생클래스에서는 파생 클래스의 오버라이딩된 what이 실행됨을 알 수 있음

---



```c++
int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 ===" << std::endl;
	Base* p_c = &c;
	p_c->what();

	return (0); 
}
```

```shell
➜  062_virtual_polymorphism git:(main) ✗ c++ ex01.cpp 
➜  062_virtual_polymorphism git:(main) ✗ ./a.out 
기반 클래스
기반 클래스
파생 클래스
 === 포인터 버전 ===
기반
```

- 파생 클래스의 객체를 기반 클래스의 포인터에 대입함
- 상속받는다면, **<u>*Derived is Base*</u>**임!
- <u>*Derived 객체도 Base 객체이기 때문에, Base 객체가 가리키는 포인터로 가리켜도 무방!*</u>

![img](https://modoocode.com/img/cpp/6.2.1.png)

- 이런 형태의 캐스팅을 (파생클래스에서 기반클래스로 캐스팅 하는 것)을 <u>***업캐스팅***</u>이라고 합니다.
- 그럼 그 반대인 다운 케스팅도 있을까???

```c++
int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 ===" << std::endl;
	Derived* p_p = &p;
	p_p->what();

	return (0); 
}
```

```shell
➜  062_virtual_polymorphism git:(main) ✗ cpp ex02.cpp 
ex02.cpp:27:11: error: cannot initialize a variable of type 'Derived *' with an rvalue of type 'Base *'
        Derived* p_p = &p;
                 ^     ~~
1 error generated.
```

- 다운 케스팅은 없습니다(뒤에서 다루겠지만, 실제로 강제하는 방법이 있음)
- 실제로 이렇게 동작하기 때문

![img](https://modoocode.com/img/cpp/6.2.3.png)

- Base 포인터에는 Derived에 대한 정보가 없기 때문에, 컴파일러 차원에서 다운 캐스팅을 막고 있음

---



```c++
int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 ===" << std::endl;
	Base* p_p = &c;

	Derived* p_c = static_cast<Derived*>(p_p);
	p_p->what();

	return (0); 
}

```

```shell
➜  062_virtual_polymorphism git:(main) ✗ cpp ex03.cpp
➜  062_virtual_polymorphism git:(main) ✗ ./a.out 
기반 클래스
기반 클래스
파생 클래스
 === 포인터 버전 ===
기반
```

- `static_cat<T*>()` 강제적으로 다운케스팅 하면 런타임오류가 발생할 수 있어, 사용하지 않는 것을 추천.
- runtime 에러가 뜬다고 하는데, Mac에서는 강제 다운 케스팅이 이상 없이 동작함.



# dynamic_cast

- 이러한 케스팅일 미연에 방지하기 위해
- 상속관계간의 포인터를 캐스팅해주는 `dynamic_cast` 지원
- 사용법은 `static_cast`와 거의 동일

```c++
int main() {
	Base p;
	Derived c;

	std::cout << " === 포인터 버전 ===" << std::endl;
	Base* p_p = &c;
	p_p->what();

	Derived* p_c = dynamic_cast<Derived*>(p_p);
	p_c->what();

	return (0); 
}
```

```shell
#local mac
➜  062_virtual_polymorphism git:(main) ✗ cp ex03.cpp ex04.cpp
➜  062_virtual_polymorphism git:(main) ✗ c++ ex04.cpp 
ex04.cpp:30:17: error: 'Base' is not polymorphic
        Derived* p_c = dynamic_cast<Derived*>(p_p);
                       ^                      ~~~
1 error generated.
```

```shell
#maybe window
test.cc: In function 'int main()':
test.cc:27:44: error: cannot dynamic_cast 'p_p' (of type 'class Base*') to type 'class Derived*' (source type is not polymorphic)
   Derived* p_c = dynamic_cast<Derived*>(p_p);
```

- 캐스팅 할 수 없다고 뜸
    - mac에서는, Base가 polymorphic(다형성)이 아니다!
    - window에서는 Base에서 Derive로 동적 케스팅은 불가(소스 타입 즉, Base가 polymorphic이 아님)라고 표시



# EmployeeList 다시보기

- 업케스팅은 별다른 제약이 없지만, 그렇게 되면 파생클래스의 맴버들에 접근이 불가능해짐.
- 즉, 기반 클래스로만 모두 설정할 수 있는 장점을 가지지만, 기반클래스의 맴버들만 사용할 수 있다는 단점이 존재.

```c++
//ex00
#include <iostream>

class Employee {
	protected:
	std::string name;
	int age;

	std::string position;
	int rank;

	public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}
	
	
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee() {}
	void print_info() {
		std::cout << name << " (" << position << ", "
			<< age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
	protected:
	int year_of_service;

	public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: Employee(name, age, position, rank), year_of_service(year_of_service) {}
	Manager(const Manager& manager)
		: Employee(manager.name, manager.age, manager.position, manager.rank) {
			year_of_service = manager.year_of_service;
		}
	Manager() : Employee() {}
	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ", "
			<< year_of_service << "년차) ==> " << calculate_pay() << "만원"
			<< std::endl;
	}
};

class EmployeeList {
	int alloc_employee;

	int current_employee;

	Employee** employee_list;

	public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee*[alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {// 여기가 up-casting이 일어난다.
		employee_list[current_employee] = employee;
		current_employee++;
	}
	int current_employee_num() { return current_employee; }
	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 비용: " << total_pay << "만원 " << std::endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};

int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	// emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	// emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
	// emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return (0);
}
```

```shell
➜  062_virtual_polymorphism git:(main) ✗ ./a.out 
노홍철 (평사원, 34) ==> 250만원
하하 (평사원, 34) ==> 250만원
유재석 (부장, 41) ==> 550만원
정준하 (과장, 43) ==> 400만원
박명수 (차장, 43) ==> 450만원
정형돈 (대리, 36) ==> 300만원
길 (인턴, 36) ==> 100만원
총 비용: 2300만원 
➜  062_virtual_polymorphism git:(main) ✗ ./../061_inheritance_protected/a.out 
노홍철 (평사원, 34) ==> 250만원
하하 (평사원, 34) ==> 250만원
정형돈 (대리, 36) ==> 300만원
길 (인턴, 36) ==> 100만원
유재석 (부장 , 41, 12년차) ==> 610만원
정준하 (과장 , 43, 15년차) ==> 475만원
박명수 (차장 , 43, 13년차) ==> 515만원
총 비용: 2500만원 
```

- 음 up-casting을 이용하면
- Manager들도 일반적인 employee의 함수들이 사용되면서, 결과가 달라짐



- 하지만 이걸 단 5초만에 해결할 수 있다???



# virtual 키워드


```c++
class Base {
	std::string s;

	public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	// virtual void what() { std::cout << s << std::endl; }
	void what() { std::cout << s << std::endl; }
};
```

```shell
➜  062_virtual_polymorphism git:(main) ✗ c++ ex06.cpp; ./a.out
기반 클래스
기반 클래스
파생 클래스
 === 기반 -> 기반 포인터 ===
기반
 === 파생 -> 기반 포인터 ===
기반
```

```c++
class Base {
	std::string s;

	public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}
	virtual void what() { std::cout << s << std::endl; }
	// void what() { std::cout << s << std::endl; }
};
```

```shell
➜  062_virtual_polymorphism git:(main) ✗ c++ ex06.cpp; ./a.out
기반 클래스
기반 클래스
파생 클래스
 === 기반 -> 기반 포인터 ===
기반
 === 파생 -> 기반 포인터 ===
파생
```
```c++
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
```
- 정리를 해보자
    - 파생 객체 c를 기반 클래스 타입에 업케스팅해서 담았다.
    - 그렇게되면 이 포인터는 파생을 가리키고 있지만 기반으로 동작함.
    - 그런데 기반 클래스 맴버함수를 virtual을 썻더니, 
    - 기반 클래스로 업케스팅된 파생클래스를 가리키는 기반 클래스 타입 포인터가, 파생 클래스의 맴버 함수를 호출했다
- `(런타임)`에서 컴퓨터는 다음과 같이 동작함
    - `p_c->what();`
        - p_c는 Base 포인터네 Base의 what을 실행해야지?
        - 어 virtual이네?
        - 잠깐 Base의 객체 맞어? Derived 객체네
        - 그럼 Derived what을 실행해야지
- **<u>*핵심은 런타임에서 이 과정이 일어난다!!!*</u>**
- 컴파일시 정해지지않고, 런타임시 이렇게 정해지는 일을 **<u>*동적 바인딩(dynamic binding)*</u>**이라고 한다.
- 그리고 virtual 키워드를 붙인 함수를 **<u>*가상 함수(virtual function)*</u>**라고 한다.



# override 키워드

CPP 과제에서 사용하지 않으므로 생략



# 그렇다면 Employee 문제를 어떻게 해결할까

- 정리하겠습니다
    - 하나의 메소드를 호출했음에도 불구하고
    - 여러가지 다른 작업들을 하는 것이 바로 다형성(polymorphism)이라고 합니다!
- virtual 키워드를 처음 접했더라도 여러번 테스트 프로그램을 만들어 확실히 이해세요!
