/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:33:55 by sna               #+#    #+#             */
/*   Updated: 2021/07/13 19:35:23 by sna              ###   ########.fr       */
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

void    simply_number_sec(int *temp, int *copy, int n)
{
    int     i;
    int     j;

    i = 0;
    while (i < n)
    {
        j = 0;
        while(j < n)
        {
            if (temp[i] == copy[j])
            {
                 temp[i] = j;
                 break ;
            }
            j++;
        }
        i++;
    }
}

void    simply_number(t_deque *a, int *copy_arr, int n)
{
    t_node  *temp;
    int     temp_arr[n];
    int     i;

    if (a == NULL || copy_arr == NULL || !n)
        return ;
    temp = a->head;
    i = 0;
    while (i < n)
    {
        temp_arr[i++] = temp->data;
        temp = temp->next;
    }
    simply_number_sec(temp_arr, copy_arr, n);
    i = 0;
    temp = a->head;
    while(i < n)
    {
        temp->data = temp_arr[i++];
        temp = temp->next;
    }
}