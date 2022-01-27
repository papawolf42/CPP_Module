/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:56:51 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 01:03:24 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
	int value_;
	static const int fractional_bit_ = 8;

	public:
	Fixed();
	Fixed(const Fixed& ref);
	Fixed(const int val);//추가: 생성자(정수 인자)
	Fixed(const float val);//추가: 생성자(부동소수점 인자)
	Fixed& operator=(const Fixed& ref);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;//추가: 부동소수점 리턴
	int toInt(void) const;//추가: 정수 리턴
};

std::ostream& operator<<(std::ostream&out, const Fixed& ref);
// 출력 연산자

#endif
