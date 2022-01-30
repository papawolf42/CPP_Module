/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:02:33 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/31 13:46:50 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("NULL"), grade_(150) {
}
Bureaucrat::Bureaucrat(std::string name, int grade): name_(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	grade_ = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name_(ref.name_), grade_(ref.grade_) { }
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	grade_ = ref.grade_;
	return (*this);// name은 const라서 대입이 안됨.
}
Bureaucrat::~Bureaucrat() {
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high! the highest grade is 1");
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low! the lowest grade is 150");
}

std::string Bureaucrat::getName() const {
	return (name_);
}
int Bureaucrat::getGrade() const {
	return (grade_);
}

void Bureaucrat::upGrade(int up) {
	if (grade_ - up < 1) {
		throw GradeTooHighException();
	}
	grade_ -= up;
}
void Bureaucrat::downGrade(int down) {
	if (grade_ + down > 150) {
		throw GradeTooLowException();
	}
	grade_ += down;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << "<" << ref.getName() << "> bureaucrat grade <" << ref.getGrade() << ">";
	return (out);
}
