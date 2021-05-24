# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 22:15:43 by sna               #+#    #+#              #
#    Updated: 2021/05/24 12:38:43 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

SRCS =		check_map_identifier.c check_map.c check_sprite.c cub3d_util.c \
			cub3d.c draw_game.c get_next_line.c input_key.c raycast.c \
			read_map.c save_bmp.c set_map_identifier.c

OBJS =		$(SRCS:.c=.o)

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		-L./libft -lft
MLX =		-lm -lmlx
OPENGL =	-framework OpenGL -framework Appkit

$(NAME) :	$(OBJS)
			$(MAKE) bonus -C ./libft
			gcc $(OBJS) $(CFLAGS) -I . $(MLX) $(LIBFT) $(OPENGL) -o $(NAME)

all :		$(NAME)

clean :		
			rm -rf $(OBJS)
			$(MAKE) clean -C ./libft

fclean :	clean
			rm -rf $(NAME)
			rm -rf save_screen.bmp
			$(MAKE) fclean -C ./libft

re :		fclean all

.PHONY :	all clean fclean re libft
