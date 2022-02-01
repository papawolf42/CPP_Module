/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 17:32:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern jang_grae;
		Bureaucrat minister("wife", 1);
		Bureaucrat king("Bradley", 1);
		Bureaucrat president("Moon", 1);

		Form* fsc = jang_grae.makeForm("shrubbery creation", "home");
		std::cout << *fsc << std::endl;
		Form* frr = jang_grae.makeForm("robotomy request", "Edward Elric");
		std::cout << *frr << std::endl;
		Form* fpp = jang_grae.makeForm("presidential pardon", "Park");
		std::cout << *fpp << std::endl;
		// Form* Wrong = jang_grae.makeForm("resignation", "Mr. Oh");
		// std::cout << *Wrong << std::endl;
		std::cout << std::endl;

		minister.signForm(*fsc);
		king.signForm(*frr);
		president.signForm(*fpp);
		std::cout << std::endl;

		minister.executeForm(*fsc);
		king.executeForm(*frr);
		president.executeForm(*fpp);

		delete fsc;
		delete frr;
		delete fpp;

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
