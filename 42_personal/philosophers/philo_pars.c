/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:36:57 by sna               #+#    #+#             */
/*   Updated: 2021/11/11 21:22:22 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (0);
}