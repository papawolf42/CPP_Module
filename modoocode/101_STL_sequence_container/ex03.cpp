// 
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
