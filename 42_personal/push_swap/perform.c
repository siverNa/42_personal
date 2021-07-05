/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:33:55 by sna               #+#    #+#             */
/*   Updated: 2021/07/05 18:49:01 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  a_is_sorted(t_deque *a)
{
    t_node *temp;

    temp = a->head;
    while (temp)
    {
        if (temp->next && temp->data < temp->next->data)
            return (0);
        temp = temp->next;
        if (temp == a->tail)
            break ;
    }
    return (1);
}