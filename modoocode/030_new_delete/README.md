# 이번 강좌에서는

- `new`와 `delete` 사용
- `scope` 개념



---

- 메모리 관리는 중요
- 힙(heap) 공간이 따로 생김. 사용자가 직접 책임짐
- 스택(stack)은 컴파일러로 안정성이 보장됨.



```c++
#include <iostream>

int	main()
{
	int* p = new int;
	*p = 42;

	std::cout << *p << std::endl;

	delete p;
	return (0);
}

```

```shell
➜  030_new_delete git:(main) ✗ ./a.out 
42
```



- 문법은 malloc이랑 비슷하다!
- 포인터에 선언하는 것도 같네

```c++
T* pointer = new T;
```

- 마지막으로 할당된 공간을 해제하기 위해서 `delete`
- 똑같네 문법은



- 지역변수를 delete하려고하면 error를 띄움. 



# new로 배열 할당하기

```c++
#include <iostream>

int	main() {
    int	arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }
    delete[] list;
    return (0);
}

```

```shell
➜  030_new_delete git:(main) ✗ cpp ex01.cpp 
➜  030_new_delete git:(main) ✗ ./a.out 
array size : 5
1
2
3
4
5
0th element of list : 1
1th element of list : 2
2th element of list : 3
3th element of list : 4
4th element of list : 5
```

- 코드 작성하면서 느낀점
    - `int *list = new int[arr_size];` 에서 약간 weird
    - 이제껏 써왔던 것이 `PascalCase`였고, 많이 봐온 것이 Java의 `camelCase` [link1](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/coding-style/coding-conventions) [link2](https://stackoverflow.com/questions/35957610/coding-style-curly-bracket-after-if-statement)
    - delete 할때 배열을 해제할 때는 문법이 `delete[]`이다 
    - for문의 증감식은 마지막에 동작한다. 출력이 0부터 되는 것을 보면
    - cin과 cout
- Scope
    - 중괄호 안에서 정의했다면, 밖에서는 소멸됨
    - 중괄호 밖에서 정의했더라도, 안에서 새롭게 정의할 수 있음.



# 돌아온 마이펫, 객체로의 유도

- 돌아온 마이펫을 C++로 다시 구현해 보면서 불편한 점 3가지를 이야기함
    1. 함수 호출이 부적절함. 현재는 논다(개[번호])인데, 개[번호]->논다() 로 바꾸는게 더 나을 것?
    2. new로 할당 후에, create로 초기화 하는데, new만 불러도 자동으로 해주면 얼마나 좋을까? -> 생성자 개념인 듯
    3. Animal뿐 아니라, Bird나 Fish같은 개념이 추가되었을 때, deep이나 height 같은 변수를 추가해 구조체를 새로 짜야함 -> 상속을 말하는 듯
- 3번 상속 빼고는 조금 납득이 가지는 않지만, 써보면서 알아야할 듯.

