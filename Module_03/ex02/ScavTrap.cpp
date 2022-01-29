/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 08:52:12 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 18:29:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "<ScavTrap> Default constructor called" << std::endl;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "<ScavTrap> String constructor called" << std::endl;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& ref) {
	std::cout << "<ScavTrap> Copy constructor called" << std::endl;
	*this = ref;
}

ScavTrap::~ScavTrap() {
	std::cout << "<ScavTrap> Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	std::cout << "<ScavTrap> Assignation called" << std::endl;
	ClapTrap::operator=(ref);
	return *this;
}

void ScavTrap::attack(std::string const& target) {
	std::cout << "ScavTrap <" << getName() << "> attack <" << target 
		<< ">, causing <" << getAttackDamage() << "> points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap <" << getName() << "> has entered in <Gate keeper mode>" << std::endl;
}
