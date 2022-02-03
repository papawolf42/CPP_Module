/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:33:14 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 11:49:07 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void) {
	int lotto[6] = {4, 8, 15, 16, 23, 42};
	iter(lotto, 6, print);
	std::cout << std::endl;

	iter(lotto, 6, addOne);
	std::cout << std::endl;

	iter(lotto, 6, print);
	std::cout << std::endl;

	char fortytwo[] = {'4', '2', 'S', 'e', 'o', 'u', 'l'};
	std::cout << std::endl;
	
	iter(fortytwo, sizeof(fortytwo), print);
	std::cout << std::endl;

	iter(fortytwo, sizeof(fortytwo), subOne);
	std::cout << std::endl;

	iter(fortytwo, sizeof(fortytwo), print);
	std::cout << std::endl;

	std::string strs[] = {"Life", "is", "42"};
	std::cout << std::endl;
	
	iter(strs, 3, print);
	std::cout << std::endl;

	return (0);
}
