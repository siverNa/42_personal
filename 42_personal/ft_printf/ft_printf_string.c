/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:55:56 by sna               #+#    #+#             */
/*   Updated: 2021/02/11 17:36:41 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_to_buff(char *str, int prec_len, int s_len)
{
	int		i;
	char	*buff;

	prec_len = (prec_len < s_len ? prec_len : s_len);
	if (!(buff = (char *)malloc(sizeof(char) * (prec_len + 1))))
		return (NULL);
	i = 0;
	while (i < prec_len)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int		put_str_width(char **buff, t_form *form)
{
	int		i;
	char	*width;

	if (form->width <= (int)ft_strlen(*buff))
		return ((int)ft_strlen(*buff));
	if (!(width = (char *)malloc(sizeof(char) *
					(form->width - ft_strlen(*buff) + 1))))
		return (0);
	i = 0;
	while ((size_t)i < form->width - ft_strlen(*buff))
	{
		width[i] = ((form->flag & F_ZERO) ? '0' : ' ');
		i++;
	}
	width[i] = '\0';
	if (!(form->flag & F_MINUS))
		*buff = ft_strjoin(width, *buff);
	else
		*buff = ft_strjoin(*buff, width);
	free(width);
	return (form->width);
}

int		print_string(char *str, t_form *form)
{
	int		len;
	char	*buff;

	len = 0;
	if (str == NULL)
		str = "(null)";
	if (!(form->flag & F_PREC) || (size_t)form->prec > ft_strlen(str))
		form->prec = ft_strlen(str);
	buff = str_to_buff(str, form->prec, ft_strlen(str));
	len = put_str_width(&buff, form);
	ft_putstr(buff);
	free(buff);
	return (len);
}
