/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 03:30:06 by gunkim           ###   ########.fr       */
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
}//c++ 11 이전에서는 배열을 초기화 리스트로 초기화 불가.

void Karen::debug(void) {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level) {
	for (size_t i = 0; i < 4; i++) {
		if (level_table_[i] == level) {
			(this->*pf_[i])();
		}
	}
}
