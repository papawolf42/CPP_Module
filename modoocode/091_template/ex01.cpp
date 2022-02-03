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