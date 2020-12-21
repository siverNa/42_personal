/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:27:15 by sna               #+#    #+#             */
/*   Updated: 2020/10/29 21:26:08 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *p_str;
	char *p_to_find;

	if (!*to_find)
		return (str);
	while (*str)
	{
		p_str = str;
		p_to_find = to_find;
		while (*p_to_find && *p_str == *p_to_find)
		{
			p_str++;
			p_to_find++;
		}
		if (*p_to_find == 0)
			return (str);
		str++;
	}
	return (0);
}
