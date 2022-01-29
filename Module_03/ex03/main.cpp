/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 18:00:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

/*
*/
int main() {
    DiamondTrap battle_curiser("Battle_Cruiser");
	DiamondTrap carrier("Carrier");
	std::cout << std::endl;

	battle_curiser.attack(carrier.getName());
	carrier.takeDamage(battle_curiser.getAttackDamage());
	carrier.beRepaired(5);
	std::cout << std::endl;

	carrier.guardGate();
	carrier.highFivesGuys();
	std::cout << std::endl;

	battle_curiser.whoAmI();
	std::cout << std::endl;

	return (0);
}
