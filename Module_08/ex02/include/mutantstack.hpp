/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:12:21 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:36:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {}
		MutantStack(const MutantStack<T>& ref)
		: MutantStack<T>::stack(ref) {}
		~MutantStack(void) {}

		MutantStack<T>& operator=(const MutantStack<T>& ref) {
			MutantStack<T>::stack::operator=(ref);
			return *this;
		}

		typedef typename MutantStack<T>::container_type::iterator iterator;
		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin(void) {
			return this->c.begin();
		}
		iterator	end(void) {
			return this->c.end();
		}
		reverse_iterator	rbegin(void) {
			return this->c.rbegin();
		}
		reverse_iterator	rend(void) {
			return this->c.rend();
		}
		const_iterator	cbegin(void) {
			return this->c.cbegin();
		}
		const_iterator	cend(void) {
			return this->c.cend();
		}
		const_reverse_iterator	crbegin(void) {
			return this->c.crbegin();
		}
		const_reverse_iterator	crend(void) {
			return this->c.crend();
		}
};

#endif
