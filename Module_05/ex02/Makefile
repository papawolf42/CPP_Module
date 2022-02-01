# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 21:27:51 by gunkim            #+#    #+#              #
#    Updated: 2022/02/01 10:52:39 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := 28B_not_28C

CXX         := c++
CXXFLAGS    := -g -Wall -Wextra -Werror -std=c++98

RM          := rm -rf

DIR_INC     := include
DIR_OBJ     := obj
DIR_SRC     := src

INCLUDE     := -I$(DIR_INC)

SRCS		:= main.cpp \
	Bureaucrat.cpp \
	Form.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp

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
	$(RM) $(OBJS) $(DIR_OBJ) *_shrubbery
	
fclean : clean
	$(RM) $(NAME) dep

re : fclean $(NAME)

.PHONY : dep

dep : $(DEPS)

%.d : $(DIR_SRC)/%.cpp
	$(CXX) $(INCLUDE) -MM $< | sed 's|^|$(DIR_OBJ)/|' | sed 's|$(DIR_OBJ)/  ||' >> dep

# DO NOT DELETE 

obj/main.o: src/main.cpp include/Bureaucrat.hpp include/Form.hpp \
include/ShrubberyCreationForm.hpp include/RobotomyRequestForm.hpp \
include/PresidentialPardonForm.hpp
obj/Bureaucrat.o: src/Bureaucrat.cpp include/Bureaucrat.hpp include/Form.hpp
obj/Form.o: src/Form.cpp include/Form.hpp include/Bureaucrat.hpp
obj/ShrubberyCreationForm.o: src/ShrubberyCreationForm.cpp \
include/ShrubberyCreationForm.hpp include/Form.hpp \
include/Bureaucrat.hpp
obj/RobotomyRequestForm.o: src/RobotomyRequestForm.cpp \
include/RobotomyRequestForm.hpp include/Form.hpp \
include/Bureaucrat.hpp
obj/PresidentialPardonForm.o: src/PresidentialPardonForm.cpp \
include/PresidentialPardonForm.hpp include/Form.hpp \
include/Bureaucrat.hpp
