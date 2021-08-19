/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:32:12 by sna               #+#    #+#             */
/*   Updated: 2021/08/19 20:26:48 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	if (a_is_sorted(&a))
		printf("a is sorted\n");
	else
		printf("a is not sorted\n");
    //./push_swap 1 2 3 4 가 입력됐을 경우 ac의 값은 5임
    //배열의 크기는 숫자 4개만 들어가야 하므로 ac - 1을 해줘야함
	///copy_arr = (int *)malloc(sizeof(int) * a.size);
	int_malloc(&copy_arr, a.size);
	sort(&a, copy_arr, a.size);

	printf("sorted number : ");
	for (int i = 0; i < a.size; i++)
		printf("%d ", copy_arr[i]);
	printf("\n");

	simply_number(&a, copy_arr, a.size);
	push_swap(&a, &b, a.size);

	while (!dq_is_empty(&a))
		printf("%d ",dq_remove_first(&a));
	printf("\n");

	while (!dq_is_empty(&b))
		printf("%d ",dq_remove_first(&b));
	printf("\n");
	free(copy_arr);
    
    //free_deque(&a);
}