/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:28:56 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/29 15:46:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& ref);
	FragTrap& operator=(const FragTrap& ref);
	~FragTrap();
		
	void highFivesGuys(void);
};

#endif
