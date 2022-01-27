/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:36:06 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/28 04:18:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a = Fixed();
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 21.21f ) * Fixed( 2 ) );
    Fixed d = Fixed::max(b, c);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( b, c ) << std::endl;
    std::cout << Fixed::min( b, c ) << std::endl;//추가해봄

    return (0);
}
