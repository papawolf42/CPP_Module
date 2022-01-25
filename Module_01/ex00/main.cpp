/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:51:36 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 00:08:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie ma("Ma Dongsuck");

	ma.announce();
	Zombie* Ahn = ma.newZombie("Ahn sohee");
	Ahn->announce();
	Ahn->randomChump("Gong you");
	delete Ahn;
}
