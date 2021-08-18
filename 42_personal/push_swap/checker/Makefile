# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 13:32:20 by sna               #+#    #+#              #
#    Updated: 2021/08/18 16:45:33 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		checker

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		-L../libft -lft
G3 =		-g3 -fsanitize=address

SRCS =		checker_main.c checker_perform.c ../swap_func.c ../perform.c \
			../get_next_line/get_next_line.c \
			../get_next_line/get_next_line_utils.c ../push_util.c \
			../deque_func.c ../build_deque.c ../perform_sec.c ../perform_third.c \
			../perform_four.c

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@$(MAKE) bonus -C ../libft
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