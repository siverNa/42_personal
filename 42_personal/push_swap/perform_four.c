/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:08:20 by sna               #+#    #+#             */
/*   Updated: 2021/08/02 19:16:28 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    five_more_two(t_deque *a, t_deque *b, int min)
{
    int i;

    i = 0;
    if (min == 3)
    {
        while (i++ < (min - 1))
            rev_rotate(&a->head, &a->tail, 'a');
        overlap_four(a, b, 4);
    }
    else if (min == 4)
    {
        rev_rotate(&a->head, &a->tail, 'a');
        overlap_four(a, b, 4);
    }
}

void    five_less_two(t_deque *a, t_deque *b, int *arr, int min)
{
    int i;

    i = 0;
    if (min == 0)
    {
        if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] &&
        arr[3] < arr[4] && arr[0] < arr[4])
            return ;
        overlap_four(a, b, 4);
    }
    else if (0 < min && min < 3)
    {
        while (i++ < min)
            rotate(&a->head, &a->tail, 'a');
        overlap_four(a, b, 4);
    }
}