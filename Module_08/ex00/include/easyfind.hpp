/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:24:18 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:42:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class EasyfindException : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return "cannot be found!";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int val) {
	typename T::iterator	temp = std::find(container.begin(), container.end(), val);
	if (temp == container.end())
		throw EasyfindException();
	return temp;
}

#endif
