/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 07:56:47 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 01:03:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	value_ = val << fractional_bit_;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	value_ = roundf(val * (1 << fractional_bit_));
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "Assignation operator called" << std::endl;
	value_ = ref.value_;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value_);
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}

float Fixed::toFloat(void) const {
	return ((float)value_ / (1 << fractional_bit_));
}

int Fixed::toInt(void) const {
	return (value_ >> fractional_bit_);
}

std::ostream& operator<<(std::ostream&out, const Fixed& ref) {
	out << ref.toFloat();
	return (out);
}
