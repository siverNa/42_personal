/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:42:29 by sna               #+#    #+#             */
/*   Updated: 2020/12/28 20:26:43 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len_int(int n)
{
	int			len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			s_len;
	int			check;
	char		*str;
	long long	temp;

	check = n < 0 ? -1 : 1;
	s_len = get_len_int(n);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str == 0)
		return (NULL);
	str[s_len] = 0;
	s_len--;
	temp = n < 0 ? -(long long)n : (long long)n;
	while (s_len >= 0)
	{
		str[s_len] = temp % 10 + '0';
		temp = temp / 10;
		s_len--;
	}
	if (check == -1)
		str[0] = '-';
	return (str);
}
/*
** Allocates (with malloc()) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
** If successful, returns a string representing an integer.
** Returns NULL on failure, or allocation failure.
*/
