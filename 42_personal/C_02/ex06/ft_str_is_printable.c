/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:07:23 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 10:29:55 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		confirm(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!confirm(str[i++]))
			return (0);
	}
	return (1);
}
