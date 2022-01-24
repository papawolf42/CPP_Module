/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:31:31 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/23 23:24:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef contact_HPP
# define contact_HPP

#include <string>

class contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

	public:
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetPhoneNumber();
		std::string GetDarkestSecret();
		void		SetFirstName();
		void		SetLastName();
		void		SetNickName();
		void		SetPhoneNumber();
		void		SetDarkestSecret();
};

#endif
