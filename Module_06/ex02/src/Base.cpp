/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:41:43 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 23:18:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

Base* generate(void) {
	std::srand(static_cast<unsigned long>(time(NULL)));

	switch (std::rand() % 3) {
		case 0:
		return (new A);
		case 1:
		return (new B);
		default :
		return (new C);
	}
}

void identify(Base* p) {
	A* a = dynamic_cast<A*>(p);
	if (a != NULL) {
		std::cout << "I'm A" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b != NULL) {
		std::cout << "I'm B" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL) {
		std::cout << "I'm C" << std::endl;
		return ;
	}
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "I'm A" << std::endl;
	} catch (std::bad_cast) { }
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "I'm B" << std::endl;
	} catch (std::bad_cast) { }
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "I'm C" << std::endl;
	} catch (std::bad_cast) { }
}
