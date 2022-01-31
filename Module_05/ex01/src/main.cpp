/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:48:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/31 14:23:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// try {
	// 	Form("GuestBook", 150, 150);
	// } catch (const std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	try {
		Form x_file("X-File", 0, 1);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Form leaf("leaf", 151, 151);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Form innovation("innovation", 24, 24);
		Bureaucrat bear("42_Polarbear", 42);

		bear.signForm(innovation);
		std::cout << innovation << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Form innovation("innovation", 24, 24);
		Bureaucrat chief("24_Dall", 24);

		chief.signForm(innovation);
		std::cout << innovation << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Form approval("Nuclear Missile", 1, 1);
		Bureaucrat president("Biden", 1);

		president.signForm(approval);
		std::cout << approval << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
