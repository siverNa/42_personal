/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:00:42 by sna               #+#    #+#             */
/*   Updated: 2021/12/01 20:28:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int				check;
	unsigned long	num;
	size_t			i;

	num = 0;
	check = 1;
	i = 0;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r' || nptr
		[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			check = check * (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)num * check);
}

void print_event(t_pars *pars, int id, char *str)
{
	pthread_mutex_lock(&(pars->m_printing));
	if (!(pars->state_die))
	{
		printf("%lli ", timestamp() - pars->init_timestamps);
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(pars->m_printing));
	return ;
}
