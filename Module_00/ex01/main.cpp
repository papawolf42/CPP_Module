/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:37:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/24 20:51:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main() {
	PhoneBook	phonebook;
	std::string	input;

	while (true) {
		std::cout << "\n------------------------------\n";
		std::cout << "please, enter command(EXIT, ADD, SEARCH): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.Add();
		else if (input == "SEARCH")
			phonebook.Search();
		else
			std::cout << "wrong command, your input is discarded" << std::endl;
	}
	return (0);
}
