/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:25:15 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 15:46:38 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_form(t_form *form)
{
	form->flag &= (~F_ZERO);
	form->flag &= (~F_MINUS);
	form->flag &= (~F_PREC);
	form->width = 0;
	form->prec = -1;
	form->type = 0;
	form->nbr_base = 10;
	form->nbr_sign = 1;
}

int		ft_nbrlen(unsigned long long nbr, t_form *form)
{
	int		i;

	if (nbr == 0 && form->prec != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr = nbr / form->nbr_base;
	}
	return (i);
}

char	*ft_baseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
