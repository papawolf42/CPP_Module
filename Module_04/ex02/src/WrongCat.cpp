/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:18:02 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:32:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongCat]"
	<< "Default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongCat]"
	<< "Copy constructor called" << std::endl;
	*this = ref;
}
WrongCat& WrongCat::operator=(const WrongCat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongCat]"
	<< "Assignation operator called" << std::endl;
	WrongAnimal::operator=(ref);
	return *this;
}
WrongCat::~WrongCat() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongCat]"
	<< "Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongCat]"
	<< "YAONG~ YAONG~" << std::endl;
}
