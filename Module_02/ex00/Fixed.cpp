/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:48:40 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 07:15:36 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) : value_(ref.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

// 대입 연산자 오버로딩
// 오직 멤버 함수로만 구현 가능함. 전역함수로 구현이 제한됨.
Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "Assignation operator called" << std::endl;
	value_ = ref.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// const를 멤버 함수 오른쪽에 써주면
// 상수함수로 선언된다.
// 다른 변수의 값을 바꾸지 않고, 읽기만 가능.
// 함수 내 호출할 수 있는 함수도 상수함수 뿐.
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value_);
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}
