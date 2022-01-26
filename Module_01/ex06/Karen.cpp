/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 04:03:17 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen() {
	pf_[0] = &Karen::debug;
	pf_[1] = &Karen::info;
	pf_[2] = &Karen::warning;
	pf_[3] = &Karen::error;
	level_table_[0] = "DEBUG";
	level_table_[1] = "INFO";
	level_table_[2] = "WARNING";
	level_table_[3] = "ERROR";
}

void Karen::debug(void) {
	std::cout << "[ DEBUG ]\n"
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}

void Karen::info(void) {
	std::cout << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Karen::warning(void) {
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Karen::error(void) {
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Karen::complain(std::string level) {
	size_t i = 0;

	for (; i < 4; i++) {
		if (level_table_[i] == level) {
			break;
		}
	}

	switch (i) {
		case DEBUG:
		(this->*pf_[DEBUG])();
		case INFO:
		(this->*pf_[INFO])();
		case WARNING:
		(this->*pf_[WARNING])();
		case ERROR:
		(this->*pf_[ERROR])();
		break;
		default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
