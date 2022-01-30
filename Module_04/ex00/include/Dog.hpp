/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:23:58 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 03:01:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	~Dog();

	void makeSound(void) const;
};

#endif
