/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_sec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:46:45 by sna               #+#    #+#             */
/*   Updated: 2021/07/27 22:14:25 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     search_min(int *arr, int size)
{
    int     i;
    int     min;
    int     min_arr;

    i = 0;
    min = 0;
    min_arr = arr[0];
    while (++i < size)
    {
        if (arr[i] < min_arr)
        {
            min_arr = arr[i];
            min = i;
        }
    }
    return (min);
}

void    dec_to_arr(t_node *temp, int *arr, int size)
{
    int     i;

    i = 0;
    while (i < size)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
}

void    perform_four(t_deque *a, t_deque *b, int size)
{
    t_node  *temp;
    int     arr[4];
    int     min;

    temp = a->head;
    dec_to_arr(temp, arr, size);
    min = search_min(arr, size);
    if (min == 0)
    {
        if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] &&
        arr[0] < arr[3])
            return ;
        test_push(a, b, 'b');
        perform_three(a, b, 3);
        test_push(b, a, 'a');
    }
    else if (min == 1)
    {
        rotate(&a->head, &a->tail, 'a');
        test_push(a, b, 'b');
        perform_three(a, b, 3);
        test_push(b, a, 'a');
    }
    else if (min == 2)
    {
        rev_rotate(&a->head, &a->tail, 'a');
        rev_rotate(&a->head, &a->tail, 'a');
        test_push(a, b, 'b');
        perform_three(a, b, 3);
        test_push(b, a, 'a');
    }
    else if (min == 3)
    {
        rev_rotate(&a->head, &a->tail, 'a');
        test_push(a, b, 'b');
        perform_three(a, b, 3);
        test_push(b, a, 'a');
    }
}

void    perform_three(t_deque *a, t_deque *b, int size)
{
    t_node  *temp;
    int     arr[3];
    
    temp = a->head;
    dec_to_arr(temp, arr, size);
    if (arr[0] < arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
        return ;
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
    {
        test_push(a, b, 'b');
        swap(&a->head, 'a');
        test_push(b, a, 'a');
    }
    else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
        swap(&a->head, 'a');
    else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
        rev_rotate(&a->head, &a->tail, 'a');
    else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
        rotate(&a->head, &a->tail, 'a');
    else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
    {
        rev_rotate(&a->head, &a->tail, 'a');
        rev_rotate(&a->head, &a->tail, 'a');
        swap(&a->head, 'a');
    }
}