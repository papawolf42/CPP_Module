# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 22:55:03 by gunkim            #+#    #+#              #
#    Updated: 2022/01/24 21:17:24 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := megaphone

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

SRCS        := megaphone.cpp

OBJS        := $(SRCS:.cpp=.o)

.PHONY: all clean fclean re test

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o test.out

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean $(NAME)
