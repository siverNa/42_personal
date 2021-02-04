/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:25:15 by sna               #+#    #+#             */
/*   Updated: 2021/02/04 18:37:57 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_form(t_form *form)
{
	form->flag &= (~F_ZERO);
	form->flag &= (~F_MINUS);
	form->flag &= (~F_PREC);
	form->width = 0;
	form->prec = 0;
	form->type = 0;
}
