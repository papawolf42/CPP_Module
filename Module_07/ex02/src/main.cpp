/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:11:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 13:32:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	/*
	** first test for copy constructor, int array
	*/
	try {
		Array<int> arr_int(6);
		
		arr_int[0] = 4;
		arr_int[1] = 8;
		arr_int[2] = 15;
		arr_int[3] = 16;
		arr_int[4] = 23;
		arr_int[5] = 42;
		// arr_int[6] = 999;

		std::cout << "arr_int : ";
		for(unsigned int i = 0; i < arr_int.size(); i++) {
			std::cout << arr_int[i] << " ";
		}
		std::cout << std::endl;

		Array<int> temp(arr_int);
		std::cout << "temp    : ";
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

		temp[5] = 24;
		std::cout << "arr_int : ";
		for(unsigned int i = 0; i < arr_int.size(); i++) {
			std::cout << arr_int[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "temp    : ";
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

	// } catch (Array::outBoundException& e) {
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	/*
	** second test for assignation operator, string array
	*/
	try {
		Array<std::string> arr_str(3);
		arr_str[0] = "life";
		arr_str[1] = "is";
		arr_str[2] = "42";

		std::cout << "arr_str : ";
		for(unsigned int i = 0; i < arr_str.size(); i++) {
			std::cout << arr_str[i] << " ";
		}
		std::cout << std::endl;

		Array<std::string> temp;
		std::cout << "temp    : ";
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

		// assgination occurs
		std::cout << "assgination occurs" << std::endl;
		temp = arr_str;
		std::cout << "temp    : ";
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

		// [] operator works
		std::cout << "[]operator works" << std::endl;
		temp[2] = "*";
		std::cout << "temp    : ";
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "arr_str : ";
		for(unsigned int i = 0; i < arr_str.size(); i++) {
			std::cout << arr_str[i] << " ";
		}
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// system("leaks Array");
}
