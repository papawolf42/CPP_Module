/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 01:19:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class Karen {
	enum {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	private:
	// std::string level;
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public:
	void complain(std::string level);
};

#endif
