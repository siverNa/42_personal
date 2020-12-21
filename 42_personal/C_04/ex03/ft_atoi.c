/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:56:08 by sna               #+#    #+#             */
/*   Updated: 2020/10/31 16:43:16 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi(char *str)
{
	int i;
	int n;
	int check;

	i = 0;
	n = 0;
	check = 0;
	while (check_space(str[i]) == 1)
		i++;
	while (check_space(str[i]) < 0)
	{
		if (check_space(str[i]) == -1)
			check++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (check % 2 == 1)
		n = n * (-1);
	return (n);
}
