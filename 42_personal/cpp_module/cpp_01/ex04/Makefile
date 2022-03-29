# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:34:24 by sna               #+#    #+#              #
#    Updated: 2022/03/28 18:34:33 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= replace

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

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