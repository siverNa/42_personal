/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:33:55 by sna               #+#    #+#             */
/*   Updated: 2021/07/22 21:22:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     a_is_sorted(t_deque *a)
{
    t_node *temp;

    temp = a->head;
    while (temp)
    {
        if (temp->next && temp->data > temp->next->data)
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

void    perform_over_five(t_deque *a, t_deque *b, int size)
{
    int     max_num;
    int     max_bits;
    int     num;
    int     i;
    int     j;

    max_num = size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        ++max_bits;
    i = -1;
    while (++i < max_bits)
    {
        j = -1;
        while (++j < size)
        {
            num = a->head->data;
            if (((num >> i) & 1) == 1)
                rotate(&a->head, &a->tail, 'a');
            else
                test_push(a, b, 'b');
        }
        while (!dq_is_empty(b))
            test_push(b, a, 'a');
    }
}

int     push_swap(t_deque *a, t_deque *b, int size)
{
    if (size <= 0)
        return (1);
    if (size == 1)
        return (0);
    if (size == 2 && a->tail->prev->data < a->tail->data)
        swap(&a->head, 'a');
    if (size > 5)
        perform_over_five(a, b, size);
    return (2);
}