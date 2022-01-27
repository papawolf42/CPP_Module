/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:35:55 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 01:38:55 by gunkim           ###   ########.fr       */
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
	Fixed(const int val);
	Fixed(const float val);
	Fixed& operator=(const Fixed& ref);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& ref) const;
	bool operator<(const Fixed& ref) const;
	bool operator>=(const Fixed& ref) const;
	bool operator<=(const Fixed& ref) const;
	bool operator==(const Fixed& ref) const;
	bool operator!=(const Fixed& ref) const;

	Fixed operator+(const Fixed& ref) const;
	Fixed operator-(const Fixed& ref) const;
	Fixed operator*(const Fixed& ref) const;
	Fixed operator/(const Fixed& ref) const;

	// 전위 후위 증감 연산자 오버로딩
	// 전위 후위 구분은 컴파일러에서 인자가 없는가, int인가로 구별함.
	// 리턴값 : 전위는 리턴값이 이미 증가한 상태로 리턴
	// 리턴값 : 후위는 
	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream&out, const Fixed& ref);
// 출력 연산자

#endif
