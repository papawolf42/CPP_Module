# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 22:55:03 by gunkim            #+#    #+#              #
#    Updated: 2022/01/12 23:38:38 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := megaphone

CPP         := c++
CPPFLAGS    := -Wall -Wextra -Werror

RM          := rm -rf

.PHONY: all clean re test

$(NAME) : megaphone.cpp
	$(CPP) $(CPPFLAGS) $^ -o $@

test : megaphone.cpp
	$(CPP) $(CPPFLAGS) $^ -o test.out

clean :
	$(RM) $(NAME)

re : clean $(NAME)