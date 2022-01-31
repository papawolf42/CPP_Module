/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 08:49:10 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		ShrubberyCreationForm s("Home");
		Bureaucrat president("Biden", 140);

		president.signForm(s);
		president.executeForm(s);
		std::cout << s << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		ShrubberyCreationForm s("Home");
		Bureaucrat president("Biden", 140);

		president.signForm(s);
		president.executeForm(s);
		std::cout << s << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
