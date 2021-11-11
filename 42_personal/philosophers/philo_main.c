/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:35:16 by sna               #+#    #+#             */
/*   Updated: 2021/11/11 21:27:23 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_error(char *str)
{
	int		i;

	i = 0;
	i = ft_strlen(str);
	write(2, "error : ", 8);
	write(2, str, i);
	write(2, "\n", 1);
	return (1);
}

int	main(int ac, char **av)
{
	t_pars	pars;
	int		result;

	if (ac != 5 && ac != 6)
		return (print_error("wrong argument! check input value.\n"));
	if ((result = init(&pars, av)))
		return(print_error("init error!\n"));
	printf("pars result\n");
	printf("num_of_philo : %d\n", pars.num_philo);
	printf("time_to_die : %d\n", pars.time_to_die);
	printf("time_to_eat : %d\n", pars.time_to_eat);
	printf("time_to_sleep : %d\n", pars.time_to_sleep);
	printf("need_eat : %d\n", pars.need_eat);
	printf("\n");
	return (0);
}
