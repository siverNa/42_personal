# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 16:09:42 by sna               #+#    #+#              #
#    Updated: 2021/12/01 21:36:33 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
PTHREAD =	-lpthread

SRCS =		philo_main.c philo_util.c philo_pars.c philo_start.c philo_time.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $^ $(CFLAGS) $(PTHREAD) -o $@

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re