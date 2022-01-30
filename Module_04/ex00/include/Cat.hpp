/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:09:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:30:53 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
	Cat();
	Cat(const Cat& ref);
	Cat& operator=(const Cat& ref);
	~Cat();

	void makeSound(void) const;
};

#endif
