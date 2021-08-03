/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/08/03 18:00:25 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	 free_deque(t_deque *a)
{
	t_node *temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
}

int     main(int ac, char **av)
{
    t_deque a;
    t_deque b;
    int     copy_arr[ac - 1];
    
    build_deque(&a, &b, ac, av);
    sort(&a, copy_arr, ac - 1);
    simply_number(&a, copy_arr, ac - 1);
    push_swap(&a, &b, ac - 1);
    free_deque(&a);
}