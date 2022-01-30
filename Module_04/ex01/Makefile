# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:27:51 by gunkim            #+#    #+#              #
#    Updated: 2022/01/30 16:12:32 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := I_do_not_want_to_set_the_world_on_fire

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

DIR_INC     := include
DIR_OBJ     := obj
DIR_SRC     := src

INCLUDE     := -I$(DIR_INC)

SRCS		:= main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \
	Brain.cpp

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
	$(RM) $(OBJS) $(DIR_OBJ)
	
fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY : dep

dep : $(DEPS)

%.d : $(DIR_SRC)/%.cpp
	$(CXX) $(INCLUDE) -MM $< | sed 's|^|$(DIR_OBJ)/|' | sed 's|$(DIR_OBJ)/  ||' >> depend_file

# DO NOT DELETE 
obj/main.o: src/main.cpp include/Animal.hpp include/Dog.hpp include/Cat.hpp \
include/WrongAnimal.hpp include/WrongCat.hpp
obj/Animal.o: src/Animal.cpp include/Animal.hpp
obj/Dog.o: src/Dog.cpp include/Dog.hpp include/Animal.hpp
obj/Cat.o: src/Cat.cpp include/Cat.hpp include/Animal.hpp
obj/WrongAnimal.o: src/WrongAnimal.cpp include/WrongAnimal.hpp \
include/Animal.hpp
obj/WrongCat.o: src/WrongCat.cpp include/WrongCat.hpp include/WrongAnimal.hpp \
include/Animal.hpp