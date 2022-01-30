/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:58:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 22:16:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Dog]"
	<< "Default constructor called" << std::endl;
	brain_ = new Brain;
}
Dog::Dog(const Dog& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Dog]"
	<< "Copy constructor called" << std::endl;
	brain_ = new Brain;
	*this = ref;
}
Dog& Dog::operator=(const Dog& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Dog]"
	<< "Assignation operator called" << std::endl;
	Animal::operator=(ref);
	*brain_ = *ref.brain_;
	return *this;
}
Dog::~Dog() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Dog]"
	<< "Destructor called" << std::endl;
	delete brain_;
}

void Dog::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Dog]"
	<< "MEONG! MEONG!" << std::endl;
}
void Dog::addIdea(std::string idea) {
	brain_->addIdea(idea);
}
std::string Dog::getIdea(unsigned int idx) const {
	return (brain_->getIdea(idx));
}
