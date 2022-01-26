# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 06:17:16 by gunkim            #+#    #+#              #
#    Updated: 2022/01/27 03:37:04 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := karenFilter

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

SRCS		:= main.cpp Karen.cpp

OBJS		:= $(SRCS:.cpp=.o)

.PHONY: all clean fclean re test

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp %.hpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

test : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o test.out

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)
