# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:23:33 by ekocak            #+#    #+#              #
#    Updated: 2023/09/17 18:12:11 by ekocak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------- VARS ----------------------------------

NAME		=	ex02

SRC			=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \

OBJS		=	$(SRC:.cpp=.o)

COMPILE		=	g++

FLAGS		=	-Wall -Wextra -Werror -std=c++98 

EXE_NAME	=	-o $(NAME)

EXEC		=	$(NAME)

FILES		=	shrub \

# ------------------------------------- RULES ---------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) $(EXE_NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJS) Street_shrubbery.txt

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(FILES)
	
re:	fclean all

.cpp.o:
	${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY:	all clean fclean re run