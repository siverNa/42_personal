/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:54:13 by sna               #+#    #+#             */
/*   Updated: 2020/11/02 12:33:18 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_len(char *base)
{
	char	check[256];
	int		i;
	int		len;
	char	c;

	i = 0;
	while (i <= 255)
		check[i++] = 0;
	len = 0;
	while (check[len] != '\0')
	{
		c = base[len];
		if (check[(int)c] == 1)
			return (0);
		if (c == '+' || c == '-')
			return (0);
		if (c == ' ')
			return (0);
		if (c >= '\t' && c <= '\r')
			return (0);
		check[(int)c] = 1;
		len++;
	}
	return (len);
}

int		get_base(char c, char *base, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		check_space(char c)
{
	if (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ')
		return (1);
	if (c == '+')
		return (-2);
	if (c == '-')
		return (-1);
	return (2);
}

int		ft_atoi_base(char *str, char *base)
{
	int		len;
	int		isc;
	int		num;
	int		check;

	check = 1;
	len = base_len(base);
	if (len == 0 || len == 1)
		return (0);
	while (check_space(*str) == 1)
		str++;
	while (check_space(*str) < 0)
	{
		if (check_space(*str) == -1)
			check = check * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		isc = get_base(*(str++), base, len);
		if (isc == -1)
			break ;
		num = (num * len) + (isc * check);
	}
	return (num);
}
