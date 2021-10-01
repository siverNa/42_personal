# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 18:05:57 by sna               #+#    #+#              #
#    Updated: 2021/10/01 21:39:27 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		pipex

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		-L./libft -lft
G3 =		-g3 -fsanitize=address

SRCS =		pipex.c pipex_process.c pipex_cmd_init.c pipex_cmd_case.c \
			pipex_build_path.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@$(MAKE) bonus -C ./libft
			$(CC) $^ $(CFLAGS) -I . $(LIBFT) -o $@ $(G3)

all:		$(NAME)

clean:
			rm -rf $(OBJS)
			@$(MAKE) clean -C ./libft

fclean: 	clean
			rm -f $(NAME)
			@$(MAKE) fclean -C ./libft

re: 		fclean all

.PHONY:		all clean fclean re