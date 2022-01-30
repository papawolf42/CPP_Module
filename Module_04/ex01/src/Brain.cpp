/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:43:19 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 15:35:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Brain]"
	<< "Default constructor called" << std::endl;
	num_idea_ = 0;
}
Brain::Brain(const Brain& ref) {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Brain]"
	<< "Copy constructor called" << std::endl;
	*this = ref;
}
Brain& Brain::operator=(const Brain& ref) {
	for (unsigned int i = 0; i < SizeBrainArray; i++) {
		idea_[i] = ref.idea_[i];
	}
	num_idea_ = ref.num_idea_;
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Brain]"
	<< "Assignation operator called" << std::endl;
	return *this;
}
Brain::~Brain() {
	std::cout << std::left << std::setfill('.') << std::setw(WidthClassName) << "[Brain]"
	<< "Destructor called" << std::endl;
}

void Brain::addIdea(std::string& idea) {
	if (num_idea_ > 100) {
		std::cout << std::left << std::setfill('.') << std::setw(WidthClassName)
		<< "[Brain]" << "I can't memorize anymore" << std::endl;
		return ;
		}
	idea_[num_idea_] = idea;
	num_idea_++;
}
std::string Brain::getIdea(unsigned int idx) const {
	if (idx < 0 || idx > num_idea_) {
		return (std::string("What are you saying?"));
	}
	return (idea_[idx - 1]);
}
