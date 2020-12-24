/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:44:07 by sna               #+#    #+#             */
/*   Updated: 2020/12/24 22:56:04 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	if (s == 0)
		return (0);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
** The strrchr() function returns a pointer to the last (end) character 'c'
** in the string 's'.
** If the character 'c' is not found, it returns null.
** If the string 's' is null, it returns null.(line 19, 20)
*/
