/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 08:14:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap scv("SCV");
	ClapTrap probe("Probe");
	std::cout << std::endl;

	scv.attack("Probe");
	scv.takeDamage(5);
	scv.beRepaired(1);
	std::cout << std::endl;

	probe.attack("Vulture");
	probe.takeDamage(20);
	probe.beRepaired(1);
	std::cout << std::endl;
	
	return (0);
}
