/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:38:59 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/24 04:35:13 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

std::string contact::GetFirstName() {
	return (first_name_);
}

std::string contact::GetLastName() {
	return (last_name_);
}

std::string contact::GetNickName() {
	return (nickname_);
}

std::string contact::GetPhoneNumber() {
	return (phone_number_);
}

std::string contact::GetDarkestSecret() {
	return (darkest_secret_);
}

void		contact::SetFirstName() {
	std::cout << "first name: ";
	std::getline(std::cin, first_name_);
	if (std::cin.eof())
		exit(1);
}

void		contact::SetLastName() {
	std::cout << "last name: ";
	std::getline(std::cin, last_name_);
	if (std::cin.eof())
		exit(1);
}

void		contact::SetNickName() {
	std::cout << "nick name: ";
	std::getline(std::cin, nickname_);
	if (std::cin.eof())
		exit(1);
}

void		contact::SetPhoneNumber() {
	std::cout << "phone number: ";
	std::getline(std::cin, phone_number_);
	if (std::cin.eof())
		exit(1);
}

void		contact::SetDarkestSecret() {
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkest_secret_);
	if (std::cin.eof())
		exit(1);
}
