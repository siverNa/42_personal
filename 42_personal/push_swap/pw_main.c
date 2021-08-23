/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/08/23 18:12:59 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_deque(t_deque *a)
{
	t_node	*temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;
	int		*copy_arr;

	build_deque(&a, &b, ac, av);
	int_malloc(&copy_arr, a.size);
	sort(&a, copy_arr, a.size);
	simply_number(&a, copy_arr, a.size);
	push_swap(&a, &b, a.size);
	free(copy_arr);
	free_deque(&a);
}
