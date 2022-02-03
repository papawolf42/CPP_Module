/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 03:34:31 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:34:58 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(5); // top에 요소 추가
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop(); // top 요소 제거

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(-42);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << std::endl << "iterator test" << std::endl;
	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << std::endl << "reverse iterator test" << std::endl;
	++rit;
	std::cout << *rit << std::endl;
	--rite;
	std::cout << *rite << std::endl;

	return 0;
}
