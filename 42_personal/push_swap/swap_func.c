/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:26:29 by sna               #+#    #+#             */
/*   Updated: 2021/08/13 17:46:48 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **head, t_node **tail, char c)
{
	if (*head == NULL || *tail == NULL || (*tail)->prev == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = (*head)->prev;
	*tail = (*tail)->prev;
	(*head)->prev = NULL;
	(*tail)->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rotate(t_node **head, t_node **tail, char c)
{
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)//비어있는 리스트면 그냥 리턴
		return ;
	(*tail)->next = *head;//연결리스트의 시작과 끝을 연결
	(*head)->prev = *tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	swap(t_node **head, char c)
{
	t_node *temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;//temp에 head리스트 주소 저장
	*head = (*head)->next;//head의 다음 리스트를 head에 저장 
	temp->next = (*head)->next;//현재 head의 리스트가 1일때, 자리를 바꾸고 다음 리스트인 2의 주소를 temp가 가질 수 있도록 작업
	temp->prev = *head;//자리를 바꾸고나면 temp가 가리키는 이전 리스트는 head가 되어야함
	(*head)->next = temp;//자리를 바꾸고난 뒤, head - temp 순이므로 head의 다음 주소에 temp 저장
	(*head)->prev = NULL;//맨 앞이므로 이전 주소엔 null 저장
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_deque *from, t_deque *to, char c)
{
	t_node *temp;

	if (from == NULL || to == NULL || !c)//from이 비어있을 때는 아무것도 수행 안함
		return ;
	temp = from->head;//from 주소 저장
	from->head = (from->head)->next;//from의 다음 리스트 주소를 from에 저장
	if (from->head == NULL)
        from->tail = NULL;
    else
		(from->head)->prev = NULL;//이전 리스트가 있다면 prev에 null 입력(이전주소 끊기?)
	if (to->head)
		(to->head)->prev = temp;//*to 주소가 존재하면 from 주소가 저장된 temp를 (*to)->prev에 입력
	else
		to->tail = temp;//아니면 *to_tail 에 temp입력
	temp->next = to->head;//temp->next 주소(다음 주소)로 *to 저장
	to->head = temp;
	(to->head)->prev = NULL;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}