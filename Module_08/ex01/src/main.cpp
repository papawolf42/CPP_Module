/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:28:10 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:32:11 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl << "----- exception test -----" << std::endl;

	Span	sp2(1);

	sp2.addNumber(0);
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		sp2.addNumber(10);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "----- 10000 test -----" << std::endl;

	Span	sp3(10000);

	for (unsigned int i = 0; i < sp3.getSize(); i++) {
		sp3.addNumber(i);
	}
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	std::cout << std::endl;

	Span	sp4(10000);

	try {
		sp4.addNumber(0, 10000);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
