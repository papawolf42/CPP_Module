
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
