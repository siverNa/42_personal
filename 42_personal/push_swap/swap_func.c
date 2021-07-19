/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:26:29 by sna               #+#    #+#             */
/*   Updated: 2021/07/19 18:51:40 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **head, t_node **tail, char c)
{
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 3);
	else if (c == 'b')
		write(1, "rrb\n", 3);
	
}

void	rotate(t_node **head, t_node **tail, char c)
{
	if (*head == NULL || *tail == NULL || (*tail)->prev == NULL)//비어있는 리스트면 그냥 리턴
		return ;
	(*tail)->next = *head;//연결리스트의 시작과 끝을 연결
	(*head)->prev = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	*head = (*head)->prev;
	(*head)->prev = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	swap(t_node **tail, char c)
{
	t_node *temp;

	if (*tail == NULL || (*tail)->prev == NULL)
		return ;
	temp = *tail;//temp에 head리스트 주소 저장
	*tail = (*tail)->prev;//head의 다음 리스트를 head에 저장 
	temp->prev = (*tail)->prev;//현재 head의 리스트가 1일때, 자리를 바꾸고 다음 리스트인 2의 주소를 temp가 가질 수 있도록 작업
	temp->next = *tail;//자리를 바꾸고나면 temp가 가리키는 이전 리스트는 head가 되어야함
	(*tail)->prev = temp;//자리를 바꾸고난 뒤, head - temp 순이므로 head의 다음 주소에 temp 저장
	(*tail)->next = NULL;//맨 앞이므로 이전 주소엔 null 저장
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_node **from, t_node **to, t_node **to_head)
{
	t_node *temp;

	if (*from == NULL)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	temp = *from;//from 주소 저장
	*from = (*from)->prev;//from의 이전 리스트 주소를 from에 저장
	if (*from)
		(*from)->next = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (*to)
		(*to)->next = temp;//*to 주소가 존재하면 from 주소가 저장된 temp를 (*to)->prev에 입력
	else
		*to_head = temp;//아니면 *to_tail 에 temp입력
	temp->prev = *to;//temp->next 주소(다음 주소)로 *to 저장
	*to = temp;
	(*to)->next = NULL;
}