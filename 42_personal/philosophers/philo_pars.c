/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:36:57 by sna               #+#    #+#             */
/*   Updated: 2021/12/01 21:23:06 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philoth(t_pars *pars)
{
	int		i;

	i = 0;
	while (i < pars->num_philo)
	{
		pars->philoth[i].id = 0;
		pars->philoth[i].c_eat = 0;
		pars->philoth[i].id_left_fork = i;
		pars->philoth[i].id_right_fork = (i + 1) % pars->num_philo;
		pars->philoth[i].time_of_last_eat = 0;
		pars->philoth[i].pars = pars;
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
		if (pthread_mutex_init(&(pars->m_fork[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(pars->m_printing), NULL))
		return (1);
	if (pthread_mutex_init(&(pars->m_eating), NULL))
		return (1);
	return (0);
}

int	init(t_pars *pars, char **av)
{
	pars->num_philo = ft_atoi(av[1]);
	pars->time_die = ft_atoi(av[2]);
	pars->time_eat = ft_atoi(av[3]);
	pars->time_sleep = ft_atoi(av[4]);
	pars->state_die = 0;
	pars->all_eat = 0;
	if (pars->num_philo < 2 || pars->time_die < 0 || pars->time_eat < 0
		|| pars->time_sleep < 0)
		return (1);
	if (av[5])
	{
		pars->n_eat = ft_atoi(av[5]);
		if (pars->n_eat <= 0)
			return (1);
	}
	else
		pars->n_eat = -1;
	if (init_mutex(pars))
		return (2);
	init_philoth(pars);
	return (0);
}
