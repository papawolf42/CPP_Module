/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:28:39 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/25 23:59:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
	private:
	std::string	name_;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);	
};
