/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_perform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:06:31 by sna               #+#    #+#             */
/*   Updated: 2021/08/20 22:10:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_perform(char *line, t_deque *a, t_deque *b)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(&a->head, 'n');
		return ;
	}
	if (!ft_strcmp(line, "sb"))
	{
		swap(&b->head, 'n');
		return ;
	}
	swap(&a->head, 'n');
	swap(&b->head, 'n');
}

void	rotate_perform(char *line, t_deque *a, t_deque *b)
{
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&a->head, &a->tail, 'n');
		return ;
	}
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&b->head, &b->tail, 'n');
		return ;
	}
	rotate(&a->head, &a->tail, 'n');
	rotate(&b->head, &b->tail, 'n');
}

void	rev_rotate_perform(char *line, t_deque *a, t_deque *b)
{
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&a->head, &a->tail, 'n');
		return ;
	}
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&b->head, &b->tail, 'n');
		return ;
	}
	rev_rotate(&a->head, &a->tail, 'n');
	rev_rotate(&b->head, &b->tail, 'n');
}
