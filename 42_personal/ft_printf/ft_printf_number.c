/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:45:37 by sna               #+#    #+#             */
/*   Updated: 2021/02/07 21:02:24 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_number(long long nbr, t_form *form)
{
	int		nbr_len;
	int		s_len;
	char	*nbr_buff;

	if (form->type == 'x' || form->type =='X' || form->type == 'p')
		form->nbr_base = 16;
	if ((form->type == 'd' || form->type == 'i') && (int)nbr < 0)
	{
		form->nbr_sign = -1;
		nbr = -nbr;
	}
	nbr_len = put_prec_str(nbr, form, &nbr_buff);
	nbr_len += put_minus(form, &nbr_buff);
	if (form->type == 'p')
		nbr_len = put_pointer_nbr(&nbr_buff);
	s_len = put_str_width(&nbr_buff, form);
	s_len += put_minus2(form, &nbr_buff, nbr_len);
	ft_putstr(nbr_buff);
	free(nbr_buff);
	return (s_len);
}
