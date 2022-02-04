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
