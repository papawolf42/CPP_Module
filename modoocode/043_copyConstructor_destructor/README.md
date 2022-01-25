# 복사생성자, 소멸자

- 복사 생성자`copy constructor` - 깊은 복사와 얕은 복사
- 소멸자`destructor`



- 생성자의 이득
    - 변수 초기화의 인간 오류를 줄임

- 함수 오버로딩의 이득
    - 인자 타입마다 함수를 따로 만들고, 함수명을 외워야 하는데 이를 제거



# 스타크래프트 만들기

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
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}
Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}
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

	std::cout << std::endl << "마린 1이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}

```

```shell
➜  043_copyConstructor_destructor git:(main) ✗ ./a.out 
 *** Marine *** 
 Location : ( 2 , 3 ) 
 HP : 50
 *** Marine *** 
 Location : ( 3 , 5 ) 
 HP : 50

마린 1이 마린 2 를 공격! 
 *** Marine *** 
 Location : ( 2 , 3 ) 
 HP : 50
 *** Marine *** 
 Location : ( 3 , 5 ) 
 HP : 45
```

- 마린이 늘어나면 어떻게 해야할까? 마린3, 마린4 하나씩 설정해두는 것은 불가능!
- 동적할당하자!



```c++
int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3);
	marines[1] = new Marine(3, 5);

	marines[0]->show_status();
	marines[1]->show_status();
	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}
```

- `new`와 `malloc`은 차이가 있을까?
- **<u>*다른점이 있는데, new는 생성자를 호출해줌.*</u>**



# 소멸자 `Destructor`

- 마린에 name 인스턴스 변수를 추가하자.

```c++
class Marine {
	int hp;					// 마린 체력
	int coord_x, coord_y;	// 마린 위치
	int damage;				// 공격력
	bool is_dead;
	char *name;
    
    public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char *marine_name);	//추가됨
};



Marine::Marine(int x, int y, const char *marine_name) {
	name = new char[strlen(marine_name) + 1];	//동적할당함
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}
```

- main에서 marine은 new를 한 다음 delete를 하는데, name은 delete를 언제해줄까?
- 안해줌, 메모리 누수가 발생함.
- <u>***생성자가 객체 생성시 자동으로 호출되는 것 처럼***</u>
- **<u>*소멸할때도 자동으로 호출되는 함수가 있다면 얼마나 좋을까????*</u>**



```c++
class Marine {
 public:
  Marine();                                       // 기본 생성자
  Marine(int x, int y, const char* marine_name);  // 이름까지 지정
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  ~Marine();
};

Marine::~Marine() {
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if (name != NULL) {
    delete[] name;
  }
}
```



- 소멸자는 인자를 가지지 않는다.
- 오버로딩도 되지 않는다



- 여기서는 `char` 배열로 `new`를 해주었기 때문에 `delete` 사이에 `[]`를 꼭 넣어주어야함



### 함수가 종료될 때, 자동으로 소멸자가 호출된다

```c++
// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
	char c;

	public:
	Test(char _c) {
		c = _c;
		std::cout << "생성자 호출 " << c << std::endl;
	}
	~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main() {
	Test a('a');
	simple_function();
}

```

```shell
➜  043_copyConstructor_destructor git:(main) ✗ cpp ex04.cpp 
➜  043_copyConstructor_destructor git:(main) ✗ ./a.out 
생성자 호출 a
생성자 호출 b
소멸자 호출 b
소멸자 호출 a
```

- 소멸자는 b부터 호출되는게 포인트

- 그러므로, 소멸자의 역할은 <u>***객체가 동적으로 할당받은 메모리를 해제하는 일***</u>
    - 추가적으로, 쓰레드 사이에서 `lock` 된 것을 푸는 역할도 있음.



# 복사생성자

- 포토 겹치기...?

```c++
#include <iostream>


class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	public:
		Photon_Cannon(int x, int y);
		Photon_Cannon(const Photon_Cannon& pc);

		void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출 !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc. coord_y;
	damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}
int main() {
	Photon_Cannon pc1(3, 3);
	Photon_Cannon pc2(pc1);
	Photon_Cannon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();
	pc3.show_status();
}

```

```shell
➜  043_copyConstructor_destructor git:(main) ✗ cpp ex05.cpp 
➜  043_copyConstructor_destructor git:(main) ✗ ./a.out 
생성자 호출 !
복사 생성자 호출 !
복사 생성자 호출 !
Photon Cannon 
 Location : ( 3 , 3 ) 
 HP : 100
Photon Cannon 
 Location : ( 3 , 3 ) 
 HP : 100
Photon Cannon 
 Location : ( 3 , 3 ) 
 HP : 100
```

- 어라 복사 생성자가 같네
- 복사 생성자 문법이 두개네...?



- 아래가 복사 생성자의 표준 정의

- ```c++
    Photon_Cannon(const Photon_Cannon& pc);
    ```

- 이름은 생성자인데, 인자로 자기 자신과 같은 인스턴스를 `const ref`로 받고 있음.

- 이를 규칙으로 쓰면

- ```c++
    T(const T& a);
    ```

- 여기서 인자를 const로 받기 때문에, 인자로 들어오는 객체의 값은 변경 불가!

- 그래서 변화시킬일이 없다면 꼭 const를 붙여줘야함

    - 미연의 실수를 방지할 수 있음.



- `pc 3 = pc2` 는 내부에서 `pc3(pc2)`로 변환해서 해석함
- 당연히 복사생성자가 호출됨.



그리고

- `Photon_cannon pc3 = pc2;`
    - 복사생성자가 호출된 것
- `Photon_Cannon pc 3;`
    `pc3 = pc2;`
    - 생성자가 호출 된 후, 대입 혹은 대입연산자를 호출
- 이 두가지 경우는 완전히 다름
- 복사생성자는 오직 '생성'시에만 호출됨.



- Default copy constructor가 존재함.
- 직관적으로 생각해 본다면, 디폴트 복사생성자는 모든 인스턴스 변수를 복제하는 기능을 가질 것.



# 디폴트 복사 생성자의 한계

- 인스턴스의 값을 복사하기 때문에, 포인터의 주소 마저 복사됨
- 이 주소를 소멸자가 free한다면, double free 문제가 생김.

```shell
➜  043_copyConstructor_destructor git:(main) ✗ cpp ex06.cpp
➜  043_copyConstructor_destructor git:(main) ✗ ./a.out 
Photon Cannon 
 Location : ( 3 , 3 ) 
 HP : 100
Photon Cannon 
 Location : ( 3 , 3 ) 
 HP : 100
a.out(70293,0x100c17d40) malloc: *** error for object 0x133e067b0: pointer being freed was not allocated
a.out(70293,0x100c17d40) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    70293 abort      ./a.out
```



- 포인터의 주소를 그대로 복사하는게 아니라
- 동적할당을 새롭게 해서 내용까지 복사하는 것을 깊은 복사`deep cpy` 라고 함
- 기존의 값만 대입해 주는 것을 얕은 복사`shallow copy` 라고 함



```c++
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출 !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc. coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}
```

- 깊은 복사는 언어단에서 지원하는건 아닌 것으로 보인다.
- 생성자에서 하던 동적할당을, 복사 생성자에 따로 다시 해주는 것으로 구현한다고 보면 될 듯.



