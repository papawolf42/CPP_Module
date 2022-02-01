/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:58:04 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 17:22:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <exception>

class Intern {
	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();

		Intern& operator=(const Intern& ref);

		Form*	makeForm(const std::string form_name, const std::string form_target);

		class InvalideFormException : public std::exception {
			public:
				const char* what() const throw();	
		};
};

#endif
