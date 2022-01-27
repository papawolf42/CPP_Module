/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:35:55 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 04:33:35 by gunkim           ###   ########.fr       */
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

	Fixed& operator++(void);
	Fixed& operator--(void);
	const Fixed operator++(int);
	const Fixed operator--(int);

	static Fixed& min(Fixed& ref1, Fixed& ref2);
	static const Fixed& min(const Fixed& ref1, const Fixed& ref2);
	static Fixed& max(Fixed& ref1, Fixed& ref2);
	static const Fixed& max(const Fixed& ref1, const Fixed& ref2);
};

std::ostream& operator<<(std::ostream&out, const Fixed& ref);
// 출력 연산자

#endif
