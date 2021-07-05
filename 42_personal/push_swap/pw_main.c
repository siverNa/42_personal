/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/07/05 19:01:01 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_deque a;
    t_deque b;
    
    build_deque(&a, &b, ac, av);
    
    if (a_is_sorted(&a))
        printf("a is sorted\n");
    else
        printf("a is not sorted\n");
    
    /*
    push(&a.tail, &b.tail, &b.head);
    push(&a.tail, &b.tail, &b.head);
    push(&a.tail, &b.tail, &b.head);
    push(&a.tail, &b.tail, &b.head);
    //swap(&b.tail);
    rev_rotate(&b.head, &b.tail);
    */

    while (!dq_is_empty(&a))
        printf("%d ",dq_remove_last(&a));
    printf("\n");
    
    while (!dq_is_empty(&b))
        printf("%d ",dq_remove_last(&b));
    printf("\n");
}