/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:17:31 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/30 11:31:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	WrongCat();
	WrongCat(const WrongCat& ref);
	WrongCat& operator=(const WrongCat& ref);
	~WrongCat();

	void makeSound(void) const;
};

#endif
