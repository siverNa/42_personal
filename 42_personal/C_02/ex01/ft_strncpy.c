/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:55:59 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 10:26:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*tmp;

	tmp = dest;
	i = 0;
	while (i < n)
	{
		*dest = *src;
		if (*src)
			++src;
		++dest;
		++i;
	}
	return (tmp);
}
