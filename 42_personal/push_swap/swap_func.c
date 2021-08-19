/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:26:29 by sna               #+#    #+#             */
/*   Updated: 2021/08/19 21:20:27 by sna              ###   ########.fr       */
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
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)
		return ;
	(*tail)->next = *head;
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
	t_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_deque *from, t_deque *to, char c)
{
	t_node	*temp;

	if (from == NULL || to == NULL)
		return ;
	temp = from->head;
	from->head = (from->head)->next;
	if (from->head == NULL)
		from->tail = NULL;
	else
		(from->head)->prev = NULL;
	if (to->head)
		(to->head)->prev = temp;
	else
		to->tail = temp;
	temp->next = to->head;
	to->head = temp;
	(to->head)->prev = NULL;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
