/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:23:58 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 15:16:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
	Brain* brain_;

	public:
	Dog();
	Dog(const Dog& ref);
	Dog& operator=(const Dog& ref);
	~Dog();

	void makeSound(void) const;
	void addIdea(std::string idea);
	std::string getIdea(unsigned int idx) const;
};

#endif
