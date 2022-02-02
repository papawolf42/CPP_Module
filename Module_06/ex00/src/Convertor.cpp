/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 05:03:58 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 20:47:23 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"


Convertor::Convertor() { }
Convertor::Convertor(const std::string literal) : literal_(literal) {
	value_ = atof(literal_.c_str());
	if (literal.length() == 1 && value_ <= 255) {
		type_ = typeChar;
	} else if (value_ == 0 && literal_.find('0', 0) == std::string::npos) {
		type_ = typeInvalid;
	} else {
		type_ = typeNum;
	}
	if (type_ == typeNum) {
		is_nan_ = isnan(value_);
		if (literal == "nan") {
			is_nan_ = true;
		}
		is_inf_ = isinf(value_);
		if (literal == "inf" || literal == "+inf" || literal == "-inf") {
			is_inf_ = true;
		}
	}
}
Convertor::Convertor(const Convertor& ref) : literal_(ref.literal_), value_(ref.value_), type_(ref.type_) { }
Convertor::~Convertor() { }

Convertor& Convertor::operator=(const Convertor& ref) {
	literal_ = ref.literal_;
	value_ = ref.value_;
	type_ = ref.type_;
	return (*this);
}

std::string Convertor::getLiteral() const {
	return (literal_);
}

void Convertor::toChar(void) {
	char print = static_cast<char>(value_);
	if (type_ == typeChar) {
		std::cout << literal_[0];
		return ;
	} else if (type_ == typeInvalid || is_nan_ == true || is_inf_ == true || value_ < 0 || value_ > 255) {
		throw ImpossibleConvertableException();
	} else if (print < 32 || 126 < print) {
		throw NonDisplayableException();
	}
	std::cout << "'" << print << "'";
}
void Convertor::toInt(void) {
	long print = static_cast<long>(value_);
	if (type_ == typeInvalid || is_nan_ == true || is_inf_ == true || value_ < INT_MIN || value_ > INT_MAX)
		throw ImpossibleConvertableException();
	else if (type_ == typeChar) {
		std::cout << static_cast<short>(literal_[0]);
		return ;
	}
	std::cout << print;
}
void Convertor::toFloat(void) {
	double value = value_;
	if (type_ == typeInvalid)
		throw ImpossibleConvertableException();
	else if (is_nan_ == true)
		throw GeneralException("nanf");
	else if (is_inf_ == true && value_ < 0)
		throw GeneralException("-inff");
	else if (is_inf_ == true)
		throw GeneralException("+inff");
	else if (type_ == typeChar)
		value = static_cast<float>(literal_[0]);

	float print = static_cast<float>(value);
	if (print - static_cast<int>(value) == 0.0f)
		std::cout << print << ".0f";
	else
		std::cout << print << "f";
}
void Convertor::toDouble(void) {
	double value = value_;
	if (type_ == typeInvalid)
		throw ImpossibleConvertableException();
	else if (is_nan_ == true)
		throw GeneralException("nan");
	else if (is_inf_ == true && value_ < 0)
		throw GeneralException("-inf");
	else if (is_inf_ == true)
		throw GeneralException("+inf");
	else if (type_ == typeChar)
		value = static_cast<double>(literal_[0]);

	if (value - static_cast<int>(value) == 0.0)
		std::cout << value << ".0";
	else
		std::cout << value;
}

Convertor::GeneralException::GeneralException() {
	msg_ = "ERROR HAS OCCURED!";
}
Convertor::GeneralException::GeneralException(const char* msg) {
	msg_ = msg;
}
const char* Convertor::GeneralException::what() const throw() {
	return (msg_);
}
const char* Convertor::ImpossibleConvertableException::what() const throw() {
	return ("impossible");
}
const char* Convertor::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}
