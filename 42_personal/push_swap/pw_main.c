/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/07/12 18:12:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_deque a;
    t_deque b;
    int     copy_arr[ac - 1];
    
    build_deque(&a, &b, ac, av);
    
    if (a_is_sorted(&a))
        printf("a is sorted\n");
    else
        printf("a is not sorted\n");
    
    //./push_swap 1 2 3 4 가 입력됐을 경우 ac의 값은 5임
    //배열의 크기는 숫자 4개만 들어가야 하므로 ac - 1을 해줘야함
    sort(&a, copy_arr, ac - 1);

    printf("sorted number : ");
    for (int i = 0; i < ac - 1; i++)
        printf("%d ", copy_arr[i]);
    printf("\n");
    
    simply_number(&a, copy_arr, ac - 1);
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