/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:38:02 by sna               #+#    #+#             */
/*   Updated: 2021/11/15 20:58:37 by sna              ###   ########.fr       */
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
	int				count_eat;
	int				id_left_fork;
	int				id_right_fork;
}					t_philoth;

typedef struct s_pars
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				need_eat;
	pthread_mutex_t	fork[255];
}					t_pars;

/*
** main.c
*/
int					print_error(char *str);
/*
** philo_util.c
*/
int					ft_strlen(const char *s);
int					ft_atoi(const char *nptr);
/*
** philo_pars.c
*/
int					init(t_pars *pars, char **av);

#endif