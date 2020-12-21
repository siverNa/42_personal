/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:05:43 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 10:30:57 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		check_lowcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		check_upcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		is_char(char c)
{
	if (check_number(c))
		return (1);
	else if (check_lowcase(c))
		return (1);
	else if (check_upcase(c))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int check;

	i = 0;
	check = 1;
	while (str[i])
	{
		if (!is_char(str[i]))
			check = 1;
		else
		{
			if (check && check_lowcase(str[i]))
				str[i] = str[i] - 32;
			else if (!check && check_upcase(str[i]))
				str[i] = str[i] + 32;
			check = 0;
		}
		i++;
	}
	return (str);
}
