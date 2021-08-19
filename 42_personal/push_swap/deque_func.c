/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:49:05 by sna               #+#    #+#             */
/*   Updated: 2021/08/19 20:49:08 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dq_remove_last(t_deque *d)
{
	t_node	*rnode;
	int		rdata;

	rnode = d->tail;
	if (dq_is_empty(d))
	{
		write(1, "deque memory error\n", 19);
		exit(-1);
	}
	rdata = d->tail->data;
	d->tail = d->tail->prev;
	free(rnode);
	if (d->tail == NULL)
		d->head = NULL;
	else
		d->tail->next = NULL;
	return (rdata);
}

int	dq_remove_first(t_deque *d)
{
	t_node	*rnode;
	int		rdata;

	rnode = d->head;
	if (dq_is_empty(d))
	{
		write(1, "deque memory error\n", 19);
		exit(-1);
	}
	rdata = d->head->data;
	d->head = d->head->next;
	free(rnode);
	if (d->head == NULL)
		d->tail = NULL;
	else
		d->tail->prev = NULL;
	return (rdata);
}

void	dq_add_last(t_deque *d, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return ;
	newnode->data = data;
	newnode->prev = d->tail;
	if (dq_is_empty(d))
		d->head = newnode;
	else
		d->tail->next = newnode;
	newnode->next = NULL;
	d->tail = newnode;
}

int	dq_is_empty(t_deque *d)
{
	if (d->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	deque_init(t_deque *d)
{
	d->head = NULL;
	d->tail = NULL;
}
