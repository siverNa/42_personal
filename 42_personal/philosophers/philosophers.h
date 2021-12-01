/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:38:02 by sna               #+#    #+#             */
/*   Updated: 2021/12/01 21:37:09 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_philoth
{
	int				id;
	int				c_eat;
	int				id_left_fork;
	int				id_right_fork;
	long long		time_of_last_eat;
	pthread_t		thread_id;
	struct s_pars	*pars;
}					t_philoth;

typedef struct s_pars
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_eat;
	int				state_die;
	int				all_eat;
	pthread_mutex_t	m_fork[255];
	pthread_mutex_t	m_printing;
	pthread_mutex_t	m_eating;
	t_philoth		philoth[255];
	long long		init_timestamps;
}					t_pars;

/*
** main.c
*/
int					print_error(char *str);
int					error_message(int error_num);
/*
** philo_util.c
*/
int					ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
void				print_event(t_pars *pars, int id, char *str);
/*
** philo_pars.c
*/
int					init_philoth(t_pars *pars);
int					init_mutex(t_pars *pars);
int					init(t_pars *pars, char **av);
/*
** philo_start.c
*/
int					philo_start(t_pars *pars);
/*
** philo_time.h
*/
long long			diff_time(long long past, long long curr);
long long			timestamp(void);
void				philo_sleep(long long t, t_pars *pars);

#endif