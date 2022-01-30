/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:09:48 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:11:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Default constructor called" << std::endl;
}
Cat::Cat(const Cat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Copy constructor called" << std::endl;
	*this = ref;
}
Cat& Cat::operator=(const Cat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Assignation operator called" << std::endl;
	Animal::operator=(ref);
	return *this;
}
Cat::~Cat() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "YAONG~ YAONG~" << std::endl;
}
