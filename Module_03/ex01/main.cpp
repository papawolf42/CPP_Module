/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 09:43:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
** Derived Class에서 Base Class의 attribute들을 사용해야함.
** 생성자, 소멸자는 순서대로 동작해야함.
** attack 맴버 함수를 가상함수로 선언해 overriding해서 써야함
** 소멸자도 가상 소멸자로 만들어야함.
** 대입 연산자에서 Base Class의 대입연산자로 초기화 해주어야함.
*/
int main() {
	ScavTrap vulture("Vulture");
	ScavTrap dragoon("Dragoon");
	std::cout << std::endl;

	vulture.attack(dragoon.getName());
	dragoon.takeDamage(vulture.getAttackDamage());
	dragoon.beRepaired(5);
	std::cout << std::endl;

	dragoon.guardGate();
	std::cout << std::endl;

	// ClapTrap *p = new ScavTrap("pointer");
	// delete p;
	return (0);
}
