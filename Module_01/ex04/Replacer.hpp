/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:57:34 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/27 00:01:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include <iostream>
#include <fstream>

enum {
	ERROR = 1
};

class Replacer {
	private:
	std::ifstream infile_;
	std::ofstream outfile_;

	public:
	Replacer();

	int checkEmpty(std::string filename, std::string s1, std::string s2);
	int openInfile(std::string filename);
	int openOutfile(std::string filename);
	void replace(std::string s1, std::string s2);
	void close();
};

#endif
