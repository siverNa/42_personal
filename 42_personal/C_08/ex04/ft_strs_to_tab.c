/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:06:30 by sna               #+#    #+#             */
/*   Updated: 2020/11/04 21:48:52 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void				*ft_free(void *str)
{
	free(str);
	return (NULL);
}

char				*ft_strdup(char *src)
{
	char			*dest;
	char			*p;
	int				i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (dest = ft_free(dest));
	p = dest;
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = 0;
	return (dest);
}

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*s_myarr;
	int				i;

	if (ac < 0)
		return (0);
	if (!(s_myarr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (s_myarr = ft_free(s_myarr));
	i = 0;
	while (av[i] != '\0' && i < ac)
	{
		s_myarr[i].size = ft_strlen(av[i]);
		s_myarr[i].str = av[i];
		s_myarr[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_myarr[i].size = 0;
	s_myarr[i].str = 0;
	s_myarr[i].copy = 0;
	return (s_myarr);
}
