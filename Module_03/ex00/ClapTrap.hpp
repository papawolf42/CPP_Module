/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:55:55 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 08:07:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
	std::string name_;
	int hit_point_;
	int energy_point_;
	int attack_damage_;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ref);
	ClapTrap& operator=(const ClapTrap& ref);
	~ClapTrap();

	void setName(std::string name);
	void setHitPoint(int hit_point);
	void setEnergyPoint(int energy_point);
	void setAttackDamage(int attack_damage);

	std::string getName(void);
	int getHitPoint(void);
	int getEnergyPoint(void);
	int getAttackDamage(void);
	
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
