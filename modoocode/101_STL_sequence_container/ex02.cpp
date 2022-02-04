// access on iterator
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
	vec.push_back(20);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);

	std::vector<int>::iterator itr = vec.begin();
	std::vector<int>::iterator end_itr = vec.end();

	/* 가장 처음 시도, runtime 오류 발생 */
	// for (; itr != end_itr; ++itr) {
	// 	if (*itr == 20) {
	// 		vec.erase(itr);
	// 	}
	// }

	/* 두번째 시도, 하지만 매우 비효율 */
	// for (; itr != vec.end(); ++itr) {
	// 	if (*itr == 20) {
	// 		vec.erase(itr);
	// 		itr = vec.begin();
	// 	}
	// }

	/* 세번째 시도, 권장되지 않음, 결국 반복자로 반복하는게 아님 */
	for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
		if (vec[i] == 20) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
	
	std::cout << " 값이 20인 원소를 지운다!" << std::endl;
	print_vector(vec);
}
