/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 00:01:14 by sna               #+#    #+#             */
/*   Updated: 2020/11/04 20:16:38 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	p = dest;
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (dest);
}
