/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:29:23 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 02:17:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	std::stringstream ss;

	for (int i = 0; i < N; i++) {
		ss << (i + 1);
		horde[i].setName(name + ss.str());
		ss.str("");
	}//to_string은 c++11부터 support
	return (horde);
}
