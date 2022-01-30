/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:53:29 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/31 05:26:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string name_;
		int grade_;//1 ~ 150

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& ref);

		std::string getName() const;
		int getGrade() const;

		void upGrade(int up);
		void downGrade(int down);

		class GradeTooHighException : public std::exception {
			public://exception에 정의된 가상함수 what(), override, noexcept는 c++11부터 사용가능.
				const char* what() const throw();//throw() 는 c++20부터 제거
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();	
		};//클래스 정의 내에 예외 클래스 선언으로, 예외들을 클래스 내로 병합시킬 수 있음.
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif
