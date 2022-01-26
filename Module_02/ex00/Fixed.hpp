/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:48:40 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 07:27:24 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
	int value_;
	static const int fractional_bit_ = 8;

	public:
	Fixed();
	Fixed(const Fixed& ref);//복사 생성자, 역시 const를 인자로 써주네
	Fixed& operator=(const Fixed& ref);//대입 연산자 오버로딩, const 써주는 게 인상적
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
