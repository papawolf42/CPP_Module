/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:49:57 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 05:32:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

const std::string& Weapon::getType() {
	return (type_);
}

void Weapon::setType(std::string type) {
	type_ = type;
}
