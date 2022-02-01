/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:50:47 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/01 10:51:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>

class RobotomyRequestForm : public Form {
	private:
		std::string target_;

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

		std::string getTarget() const;

		void  execute(const Bureaucrat& executor) const;
};

#endif
