/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:37:15 by sna               #+#    #+#             */
/*   Updated: 2021/07/19 18:51:15 by sna              ###   ########.fr       */
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
/*
** swap_func.c
*/
void	            rev_rotate(t_node **head, t_node **tail, char c);
void	            rotate(t_node **head, t_node **tail, char c);
void	            swap(t_node **tail, char c);
void                push(t_node **from, t_node **to, t_node **to_end);
/*
** perform.c
*/
int                 a_is_sorted(t_deque *a);
void                simply_number_sec(int *temp, int *copy, int n);
void                simply_number(t_deque *a, int *copy_arr, int n);
void                perform(t_deque *a, t_deque *b, int size);
/*
** quick_sort.c
*/
void                quick_swap(int *arr, int a, int b);
int                 partition(int *arr, int left, int right);
void                quicksort(int *arr, int left, int right);
void                sort(t_deque *a, int *arr, int n);
/*
** test_swap_func.c
*/
void	            test_push(t_deque *a, t_deque *b, char c);

#endif