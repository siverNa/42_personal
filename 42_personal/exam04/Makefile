NAME		= microshell

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
G3			= -g3 -fsanitize=address

SRCS		= microshell.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I . -o $@ -c $< 

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:
			make fclean
			make all

.PHONY:		all clean fclean re