/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:04:07 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 07:13:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name_;
		bool				signed_;
		const int			sign_grade_;
		const int			execute_grade_;

	public:
		Form();
		Form(std::string name, int sign_grade, int execute_grade);
		Form(const Form& ref);
		virtual ~Form();

		Form& operator=(const Form& ref);

		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;

		void			beSigned(const Bureaucrat& signer);
		virtual void	execute(const Bureaucrat& executor) const = 0;

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
		class FormNotSignedException : public std::exception {
			private:
				const char* msg_;
			public:
				FormNotSignedException(void);
				FormNotSignedException(const char *msg);
				const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif
