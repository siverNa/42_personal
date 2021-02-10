# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 14:36:37 by sna               #+#    #+#              #
#    Updated: 2021/02/10 15:29:00 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
LIBFT 		= libft
LIBFT_LIB 	= libft.a

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar rcs
RM 			= rm -f

SRCS 		= ft_printf.c ft_printf_char.c ft_printf_string.c\
			  ft_printf_number.c ft_printf_util.c

OBJS 		= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean : 
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re libft
