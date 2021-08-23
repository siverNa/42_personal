# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 18:07:34 by sna               #+#    #+#              #
#    Updated: 2021/08/23 19:37:14 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		-L./libft -lft

SRCS =		pw_main.c build_deque.c deque_func.c swap_func.c perform.c \
			quick_sort.c perform_sec.c perform_third.c \
			perform_four.c push_util.c

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