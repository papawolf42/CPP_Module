/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:29:33 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:31:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void)
	: _nums(0), _size(0), _fill(0) {}

Span::Span(unsigned int n)
	: _nums(n), _size(n), _fill(0) {}

Span::Span(const Span& ref)
	: _nums(ref._nums), _size(ref._size), _fill(ref._fill) {}

Span::~Span(void) {}

Span&	Span::operator=(const Span& ref) {
	_nums = ref._nums;
	_size = ref._size;
	_fill = ref._fill;
	return *this;
}

unsigned int	Span::getSize(void) {
	return _size;
}

void	Span::addNumber(int num) {
	if (_size < _fill + 1)
		throw SpanException("Span is full-filled!");
	else {
		_nums.at(_fill) = num;
		_fill++;
	}
}

void	Span::addNumber(unsigned int begin, unsigned int end)
{
	if (begin > _size || end > _size)
		throw SpanException("It is out of range!");
	else {
		srand((unsigned int)time(NULL));
		for (unsigned int i = begin; i < end; i++) {
			_nums.at(i) = rand();
			_fill++;
		}
	}
}

int	Span::shortestSpan(void) {
	if (_fill <= 1)
		throw SpanException("Number is not enough!");
	int	ret = INT_MAX;
	int	temp;
	for (unsigned int i = 0; i < _fill; i++) {
		for (unsigned int j = i + 1; j < _fill; j++) {
			if (_nums.at(i) > _nums.at(j))
				temp = _nums.at(i) - _nums.at(j);
			else
				temp = _nums.at(j) - _nums.at(i);
			if (temp < ret)
				ret = temp;
		}
	}
	return ret;
}

int	Span::longestSpan(void) {
	if (_fill <= 1)
		throw SpanException("Number is not enough!");
	std::sort(_nums.begin(), _nums.end());
	int	min = _nums.at(0);
	int	max = _nums.at(getSize() - 1);

	return (max - min);
}

Span::SpanException::SpanException(std::string msg)
: _msg(msg) {}

Span::SpanException::~SpanException(void) throw() {}

const char*	Span::SpanException::what(void) const throw() {
	return _msg.c_str();
}
