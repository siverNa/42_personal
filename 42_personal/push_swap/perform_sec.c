/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_sec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:46:45 by sna               #+#    #+#             */
/*   Updated: 2021/07/27 18:53:05 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
void    perform_four(t_deque *a, t_deque *b, int size)
{

}
*/

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