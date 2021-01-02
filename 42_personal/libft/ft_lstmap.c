/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 20:59:51 by sna               #+#    #+#             */
/*   Updated: 2020/12/31 21:12:05 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*list_adr;
	t_list	*curr;

	if (lst == 0 || (new_list = ft_lstnew(f(lst->content))) == 0)
		return (NULL);
	curr = new_list;
	list_adr = lst->next;
	while (list_adr != NULL)
	{
		if ((curr->next = ft_lstnew(f(list_adr->content))) == 0)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		curr = curr->next;
		list_adr = list_adr->next;
	}
	return (new_list);
}
/*
** Iterates the list ’lst’ and applies the function ’f’
** to the content of each element.
** Creates a new list resulting of the successive applications of
** the function ’f’.
** The ’del’ function is used to delete the content of an element if needed.
** The new list. Return NULL if the allocation fails.
*/
