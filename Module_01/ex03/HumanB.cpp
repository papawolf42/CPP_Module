/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:56:17 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 06:11:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
	weapon_ = &weapon;
}

void HumanB::attack() {
	std::cout << name_ << " attacks with his " ;
	if (weapon_ == NULL) {
		std::cout << "bare body" << std::endl;
	} else {
		std::cout << weapon_->getType() << std::endl;
	}
}
