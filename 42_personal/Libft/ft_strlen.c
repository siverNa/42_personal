/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:29:57 by sna               #+#    #+#             */
/*   Updated: 2020/12/22 19:58:45 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
** The return type 'size_t' is 'unsigned int' type if you go over the source.
** That is, it returns an unsigned integer (length of string).
** The parameter 'const char *s' is the name of the array-
** to obtain the length of the string.
*/
