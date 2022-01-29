/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 15:51:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
** ex03에서 다중 상속, 그리고 다이아몬드 상속을 구현하기 위해 
** ClapTrap을 상속받는 추가적인 파생 클래스인 FragTrap을 만들어봄
** 특별한 함수 void highFivesGuys();를 추가
** ScavTrap과 달리 attack을 overriding 하지 않는다.
*/
int main() {
	FragTrap tank("Siege-Tank");
	FragTrap reaver("Reaver");
	std::cout << std::endl;

	tank.attack(reaver.getName());
	reaver.takeDamage(tank.getAttackDamage());
	tank.beRepaired(5);
	std::cout << std::endl;

	reaver.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
