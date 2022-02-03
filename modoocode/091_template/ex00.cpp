
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
		// 인덱스를 3을 넣으면 d를 지우고 e가 d 자리에 와야함.
		// ㅇㅇ 맞네

		// 현재 벡터의 크기를 구한다.
		int size() { return length; }

		~Vector() {
			if (data) {
				delete[] data;
			}
		}
};
