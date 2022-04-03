# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 15:13:22 by sna               #+#    #+#              #
#    Updated: 2022/04/03 17:27:17 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Animal

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
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