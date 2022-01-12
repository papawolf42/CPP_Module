# 함수의 오버로딩(Overloading)

- 객체 지향 프로그래밍에 앞서
- C++과 C와는 다른 새로운 기능을 잠시 살펴보자
- 바로 **함수의 오버로딩**
- 사전에서 찾으면
    - 과적하다
    - 너무 많이 주다(부과하다)
    - (시스템에) 과부하가 걸리게 하다
- 오버로딩은 '함수에 과부하를 주는 것'???
- 맞는 말
- C에서는 하나의 이름을 가지는 함수는 단 1개만 존재할 수 없었음
- printf는 C라이브러리에 단 하나 존재, scanf도 마찬가지
- **하지만 C++에서는 같은 이름의 함수가 여러개 존재해도 됨.**
- C++에서 같은 이름의 함수를 호출 했을 때 ***<u>구분을 어떻게</u>***???



```c++
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main()
{
	int i = 42;
	char c = '*';
	double f = 4.2f;

	print(i);
	print(c);
	print(f);

	return (0);
}

```

```shell
➜  042_function_overloading_constructor git:(main) ✗ c++ ex00.cpp 
➜  042_function_overloading_constructor git:(main) ✗ ./a.out 
int : 42
char : *
double : 4.2
```

- 어떻게 구분하는거지???
- 이름이 같은 것이고, 인자가 다름!
- C에서는 인자가 다르면 각각 따로 만들어주어야했음
- Soooooo coooooool!!!



```c++
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
// void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main()
{
	int i = 42;
	char c = '*';
	double f = 4.2f;

	print(i);
	print(c);
	print(f);

	return (0);
}

```

```shell
➜  042_function_overloading_constructor git:(main) ✗ ./a.out 
int : 42
int : 42
double : 4.2
```

- char 인자를 받는 함수를 주석처리했더니 다르게 동작함
- 맞는 인자가 없는 경우, ***<u>자신과 최대한 근접한 함수</u>***를 찾게됨



- **저번에 이거 봤는데, 규칙이 일관된 기준이 있는 것 같지는 않아서, 너무 이해하려고는 하지말자.**

- 1단계
    - 자신과 타입이 정확히 일치하는 함수를 찾는다.
- 2단계
    - 일치하지 타입이 없는 경우, 아래와 같이 형 변환을 통해서 일치하는 함수를 찾는다.
    - Char, unsigned char, short 는 int 로 변환
    - Unsigned short 는 int의 크기에 따라 int 혹은 unsigned int
    - Float은 double로 변환
    - Enum은 int로 변환
- 3단계
    - 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾음.
    - 임의의 숫자 타임은 다른 숫자 타임으로 변환 (float -> int)
    - Enum도 임의의 숫자 타입으로 변환 (Enum -> double)
    - 0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환
    - 포인터는 void 포인터로 변환
- 4단계
    - 유저 정의된 타입 변환으로 일치하는 것을 찾음.



- 1단계는 너무 당연하고
- 2단계는 문자는 문자끼리, 정수는 정수끼리, 소수면 소수끼리 하면 될 듯
    - 기본적으로 크기가 큰 타입으로 형변환(casting)되는 듯
    - Char(1), unsigned char(1), short(2) -> int(4)
    - unsinged char(1), int(4) -> int(4), unsigned int(4)
    - Float(4) -> double(8)
    - Enum(4) -> int(4)
- 3단계
    - 이제 동일 종류가 아니라도 값이 같을 수 있는 형변환을 시킴
    - 소수 -> 정수, 정수 -> 소수, 주소 -> 일반, 일반 -> 주소





- 오버로딩의 규칙을 숙지해야하는 것은 *<u>**매우 중요!!!**</u>*

- 이를 고려하지 않으면 나중에 오류가 많이 발생함, 오류의 향연이 됨.



# Date 클래스

- 함수가 밖에 나와있다?
- 앞에 클래스 이름을 붙여주면 클래스에서 정의된 함수의 의미를 부여하게 됨. like `Date::ShowDate()`
- 앞에 namespace가 없다면, 멤버 함수가 아닌 일반적인 함수가 됨
- 일반적으로, 간단한 함수를 제외하면 대부분의 함수는 클래스 밖에서 정의하게 됨. (단, 탬플릿 클래스는 모두 탬플릿 내부에 정의함)



- 만약에 앞의 과제에서 `SetDate`가 없었다면?
    - 쓰레기 값이 출력 될 것임
- 훌륭한 프로그래머는 **<u>*생성 후 초기화*</u>** 를 숙지하겠지만
- 초기화를 빠뜨린다면 큰일
- 이를 언어 차원에서 **생성자(constructor)**가 존재



# 생성자(constructor)

```c++
Date {
  private:
    
  public:
    Date(int year, int month, int day)
};

int main() {
	Date day(1990, 12, 11);
    day.ShowDate();
}

```

- 문법 `클래스이름 (인자);` ClassName 
- **객체 생성시 자동으로 호출되는 함수**

```c++
Date day(1990, 12, 11);
```

- Date 클래스의 day 객체를 만들면서 생성자 `Date(int, int, int)` 호출

```c++
Date day = Date(1990, 12, 11);
```



```c++
Date day(1990, 12, 11);			// 암시작(implicit)
Date day = Date(1990, 12, 11);	// 명시적(explicit)
```

- psi님은 암시적 방법을 선호함



# 디폴트 생성자(Default constructor)

```c++
Date day;
```

- 이건 생성자가 호출될까? Yes
- 디폴트 생성자(Default Constructor)
- 명시적으로 정의하지 않을 경우, 자동으로 추가해주는 생성자



```c++
Date {
  Date() {
      year = 2022;
      month = 1;
      day = 12;
  }
};

int main() {
    Date day1 = Date();	// ok
    Date day2;			// ok
    Date day3();		// wrong
}
```



- 여기서 문법적으로 헷갈리는 것이 있는데,
- day1의 경우 생성자를 명시적으로 호출하는 방식
- day3는 암시적으로 생성하는 것 같지만, 실제로는 함수를 선언하게된다
- 암시적으로 선언하려면 day2처럼 호출해야함.



- C++11 이전에는 디폴트 생성자를 쓰기위해서는 생성자를 정의하지 않았어야 했음.
- 하지만 이것이 실수로 빠뜨린 것인지, 사용하려는 것인지 알 수 없었죠.
- 그래서 11부터는 명시적으로 디폴트 생성자를 사용하도록 명시할 수 있습니다.



# 생성자 오버로딩

- 예제로 풀어봄, 하나는 인자 없이, 하나는 인자있게 
- 4가지 생성자 호출 다해봄. 암시적, 명시적 폼.

```c++
#include <iostream>

class Date {
	int year_;
	int month_;
	int day_;

	public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
	void AddDay(int inc) {
		day_ += inc;
		while (1)
		{
			if (day_ > 31 && (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)) {
				day_ -= 31;
				AddMonth(1);
			}
			else if (day_ > 30 && (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)) {
				day_ -= 30;
				AddMonth(1);
			}
			else if ((month_ == 2) && day_ > 28 + IsLeapYear()) {
				day_ -= 28 + IsLeapYear();
				AddMonth(1);
			}
			else {
				break;
			}
		}
	}
	void AddMonth(int inc) {
		month_ += inc;
		while (1) {
			if (month_ > 12) {
				month_ -= 12;
				AddYear(1);
			}
			else {
				break;
			}
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}

	void ShowDate() {
		std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
	}
	int IsLeapYear() {
		if (year_ % 4 == 0 && (year_ % 100 != 0) || year_ % 400 == 0)
			return (1);
		else
			return (0);
	}

	Date() {
		std::cout << "default constructor called!" << std::endl;
		year_ = 2022;
		month_ = 1;
		day_ = 12;
	}

	Date(int year, int month, int day) {
		std::cout << "3 parameter constructor called!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

int main(int argc, char const *argv[])
{
	// Date date;


	Date day1(1990, 12, 11);
	day1.ShowDate();

	Date day2 = Date(1990, 12, 11);
	day2.ShowDate();

	Date today = Date();
	today.ShowDate();
	Date today2;
	today2.ShowDate();

	return 0;
}

```



# 생각해보기

