// importance of reverse iterator
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
