/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 06:18:01 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 00:02:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char *argv[]) {

	if (argc != 4)
	{
		std::cout << "Wrong fommat entered\n"
			<<"Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}

	Replacer replacer;
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (replacer.checkEmpty(filename, s1, s2) == ERROR)
		return (1);
	if (replacer.openInfile(filename) == ERROR)
		return (2);
	if (replacer.openOutfile(filename) == ERROR) {
		replacer.close();
		return (3);
	}
	replacer.replace(s1, s2);
	replacer.close();
}
