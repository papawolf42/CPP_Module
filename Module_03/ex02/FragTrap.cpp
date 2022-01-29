/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:28:51 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 15:41:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "<FragTrap> Default constructor called" << std::endl;
	hit_point_ = 100;
	energy_point_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "<FragTrap> String constructor called" << std::endl;
	hit_point_ = 100;
	energy_point_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& ref) {
	std::cout << "<FragTrap> Copy constructor called" << std::endl;
	*this = ref;
}

FragTrap::~FragTrap() {
	std::cout << "<FragTrap> Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	std::cout << "<FragTrap> Assignation called" << std::endl;
	ClapTrap::operator=(ref);
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap <" << name_ << "> request HIGHFIVE, come on !!!" << std::endl;
}
