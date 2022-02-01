/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 10:13:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		ShrubberyCreationForm hobby_life("Home");
		Bureaucrat minister("wife", 150);

		minister.signForm(hobby_life);
		std::cout << std::endl;
	
		minister.upGrade(10);
		minister.signForm(hobby_life);
		std::cout << std::endl;
	
		minister.executeForm(hobby_life);
		std::cout << std::endl;
	
		minister.upGrade(10);
		minister.executeForm(hobby_life);
		std::cout << std::endl;
	
		std::cout << hobby_life << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	try {
		RobotomyRequestForm automail("Edward Elric");
		Bureaucrat king("Bradley", 1);

		king.signForm(automail);
		std::cout << std::endl;

		king.executeForm(automail);
		std::cout << std::endl;

		std::cout << automail << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	try {
		PresidentialPardonForm pardon_form("Park");
		Bureaucrat president("Moon", 1);

		president.signForm(pardon_form);
		std::cout << std::endl;

		president.executeForm(pardon_form);
		std::cout << std::endl;
		
		std::cout << pardon_form << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
