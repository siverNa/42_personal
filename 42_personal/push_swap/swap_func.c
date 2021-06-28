/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:26:29 by sna               #+#    #+#             */
/*   Updated: 2021/06/28 17:59:52 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **from, t_node **to, t_node **to_head)
{
	t_node *tmp;

	if (*from == NULL)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	tmp = *from;//from 주소 저장
	*from = (*from)->prev;//from의 이전 리스트 주소를 from에 저장
	if (*from)
		(*from)->next = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (*to)
		(*to)->next = tmp;//*to 주소가 존재하면 from 주소가 저장된 tmp를 (*to)->prev에 입력
	else
		*to_head = tmp;//아니면 *to_end 에 tmp입력
	tmp->prev = *to;//tmp->next 주소(다음 주소)로 *to 저장
	*to = tmp;
	(*to)->next = NULL;
}