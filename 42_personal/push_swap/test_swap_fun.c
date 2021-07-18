/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:45:14 by sna               #+#    #+#             */
/*   Updated: 2021/07/18 20:58:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_deque *a, t_deque *b)
{
	t_node *temp;

	if (a == NULL || b == NULL)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	temp = a->tail;//from 주소 저장
	a->tail = (a->tail)->prev;//from의 이전 리스트 주소를 from에 저장
	if (a->tail == NULL)
        a->head = NULL;
    else
		(a->tail)->next = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (b->tail)
		(b->tail)->next = temp;//*to 주소가 존재하면 from 주소가 저장된 temp를 (*to)->prev에 입력
	else
		b->head = temp;//아니면 *to_tail 에 temp입력
	temp->prev = b->tail;//temp->next 주소(다음 주소)로 *to 저장
	b->tail = temp;
	(b->tail)->next = NULL;
}