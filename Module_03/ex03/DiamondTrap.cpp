/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:15:26 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 18:15:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "<DiamondTrap> Default constructor called" << std::endl;
	name_ = "Unknown";
	setName("Unknown_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(), FragTrap() {
	std::cout << "<DiamondTrap> String constructor called" << std::endl;
	name_ = name;
	setName(name + "_clap_name");
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) {
	std::cout << "<DiamondTrap> Copy constructor called" << std::endl;
	*this = ref;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "<DiamondTrap> Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref) {
	std::cout << "<DiamondTrap> Assignation called" << std::endl;
	ClapTrap::operator=(ref);
	return *this;
}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout
	<< "Who Am I ???\n"
	<< "my full name is <" << getName() << ">\n"
	<< "just call me <" << name_ << ">" << std::endl;
}
