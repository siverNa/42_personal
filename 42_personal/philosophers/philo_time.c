/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:28:03 by sna               #+#    #+#             */
/*   Updated: 2021/12/01 21:36:00 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	diff_time(long long past, long long curr)
{
	return (curr - past);
}

long long	timestamp(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

void	philo_sleep(long long t, t_pars *pars)
{
	long long		i;

	i = timestamp();
	while (!(pars->state_die))
	{
		if (diff_time(i, timestamp()) >= t)
			break ;
		usleep(50);
	}
}
