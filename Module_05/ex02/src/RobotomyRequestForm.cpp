/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:51:48 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 10:45:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 72, 45), target_(target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
	Form::operator=(ref);
	target_ = ref.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
	return (target_);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException("NOT ENOUGH GRADE TO EXECUTE");
	if (this->getSigned() == false)
		throw FormNotSignedException();

	srand((unsigned int)time(NULL));
	std::cout
	<< "wiiiiing shiiiing bbbrrrrrrr" << std::endl;
	if (rand() % 2) {
		std::cout << "<" << this->getTarget() << "> has been robotomized successfully" << std::endl;
	} else {
		std::cout << "<" << this->getTarget() << "> failed to robotomized" << std::endl;
	}
}
