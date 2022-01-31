/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:53:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 08:16:05 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& ref);

		std::string	getName() const;
		int			getGrade() const;

		void		upGrade(int up);
		void		downGrade(int down);
		void		signForm(Form& form);
		void		executeForm(Form const & form);

		class GradeTooHighException : public std::exception {
			private:
				const char* msg_;
			public:
				GradeTooHighException(void);
				GradeTooHighException(const char *msg);
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				const char* msg_;
			public:
				GradeTooLowException(void);
				GradeTooLowException(const char *msg);
				const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif
