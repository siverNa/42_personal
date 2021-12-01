/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:53:13 by sna               #+#    #+#             */
/*   Updated: 2021/12/01 21:37:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	finish(t_pars *pars, t_philoth *phith)
{
	int			i;

	i = 0;
	while (i < pars->num_philo)
	{
		pthread_join(phith[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < pars->num_philo)
	{
		pthread_mutex_destroy(&(pars->m_fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(pars->m_printing));
	pthread_mutex_destroy(&(pars->m_eating));
}

void	death_check(t_pars *p, t_philoth *h)
{
	int			i;

	while (!(p->all_eat))
	{
		i = 0;
		while (i < p->num_philo && !(p->state_die))
		{
			pthread_mutex_lock(&(p->m_eating));
			if (diff_time(h[i].time_of_last_eat, timestamp()) > p->time_die)
			{
				print_event(p, h->id, "is die");
				p->state_die = 1;
			}
			pthread_mutex_unlock(&(p->m_eating));
			usleep(50);
			i++;
		}
		if (p->state_die == 1)
			break ;
		i = 0;
		while (p->n_eat != -1 && i < p->num_philo && h[i].c_eat >= p->n_eat)
			i++;
		if (i == p->num_philo)
			p->all_eat = 1;
	}
}

void	philo_eat(t_philoth *phith)
{
	t_pars		*pars;

	pars = phith->pars;
	pthread_mutex_lock(&(pars->m_fork[phith->id_left_fork]));
	print_event(pars, phith->id, " has taken left fork.");
	pthread_mutex_lock(&(pars->m_fork[phith->id_right_fork]));
	print_event(pars, phith->id, " has taken right fork.");
	pthread_mutex_lock(&(pars->m_eating));
	print_event(pars, phith->id, " is eating");
	phith->time_of_last_eat = timestamp();
	pthread_mutex_unlock(&(pars->m_eating));
	philo_sleep(pars->time_eat, pars);
	(phith->c_eat)++;
	pthread_mutex_unlock(&(pars->m_fork[phith->id_left_fork]));
	pthread_mutex_unlock(&(pars->m_fork[phith->id_right_fork]));
}

void	*p_thread(void *philosopher)
{
	int			i;
	t_pars		*pars;
	t_philoth	*phith;

	i = 0;
	phith = (t_philoth *)philosopher;
	pars = phith->pars;
	if (phith->id % 2)
		usleep(15000);
	while (!(pars->state_die))
	{
		philo_eat(phith);
		if (pars->all_eat)
			break ;
		print_event(pars, phith->id, " is sleep.");
		philo_sleep(pars->time_sleep, pars);
		print_event(pars, phith->id, " is think.");
		i++;
	}
	return (NULL);
}

int	philo_start(t_pars *pars)
{
	int			i;
	t_philoth	*phith;

	i = 0;
	phith = pars->philoth;
	pars->init_timestamps = timestamp();
	while (i < pars->num_philo)
	{
		if (pthread_create(&(phith[i].thread_id), NULL, p_thread, &(phith[i])))
			return (1);
		phith[i].time_of_last_eat = timestamp();
		i++;
	}
	death_check(pars, phith);
	finish(pars, phith);
	return (0);
}
