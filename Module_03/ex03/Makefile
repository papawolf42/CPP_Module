# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:27:51 by gunkim            #+#    #+#              #
#    Updated: 2022/01/29 17:44:48 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := Now_it_is_weird!

CXX         := c++
CXXFLAGS    := -Wno-shadow -Wall -Wextra -Werror -std=c++98
# CXXFLAGS    := -fsanitize=address -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

SRCS		:= main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp

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
