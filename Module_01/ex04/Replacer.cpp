/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:57:31 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 00:08:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer() : infile_(NULL), outfile_(NULL) {}

int Replacer::checkEmpty(std::string filename, std::string s1, std::string s2) {
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cout << "your input contain empty" << std::endl;
		return (ERROR);
	}
	return (0);
}

int Replacer::openInfile(std::string filename) {
	infile_.open(filename, std::ios::in);
	if (infile_.fail() == true) {
		std::cout << "opening file " << filename << " fails" << std::endl;
		return (ERROR);
	}
	return(0);
}

int Replacer::openOutfile(std::string filename) {
	for (size_t i = filename.length(); i > 0; i--) {
		filename[i - 1] = toupper(filename[i - 1]);
	}
	outfile_.open(filename + ".replace", std::ios::out | std::ios::trunc);
	if (outfile_.fail() == true) {
		std::cout << "opening file " << filename << " fails" << std::endl;
		return (ERROR);
	}
	return (0);
}

void Replacer::replace(std::string s1, std::string s2) {
	std::string line;
	size_t pos = 0;
	size_t i = 0;

	while (std::getline(infile_, line)) {
		while ((i = line.find(s1, pos)) != std::string::npos) {
			line.erase(i, s1.length());
			line.insert(i, s2);
			pos = i + s2.length();
		}
		outfile_ << line << "\n";
		pos = 0;
	}
}

void Replacer::close() {
	if (infile_ != NULL)
		infile_.close();
	if (outfile_ != NULL)
		outfile_.close();
}
