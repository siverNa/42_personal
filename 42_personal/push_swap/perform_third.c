/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_third.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:09:26 by sna               #+#    #+#             */
/*   Updated: 2021/08/19 21:13:05 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overlap_four(t_deque *a, t_deque *b, int size)
{
	push(a, b, 'b');
	perform_four(a, b, size);
	push(b, a, 'a');
}

void	overlap_three(t_deque *a, t_deque *b, int size)
{
	push(a, b, 'b');
	perform_three(a, size);
	push(b, a, 'a');
}

void	four_more_two(t_deque *a, t_deque *b, int min)
{
	if (min == 2)
	{
		rev_rotate(&a->head, &a->tail, 'a');
		rev_rotate(&a->head, &a->tail, 'a');
		overlap_three(a, b, 3);
	}
	else if (min == 3)
	{
		rev_rotate(&a->head, &a->tail, 'a');
		overlap_three(a, b, 3);
	}
}

void	four_less_two(t_deque *a, t_deque *b, int *arr, int min)
{
	if (min == 0)
	{
		if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3]
			&& arr[0] < arr[3])
			return ;
		overlap_three(a, b, 3);
	}
	else if (min == 1)
	{
		rotate(&a->head, &a->tail, 'a');
		overlap_three(a, b, 3);
	}
}
