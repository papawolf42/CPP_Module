/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:31:30 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 10:12:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5), target_(target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
	Form::operator=(ref);
	target_ = ref.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
	return (target_);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException("NOT ENOUGH GRADE TO EXECUTE");
	if (this->getSigned() == false)
		throw FormNotSignedException();

	std::cout << "<" << this->getTarget() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}
