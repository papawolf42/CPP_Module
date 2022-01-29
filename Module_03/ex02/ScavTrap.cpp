/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 08:52:12 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 09:32:50 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "<ScavTrap> Default constructor called" << std::endl;
	hit_point_ = 100;
	energy_point_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "<ScavTrap> String constructor called" << std::endl;
	hit_point_ = 100;
	energy_point_ = 50;
	attack_damage_ = 20;
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
	std::cout << "ScavTrap <" << name_ << "> attack <" << target 
		<< ">, causing <" << attack_damage_ << "> points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap <" << name_ << "> has entered in <Gate keeper mode>" << std::endl;
}
