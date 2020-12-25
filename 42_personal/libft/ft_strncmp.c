/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:47:51 by sna               #+#    #+#             */
/*   Updated: 2020/12/25 15:29:39 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
/*
** The function ft_strncmp() compares two strings 's1' and 's2'
** entered as parameters by n.
** Characters that appear after NULL ('\0') are not compared.
** If s1[i] > s2[i], return positive, s1[i] < s2[i] return negative.
** If s1 == s2 or n = 0, return 0.
*/
