# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 21:09:02 by sna               #+#    #+#              #
#    Updated: 2022/04/10 17:39:50 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Iter

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f
G3			= -g3 -fsanitize=address

SRCS		= main.cpp

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