/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:51:36 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 03:30:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string string("HI THIS IS BRAIN");
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "address string    : " << &string << std::endl;
	std::cout << "address pointer   : " << stringPTR << std::endl;
	std::cout << "address reference : " << &stringREF << std::endl;

	std::cout << "using pointer     : " << *stringPTR << std::endl;
	std::cout << "using reference   : " << stringREF << std::endl;
}
