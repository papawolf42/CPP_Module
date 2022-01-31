/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:21:51 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 08:47:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), target_("NULL") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), target_(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) 
	: Form(ref.getName(), 145, 137), target_(ref.getTarget()) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
	Form::operator=(ref);
	target_ = ref.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const {
	return (target_);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException("NOT ENOUGH GRADE TO EXECUTE");
	if (this->getSigned() == false)
		throw FormNotSignedException();

	std::ofstream outfile;
	outfile.open(target_ + "_shrubbery", std::ios::out | std::ios::trunc);
	if (outfile.fail() == true)
		throw OutFileCannotOpenException();
	outfile << SHRUBBERY << std::endl;
	outfile.close();
}

ShrubberyCreationForm::OutFileCannotOpenException::OutFileCannotOpenException()
	: msg_("FAILED TO OPEN FILE") {}
ShrubberyCreationForm::OutFileCannotOpenException::OutFileCannotOpenException(const char *msg)
	: msg_(msg) {}
const char* ShrubberyCreationForm::OutFileCannotOpenException::what() const throw() {
	return (msg_);
}
