# 이번 강좌

- 함수 기초적인거 사용해보기
- C++ reference 도입
- 레퍼런스 배열과 배열의 레퍼런스



# 복습해야할 내용

- 레퍼런스란?
- 변수나 상수를 가리키는 다른 방법(포인터와 비슷)
- 레퍼런스는 반드시 **처음에** 누구의 별명이 될 것인지 지정해야함
- 레퍼런스가 한 번 별명이 되면, 다른 이의 별명이 될 수 없음
- 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.
    - 그럼 존재하는 경우는?
- 함수의 인자로 받는 경우 int function(int &r)
- 일반적으로 상수 혹은 리터럴에 대한 참조자는 금지된다. 다만, 상수 참조자로 참조할 수 있습니다.

- 레퍼런스의 배열은 불가능하고, 배열의 레퍼런스는 가능하다.
- 레퍼런스를 인자로 받는 함수는 쉬운편이지만, 레퍼런스를 리턴하는 함수는 어려움
    - 지역변수를 참조자로 리턴하면 컴파일 에러
    - 하지만 외부변수를 레퍼런스로 받아 리턴하는 것은 가능
    - 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기 : 불가능, 메모리가 없음 댕글링 레퍼런 여기서도 const를 하면 됨. 값을 받는 것이기 때문
    - 즉 참조자는 참조값을 변경하려고 하는 메모리가 존재하는지가 중요????




```c++
//ex01.cpp

#include <iostream>

int	main()
{
	int a = 3;
	int& another_a = a;

	another_a = 5;
	std::cout << "a: " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

	return (0);
}

```

```shell
$ ./a.out 
a: 5
another_a : 5
```

- 포인터와 매우 흡사하게 동작함.
- 왜 주소연산자 변수에 붙이지 않고 타입에 붙였는지...
- 포인터와 마찬가지로 **변수나 상수를 가리키는 다른 방식이 바로 참조자(레퍼런스 - reference)**



- 참조자를 선언하는 방식

    - `int` -> `int&`
    - `double` -> `double&`
    - `int*` -> `int*&`
    - 포인터도 참조자 선언이 가능함
- 포인터와 상당히 유사한 개념이나 차이점이 존재

    - 레퍼런스는 처음에 반드시 누구의 별명이 될 것인지 지정해야함. | 포인터는 선언과 초기화를 따로 할 수 있음.
    - 레퍼런스는 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없음. | 포인터는 다른 주소값을 대입해서 다른 주소를 가리킬 수 있음.
    - 레퍼런스는 메모리 상에 존재하지 않을 수 있음.(could be)



# 함수 인자로 레퍼런스 받기

```c++
//c
#include <iostream>

int	change_val(int &p)
{
	p = 42;

	return (0);
}

int	main()
{
	int	number = 4;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}

```

- 레퍼런스는 포인터와 다르게 메모리를 점유할 수도, 안할 수도 있음.
- 함수 인자가 아닌 경우, 별칭으로 replace하면 그만
- 아까? 레퍼런스는 초기화 없이 선언만 하는건 불가능하다고? 하지만 함수를 호출하는 순간 대입되므로 가능.



# 여러가지 참조자 예시들

```c++
//ex03.cpp
#include <iostream>

int	main()
{
	int	x;
	int& y = x;
	int& z = y;

	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

```

```shell
./a.out
x : 1 y : 1 z : 1
x : 2 y : 2 z : 2
x : 3 y : 3 z : 3
```

- 여기 reference의 작동방식을 알 수 있음
- C++에서는 참조자의 참조자를 만드는 것은 금지됨
- 문법상 참조자의 참조자라면 `int&&`로 선언해야하는 것이 아닐까?



## Question - pointer가 있는데 굳이 참조자를 써야할까???

- scanf와 달리 cin은 주소연산자를 쓰지 않는다, 왜 그럴까??
    - cin이 reference이기 때문

- 개인적으로, 코드가 깔끔해지기 때문이 아닐까 싶음. 
    - pointer는 값을 대입할때마다 `*pa = a;`와 같은식으로 연산자를 붙여서 대입해야하는 단점이 존재.



# 상수에 대한 참조자

- 상수에 별칭을 매기는 행위는 불가? 오류자체가 뜬다
- 그래서 리퍼럴 자체를 const 옵션을 주면 선언이 가능함.



# 레퍼런스의 배열과 배열의 레퍼런스

- 레퍼런스의 배열을 만들어보자

```c++
#include <iostream>

int	main()
{
int	a, b;
int& arr[2] = {a, b};
}

```

```shell
cpp ex04.cpp 
ex04.cpp:6:10: error: 'arr' declared as array of references of type 'int &'
int& arr[2] = {a, b};
^
1 error generated.
```

- 배열은 사실 주소임, 하지만 레퍼런스는 주소값을 특별한 경우가 아니고서야 가지지 않음.

- `arr[i]`는 `*(arr + i)`로 처리되는데 `arr`가 주소가 아님.

- 이런 모순으로 언어 차원에서 금지됨

- 하지만 그 반대 배열들의 레퍼런스는 가능함.



```c++
//ex06.cpp
#include <iostream>

int	main()
{
	int	arr[3] = {1, 2, 3};
	int (&ref)[3] = arr;
	//int &ref[3] = arr; (x)

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return (0);
}

```

```shell
cpp ex05.cpp; ./a.out 
231
```

- 이때 선언이 굉장히 독특함
- `int (&ref)[3]` 가 아니라 `int &ref[3]`로 선언하면 래퍼런스의 배열을 선언했다고 에러를 띄움.
- 그럼 파싱단계를 고려하면 이렇게 처리되는 것임
- 차이는 이것임.
    - 그냥 선언하면(괄호 없이) 레퍼런스 배열이되고
    - 괄호를 씌우면 레퍼런스를 먼저 특정하고 배열을 만드니 이게 레퍼런스의 배열아냐???
- 괄호가 없으면 레퍼런스의 배열 -> 레퍼런스들이 모여있는 것
- 괄호가 있다면 배열의 레퍼런스 -> 배열의 별칭이 되는 것, 여기서 배열의 크기를 주어야하나?

```c++
// 배열의 레퍼런스에서 배열의 크기가 다른 경우
#include <iostream>

int	main()
{
	int	arr[3] = {1, 2, 3};
	int (&ref)[4] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return (0);
}

```

```shell
cpp ex05.cpp;
ex05.cpp:6:8: error: non-const lvalue reference to type 'int [4]' cannot bind to a value of unrelated type
      'int [3]'
        int (&ref)[4] = arr;
              ^         ~~~
1 error generated.
```

- 상수가 아닌 `lvalue`가 다르다고 뜬다.



- 다시 정리하면
- 레퍼런스의 배열은 불가능
- 괄호가 우선 해석함, 괄호가 없는 경우 배열부터 처리
- 컴파일러 입장에서는
    - 괄호가 없는 경우, 크기 3의 배열을 만드는데 type이 레퍼런스네?
    - 괄호가 있는 경우, 레퍼런스인데 크기3의 배열을 담으려고하네?





# 레퍼런스를 리턴하는 함수

```c++
//➜  020_reference git:(main) ✗ c++ ex06.cpp
ex06.cpp:6:10: warning: reference to stack memory associated with local variable 'a' returned
      [-Wreturn-stack-address]
        return (a);
                ^
1 warning generated.
//➜  020_reference git:(main) ✗ ./a.out 
2
3
```

```shell
c++ ex06.cpp 
ex06.cpp:6:10: warning: reference to stack memory associated with local variable 'a' returned
      [-Wreturn-stack-address]
        return (a);
```

- 지역변수 a 의 스택 메모리를 을 가리키는 레퍼런스, 에러코드는 `stack 주소 반환`
- 실행시키면 동작은 함.
- 문제는 리턴하는 순간 지역변수가 사라진다는 점.
- **원래 참조하던 레퍼런스가 사라지는 것을 댕글링 레퍼런스(Dangling reference)라고 함**



---

**Note!!!**

댕글링 레퍼런스가 생기지 않도록,

**지역변수의 레퍼런스를 리턴하지 않도록 조심해야함**

---



외부 변수의 레퍼런스를 리턴

```c++
//ex07
#include <iostream>

int& function(int& a)
{
	a = 42;
	return (a);
}

int	main()
{
	int	b = 2;
	int	c = function(b);
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	return (0);
}

```

```shell
➜  020_reference git:(main) ✗ ./a.out 
b :42
c :42
```

- 결과가 생각보다 어려웠음.
- 이건 되네
- 내부가 어떻게 처리되는지...
- 컴파일러가 어떻게 지역변수발 레퍼런스인지, 외부 변수인지 아는거지???



## 레퍼런스의 장점?

- C언어에서 큰 구조체를 인자로 넘기면 복사가 일어남
- 포인터를 리턴하면 주소 한번만 복사됨
- 레퍼런스로 주소값 복사로 전달이 끝남. 
- 이건 레퍼런스만의 장점은 아닌데...?



### 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기

```c++
#include <iostream>

int	function()
{
	return (42);
}

int	main()
{
	int& a = function();
	return (0);
}

```

```shell
➜  020_reference git:(main) ✗ c++ ex08.cpp 
ex08.cpp:10:7: error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
        int& a = function();
             ^   ~~~~~~~~~~
1 error generated.
```

- 해석, 비상수인 lvalue가 int 타입 변수를 가르키는 레퍼런스는 int타입의 임시적으로 묶을 수 없다??
- 대입하는 것은 bind이고, 비상수라서?
- **lvalue와 rvalue는 나중에 다룬다.**
- 함수의 리턴값은 가변적이니까, 참조할 수 없지. 그렇지 ㅇㅇ



- 하지만 상수 레퍼런스에 값을 받으면 리턴값을 받을 수 있음.



이 표를 다시 적을 수 있으면



|                    | 함수에서 값 리턴 int f()                                     | 함수에서 참조자 리턴 int& f()                                |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| int a = f()        | 값 복사가 일어남                                             | 아 레퍼런스를 리턴, 가능하나 지역변수만 피하면됨, 외부 지역변수면 가능. |
| int& a = f()       | 불가능, 지역 변수가 소멸되면서 레퍼런스로 가리킬 수 없음.<br />다만 리턴되는 변수가 외부 변수면 가능. | 위와 마찬가지로 레퍼런스가 지역변수면 안됨. 외부 변수 가능   |
| const int& a = f() | 상수로 가리키기 때문에 지역변수의 수명이 연장됨.             | 지역변수도됨. 지역변수 생명 연장. 하지만 값을 바꿀 순 없는듯??? |

- 틀렸넹
- 다틀렸넹...
- 컴파일 불가능, 지역변수 레퍼런스 리턴 주의 같은 정도의 차이가 존재.
- 다시 읽어보자



# 생각해보기

- 메모리 상에 반드시 존재해야할 이유가 있을까?
- 메모리 점유가 필요 없는 상황
    - 그저 문자열 replace만 하면 되는 상황. 인자나 리턴값으로 받지않고, 함수 내에서 별칭으로 쓰는 경우
- 메모리 점유가 필요한 상황
    - 인자로 넘기는 경우, 결국 레퍼런스지만 외부 변수의 주소를 가리켜야하므로?
    - 상수 참조자로 받는 경우, 점유할 수 밖에 없게됨. 별칭을 가리키는게 아니므로.



메모리에 존재하지 않아도 되는 경우
- 레퍼런스가 함수 내에서 별칭으로만 쓰이는 경우, 컴파일러 내부 동작은 모르지만, 별칭을 replace하는 방식으로만 구현한다면 실제 메모리에 변수를 만들 필요가 없을 것 같습니다.

메모리에 존재해야 하는 경우
- 인자로 넘기는 경우, 해당 함수에서 지역변수가 되어야하는데, 참조 대상의 주소값을 함수의 지역변수로 넘기는 일이 일어난다면, 메모리를 점유하지 않을까요
- 리턴값을 상수(const) 참조자로 받는 경우, 상수 참조자는 상수든 리터럴이든 가리키는 대상이 있었어야 할텐데 없으니, 함수 내의 변수나 리터럴의 주소값을 가지는식으로 메모리에 존재할 것 같습니다.





