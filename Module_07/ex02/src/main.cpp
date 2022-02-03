/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:11:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 12:39:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array arr_int(6);
		
		arr_int[0] = 4;
		arr_int[1] = 8;
		arr_int[2] = 15;
		arr_int[3] = 16;
		arr_int[4] = 23;
		arr_int[5] = 42;
		// arr_int[6] = 999;

		for(unsigned int i = 0; i < arr_int.size(); i++) {
			std::cout << arr_int[i] << " ";
		}
		std::cout << std::endl;

		Array temp(arr_int);
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

		temp[5] = 24;
		for(unsigned int i = 0; i < arr_int.size(); i++) {
			std::cout << arr_int[i] << " ";
		}
		std::cout << std::endl;
		for(unsigned int i = 0; i < temp.size(); i++) {
			std::cout << temp[i] << " ";
		}
		std::cout << std::endl;

	} catch (Array::outBoundException& e) {
		std::cerr << e.what() << std::endl;
	}

	system("leaks Array");
}
