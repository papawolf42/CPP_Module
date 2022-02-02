/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:59:12 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 22:11:32 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main() {
	Data me = {"gunkim", 2, 89};
	std::cout << "address me      : " << &me << std::endl;
	
	uintptr_t addr = serialize(&me);
	std::cout << std::hex << "address uintptr : " << addr << std::endl;

	Data* ref = deserialize(addr);
	std::cout << "address ref     : " << ref << std::endl;

	std::cout << "nickname  : " << ref->nickname << std::endl;
	std::cout << "blackhole : " << ref->blackhole << std::endl;
	std::cout << "wallet    : " << ref->wallet << std::endl;
}
