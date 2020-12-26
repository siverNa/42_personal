/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:39:17 by sna               #+#    #+#             */
/*   Updated: 2020/12/26 19:02:53 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c_dest;
	unsigned char	c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		if (c_dest[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
/*
** It replicates 'src' data to 'dest' as much as 'n' bytes.
** If the 'src' data encounters the letter 'c'
** it replicates up to 'c' and stops replication.
** Returns the number after replication ends in the replicated 'dest' variable.
** If you do not meet the character 'c'
** clone the 'n' byte and return the null.
*/
