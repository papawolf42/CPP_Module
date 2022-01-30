/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:09:48 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 15:37:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Default constructor called" << std::endl;
	brain_ = new Brain;
}
Cat::Cat(const Cat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Copy constructor called" << std::endl;
	brain_ = new Brain;
	*this = ref;
}
Cat& Cat::operator=(const Cat& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Assignation operator called" << std::endl;
	Animal::operator=(ref);	
	*brain_ = *ref.brain_;
	return *this;
}
Cat::~Cat() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "Destructor called" << std::endl;
	delete brain_;
}

void Cat::makeSound(void) const {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Cat]"
	<< "YAONG~ YAONG~" << std::endl;
}
void Cat::addIdea(std::string idea) {
	brain_->addIdea(idea);
}
std::string Cat::getIdea(unsigned int idx) const {
	return (brain_->getIdea(idx));
}
