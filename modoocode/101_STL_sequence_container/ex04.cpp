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
