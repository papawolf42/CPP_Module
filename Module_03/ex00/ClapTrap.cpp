/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:58:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 08:15:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_(NULL), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name_(name), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	name_ = ref.name_;
	hit_point_ = ref.hit_point_;
	energy_point_ = ref.energy_point_;
	attack_damage_ = ref.attack_damage_;
	return *this;
}

void ClapTrap::setName(std::string name) {
	name_ = name;
}
void ClapTrap::setHitPoint(int hit_point) {
	hit_point_ = hit_point;
}
void ClapTrap::setEnergyPoint(int energy_point) {
	energy_point_ = energy_point;
}
void ClapTrap::setAttackDamage(int attack_damage) {
	attack_damage_ = attack_damage;
}

std::string ClapTrap::getName(void) {
	return (name_);
}
int ClapTrap::getHitPoint(void) {
	return (hit_point_);
}
int ClapTrap::getEnergyPoint(void) {
	return (energy_point_);
}
int ClapTrap::getAttackDamage(void) {
	return (attack_damage_);
}

void ClapTrap::attack(std::string const& target) {
	std::cout << "ClapTrap <" << name_ << "> attack <" << target 
		<< ">, causing <" << attack_damage_ << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point_ > 0) {
		std::cout << "ClapTrap <" << name_ << "> take <" << amount << "> points of damage!" << std::endl;
		hit_point_ -= amount;
	}
	if (hit_point_ > 0) {
		std::cout << " remain HP is <" << hit_point_ << ">" << std::endl; 
	} else {
		std::cout << " HP reach 0, Claptrap <" << name_ << "> destroyed" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit_point_ > 0) {
		hit_point_ += amount;
		std::cout << "ClapTrap <" << name_ << "> has been repaired by <" << amount << "> points" << std::endl;
		std::cout << " remain HP is <" << hit_point_ << ">" << std::endl; 
	} else {
		std::cout << "ClapTrap <" << name_ << "> has already been completely destroyed and cannot be repaired" << std::endl;
	}
}

