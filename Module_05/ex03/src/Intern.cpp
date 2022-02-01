/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:13:23 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 17:31:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }
Intern::Intern(const Intern& ref) { (void)ref; }
Intern::~Intern() { }

Intern& Intern::operator=(const Intern& ref) {
	(void)ref;
	return (*this);
}

Form* Intern::makeForm(const std::string form_name, const std::string form_target) {
	int i;
	std::string table_form_name[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3; i++) {
		if (table_form_name[i] == form_name)
			break;
	}

	switch (i) {
		case 0:
			std::cout << "Intern creates <" << table_form_name[i] << ">" << std::endl;
			return (new ShrubberyCreationForm(form_target));
		case 1:
			std::cout << "Intern creates <" << table_form_name[i] << ">" << std::endl;
			return (new RobotomyRequestForm(form_target));
		case 2:
			std::cout << "Intern creates <" << table_form_name[i] << ">" << std::endl;
			return (new PresidentialPardonForm(form_target));
		default:
			throw InvalideFormException();
	}
}

const char* Intern::InvalideFormException::what() const throw() {
	return ("A form with that name doesn't exist yet");
}
