/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:50:01 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/26 04:16:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	std::string type_;
	
	public:
	Weapon();
	Weapon(std::string type);
	
	const std::string& getType();
	void setType(std::string type);
};

#endif
