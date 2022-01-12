/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:55:07 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/12 23:26:17 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Megaphone {
	private:
		char **my_word;
	public:
		Megaphone(char **_my_word) {
			my_word = _my_word;
		}
		void Capitalize() {
			for (int i = 1; my_word[i]; i++) {
				for (int j = 0;my_word[i][j] != '\0'; j++) {
					if ('a' <= my_word[i][j] && my_word[i][j] <= 'z')
						my_word[i][j] = my_word[i][j] - 'a' + 'A';
				}
			}
		}
		void yell() {
			for (int i = 1; my_word[i]; i++) {
				std::cout << my_word[i];
			}
			std::cout << std::endl;
		}
};

int main(int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		Megaphone have_to_say(argv);
		have_to_say.Capitalize();
		have_to_say.yell();
	}
	return (0);
}
