/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:25:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/25 01:24:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx_(0) {}

void	PhoneBook::Add() {
	size_t	i = idx_ % maxContact;

	std::cout << "\n------------------------------\n";
	std::cout << "we will add new contact.\n";
	std::cout << "please, input information\n";
	contact_[i].SetFirstName();
	contact_[i].SetLastName();
	contact_[i].SetNickName();
	contact_[i].SetPhoneNumber();
	contact_[i].SetDarkestSecret();
	++idx_;
}

void	PhoneBook::Search() {
	if (idx_ == 0)
	{
		std::cout << "ERROR: PhoneBook is empty now, please add contact using command ADD\n";
		return ;
	}
	SearchDisplayHead();
	for (size_t i = 0; i < idx_ && i < maxContact; i++) {
		SearchDisplayRow(i);
	}
	SearchDisplayDivider();
	SearchIndex();
}

void	PhoneBook::SearchDisplayHead() {
	std::cout << std::endl;
	SearchDisplayDivider();
	SearchDisplayColumn("index");
	SearchDisplayColumn("first name");
	SearchDisplayColumn("last name");
	SearchDisplayColumn("nick name");
	std::cout << "|" << std::endl;
	SearchDisplayDivider();
}

void	PhoneBook::SearchDisplayRow(size_t i) {
	SearchDisplayColumn(std::to_string(i + 1));
	SearchDisplayColumn(contact_[i].GetFirstName());
	SearchDisplayColumn(contact_[i].GetLastName());
	SearchDisplayColumn(contact_[i].GetNickName());
	std::cout << "|" << std::endl;
}

void	PhoneBook::SearchDisplayColumn(std::string content) {
	std::cout << "|";
	if (content.length() <= maxWidth)
		std::cout << std::right << std::setw(maxWidth) << content;
	else {
		std::cout << content.substr(0, 9);
		std::cout << ".";
	}
}

void	PhoneBook::SearchDisplayDivider() {
	std::cout << "+----------+----------+----------+----------+\n";
}

void	PhoneBook::SearchIndex() {
	std::string			input;
	size_t				index;	

	std::cout << "Which contact detail would you like to look up? ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(1);
	else if (!(std::istringstream(input) >> index)) {
		std::cout << "Please enter a number.\n";
	}
	else if (index < 1 || index > maxContact)
		std::cout << "index is out of range!\n";
	else if (index > idx_)
		std::cout << "index hasn't been added yet\n";
	else {
		std::cout << "first name: " << contact_[index - 1].GetFirstName() << std::endl;
		std::cout << "last name: " << contact_[index - 1].GetLastName() << std::endl;
		std::cout << "nick name: " << contact_[index - 1].GetNickName() << std::endl;
		std::cout << "phone number: " << contact_[index - 1].GetPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << contact_[index - 1].GetDarkestSecret() << std::endl;
	}
}
