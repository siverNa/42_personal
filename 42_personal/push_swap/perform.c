/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:33:55 by sna               #+#    #+#             */
/*   Updated: 2021/07/12 18:53:53 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     a_is_sorted(t_deque *a)
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

void    simply_number(t_deque *a, int *copy_arr, int n)
{
    t_node  *temp;
    int     temp_arr[n];
    int     i;
    int     j;

    if (a == NULL || copy_arr == NULL || !n)
        return ;
    temp = a->head;
    i = 0;
    while (i < n)
    {
        temp_arr[i++] = temp->data;
        temp = temp->next;
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        while(j < n)
        {
            if (temp_arr[i] == copy_arr[j])
            {
                 temp_arr[i] = j;
                 break ;
            }
            j++;
        }
        i++;
    }
    i = 0;
    temp = a->head;
    while(i < n)
    {
        temp->data = temp_arr[i++];
        temp = temp->next;
    }
}