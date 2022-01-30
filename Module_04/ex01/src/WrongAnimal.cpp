/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:15:06 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:15:07 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type): type_(type) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "String constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "Copy constructor called" << std::endl;
	*this = ref;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref) {
	type_ = ref.type_;
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "Assignation operator called" << std::endl;
	return *this;
}
WrongAnimal::~WrongAnimal() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "Destructor called" << std::endl;
}

void WrongAnimal::setType(std::string type) {
	type_ = type;
}
std::string WrongAnimal::getType(void) const {
	return (type_);
}

void WrongAnimal::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[WrongAnimal]"
	<< "blah~! blah~!" << std::endl;
}
