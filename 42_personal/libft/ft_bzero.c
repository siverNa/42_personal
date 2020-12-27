/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:51:13 by sna               #+#    #+#             */
/*   Updated: 2020/12/25 18:04:15 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (s);
}
/*
** The bzero() function fills the memory area of 's' with 0x00 as 'n' bytes.
** It is similar memset(s, 0x00, n);
** You can replace this code with a memset(s, 0, n).
*/