/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:33:14 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/03 09:56:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void) {
	int a = 2;
	int b = 3;

	::swap( a,b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a,b ) = " << ::min( a,b ) << std::endl;
	std::cout << "max( a,b ) = " << ::max( a,b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap( c,d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c,d ) = " << ::min( c,d ) << std::endl;
	std::cout << "max( c,d ) = " << ::max( c,d ) << std::endl;

	std::string e = "42.42";
	std::string f = "42.4242";

	::swap( e,f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e,f ) = " << ::min( e,f ) << std::endl;
	std::cout << "max( e,f ) = " << ::max( e,f ) << std::endl;

	return (0);
}
