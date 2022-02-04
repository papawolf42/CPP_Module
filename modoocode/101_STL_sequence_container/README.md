# 이번 강좌에서는

- C++ 표준 템플릿 라이브러리 개요
- 시퀀스 컨테이너(sequence container)
- 반복자(iterator)
- 범위 기반 for 문(Range-based for loop)



- C++의 표준 템플릿 라이브러리(STL)을 사용
- 능률을 `100%` 업해주는 엄청난 도구
- `STL`의 도입으로 C++이 한번 도약한 것.



# C++ 표준 템플릿 라이브러리 (Standard Template Library - STL)

- 꽤 많은 종류의 라이브러리가 있음
    - 대표적인 입출력 라이브러리 (iostream)
    - 시간 관련 라이브러리 (chrono)
    - 정규 표현식 라이브러리 (regex) 
- 하지만 보통 C++ STL이라고 하면 다음 3가지를 의미함
    1. 임의 타입의 객체를 보관할 수 있는 컨테이너 (container)
    2. 컨테이너에 보관된 원소에 접근할 수 있는 반복자 (iterator)
    3. 반복자들을 가지고 일련의 작업을 수행하는 알고리즘 (algorithm)



- 가장 핵심은 **컨테이너**
    - 객체의 특성과 무관하게 라이브러리를 자유롭게 사용가능!, `템플릿 덕분이죠!!!`
    - int string 말고도 저희가 만든 class 모두 사용가능!!!
    - C 였다면 불간으 했을 일

- 반복자 도입
    - 필요한 최소한의 코드만으로 작성 가능.
    - 다시 말하면 `M` 개의 컨테이너가 존재
    - `N` 개의 알고리즘
    - `MN` 개의 알고리즘 코드

- 반복자를 통해, 컨테이너 추상화
    - N개의 알고리즘 코드로 M종류의 컨테이너 모두 지원가능



# C++ 'STL' 컨테이너 - 벡터 (std::vector)

- 컨테이너는 크게 2 종류
    - **시퀀스 컨테이너(sequence container)**
    - **연관 컨테이너(associative container)**



- 시퀀스 컨테이너
    - vector
    - list
    - deque



- Vector는 
    - 쉽게는 **가변길이 배열**
    - 메모리산 숭차적으로 저장
    - 임의의 원소 접근을 매우 빠르게 수행



# 정확히 얼마나 빠르다고?

- 매우 빠르다는 주관적
    - 컴공에서는 어떠한 작업의 처리 속도를 `복잡도(complexity)`라고 부름
    - 그 복잡도 `Big O 표기법` 으로 나타냄



- 버블정렬
    - 대충 O( N^2 )



(중략)



- vector의 경우, 원소 접근을 `O(1)`으로 가능
    - 원소 추가 `(push_back)`
    - 원소 제거 `(pop_back)`
    - 모두 O(1)으로 가능



- 원소 추가 작업은 엄밀히는 **amortized O(1)**
    - 벡터는 현재의 원소 수보다, 더 많은 공간을 미리 할당해 놓음
    - 그래서 대부분 O(1)로 원소 쓰기 가능.
- 문제는 할당된 공간을 다 채웠을 경우
    - 모든 원소를 복사해서 메모리를 옮기게 되므로 
    - 매우 드물게 복잡도 O(n)까지 늘어남



- 맨 뒤의 원소를 추가 제거는 빠르지만, 임의의 원소를 추가 제거하는 것은 느림
    - 제거 후 원소를 한칸씩 이동시켜주어야 하기 때문



# 반복자(iterator)

- 컨테이너에 / 원소에 접근할 수 있는 / 포인터 같은 객체



- 반복자는 컨테이너에서 `iterator` 멤버 타입으로 정의되어있음.
    - vector는 반복자를 얻기 위해서는 begin()과 end() 함수를 사용함.

![img](https://modoocode.com/img/2165E44C595A970A1676B5.webp)

- begin() : 첫번째 원소를 가리키는 반복자를 리턴
- end(): 마지막 원소(x), 마지막 원소 한칸 뒤를 가리키는 반복자를 리턴
    - 여러 이유가 있겠지만, 빈 벡터를 표현할 수 있다는 것.
    - begin() == end() 라면, 원소가 없는 벡터를 의미
    - (사견) 'null'이나 NULL과 같은 역할을 하게 하기 위해서 인 것 같음.



```c++
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	//전체 벡터 출력하기
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		std::cout << *itr << std::endl;
	}

	std::vector<int>::iterator itr = vec.begin() + 2;
	std::cout << "3 번째 원소 :: " << *itr << std::endl;
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ ./a.out 
10
20
30
40
3 번째 원소 :: 30
```



- vector의 반복자 타입은 이렇게 정의함
    - `std::vector<>::iterator`
    - `vec.begin()` 이나 `vec.end()` 함수가 이를 리턴함



- 실제로 반복자는 포인터가 아니지만,
    - 포인터 처럼 사용가능함.
    - 값을 출력할 때는 `*`를 붙여서 출력함
    - 당연히 연산자 오버로딩임



- 마찬가지로 + 2 와 같이, 증감 연산자로 떨어진 만큼의 원소를 가리키게 할 수 있음



```c++
for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
```

- `typename`을 줘야하는데, `iterator`가 `std::vector<T>` 의 의존타입이기 때문
    - typename은 의존타입인데
    - T가 typename의 T인지, 다른 namespace나 class 이름의 T인지를 구분하기 위해서 꼭 붙여주어야함.



```c++
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	// for (std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "----------------------------" << std::endl;

	// vec[2] 앞에 15 추가
	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	std::cout << "----------------------------" << std::endl;
	// vec[3] 제거
	vec.erase(vec.begin() + 3);
	print_vector(vec);
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ ./a.out 
처음 벡터 상태
10
20
30
40
----------------------------
10
20
15
30
40
----------------------------
10
20
15
40
```

- ​	`vec.insert(vec.begin() + 2, 15);`
    - 2번 인덱스인 30 앞에, 15를 추가함.
- 임의의 인덱스에 추가하는 것은 `O(n)`





---

- 이번 사례는 실행시 오류가 남

```c++
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	std::cout << "[ ";
	// for (std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}
	std::cout << "]";
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(20);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);

	std::vector<int>::iterator itr = vec.begin();
	std::vector<int>::iterator end_itr = vec.end();

	for (; itr != end_itr; ++itr) {
		if (*itr == 20) {
			vec.erase(itr);
		}
	}
	
	std::cout << "값이 20인 원소를 지운다!" << std::endl;
	print_vector(vec);
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ ./a.out 
처음 벡터 상태
[ 10
20
30
40
20
[1]    55936 segmentation fault  ./a.out
```

- 만약 컨테이너에 원소를 추가 혹은 제거하게되면
    - 기존의 사용하던 반복자 모두 사용 불가능하게됨.
    - `vec.erase(itr)` 이후에 `itr`, `end_itr` 모두 무효화 되게 됨
- `itr != end_itr` 이 성립하지 않아 무한루프에 빠지게 됨.



- 이를 고쳐보자.

```c++
for (; itr != vec.end(); ++itr) {
    if (*itr == 20) {
        vec.erase(itr);
        itr = vec.begin();
    }
}
```

- 아주 비효율적임.
- 이런 방법도 존재

```c++
for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
    if (vec[i] == 20) {
        vec.erase(vec.begin() + i);
        i--;
    }
}
```

- 반복자가 아닌 정수로 접근중
- 위 방법은 권장되지 않음
- 원소 접근은 반복자로 하는게 좋았지만, 기존의 배열처럼 접근하기 때문



- 이 문제는 C++ 알고리즘 라이브러리에 대해 배우면 깔끔히 해결됨.



- `vector`에서 지원하는 반복자로 `const_iterator` 가 존재
    - `const pointer`라고 생각하면됨
    - 즉 `const_iterator`로 가리키고 있는 원소의 값은 바꿀 수 없음.



```c++
// value indicated const iterator cannot change
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	std::cout << "[ ";
	// for (std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "]";
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "초기 벡터 상태" << std::endl;
	print_vector(vec);

	// itr은 vec[2]를 가리킨다.
	std::vector<int>::iterator itr = vec.begin() + 2;
	
	*itr = 50;

	std::cout << "---------------" << std::endl;
	print_vector(vec);

	std::vector<int>::const_iterator citr = vec.cbegin() + 2;

	// 상수 반복자가 가리키는 값은 바꿀 수 없다. 불가능.
	*citr = 30;
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ c++ ex03.cpp 
ex03.cpp:36:8: error: cannot assign to return value because function 'operator*'
      returns a const value
        *citr = 30;
        ~~~~~ ^
/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/iterator:1458:60: note: 
      function 'operator*' which returns const-qualified type
      'std::__1::__wrap_iter<const int *>::reference' (aka 'const int &') declared here
    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_IF_NODEBUG reference operator*(...
                                                           ^~~~~~~~~
1 error generated.
```

```shell
'citr': you cannot assign to a variable that is const
```



- `const` 반복자의 경우, 꼭 `cbegin()`과 `cend()`를 사용해야 얻을 수 있습니다.
- 많은 경우 반복자의 값을 바꾸지 않고, 참조만 하는 경우가 많으므로, `const iterator`를 적극적으로 활용해야합니다.

---



- 마지막으로 vector에는 역반복자(reverse iterator) 가 있습니다.
- 이는 똑같지만 벡터 뒤에서 부터 앞으로 거꾸로 간다는 특징이 있음.

```c++
// reverse iterator
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	// for (std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "초기 vec 상태" << std::endl;
	print_vector(vec);

	std::cout << "역으로 vec 출력하기!" << std::endl;
	std::vector<int>::reverse_iterator ritr = vec.rbegin();
	for (; ritr != vec.rend(); ritr++) {
		std::cout << *ritr << std::endl;
	}
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ cpp ex04.cpp; ./a.out
초기 vec 상태
10
20
30
40
역으로 vec 출력하기!
40
30
20
10
```

![img](https://modoocode.com/img/275B1D3D595B2F4011531A.webp)

- 역반복자는 증가시키면 반복자가 왼쪽으로 이동함.
- 역반복자 역시 상수 연산자가 있음
    - `const_reverse_iterator`
    - `crbegin()`, `crend()`



---

- 역반복자는 매우 중요함

```c++
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	// 끝에서 부터 출력하기
	for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
		std::cout << vec[i] << std::endl;
	}
	return (0);
}

```

```shell
(중략)
155891013
0
1
0
5
168
6528
0
0
0
0
[1]    75772 segmentation fault  ./a.out
```

- 아무래도 size_type이라는 타입이, 음수가 없는 정수형인듯 함.
- 캐스팅하면 그만이지만, 가장 현명한 것은 역반복자를 사용하는 것



# 범위 기반 for 문 (range based for loop)

- 컨테이너 원소를 for문으로 접근하는데, 
- `c++11` 부터는 이와 같은 패턴을 매우 간단히 나타내는 방식을 제공
- 바로 ***<u>범위 기반 (range-based) for 문</u>***

```c++
// range-based-for-loop
#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	// 끝에서 부터 출력하기
	for (int elem : vec) {
		std::cout << "원소 : " << elem << std::endl;
	}
	return (0);
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ c++ ex06.cpp; ./a.out 
ex06.cpp:12:16: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (int elem : vec) {
                      ^
1 warning generated.
원소 : 1
원소 : 2
원소 : 3
```

- c++ 컴파일러는 기본적으로 `c++11`을 `warning` 으로 처리함.



- 범위 기반 for 문에 저렇게 쓰면
    - elem에 vec의 원소들이 루프마다 복사되어 들어가게 됨.





---

- 만약에 복사하기보다, 레퍼런스를 받고 싶다면 어떻게 해야할까요?

```c++
// range-based-for-loop
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
	// for (T elem : vec) {
	for (const auto& elem : vec) {
		std::cout << elem << std::endl;
	}
}

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::cout << "print_vector" << std::endl;
	print_vector(vec);

	std::cout << "print_vector_range_based" << std::endl;
	print_vector_range_based(vec);

	return (0);
}

```

```shell
➜  101_STL_sequence_container git:(main) ✗ c++ ex07.cpp; ./a.out
ex07.cpp:15:13: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : vec) {
                   ^
ex07.cpp:15:24: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : vec) {
                              ^
print_vector
1
2
3
4
print_vector_range_based
1
2
3
4
```

- const auto???
    - (재고) 아마도 `auto`는 자동으로 타입을 케스팅해주는게 아닐까 싶음



# 리스트(list)

- 리스트는 양방향 연결 구조를 가진 자료형

![img](https://modoocode.com/img/246A0A4B595B396939AF3D.webp)



- `vector`와 달리 임의의 원소에 바로 접근할 수 없음.
    - `[]` 나 `at` 함수가 아예 정의되어 있지 않음.
- `list` 컨테이너는 자체에서는 시작 원소와 마지막 원소의 위치만 기억.
- 임의의 위치에 있는 원소에 접근하기 위해 하나씩 링크를 따라가야함.



- 물론 리스트의 장점이 있음!!
    - vector의 경우 임의의 위치를 추가 제거하는 작업이 O(n)
    - list의 경우 임의의 위치를 추가 제거하는 작업이 O(1)
    - 매우 빠름!!
    - 위치 앞 뒤에 링크값만 바꾸어주면 되기 때문



```c++
// first list
#include <iostream>
#include <list>

int main() {
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		std::cout << *itr << std::endl;
	}
	return (0);
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ ./a.out 
10
20
30
40
```



- 재미있는 점!!!!
    - list는 반복자의 경우 다음과 같은 연산 2가지 밖에 못함
    - 임의의 위치를 갈수 없음
    - 리스트의 반복자는 오직 한칸씩만 움직이 ㄹ수 있음

```c++
itr++    //(O)가능, 반복자로 다음 원소를 가리킴
itr--    //(O)가능, --itr로도됨.
itr + 5  //(X)불가능!
```



- 리스트의 구조를 생각해보면 알 수 있음
- 한번에 한칸씩 이동할 수 있고, 
- 메모리상에서 연속적으로 존재하지 않음!
- 반면에 벡터는 메모리상에 연속적으로 존재함



- 리스트에서 반복자의 타입을 보면
    - `BidirectionalIterator` 임을 알 수 있음. 
        - 양방향으로 이동가능
        - 한 칸 씩 이동 가능
    - 
    - `RandomAccessIterator`는 벡터의 방식
        - 참고로 `BidirectionalIterator`를 상속받는 식임



```c++
// lists are not invalidated by erase()
#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
	std::cout << "[ ";
	for (const auto& elem : lst) {
		std::cout << elem << " ";
	}
	std::cout << "]";
}

int main() {
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(30);

	std::cout << "처음 리스트의 상태 " << std::endl;
	print_list(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
		if (*itr == 20) {
			lst.insert(itr, 50); // 아마도 50이 20 앞에 추가되는 듯.
		}
	}

	std::cout << "값이 20인 원소 앞에 50을 추가 " << std::endl;
	print_list(lst);

	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == 30) {
			lst.erase(itr);
			// break;
		}
	}

	std::cout << "값이 30 인 원소 제거" << std::endl;
	print_list(lst);

	return (0);
}
```

```shell
➜  101_STL_sequence_container git:(main) ✗ c++ ex09.cpp; ./a.out
ex09.cpp:8:13: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : lst) {
                   ^
ex09.cpp:8:24: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : lst) {
                              ^
2 warnings generated.
처음 리스트의 상태 
[ 10 20 30 40 30 ]값이 20인 원소 앞에 50을 추가 
[ 10 50 20 30 40 30 ]값이 30 인 원소 제거
[ 10 50 20 40 ]%                  
```

- `itr`은 한칸씩 증감 가능
- `vector`와 다르게 `insert`에서 O(1)로 매우 빠름
- `erase`로 지워도 `vector`와 다르게 반복자가 무효화되지 않음. 각원소의 주소값이 안바뀌기 때문!



# 덱 (deque - double ended queue)

- 마지막으로 살펴볼 컨테이너 `덱(deque)`



- 원소 접근 O(1)
- 맨 앞뒤 원소 추가 제거 O(1)
- 임의의 원소 추가 제거  O(n)
    - 벡터보다 빠름



- 벡터와 비슷하지만, 덱은 벡터와 달리 메모리에 연속적으로 존재하지 않음
- 어디 저장되어있는지 저장하기 위한 추가적인 메모리를 필요
- `libc++ 라이브러리`에서는 1개의 원소 보관 덱이 원소 크기의 8배를 사용.



![img](https://modoocode.com/img/245FC94C595B5F9B133E4E.webp)

- 실행 속도를 위해, 메모리를 (많이) 희생하는 컨테이너

    - 일정 크기로 잘려 각각의 `블록` 에 존재

    - 블록들의 주소를 저장하는 벡터가 필요

    - 참고로, 이 벡터는 기존 벡터와 다르게, 새로 할당시 앞, 뒤쪽으로 모두 공간을 남겨놓게됨
        - 이 때문에, 맨 앞뒤로 원소 추가시 속도 O(1)



- 그렇다면 왜 덱이 벡터보다 원소 삽입 작업이 더 빠를까?
    - 메모리가 꽉 차는 경우에 한해 벡터는 O(n)을 가지는데
    - 덱은 전부 복사를 할 필요는 없음

![img](https://modoocode.com/img/23015636595B647418F5CE.webp)





- 대체로 벡터에 저장되는 객체들의 크기가 주소값의 크기보다 크기 때문에 복사속도가 훨씬 빠름.

---



```c++
// first deque
#include <iostream>
#include <deque>

template <typename T>
void print_deque(std::deque<T>& dq) {
	// 전체 덱을 출력하기
	std::cout << "[ ";
	for (const auto& elem : dq) {
		std::cout << elem << " ";
	}
	std::cout << "]";
}

int main() {
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(30);
	dq.push_front(40);

	std::cout << "초기 dq 상태" << std::endl;
	print_deque(dq);

	std::cout << "맨 앞의 원소 제거" << std::endl;
	dq.pop_front();
	print_deque(dq);
}

```

```shell
➜  101_STL_sequence_container git:(main) ✗ touch ex10.cpp
➜  101_STL_sequence_container git:(main) ✗ c++ ex10.cpp; ./a.out 
ex10.cpp:9:13: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : dq) {
                   ^
ex10.cpp:9:24: warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
        for (const auto& elem : dq) {
                              ^
2 warnings generated.
초기 dq 상태
[ 40 30 10 20 ]맨 앞의 원소 제거
[ 30 10 20 ]%      
```



- 벡터처럼 `RaddomAccessIterator` 를 사용



# 그래서 어떤 컨테이너를 사용해야돼?

- 어떤 컨테이너를 사용할지는 전적으로 어떠한 작업을 하느냐에 따름
    - 일반적인 상황에서는 `벡터`를 사용(만능!!!)
    - 맨끝이 아닌 중간에 원소를 추가하거나 제거하는 일이 많고, 원소를 순차적으로 접근한다면 `리스트`를 사용
    - 맨 처음과 끝에 원소를 추가하는 작업을 많이 한다면 `덱`



