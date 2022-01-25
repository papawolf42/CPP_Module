/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:56:17 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 04:08:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : name_(name), weapon_(weapon) {}

void HumanA::attack() {
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
