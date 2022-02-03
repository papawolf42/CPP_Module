/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 03:23:47 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/04 03:26:47 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	try
	{
		std::vector<int>			vec;
		std::vector<int>::iterator	iter;

		vec.push_back(-42);
		vec.push_back(0);
		vec.push_back(42);
		vec.push_back(4242);

		iter = easyfind(vec, 42);
		std::cout << *iter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
