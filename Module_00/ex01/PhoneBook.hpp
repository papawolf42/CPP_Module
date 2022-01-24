/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:38:16 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/24 20:52:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
	enum {
		maxContact = 8,
		maxWidth = 10
	};
	
	private:
		size_t	idx_;
		contact	contact_[maxContact];

	public:
		PhoneBook();
		void	Add();
		void	Search();
		void	SearchDisplayHead();
		void	SearchDisplayRow(size_t i);
		void	SearchDisplayColumn(std::string content);
		void	SearchDisplayDivider();
		void	SearchIndex();
};

#endif
