/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:30:08 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 02:14:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie() {
	std::cout << "<" << name_ << "> destructor called" << std::endl;
}

void Zombie::announce(void) {
	std::cout << "<" << name_ << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	name_ = name;
}
