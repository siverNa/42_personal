/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:29:32 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 11:26:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	char				*ptr;

	i = 0;
	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src && i < nb)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	*ptr = 0;
	return (dest);
}
