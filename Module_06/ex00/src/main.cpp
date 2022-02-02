/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:33:14 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 20:48:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return (1);
	}

	Convertor c(argv[1]);
	try {std::cout << "char: ";		c.toChar(); 	std::cout << std::endl; } catch (std::exception& e) { std::cout << e.what() << std::endl; }
	try {std::cout << "int: ";		c.toInt(); 		std::cout << std::endl; } catch (std::exception& e) { std::cout << e.what() << std::endl; }
	try {std::cout << "float: ";	c.toFloat() ;	std::cout << std::endl; } catch (std::exception& e) { std::cout << e.what() << std::endl; }
	try {std::cout << "double: ";	c.toDouble(); 	std::cout << std::endl; } catch (std::exception& e) { std::cout << e.what() << std::endl; }
	return (0);
}
