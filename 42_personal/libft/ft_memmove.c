/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:02:49 by sna               #+#    #+#             */
/*   Updated: 2020/12/26 20:15:13 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*c_src;

	if (dest == '\0' && src == '\0')
		return (0);
	if (dest <= src)
	{
		tmp = dest;
		c_src = src;
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest;
		tmp = tmp + n;
		c_src = src;
		c_src = c_src + n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}
/*
** Copy 'n' byte from 'src' memory to 'dest' memory.
** The 'src' array first copies the memory area
** that does not overlap the memory area of 'src' and 'dest'.
** Returns the pointer in the dest.
*/
