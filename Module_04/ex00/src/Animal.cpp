/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:58:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:13:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "Default constructor called" << std::endl;
}
Animal::Animal(std::string type): type_(type) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "String constructor called" << std::endl;
}
Animal::Animal(const Animal& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "Copy constructor called" << std::endl;
	*this = ref;
}
Animal& Animal::operator=(const Animal& ref) {
	type_ = ref.type_;
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "Assignation operator called" << std::endl;
	return *this;
}
Animal::~Animal() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "Destructor called" << std::endl;
}

void Animal::setType(std::string type) {
	type_ = type;
}
std::string Animal::getType(void) const {
	return (type_);
}

void Animal::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Animal]"
	<< "blah~! blah~!" << std::endl;
}
