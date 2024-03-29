/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:37:15 by sna               #+#    #+#             */
/*   Updated: 2021/08/23 18:03:00 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define TRUE		1
# define FALSE		0
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_deque
{
	int				size;
	int				top;
	t_node			*head;
	t_node			*tail;
}					t_deque;

/*
** deque_func.c
*/
int					dq_remove_last(t_deque *d);
int					dq_remove_first(t_deque *d);
void				dq_add_last(t_deque *d, int data);
int					dq_is_empty(t_deque *d);
void				deque_init(t_deque *d);
/*
** build_deque.c
*/
void				print_error(void);
int					check_overlap(t_deque *q, int ac);
int					check_number(char **av);
void				lst_addend(char *str, t_deque *a, int *j);
void				build_deque(t_deque *a, t_deque *b, int ac, char **av);
/*
** swap_func.c
*/
void				rev_rotate(t_node **head, t_node **tail, char c);
void				rotate(t_node **head, t_node **tail, char c);
void				swap(t_node **head, char c);
void				push(t_deque *from, t_deque *to, char c);
/*
** perform.c
*/
int					a_is_sorted(t_deque *a);
void				simply_number_sec(int *temp, int *copy, int n);
void				simply_number(t_deque *a, int *copy_arr, int n);
void				perform_over_five(t_deque *a, t_deque *b, int size);
int					push_swap(t_deque *a, t_deque *b, int size);
/*
** perform_sec.c
*/
int					search_min(int *arr, int size);
void				dec_to_arr(t_node *temp, int *arr, int size);
void				perform_five(t_deque *a, t_deque *b, int size);
void				perform_four(t_deque *a, t_deque *b, int size);
void				perform_three(t_deque *a, int size);
/*
** perform_third.c
*/
void				overlap_four(t_deque *a, t_deque *b, int size);
void				overlap_three(t_deque *a, t_deque *b, int size);
void				four_more_two(t_deque *a, t_deque *b, int min);
void				four_less_two(t_deque *a, t_deque *b, int *arr, int min);
/*
** perform_four.c
*/
void				five_more_two(t_deque *a, t_deque *b, int min);
void				five_less_two(t_deque *a, t_deque *b, int *arr, int min);
/*
** quick_sort.c
*/
void				quick_swap(int *arr, int a, int b);
int					partition(int *arr, int left, int right);
void				quicksort(int *arr, int left, int right);
void				sort(t_deque *a, int *arr, int n);
/*
**  push_util.c
*/
int					int_malloc(int **arr, int size);
int					ft_atoi_pw(char *str, int *i);
char				**ft_free_pw(char **new_str);
int					ft_str_isdigit(char *c);
void				insert_a_deq(t_deque *a, char **av, int ac);

#endif
