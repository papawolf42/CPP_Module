/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:56:11 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 06:13:51 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	std::string name_;
	Weapon* weapon_;

	public:
	HumanB(std::string name);

	void attack();
	void setWeapon(Weapon& weapon);
};

#endif
