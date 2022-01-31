/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:03:58 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/31 14:22:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iomanip>

Form::Form() : name_("NULL"), signed_(false), sign_grade_(24), execute_grade_(42) {
}
Form::Form(std::string name, int sign_grade, int execute_grade): name_(name), signed_(false), sign_grade_(sign_grade), execute_grade_(execute_grade) {
	if (sign_grade < 1 || execute_grade < 1) {
		throw GradeTooHighException();
	} else if (sign_grade > 150 || execute_grade > 150) {
		throw GradeTooLowException();
	}
}
Form::Form(const Form& ref) : name_(ref.name_), signed_(ref.signed_), sign_grade_(ref.sign_grade_), execute_grade_(ref.execute_grade_) { }
Form::~Form() {}

Form& Form::operator=(const Form& ref) {
	signed_ = ref.signed_;
	return (*this);//const attribute는 초기화 때 대입 가능해서, 대입할 수 없음.
}

std::string Form::getName() const {
	return (name_);
}
bool Form::getSigned() const {
	return (signed_);
}
int Form::getSignGrade() const {
	return (sign_grade_);
}
int Form::getExecuteGrade() const {
	return (execute_grade_);
}

void Form::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > sign_grade_) {
		throw GradeTooLowException("NOT ENOUGH GRADE");
	}
	signed_ = true;
}

Form::GradeTooHighException::GradeTooHighException()
	: msg_("Grade is too high! the highest grade is 1") {}
Form::GradeTooHighException::GradeTooHighException(const char *msg)
	: msg_(msg) {}
const char* Form::GradeTooHighException::what() const throw() {
	return (msg_);
}

Form::GradeTooLowException::GradeTooLowException()
	: msg_("Grade is too low! the lowest grade is 150") {}
Form::GradeTooLowException::GradeTooLowException(const char *msg)
	: msg_(msg) {}
const char* Form::GradeTooLowException::what() const throw() {
	return (msg_);
}

std::ostream& operator<<(std::ostream& out, const Form& ref) {
	out
	<< "----------------------------------------\n"
	<< "| NAME            : " << std::left << std::setw(19) << (ref.getName().length() > 19 ? ref.getName().substr(0, 19) : ref.getName())  << "|\n"
	<< "| SIGNATURE       : " << std::left << std::setw(19) << (ref.getSignGrade() == true ? "O" : "X") << "|\n"
	<< "| GRADE TO SIGN   : " << std::left << std::setw(19) << ref.getExecuteGrade() << "|\n"
	<< "| GRADE TO EXEC   : " << std::left << std::setw(19) << ref.getExecuteGrade() << "|\n"
	<< "----------------------------------------\n";
	return (out);
}
