/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:37:15 by sna               #+#    #+#             */
/*   Updated: 2021/06/24 17:42:57 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define TRUE       1
# define FALSE      0
# define INT_MAX    2147483647
# define INT_MIN    (-INT_MAX - 1)

typedef struct      s_node
{
    int             data;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;

typedef struct      s_deque
{
    int             size;
    int             top;
    t_node          *head;
    t_node          *tail;
}                   t_deque;

/*
** deque_func.c
*/
int                 dq_get_last(t_deque *d);
int                 dq_get_first(t_deque *d);
int                 dq_remove_last(t_deque *d);
int                 dq_remove_first(t_deque *d);
void                dq_add_last(t_deque *d, int data);
void                dq_add_first(t_deque *d, int data);
void                dq_add_first(t_deque *d, int data);
int                 dq_is_empty(t_deque *d);
void                deque_init(t_deque *d);

/*
** build_deque.c
*/
void                print_error();
int                 check_overlap(t_deque *q, int ac);
int                 check_number(int ac, char **av);
void                lst_addend(char *str, t_deque *a);
void                build_deque(t_deque *a, t_deque *b, int ac, char **av);

#endif