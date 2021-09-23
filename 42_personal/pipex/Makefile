# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 18:05:57 by sna               #+#    #+#              #
#    Updated: 2021/09/23 19:13:54 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		-L./libft -lft

SRCS =		pipex.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@$(MAKE) bonus -C ./libft
			$(CC) $^ $(CFLAGS) -I . $(LIBFT) -o $@

all:		$(NAME)

clean:
			rm -rf $(OBJS)
			@$(MAKE) clean -C ./libft

fclean: 	clean
			rm -f $(NAME)
			@$(MAKE) fclean -C ./libft

re: 		fclean all

.PHONY:		all clean fclean re