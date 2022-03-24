# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 01:22:09 by sna               #+#    #+#              #
#    Updated: 2022/03/25 01:12:16 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PhoneBook

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -I.
RM			= rm -f

SRCS		= Contact.cpp PhoneBook.cpp main.cpp
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