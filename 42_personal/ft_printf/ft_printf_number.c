/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:45:37 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 17:47:33 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_pointer_nbr(char **n_buff)
{
	*n_buff = ft_strjoin("0x", *n_buff);
	return (ft_strlen(*n_buff));
}

int		put_minus(t_form *form, char **n_buff)
{
	int		nbr_len;

	nbr_len = 0;
	if ((form->type == 'd' || form->type == 'i') &&
			!(form->flag & F_ZERO) && form->nbr_sign == -1)
	{
		*n_buff = ft_strjoin("-", *n_buff);
		nbr_len = 1;
	}
	return (nbr_len);
}

int		put_minus2(t_form *form, char **n_buff, int n_len)
{
	int		nbr_len;

	nbr_len = 0;
	if ((form->flag & F_ZERO) && form->nbr_sign == -1)
	{
		if (n_len >= form->width)
		{
			*n_buff = ft_strjoin("-", *n_buff);
			nbr_len = 1;
		}
		else if (n_len < form->width)
			*n_buff[0] = '-';
	}
	return (nbr_len);
}

int		put_str_prec(unsigned long long nbr, t_form *form, char **n_buff)
{
	int		nbr_len;
	int		prec_len;
	int		i;

	nbr_len = ft_nbrlen(nbr, form);
	prec_len = (form->prec > nbr_len) ? form->prec : nbr_len;
	if (!(*n_buff = (char *)malloc(sizeof(char) * (prec_len + 1))))
		return (0);
	i = 0;
	(*n_buff)[prec_len] = '\0';
	while (nbr_len + i < prec_len)
	{
		(*n_buff)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && form->prec != 0)
		(*n_buff)[prec_len - i] = '0';
	while (nbr)
	{
		(*n_buff)[prec_len - i] = ft_baseset(form->type)[nbr % form->nbr_base];
		nbr = nbr / form->nbr_base;
		i++;
	}
	return (nbr_len);
}

int		print_number(unsigned long long nbr, t_form *form)
{
	int		nbr_len;
	int		s_len;
	char	*nbr_buff;

	if (form->type == 'x' || form->type == 'X' || form->type == 'p')
		form->nbr_base = 16;
	if ((form->type == 'd' || form->type == 'i') && (int)nbr < 0)
	{
		form->nbr_sign = -1;
		nbr = -nbr;
	}
	nbr_len = put_str_prec(nbr, form, &nbr_buff);
	nbr_len += put_minus(form, &nbr_buff);
	if (form->type == 'p')
		nbr_len = put_pointer_nbr(&nbr_buff);
	s_len = put_str_width(&nbr_buff, form);
	s_len += put_minus2(form, &nbr_buff, nbr_len);
	ft_putstr(nbr_buff);
	free(nbr_buff);
	return (s_len);
}
