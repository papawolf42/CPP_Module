/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:59:09 by gunkim            #+#    #+#             */
/*   Updated: 2022/02/02 22:04:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>//uintptr_t

typedef struct s_intra {
	char	nickname[9];
	int		blackhole;
	int		wallet;
} Data;

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif
