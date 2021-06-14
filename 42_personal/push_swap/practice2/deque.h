#ifndef DEQUE_H
# define DEQUE_H

# include <unistd.h>
# include <stdlib.h>
# define    TRUE    1
# define    FALSE   0

typedef int         Data; //이렇게 써도 norm에 안걸리는지?

typedef struct      s_node
{
    Data            data;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct      s_deque
{
    t_node          *head;
    t_node          *tail;
}                   t_deque;

Data                dq_get_last(t_deque *d);
Data                dq_get_first(t_deque *d);
Data                dq_remove_last(t_deque *d);
Data                dq_remove_first(t_deque *d);
void                dq_add_last(t_deque *d, Data data);
void                dq_add_first(t_deque *d, Data data);
void                dq_add_first(t_deque *d, Data data);
int                 dq_is_empty(t_deque *d);
void                deque_init(t_deque *d);

#endif