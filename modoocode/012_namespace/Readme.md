# Namespace

- iostream 은 C++ 표준 입출력을 포함함
- cout 앞에 std
- `std`는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간(name space)

- 이것도 생각보다 복잡할 수 

## 이름공간 정의 방법

```c++
// header1.h
namespace header1
{
    int foo();
    void bar();
}
```



```c++
// header2.h
namespace header2
{
    int foo();
    void bar();
}
```




- 같은 이름의 함수가 다른 이름공간에서 각각 선언됨.
- 해당되는 이름공간에서는 따로 이름공간을 명시하지 않고 자유롭게 호출 간으

```c++
#include "header1.h"

namespace header1
{
    int func() 
    {
        foo(); // 자동으로 header1::foo() 가 호출됨
    }
}
```



- 반복적으로 namespace를 호출하기 귀찮을 때는 `using`을 사용하면됨

```c++
#incldue "header1.h"
#include "header2.h"
using namespace header1;

int	main()
{
    header2::foo();	// header2의 foo 함수
    foo();			// header1의 foo 함수
}
```



---

**Note**

`using namespace std;`과 같은사용은 권장되지 않음. `std`에 이름이 겹치는 함수를 만들면, 오류가 발생

C++ 표준 라이브러리에는 정말 많은 함수가 존재하므로, 이름이 겹치면 고치느라 시간을 많이 잡아먹음.

또 std에 함수가 추가되면, 잘 작동하던 코드에서 문제가 발생할 수 있으므로

사용은 권장하지 않고, 이름앞에 반드시 이름공간을 적어주는게 좋음.

---



- cout은 ostream 클래스의 객체, 표준출력(C언어의 stdout에 대응됨)



## 이름 없는 이름 공간

- 재밋게도 C++에서 이름 공간의 이름을 굳이 설정하지 않을 수 있음
- 이 경우 마치 static 키워드와 같은 효과를 가짐

```c++
#include <iostream>

namespace
{
    int OnlyInThisFile() {}
    
    int only_in_this_file = 0;
}

int	main()
{
    OnlyInThisFile();
    only_in_this_file = 3;
}
```



## 생각해 보기

```c++
//ex01
#include <iostream>

namespace
{
	int	OnlyInThisFile() {}
	int	only_in_this_file = 0;
}

int	main()
{
	// OnlyInThisFile();
	only_in_this_file = 1;

	std::cout << "is this real???" << std::endl;
	std::cout << "what number I chosen is " << only_in_this_file << std::endl;
}
```

```shell
#output
is this real???
what number I chosen is 1
```

- int 변수 선언도 안했는데, 대입이 되네(x)
- 전역변수로 인식 되었던 것임
- `-Werror` 플래그 함수가 return값이 정의되지 않는다고 경고하네.



```c++
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:59:15 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/10 21:00:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::cout << "hi" << std::endl
			 << "my name is "
			 << "gunkim" << std::endl;
}
```

```shell
#output
hi
my name is gunkim
```

- `std::cout` indentation이 편하지 않음.
- `;` 으로 함수가 종료됨을 알려주어야 함
- 그 전까지는 계속 출력을 늘릴 수 있다.

