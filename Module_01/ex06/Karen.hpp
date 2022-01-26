/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:54:35 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 04:00:34 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen {
	enum {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (Karen::*pf_[4])();
	std::string level_table_[4];

	public:
	Karen();
	void complain(std::string level);
};


#endif
