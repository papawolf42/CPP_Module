# const, static

- 생성자 초기화 리스트(initializer list)
- 클래스의 `const`, `static` 변수
- 레퍼런스 타입을 리턴하는 함수
- `this` 포인터
- `const` 멤버 함수



# 생성자의 초기화 리스트(initializer list)

```c++
#include <iostream>

class Marine {
	int hp;					// 마린 체력
	int coord_x, coord_y;	// 마린 위치
	int damage;				// 공격력
	bool is_dead;

	public:
	Marine();
	Marine(int x, int y);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
};
// Marine::Marine() {
// 	hp = 50;
// 	coord_x = coord_y = 0;
// 	damage = 5;
// 	is_dead = false;
// }
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

// Marine::Marine(int x, int y) {
// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// }
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();
}

```

```shell
➜  044_const_static git:(main) ✗ cpp ex01.cpp 
➜  044_const_static git:(main) ✗ ./a.out 
 *** Marine *** 
 Location : ( 2 , 3 ) 
 HP : 50
 *** Marine *** 
 Location : ( 3 , 5 ) 
 HP : 50
```

- 이전 강에서 썻던 marine의 variable이였던 name은 제거. 소멸자`deconstructor`도 제거

- 초기화 리스트를 써보았는데, 멤버 변수를 초기화하는 것은 같은데, 폼만 다르다고 할 수 있을 듯.

- 문법은 다음과 같음.

    ```c++
    (생성자 이름) : var1(arg1), var2(arg2) {}
    ```

- 차이가 있는데,
    - var1과 arg1의 이름이 같아도 된다!

	```c++
    Marine::Marine(int coord_x, int coord_y)
        : coord_x(coord_x), coord_y(coord_y), hp(50), damage(5), is_dead(false) {}
    ```



- **<u>*초기화자 리스트는 생성과 초기화를 동시에 하게됨*</u>**
- 초기화자 리스트를 사용하지 않으면, **<u>*생성 후 초기화*</u>**를 하게됨
- 초기화자 리스트를 사용하면
    - 작업상 조금 더 효율적이됨
    - 반드시 생성과 초기화가 동시에 되어야 하는, **<u>*레퍼런스와 상수*</u>**에 사용할 수 있음



# 생성된 총 'Marine' 수 세기 (static 변수)

- 마린의 수를 저장하려면, 변수를 두고 저장할 수 밖에 없음
- 전역변수를 쓰면 되지 않냐? (x)
    - 전역변수는 반드시 필요한 경우에만 써야함
- c++ 에서는 `static 멤버 변수`를 지원함
    - 전역변수 같지만, 클래스에만 종속되는 변수! 바로 `static 멤버 변수`
- 모든 클래스가 공유하는 변수!



- static은 자동으로 0으로 초기화됨

- 굳이 초기화 하고 싶다면 클래스 외부에서 초기화 해주어야 함.

- 클래스 내부에서도 당연히 private이기 때문에 초기화하지 못함.

- 하지만 const static으로 선언한다면 내부에서도 가능함.

- **외부에서 초기화 해줄때는 static이라는 명시를 해주지 않네?**

    ```c++
    class Marine {
        static int total_marine_num;
        static int total_marine_num = 0;		//(X) 내부에서 초기화 불가
        const static int total_marine_num = 0;	//(O) const라면 초기화 가능
    }
    int Marine::total_marine_num = 0;	//이런식으로 초기화 가능
    ```

    

# static 함수

- static 변수뿐 아니라 static 함수도 만들 수 있음.
- static 변수가 객체가 아닌 클래스에 단 1개 존재하고 공유하는 것 처럼
    - static 함수도 객체가 아닌 클래스에 존재하게 됨.
    - 다른 함수들은 객체를 선언하고 `Class::object.function();` 으로 호출하지만
    - static 함수는 멤버 없이도, `Class::function();` 으로 클래스 자체로 호출할 수 있음





# this

- ex05
- this는 C++ 언어상의 키워드
- 객체 자신을 가리키는 포인터 역할.



- 실제로 모든 멤버 함수 내에서는 `this 키워드`가 정의되어 있음.
- **<u>*이 키워드가 없는 함수는 static 함수 뿐*</u>**



# 레퍼런스를 리턴하는 함수

```c++
// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
	int x;

	public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	// int& e = a.get_x();
	// e = 2;
	// a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
}
```

```shell
➜  044_const_static git:(main) ✗ cpp ex06.cpp
➜  044_const_static git:(main) ✗ ./a.out 
5
4
4
4
```

- 래퍼런스를 리턴하는 경우, 아주 명확한 예제가 아닌가 싶음
- 함수는 2가지
    - 인트 레퍼런스 리턴
    - 인트 리턴
- 그리고 함수의 리턴값을 받는 인자도 총 2가지
    - 인트 레퍼런스
    - 인트

|          | int& func                   | int func                          |
| -------- | --------------------------- | --------------------------------- |
| int& var | (1) 리턴 가능, alias를 획득 | (2) 값만 대입. like 상수 레퍼런스 |
| int var  | (3) `ERROR`                 | (4) 값만 대입                     |

- 3번의 경우, 별명을 받아도, 리턴하는 변수가 소멸하기 때문에, 오류
- 정확히는 `int&`는 `lvalue` `int& func`은 `rvalue`이므로
- `c++11` 에서 추가된 이 `r-value reference(우측값 참조)` 기능을 알아보려면 [여기](https://modoocode.com/189)



# const 함수

- 뭐 이런 함수가 다있어...

```c++
class Marine {
	int attack();//기존 함수
	int attack() const;
};

//문법
(기존 함수 정의) const;
int Marine::attack const { return default_damage; }

```

- '상수 멤버 함수'로 정의한 것
- 명시적으로 '이 함수는 다른 변수의 값을 바꾸지 않는 함수'
- 상수 함수 내에서 호출 가능한 함수는 다른 상수 함수 뿐.



# 생각해보기

- 자 코드를 한번 보자.



```c++
#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

// 위는 integer x를 담는 class A

class B {// 여기서 부터 독특한데
  A a;// Class A 타입의 멤버 변수 a를 멤버 변수로 가짐.

 public:
  B(int c) : a(c) {}// 생성자가 굉장히 독특한데, B(A a)즉 클래스 A타입이 아니라, 정수 c를 받고 있음...?
  B(const B& b) : a(b.a) {}// 일반적인 복사 생성자
  A get_A() {// A를 가져오는 함수.
    A temp(a);
    return temp;
  }
};

int main() {
  B b(10);//와우 이게 동작한다고...?

  std::cout << "---------" << std::endl;
  A a1 = b.get_A();//A를 하나 만들면서 초기화...? 임시객체가 만들어져서 대입.
}
```



- 
