/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_third.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:09:26 by sna               #+#    #+#             */
/*   Updated: 2021/07/29 19:50:14 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    overlap_four(t_deque *a, t_deque *b, int size)
{
    test_push(a, b, 'b');
    perform_four(a, b, size);
    test_push(b, a, 'a');
}

void    overlap_three(t_deque *a, t_deque *b, int size)
{
    test_push(a, b, 'b');
    perform_three(a, b, size);
    test_push(b, a, 'a');
}