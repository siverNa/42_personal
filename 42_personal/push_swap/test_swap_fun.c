/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:45:14 by sna               #+#    #+#             */
/*   Updated: 2021/07/22 20:37:47 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_deque *a, t_deque *b, char c)
{
	t_node *temp;

	if (a == NULL || b == NULL || !c)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	temp = a->head;//from 주소 저장
	a->head = (a->head)->next;//from의 다음 리스트 주소를 from에 저장
	if (a->head == NULL)
        a->tail = NULL;
    else
		(a->head)->prev = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (b->head)
		(b->head)->prev = temp;//*to 주소가 존재하면 from 주소가 저장된 temp를 (*to)->prev에 입력
	else
		b->tail = temp;//아니면 *to_tail 에 temp입력
	temp->next = b->head;//temp->next 주소(다음 주소)로 *to 저장
	b->head = temp;
	(b->head)->prev = NULL;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}