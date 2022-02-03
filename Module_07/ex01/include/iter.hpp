/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:58:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 11:49:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* array, int size, void (*ptr)(T&)) {
	for (int i = 0; i < size; i++) {
		ptr(array[i]);
	}
}

template <typename T>
void print(T& ref) {
	std::cout << ref << " ";
}

template <typename T>
void addOne(T& a) {
	a++;
}

template <typename T>
void subOne(T& a) {
	a--;
}

#endif
