/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:51:40 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/10 20:57:54 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace
{
	int	OnlyInThisFile() {}
	// int	only_in_this_file = 0;
}

int	main()
{
	// OnlyInThisFile();
	only_in_this_file = 1;

	std::cout << "is this real???" << std::endl;
	std::cout << "what number I chosen is " << only_in_this_file << std::endl;
}