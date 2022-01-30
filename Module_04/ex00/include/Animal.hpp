/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:53:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:29:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>

enum {
	WidthClassName = 14
};

class Animal {
	protected:
	std::string type_;

	public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& ref);
	Animal& operator=(const Animal& ref);
	virtual ~Animal();

	void setType(std::string type);
	std::string getType(void) const;

	virtual void makeSound(void) const;
};

#endif
