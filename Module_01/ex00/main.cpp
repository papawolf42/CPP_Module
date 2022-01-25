/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:51:36 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 00:17:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie ma("Ma Dongsuck");
	ma.announce();

	Zombie* ahn = newZombie("Ahn sohee");
	ahn->announce();
	
	randomChump("Gong you");
	delete ahn;
	return (0);
}
