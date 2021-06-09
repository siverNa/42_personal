#ifndef DEC_QUEUE
# define DEC_QUEUE

# include <unistd.h>
# include <stdlib.h>
# define TRUE			1
# define FALSE			0
# define ERROR			-1
# define MAX_DEQUE_SIZE	5

typedef struct	s_deque
{
	int	*data;
	int rear;
	int front;
}				t_deque;

int				init_deque(t_deque *q);
int				is_empty(t_deque *q);
int				get_rear(t_deque *q);
int				get_front(t_deque *q);
int				is_full(t_deque *q);
void			add_rear(t_deque *q, int data);
void			add_front(t_deque *q, int data);
int				delete_front(t_deque *q);
int				delete_rear(t_deque *q);
int				print_deque(t_deque *q);

#endif
