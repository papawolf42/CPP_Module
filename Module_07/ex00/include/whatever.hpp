/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:47:50 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 09:54:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T& a, T& b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T& max(T& a, T& b) {
	if (a > b)
		return (a);
	return (b);
}

#endif
