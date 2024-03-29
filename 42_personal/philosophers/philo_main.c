/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:35:16 by sna               #+#    #+#             */
/*   Updated: 2021/12/02 20:56:02 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_error(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(2, "error : ", 8);
	write(2, str, i);
	write(2, "\n", 1);
	return (1);
}

int	error_message(int error_num)
{
	if (error_num == 1)
		print_error("There is a problem with the input value.\n");
	if (error_num == 2)
		print_error("An error occurs when initializing the mutex.\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_pars	pars;
	int		result;

	if (ac != 5 && ac != 6)
		return (print_error("wrong argument! check input value.\n"));
	result = init(&pars, av);
	if (result)
		return (error_message(result));
	if (philo_start(&pars))
		return (print_error("An error has occurred in the thread.\n"));
	return (0);
}
