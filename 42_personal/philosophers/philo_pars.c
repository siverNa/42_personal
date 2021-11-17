/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:36:57 by sna               #+#    #+#             */
/*   Updated: 2021/11/16 15:23:24 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_philoth(t_pars *pars)
{
	int		i;

	i = 0;
	while (i < pars->num_philo)
	{
		pars->philo[i].id = 0;
		pars->philo[i].count_eat = 0;
		pars->philo[i].id_left_fork = i;
		pars->philo[i].id_right_fork = (i + 1) % pars->num_philo;
		pars->philo[i].time_of_last_eat = 0;
		pars->philo[i].pars = pars;
		i++;
	}
	return (0);
}

int	init_mutex(t_pars *pars)
{
	int		i;

	i = 0;
	while (i < pars->num_philo)
	{
		if (pthread_mutex_init(&(pars->fork[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init(t_pars *pars, char **av)
{
	pars->num_philo = ft_atoi(av[1]);
	pars->time_to_die = ft_atoi(av[2]);
	pars->time_to_eat = ft_atoi(av[3]);
	pars->time_to_sleep = ft_atoi(av[4]);
	if (pars->num_philo < 2 || pars->time_to_die < 0 || pars->time_to_eat < 0
		|| pars->time_to_sleep < 0)
		return (1);
	if (av[5])
	{
		pars->need_eat = ft_atoi(av[5]);
		if (pars->need_eat <= 0)
			return (1);
	}
	else
		pars->need_eat = -1;
	if (init_mutex(pars))
		return (2);
	init_philoth(pars);
	return (0);
}