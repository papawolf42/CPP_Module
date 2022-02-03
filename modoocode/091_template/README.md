# 이번 강좌에서는

- C++ 템플릿 (template) 도입
- 클래스 템플릿과 함수 템플릿
- 템플릿 인스턴스화와 템플릿 특수화
- 함수 객체 (Functor)
- 타입이 아닌 템플릿 인자
- 디폴트 템플릿 인자



- 시간이 없고 생소한 개념이 많으므로
    - 한번에 이해하는 것보다는, 여러번 많이 본다고 생각하자.



- 이제 새로운 세계로!!!
- 지난 강좌를 보진 않았지만, 벡터(vector)와 스택(stack)을 써봄
    - 아주아주 편리한 자료형
    - LIFO(Last In First Out)
    - pop과 push를 통해 여러가지 작업을 함



- **<u>*하지만 한가지 문제는 데이터 타입이 바뀔 때 마다 다른 벡터를 만들어 주어야한다는 단점이 존재*</u>**



```c++

#include <iostream>

class Vector {
	private:
		std::string*	data;//문자열 배열
		int				capacity;//용량
		int				length;//길이

	public:
		// 생성자
		Vector(int n = 1)
		: data(new std::string[n]), capacity(n), length(0) {}

		// 맨 뒤에 새로운 원소 추가
		void push_back(std::string s) {
			if (capacity <= length) {//capaicty가 length보다 모자랄때 용량을 2배로 눌림.
				std::string* temp = new std::string[capacity * 2];
				for (int i = 0; i < length; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				capacity *= 2;
			}

			data[length] = s;
			length++;
		}

		// 임의의 위치의 원소에 접근
		std::string operator[](int i) { return data[i]; }

		// x 번째 위치한 원소를 제거한다.
		void remove(int x) {
			for (int i = x + 1; i < length; i++) {
				data[i - 1] = data[i];
			}
			length--;
		}
		// 추가적인 생각
		// capacity 8, length는 4
		// capacity                      8
		// length(index) 0 1 2 3 4 5 6 7
		// data          a b c d e f g h


		// 현재 벡터의 크기를 구한다.
		int size() { return length; }

		~Vector() {
			if (data) {
				delete[] data;
			}
		}
};

```



- 단점이 존재하는데, 이 `vector` 클래스의 경우 `string`만 저장할 수 있음.
- int를 원한다면?
- char를 담고 싶다면 어떻게?
    - std::string 부분을 모두 char 로 바꿔주면 그만
    - **<u>*하지만 이는 엄청난 낭비*</u>**



- 다시 말해 우리는 `T`라는 타입의 객체들을 보관하는 `vector`를 만들고 싶을 경우

```c++
class Vector {
  T* data;
  int capacity;
  int length;

 public:
  // 생성자
  Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(T s) {
    if (capacity <= length) {
      T* temp = new T[capacity * 2];
      for (int i = 0; i < length; i++) {
        temp[i] = data[i];
      }
      delete[] data;
      data = temp;
      capacity *= 2;
    }

    data[length] = s;
    length++;
  }

  // 임의의 위치의 원소에 접근한다.
  T operator[](int i) { return data[i]; }

  // x 번째 위치한 원소를 제거한다.
  void remove(int x) {
    for (int i = x + 1; i < length; i++) {
      data[i - 1] = data[i];
    }
    length--;
  }

  // 현재 벡터의 크기를 구한다.
  int size() { return length; }

  ~Vector() {
    if (data) {
      delete[] data;
    }
  }
};
```

- 컴파일러가 T부분에 우리가 원하는 타입을 채워서 코드를 생성해주면 엄청 편할 것임
- **<u>*마치 어떠한 틀에 타입을 집어넣으면 원하는 코드가 딱딱 튀어나오는 틀*</u>** 같이 말이죠.



# C++ 템플릿(template)

- 놀랍게도 이 기능을 C++에서는 template 라는 이름으로 지원
- 영단어 뜻도, 형판이라 틀이라고 생각하면 됨
- 정확하게 같은 의미로 사용됨

```c++
//ex01 template 첫 활용
#include <iostream>
#include <string>

template <typename T>
class Vector {
	private:
		T*				data;//문자열 배열
		int				capacity;//용량
		int				length;//길이

	public:
		// 생성자
		Vector(int n = 1)
		: data(new T[n]), capacity(n), length(0) {}

		// 맨 뒤에 새로운 원소 추가
		void push_back(T s) {
			if (capacity <= length) {//capaicty가 length보다 모자랄때 용량을 2배로 눌림.
				T* temp = new T[capacity * 2];
				for (int i = 0; i < length; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				capacity *= 2;
			}

			data[length] = s;
			length++;
		}

		// 임의의 위치의 원소에 접근
		T operator[](int i) { return data[i]; }

		// x 번째 위치한 원소를 제거한다.
		void remove(int x) {
			for (int i = x + 1; i < length; i++) {
				data[i - 1] = data[i];
			}
			length--;
		}

		// 현재 벡터의 크기를 구한다.
		int size() { return length; }

		~Vector() {
			if (data) {
				delete[] data;
			}
		}
};

int main() {
	// int를 보관하는 벡터를 만든다.

	Vector<int> int_vec;
	int_vec.push_back(4);
	int_vec.push_back(2);

	std::cout << "-------- int vector --------" << std::endl;
	std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
	std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

	// string을 보관하는 벡터
	Vector<std::string> str_vec;
	str_vec.push_back("Life is");
	str_vec.push_back("42");

	std::cout << "-------- str vector --------" << std::endl;
	std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
	std::cout << "두번째 원소 : " << str_vec[1] << std::endl;
	
}
```

```shell
➜  091_template git:(main) ✗ c++ ex01.cpp 
➜  091_template git:(main) ✗ ./a.out 
-------- int vector --------
첫번째 원소 : 4
두번째 원소 : 2
-------- str vector --------
첫번째 원소 : Life is
두번째 원소 : 42
```



- 문법을 좀 살펴볼까

```c++
template <typename T>
```

- 선언부 상단에 템플릿을 정의
- 템플린 인자로 T를 받음
- T는 반드시 어떠한 타입의 이름임을 명시하고 있음
- 지금은 Vector라는 이름의 클래스에 대한 탬플릿을 명시하였는데
    - **<u>*아래 클래스가 아닌 함수가 온다면 함수 탬플릿이됨*</u>**



```c++
template <class T>
```

- 라고도 쓸때가 있는데, 이는 정확히! `<typename T>` 와 동일한 것.
- 꼭 클래스가 와야한다는 말이 아님.
- 하지만 typename을 쓰는 것을 더 **<u>*권장*</u>**함



- 왜 2개의 키워드를 정의했느냐?
    - 이는 c++의 역사와 관려됨
    - 처음에는 class를 키워드로 사용했는데, 클래스가 와야하는 것 처럼 느껴지니까 typename으로 바꿈.
    - 하지만 호환상 남겨둠



- 템플릿에 인자로 전달하기위해

```c++
Vector<int> int_vec;
Vector<std::string> str_vec;
```

- 과 같이 사용해서, 컴파일러가 이것을 보고, 실제 코드를 생성하게 됨.



- T가 int로 치환된 클래스 객체 int_vec 을 생성하괴 되는 것
- **<u>*이를 클래스 탬플릿에 인자를 전달해서 실제 코드를 생성하는 것을 클래스 템플릿 인스턴스화(class template instantiation)이라고 함.*</u>**



- 템플릿이 인스턴스화 되지 않고 덩그러니 있다면, 컴파일 시 아무런 코드로 변환되지 않음.
- 인스턴스화가 되어야 비로소 코드를 생성하게 됨.



- **<u>*간혹 일부 타입에서는 다른 방식으로 처리해야할 경우가 생김*</u>**

```c++
Vector<bool> int_vec;
```

- bool을 저장하는 벡터로 사용할 수 있지만,
    - C++에서는 기본으로 처리하는 단위가 `1byte`임
- 그래서 bool은 1개 비트로 저장 가능하지만 8비트를 사용해서 bool값을 저장해야하게됨.
- 따라서 `Vector<bool>`의 경우 특별히 따로 처리해주어야함.



# 템플릿 특수화(template specialization)

- 다음과 같이 수행함

```c++
template <typename A, typename B, typename C>
calss test {};
```

- 이런식으로 쓰면
    - A는 int, C는 double 일 때 따로 처리하고 싶어! 라면
    - 아래와 같이 선언해주면 됨.

```c++
template <typename B>
class test<int, B, double> {};
```

- B 조차 특수화 하고 싶다면

```c++
template <>
class test<int, int, double> {};
```



- `Vector<bool>`을 구현하기 위해서 int 배열을 사용할 것임.
- 원래방식대로라면 1bit가 아닌 1byte를 쓰겠지만
- 1개의 인트 4byte에 32개의 bool값을 저장할 것!



- (중략) 여기는 비트연산자 내용과 bit mask 정도 내용이 나옴



# 함수 템플릿 (Function template)

- 이번에는 함수 템플릿을 알아보자

```c++

#include <iostream>
#include <string>

template <typename T>
T max(T& a, T& b) {
	return a > b ? a : b;
}

int main () {
	int a = 1, b = 2;
	std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

	std::string s = "hello", t = "wolrd";
	std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}
```

```shell
➜  091_template git:(main) ✗ c++ ex02.cpp 
➜  091_template git:(main) ✗ ./a.out 
Max (1,2) ? : 2
Max (hello,wolrd) ? : wolrd
```



- 클래스 템플릿과 마찬가지로, 함수도 템플릿화 가능
- 위 함수도 인스턴스화 전까지는 컴파일 시 아무런 코드를 변환하지 않음.



- 차이점이 있다면
    - 함수 템플릿은 인스턴스화 할때 <> 로 type을 지정해주지 않습니다.
    - 마치 `max<int>(a, b)` 이런식으로 사용하지 않음.
    - 컴파일러가 자동으로 이렇게 처리함.
    - 마찬가지로 `max<string>(s, t)` 내부적으로 이렇게 처리됨.



```c++

//ex01 template 첫 활용
#include <iostream>
#include <string>

template <typename T>
class Vector {
	private:
		T*				data;//문자열 배열
		int				capacity;//용량
		int				length;//길이

	public:
		// 생성자
		Vector(int n = 1)
		: data(new T[n]), capacity(n), length(0) {}

		// 맨 뒤에 새로운 원소 추가
		void push_back(T s) {
			if (capacity <= length) {//capaicty가 length보다 모자랄때 용량을 2배로 눌림.
				T* temp = new T[capacity * 2];
				for (int i = 0; i < length; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				capacity *= 2;
			}

			data[length] = s;
			length++;
		}

		// 임의의 위치의 원소에 접근
		T operator[](int i) { return data[i]; }

		// x 번째 위치한 원소를 제거한다.
		void remove(int x) {
			for (int i = x + 1; i < length; i++) {
				data[i - 1] = data[i];
			}
			length--;
		}

		// 현재 벡터의 크기를 구한다.
		int size() { return length; }

    	// 이 부분이 추가됨
		void swap(int i, int j) {
			T temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		~Vector() {
			if (data) {
				delete[] data;
			}
		}
};

template <typename Cont>
void bubble_sort(Cont& cont) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i; j < cont.size(); j++) {
			if (cont[i] > cont[j]) {
				cont.swap(i, j);
			}
		}
	}
}

int main() {
	// int를 보관하는 벡터를 만든다.

	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(8);
	int_vec.push_back(5);
	int_vec.push_back(3);

	std::cout << "-------- 정렬 이전 --------" << std::endl;
	for (int i = 0; i < int_vec.size(); i++) {
		std::cout << int_vec[i] << " ";
	}
	std::cout << std::endl;

	bubble_sort(int_vec);
	std::cout << "-------- 정렬 이후 --------" << std::endl;
	for (int i = 0; i < int_vec.size(); i++) {
		std::cout << int_vec[i] << " ";
	}
	std::cout << std::endl;
}
```

```shell
➜  091_template git:(main) ✗ c++ ex03.cpp
➜  091_template git:(main) ✗ ./a.out     
-------- 정렬 이전 --------
3 1 2 8 5 3 
-------- 정렬 이후 --------
1 2 3 3 5 8 
```



- bubble_sort 라는 함수는 임의의 컨테이너를 받아서 정렬해주는 함수
- **<u>*컨테이너*</u>**란 데이터를 보관하는 것 이라고 생각하면됨



- swap이 실제로 이번에 추가된 함수임
- 만약 템플릿 함수에서 전달되는 객체에 이런 메소드들이 정의되어있지 않다면?
- 컴파일시에 멤버함수나 멤버 변수를 찾을 수 없다는 오류를 뱉 됨.

```shell
➜  091_template git:(main) ✗ c++ ex03.cpp 
ex03.cpp:61:10: error: no member named 'swap' in 'Vector<int>'
                                cont.swap(i, j);
                                ~~~~ ^
ex03.cpp:84:2: note: in instantiation of function template specialization 'bubble_sort<Vector<int> >' requested here
        bubble_sort(int_vec);
        ^
1 error generated.
```



- 재미있게, 컴파일시 모든 템플릿들이 인스턴스화 된다는 사실
- 이 사실만으로 여러가지 흥미로운 코드를 짤 수 있는데
- 이러한 방식을 **<u>*템플릿 메타 프로그래밍(template metaprogramming)*</u>**이라고 합니다.



- 진짜 재밋는 질문
- 지금 bubble_sort는 오름차순으로 구현됨.
- 그럼 내림차순으로 구현하려면 어떻게 해야할까?
    - 가장 이상적인 방법은... 함수의 인자로 구현한다던가, 아니면 전역변수나 객체에 어떤 설정값을 저장해둔다정도...?



# 함수 객체(Function Object - Functor)의 도입

```c++

//ex01 template 첫 활용
#include <iostream>
#include <string>

template <typename T>
class Vector {
	private:
		T*				data;//문자열 배열
		int				capacity;//용량
		int				length;//길이

	public:
		// 생성자
		Vector(int n = 1)
		: data(new T[n]), capacity(n), length(0) {}

		// 맨 뒤에 새로운 원소 추가
		void push_back(T s) {
			if (capacity <= length) {//capaicty가 length보다 모자랄때 용량을 2배로 눌림.
				T* temp = new T[capacity * 2];
				for (int i = 0; i < length; i++) {
					temp[i] = data[i];
				}

				delete[] data;
				data = temp;
				capacity *= 2;
			}

			data[length] = s;
			length++;
		}

		// 임의의 위치의 원소에 접근
		T operator[](int i) { return data[i]; }

		// x 번째 위치한 원소를 제거한다.
		void remove(int x) {
			for (int i = x + 1; i < length; i++) {
				data[i - 1] = data[i];
			}
			length--;
		}

		// 현재 벡터의 크기를 구한다.
		int size() { return length; }

		void swap(int i, int j) {
			T temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		~Vector() {
			if (data) {
				delete[] data;
			}
		}
};

template <typename Cont>
void bubble_sort(Cont& cont) {
  for (int i = 0; i < cont.size(); i++) {
    for (int j = i + 1; j < cont.size(); j++) {
      if (cont[i] > cont[j]) {
        cont.swap(i, j);
      }
    }
  }
}

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i; j < cont.size(); j++) {
			if (!comp(cont[i], cont[j])) {
				cont.swap(i, j);
			}
		}
	}
}

struct Comp1 {
	bool operator()(int a, int b) { return a > b; }
};
struct Comp2 {
	bool operator()(int a, int b) { return a < b; }
};


int main() {
	// int를 보관하는 벡터를 만든다.

	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(8);
	int_vec.push_back(5);
	int_vec.push_back(3);

	std::cout << "-------- 정렬 이전 --------" << std::endl;
	for (int i = 0; i < int_vec.size(); i++) {
		std::cout << int_vec[i] << " ";
	}
	std::cout << std::endl;

	Comp1 comp1;
	bubble_sort(int_vec, comp1);
	std::cout << "-------- 내림차순 이후 --------" << std::endl;
	for (int i = 0; i < int_vec.size(); i++) {
		std::cout << int_vec[i] << " ";
	}
	std::cout << std::endl;

	Comp2 comp2;
	bubble_sort(int_vec, comp2);
	std::cout << "-------- 오름차순 이후 --------" << std::endl;
	for (int i = 0; i < int_vec.size(); i++) {
		std::cout << int_vec[i] << " ";
	}
	std::cout << std::endl;
}

```

```shell
➜  091_template git:(main) ✗ c++ ex04.cpp; ./a.out
-------- 정렬 이전 --------
3 1 2 8 5 3 
-------- 내림차순 이후 --------
8 5 3 3 2 1 
-------- 오름차순 이후 --------
1 2 3 3 5 8 
```



- (사견)
    - 어라 왜 구조체를 쓰지?
    - comp() 라는 함수를 만들고 함수포인터를 넣어주는게 아니라!
    - `operator()` 연산자 오버로딩을 하고, 구조체에 담아줌.
    - 구조체를 선언하고, 그 구조체를 넘겨주네...????
- 구조체이지만 이를 객체라고 부르넹
- 함수는 아니지만, 함수인척 하는 객체를 함수 객체(Function Object)
    - 줄여서 `Functor`라고 부름
- 그래서 사용하면 템플릿 인스턴스화가 일어남.



- C였다면 구닥다리 함수포인터를 사용했을 것
    - 왜 구닥다리지...
- Functor를 사용하면 여로모로 편리
- 함수포인터로 처리하면 컴파일러가 최적화를 못하지만
    - Functor는 컴파일러가 인라인화를 시켜 매우 빠르게 작업시킬 수 있음



# 타입이 아닌 템플릿 인자 (non-type template arguments)

- 한가지 재미 있는 점은 템플릿 인자를 타입만 받을 수 있는 건아님

```c++

#include <iostream>

template <typename T, int num>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;
}
```

```shell
➜  091_template git:(main) ✗ c++ ex05.cpp; ./a.out 
x : 8
```

- 타입이 아닌 인자를 받게됨.
- 만약 <>를 인자에 지정하지 않았다면 컴파일 타임 오류가 발생.
- 상식적으로 <>를 비우면 어떤 값이 들어갈지 알 수 없기 떄문



- 템플릿 인자로 전달 가능한 타입들은 제한적
    - 정수타입(bool, char, int, long 등등), 
    - (불가능) `float`, `dobble` 은 제외
    - 포인터 타입
    - enum 타입
    - std::nullptr_t (널 포인터)

---





- C에서 배열의 가장 큰 문제점은 배열을 전달할 때
    - 배열의 크기를 잃어버린다는 점.

```c++
// array from c++11

#include <iostream>
#include <array>

int main() {
	std::array<int, 5> arr = {1, 2, 3, 4, 5};

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
```

```shell
➜  091_template git:(main) ✗ c++ ex06.cpp 
➜  091_template git:(main) ✗ ./a.out 
1 2 3 4 5 
```

- size 크기를 가지고 있음



- 여기에 이런 함수를 만든다면 어떨까?

```c++
void print_array(const std::array<int, 5>& arr);
```

```c++
// array from c++11

#include <iostream>
#include <array>

template <typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	std::array<int, 6> arr2 = {4, 8, 15, 16, 23, 42};
	std::array<int, 3> arr3 = {0, 9, 42};

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
	
	return (0);
}
```

```shell
➜  091_template git:(main) ✗ c++ ex06.cpp 
➜  091_template git:(main) ✗ ./a.out 
1 2 3 4 5 
4 8 15 16 23 42 
0 9 42 
```

- 여기에 T은 타입만 주어짐
- (사견) 처음에는 이렇게 선언해야 하나 싶었음

```c++
void print_array(const T&<int, 5> arr) {
```

- array 크기별로 만들어주어야하나?
- 그건 아님.



- 그럼 정리하면
- array도 template 인스턴스로 만들어지고
- array를 출력하는 함수도 template 인스턴스로 만들어지네





# 디폴트 템플릿 인자

- 마지막으로
- 이 넘겨주는 인자를 디폴트 인자로 지정할 수 있음.