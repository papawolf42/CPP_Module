/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:36:01 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 04:19:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
}

Fixed::Fixed(const Fixed& ref) {
	*this = ref;
}

Fixed::Fixed(const int val) {
	value_ = val << fractional_bit_;
}

Fixed::Fixed(const float val) {
	value_ = roundf(val * (1 << fractional_bit_));
}

Fixed& Fixed::operator=(const Fixed& ref) {
	value_ = ref.value_;
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed& ref) const {
	return (value_ > ref.value_);	
}

bool Fixed::operator<(const Fixed& ref) const {
	return (value_ < ref.value_);	
}

bool Fixed::operator>=(const Fixed& ref) const {
	return (value_ >= ref.value_);	
}

bool Fixed::operator<=(const Fixed& ref) const {
	return (value_ <= ref.value_);	
}

bool Fixed::operator==(const Fixed& ref) const {
	return (value_ == ref.value_);	
}

bool Fixed::operator!=(const Fixed& ref) const {
	return (value_ != ref.value_);	
}

Fixed Fixed::operator+(const Fixed& ref) const {
	return (value_ + ref.value_);
}

Fixed Fixed::operator-(const Fixed& ref) const {
	return (value_ - ref.value_);
}

Fixed Fixed::operator*(const Fixed& ref) const {
	Fixed rtn(this->toFloat() * ref.toFloat());
	return (rtn);
}

Fixed Fixed::operator/(const Fixed& ref) const {
	Fixed rtn(this->toFloat() / ref.toFloat());
	return (rtn);
}

Fixed& Fixed::operator++(void) {
	value_ += 1;
	return (*this);
}
Fixed& Fixed::operator--(void) {
	value_ -= 1;
	return (*this);
}
const Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	value_ += 1;
	return (temp);
}
const Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	value_ -= 1;
	return (temp);
}

Fixed& Fixed::min(Fixed& ref1, Fixed& ref2) {
	if (ref1.toFloat() < ref2.toFloat()) {
		return (ref1);
	} else {
		return (ref2);
	}
}

const Fixed& Fixed::min(const Fixed& ref1, const Fixed& ref2) {
	if (ref1.toFloat() < ref2.toFloat()) {
		return (ref1);
	} else {
		return (ref2);
	}
}

Fixed& Fixed::max(Fixed& ref1, Fixed& ref2) {
	if (ref1.toFloat() > ref2.toFloat()) {
		return (ref1);
	} else {
		return (ref2);
	}
}

const Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2) {
	if (ref1.toFloat() > ref2.toFloat()) {
		return (ref1);
	} else {
		return (ref2);
	}
}

std::ostream& operator<<(std::ostream&out, const Fixed& ref) {
	out << ref.toFloat();
	return (out);
}
