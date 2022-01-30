/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:53:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:25:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

class WrongAnimal {
	protected:
	std::string type_;

	public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& ref);
	WrongAnimal& operator=(const WrongAnimal& ref);
	~WrongAnimal();

	void setType(std::string type);
	std::string getType(void) const;

	void makeSound(void) const;
};

#endif
