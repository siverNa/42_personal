/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:13:25 by sna               #+#    #+#             */
/*   Updated: 2020/10/29 23:23:44 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int a;

	if (nb < 0)
		return (0);
	i = 1;
	a = 1;
	while (i <= nb)
	{
		a = a * i;
		++i;
	}
	return (a);
}
