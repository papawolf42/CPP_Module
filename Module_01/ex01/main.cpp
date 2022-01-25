/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:51:36 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 02:18:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	int num = 4;

	Zombie* horde = zombieHorde(num, "Diablo");

	for (int i = 0; i < num; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
}
