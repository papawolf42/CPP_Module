# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:27:51 by gunkim            #+#    #+#              #
#    Updated: 2022/02/04 03:33:16 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := span

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

DIR_INC     := include
DIR_OBJ     := obj
DIR_SRC     := src

INCLUDE     := -I$(DIR_INC)

SRCS		:= main.cpp span.cpp

OBJS		:= $(addprefix $(DIR_OBJ)/, $(SRCS:.cpp=.o))
DEPS        := $(SRCS:.cpp=.d)

vpath %.c $(DIR_SRC)

.PHONY: all clean fclean re test

$(NAME) : $(DIR_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $@

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

clean :
	$(RM) $(OBJS) $(DIR_OBJ) dep
	
fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : dep

dep : $(DEPS)

%.d : $(DIR_SRC)/%.cpp
	$(CXX) $(INCLUDE) -MM $< | sed 's|^|$(DIR_OBJ)/|' | sed 's|$(DIR_OBJ)/  ||' >> dep

# DO NOT DELETE 

obj/main.o: src/main.cpp include/span.hpp
obj/span.o: src/span.cpp include/span.hpp
