/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:31:13 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 10:50:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string target_;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

		std::string getTarget() const;

		void  execute(const Bureaucrat& executor) const;
};

#endif
