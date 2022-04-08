# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:09:02 by sna               #+#    #+#              #
#    Updated: 2022/04/08 17:26:48 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
G3			= -g3 -fsanitize=address

SRCS		= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

%.o:		%.cpp
			$(CC) $(CFLAGS) -I . -o $@ -c $< 

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re