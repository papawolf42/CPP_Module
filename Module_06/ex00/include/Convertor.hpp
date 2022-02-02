/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:36:14 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 20:19:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

# include <iostream>
# include <cctype>//isdigit, isalpha
# include <cmath>//isnan, isinf

class Convertor {
	enum {
		typeChar,
		typeNum,
		typeInvalid
	};

	private:
		std::string			literal_;
		double				value_;
		int					type_;
		bool				is_nan_;
		bool				is_inf_;

	public:
		Convertor();
		Convertor(const std::string literal);
		Convertor(const Convertor& ref);
		virtual ~Convertor();

		Convertor& operator=(const Convertor& ref);

		std::string		getLiteral() const;

		void		toChar(void);
		void		toInt(void);
		void		toFloat(void);
		void		toDouble(void);

		void		printForm(void);

		class GeneralException : public std::exception {
			private:
				const char* msg_;
			public:
				GeneralException(void);
				GeneralException(const char *msg);
				const char* what() const throw();	
		};
		class ImpossibleConvertableException : public std::exception {
				const char* what() const throw();	
		};
		class NonDisplayableException : public std::exception {
				const char* what() const throw();	
		};
		
};

#endif
