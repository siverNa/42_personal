/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:14:19 by sna               #+#    #+#             */
/*   Updated: 2021/08/13 17:47:47 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_atoi_pw(char *str, int *i)
{
    long    num;
    int     sign;

    num = 0;
    sign = 1;
    while (str[*i] == '\f' || str[*i] == '\n' || str[*i] == '\r' || str
		[*i] == '\t' || str[*i] == '\v' || str[*i] == ' ')
		++*i;
    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        ++*i;
    }
    while (str[*i])
    {
        if (str[*i] < '0' || str[*i] > '9')
            break ;
        num = num * 10 + (str[*i] - '0');
        ++*i;
    }
    while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
        ++*i;
    if (num * sign < -2147483648 || num * sign > 2147483647)
        print_error();
    return (num * sign);
}

char	**ft_free_pw(char **new_str)
{
	size_t	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (NULL);
}

int		ft_str_isdigit(char *c)
{
	int 	i;

	i = 0;
	if (c[i] == '+' || c[i] == '-')
		i++;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	insert_a_deq(t_deque *a, char **av, int ac)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	a->size = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{	
			lst_addend(av[i], a, &j);
			a->size++;
		}
		i++;
	}
}